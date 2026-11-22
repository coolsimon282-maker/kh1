# Porting plan: from the matching decompile to native PC and PSP builds

Status: planning (22 Nov 2026). The matching decompile comes first; this track runs alongside it and must never
slow it down. Everything here is built from the user's own disc; no game data is ever shipped.

Lessons are taken from existing decompile ports, mainly the Ocarina of Time PSP port
([z2442/oot-PSP](https://github.com/z2442/oot-PSP), with design notes in its `docs/`), the Super Mario 64 PSP
port ([z2442/sm64-port](https://github.com/z2442/sm64-port)) and Mario Kart 64 on PSP
([beckerd/psp_mk64_portable](https://github.com/beckerd/psp_mk64_portable)). They share one design: leave the game
code alone, replace the console's system library, and translate the console's graphics command stream at run time.

## The shape of the port

```
 game code (decompiled C, unchanged)          <- the matching decompile, ~6,300 functions
 ─────────────────────────────────────────────────────────────── platform boundary (~80 functions)
 libsce shim: same names and signatures as Sony's libraries   <- like OoT's libultra_psp.c
   graphics: sceDmaSend chains -> packet translator -> GE (PSP) / OpenGL-Vulkan (PC)
   sound/files: sceSifCallRpc -> host audio + file reads from the user's disc image
   saves, pad, CD, video: small host-specific implementations
 portable maths: libvu0 / libm / libc / libgcc               <- plain C (PC), VFPU (PSP)
```

## The platform boundary (measured)

Every `jal` from game code into the library area of the original program (`eu-notes/platform_calls.py`):
**167 library functions, 4,219 call sites.** About 3,350 of those sites are portable maths and C (libvu0, libm,
libc, libgcc). The real hardware boundary is roughly 80 functions:

- **graphics:** `sceDmaSend` / `sceDmaGetChan` (343 sites) and 9 GS functions (265 sites). The game builds
  VIF/GIF packets and sends them to VU1 and the GS by DMA.
- **IOP RPC (sound, files):** `sceSifCallRpc` (20 sites) plus the kernel's thread, cache and DMA-handler functions.
- **memory card:** 15 functions. **CD:** 11. **pad:** 5. **IPU (FMVs):** 1. **rumble / dbc / perf:** 1 each.

The full table is in [platform-boundary-table.md](platform-boundary-table.md).

## Workstreams

### P0: groundwork. Can start now, by scripts or one light agent, without touching matching work.
1. **Platform boundary inventory.** Done; see above.
2. **Rendering path map.** List the game functions that build DMA/VIF/GIF packets (the callers of
   `sceDmaSend`, `sceGsExecLoadImage`, `sceGsSyncPath`). Find where the VU1 microprograms live in the program and
   data, what each one does (skinning, lighting, clipping), and the packet formats. This decides the translator
   level for P2.
3. **IOP / sound map.** Find which IOP modules the game loads, which RPC servers it calls and what each
   `sceSifCallRpc` site asks for (sound effects, music, streaming, file loading).
4. **Asset inventory.** Document KH1 FM's disc layout and formats (the archive, models, textures, motions,
   sound banks), using existing community format knowledge. Design the first-boot converter (P3).
5. **Memory map.** Record the heaps, fixed buffers and VRAM use, with sizes and peaks per area. This is the input
   for the PSP memory budget.
6. **Main loop and timing.** Find the frame loop, the vsync waits and the logic/render split, to plan 60 fps
   presentation.

### P1: shiftable build. Experiment early, finish once most code is C.
- A non-matching build option in which the code may move: no fixed-address symbol files for code, every data
  reference symbolic.
- Find the hard-coded addresses: absolute constants used as pointers (a3 found symbols for `0xFE0000`-style
  constants), pointer tables in data, and overlays if any.
- Done when the ELF still runs in PCSX2 after code is deliberately shifted. That's the proof the code is portable.

### P2: platform layer (libsce shim)
- Headers with Sony's exact signatures; one implementation per target (`port/pc/`, `port/psp/`).
- **Graphics translator.** Decide from the P0 rendering map between two approaches:
  (a) **packet level**: interpret the VIF/GIF stream, run VU1 microprograms in C (or VFPU), and emit GE or GL
  draws. This is generic and close to how the N64 ports translate display lists, but VU1 emulation costs CPU time.
  (b) **draw-call level**: replace KH's own few model/sprite drawing functions with native ones that skip the
  packets. Faster, but each drawing path needs rewriting.
  Likely a mix: (b) for the hot paths (character and map models), (a) for the rarer effects.
- Keep `libvu0` as a portable C implementation (PC) with a VFPU version for the PSP's hot paths.
- 64-bit (PC): find the structs that store pointers in 32-bit fields. The PSP is 32-bit, so this matters for PC only.

### P3: assets, built on first boot from the user's own disc (OoT PSP model)
- The user points the port at their own disc image. The port checks it (size and checksum of SLPS_251.98 or the
  ISO), converts once into a packed asset file behind a progress screen, and later launches just read that file.
- Conversion: textures (PS2 TM2/GS formats to GE swizzled formats or GL), models (to vertex buffers with
  pre-resolved skinning data), sounds (to host formats).
- PSP: smaller textures and a streaming layout, because memory is the hard limit (below).

### P4: targets
- **PC first**: easiest to debug, lots of memory, and the GL/Vulkan renderer doubles as the reference renderer.
- **PSP second**, with OoT PSP's proven techniques:
  - **GE submission batching** (12 draws or 220 triangles per publish) and a **2 MiB cached vertex arena** with one
    `sceKernelDcacheWritebackRange` per batch (about 12× fewer kernel calls in OoT).
  - **VFPU assembly** for transform and clipping; a texture manager/cache.
  - A **separate video thread**, so game logic runs the next tick while the GE draws.
  - **Audio mixing on the Media Engine.**
  - **20 fps default with 60 fps presentation** by matrix interpolation; the simulation stays at its own rate.
  - Suspend/resume handling, and TV-out on Slim models.
  - **Memory is the hard part.** N64 games (4–8 MB) fitted easily; KH1 used 32 MB plus separate VRAM, IOP and SPU
    memory. Target the PSP Slim (64 MB), stream assets per area, and use smaller textures.

## Order of work and dependencies
1. Matching decompile (in progress), with P0 groundwork alongside it.
2. Data into C, real source files instead of `src/unsplit` placeholders, and names and types.
3. P1, the shiftable build.
4. P2 and P3 for PC, giving the first native build.
5. P4 for PSP.

## Rules
- Only the user's own disc, read at first boot or by the user's own conversion step. Nothing from the disc or from
  the PC remaster is committed or shipped. The remaster, if used at all, is reference-only, to understand the PS2
  code.
- The port is the decompiled game itself built for new targets. It is separate from the user's own `psp-engine`
  project; no KH code or assets go into that.
