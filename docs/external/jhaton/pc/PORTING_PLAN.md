# Kingdom Hearts PC Port Plan

## Goal

Produce a playable native PC build of the original Japanese Kingdom Hearts release while preserving the existing exact-matching PlayStation 2 build. The PC build must support arbitrary changes to recovered C logic, scripts, assets, rendering, audio, and platform behavior without requiring original code or data to retain PlayStation 2 addresses or sizes.

The matching and PC builds are separate products:

- **PS2 matching build:** reproduces the original ELF and checksum.
- **PC development build:** prioritizes observable compatibility, portability, debugging, and unrestricted modification.

## Licensing policy

The PC port will not incorporate, copy, or link GPL implementation code. PCSX2 may be used only as a behavioral oracle: running the legally supplied game, capturing traces and reference images, comparing state, and validating behavior. Knowledge learned from observation must be reimplemented independently in this repository.

Dependencies introduced into `pc/` must have licenses compatible with a non-GPL project. Dependency provenance and license must be recorded before code is imported.

## Host architecture

- **Language:** C++20 for the host runtime, ownership, generated-code dispatch, tools, and renderer management.
- **Recovered game code:** remains C-compatible and can be linked into the C++ host through explicit interfaces.
- **Platform:** SDL3 for windows, input, audio devices, timing, and portable OS integration.
- **Native renderer target:** SDL_GPU.
- **Compatibility renderer:** an independently implemented backend that consumes the original DMA/VIF/VU/GIF/GS behavior. SDL_GPU is preferred if an evidence-driven frame replay proves it can express the required behavior; otherwise the compatibility backend may use a non-GPL lower-level API while the native renderer remains SDL_GPU.
- **Build:** CMake and Ninja, independent of the Splat/MIPS matching graph.

## Architectural invariants

1. Guest pointers and function addresses are explicit 32-bit values. Host pointers never appear in guest-facing data.
2. Guest memory access is bounds-checked and little-endian.
3. Indirect guest calls go through a dispatcher; guest addresses are never cast to host function pointers.
4. Unsupported instructions, SDK calls, renderer states, or assets fail with precise diagnostics. There are no silent success stubs.
5. Simulation uses a fixed update tick independent of render frequency.
6. Filesystem, input, audio, timing, threading, and rendering are behind narrow host interfaces.
7. Original assets remain local inputs. Generated traces and source-derived metadata may be committed only when they do not contain prohibited game assets.
8. Native overrides are keyed by original guest addresses so translated functions can be replaced individually with recovered or modified C.
9. The PS2 matching build and its checksum gates remain unchanged.

## Execution strategy

Unrecovered native functions cannot block the port. Guest code has three execution tiers:

1. Native C override.
2. Independently generated static R5900 translation.
3. Interpreter fallback for unsupported functions or instructions.

The runtime gradually replaces translated logic with portable recovered C. The graphics path follows the same progression:

1. Compatibility execution of original graphics commands.
2. Native replacements for individual render systems.
3. Complete SDL_GPU renderer using decoded source assets.

## Milestones

### A0 — Host and graphics evidence foundation

Create a native SDL3/SDL_GPU executable and the interfaces needed for evidence-driven graphics work.

Acceptance:

- CMake configures and builds with the system SDL3 package.
- The application creates an SDL window and SDL_GPU device, selects a supported shader format, acquires a swapchain texture, submits command buffers, and shuts down cleanly.
- A deterministic diagnostic frame verifies the complete host render loop. This frame is only a platform proof, not a claim of game rendering.
- A non-interactive smoke mode runs in CI or a headless environment without waiting for user input.
- Renderer-backend and trace interfaces are concrete, versioned, bounds-checked, and tested.
- Runtime logs include SDL version, selected GPU backend/device, shader format, swapchain format, and failures.
- The existing PS2 scripting tests remain green.

### A1 — Real Kingdom Hearts GS frame replay

Capture one complete frame from a known room using PCSX2 solely as an oracle, then replay it in an independently implemented compatibility backend.

Capture contract includes:

- DMA and GIF command data needed by the frame.
- VIF streams and referenced VU microprogram/state.
- GS register writes.
- Referenced texture and local-memory state.
- Frame dimensions and a reference image.
- Provenance identifying game version and scenario without committing the ISO or executable.

Acceptance:

- The trace reader rejects malformed, truncated, unsupported-version, and out-of-range records.
- Replay produces a deterministic output image.
- Automated comparison reports differing pixels, maximum per-channel error, and diagnostic output.
- Evidence decides whether SDL_GPU is sufficient for compatibility rendering. If not, only the compatibility backend changes.

### B — Guest memory and ELF execution

- Load the JP ELF segments at their original virtual addresses.
- Model guest RAM and relevant memory-mapped regions.
- Execute real R5900 functions through static translation with interpreter fallback.
- Implement indirect guest-call dispatch and native override registration.
- Use PCSX2 traces to compare register, memory, and call effects.

Acceptance: execute a deterministic real game function and match its observed result and memory changes.

### C — Engine initialization

Implement or translate the platform boundaries required to reach the game main loop:

- Allocation and work buffers.
- Threads, semaphores, alarms, and fixed-step timing.
- Local file access replacing CD/DVD reads.
- Controller input.
- High-level SIF/IOP service boundaries with explicit unsupported operations.
- Script package loading and task scheduling.

Acceptance: reach stable engine updates with traceable failures and no silent SDK stubs.

### D — First rendered room

Run one actual room with:

- Room geometry and textures.
- Object creation.
- Camera.
- Event scripts.
- Player model and animation.
- Input and collision.
- Stable frame pacing.

Acceptance: deterministic room entry, visible output, controllable player, and reference comparisons against the PS2 oracle.

### E — Playable vertical slice

Complete one connected gameplay sequence containing:

- Room transition.
- Exploration.
- Combat and enemy behavior.
- UI and text.
- Audio.
- Cutscene execution.
- Save/load boundary.

### F — Whole-game compatibility

Support the original campaign end to end using compatibility systems where native replacements do not yet exist.

### G — Native development engine

Progressively replace compatibility paths with maintainable PC systems:

1. Static room geometry and textures.
2. Cameras and transforms.
3. Skeletons, skinning, and animations.
4. Collision and debug visualization.
5. UI and text.
6. Shadows and post-processing.
7. PPP particles and effects.
8. Remaining specialized VU paths.
9. Native audio and asset source pipelines.

Both renderers may coexist during migration and can render the same scenario for comparison.

## Development loop target

```text
edit recovered C / script / asset
              |
              v
incremental PC build
              |
              v
launch exact room or scenario
              |
              v
trace, compare, debug, iterate
```

The final project should provide one-command configuration, incremental build, launch, symbols, crash symbolication, runtime logging, scenario selection, and deterministic smoke checks.

## Current status

Milestone **A0 — Host and graphics evidence foundation** is complete:

- `pc/` configures independently with CMake, the system SDL3 package, and `glslc` for build-time SPIR-V shader
  compilation.
- `khpc` creates an SDL3 window and SDL_GPU device through Vulkan.
- Interactive rendering acquires and clears the real swapchain.
- `khpc --smoke` clears a 4x4 `R8G8B8A8_UNORM` GPU texture to magenta, downloads it, and verifies every
  pixel before presenting a frame.
- Runtime diagnostics report SDL versions, video driver, GPU driver/device details, shader formats, and
  swapchain format.
- The strict `KHTRACE` 1.0 parser validates framing, fixed record layouts, CRC-32 checksums, size limits,
  required records, and hardware-record bounds.
- Synthetic trace tests cover the valid format and 24 malformed-input classes without embedding game data.

Milestone **A1 — Real Kingdom Hearts GS frame replay** now has a working clean-room vertical slice:

- A development payload is independently linked at guest `0x00680000` and injected by extending the original JP
  ELF `PT_LOAD`; the matching ELF remains unchanged.
- Four preinstalled hooks observe `sceDmaSend`, the registered VSync callback, `sceGsExecLoadImage`, and
  `sceGsPutDrawEnv`. The hooks resume the original functions through verified displaced-instruction trampolines.
- A standard-library PINE client arms and observes capture state without PCSX2 code or libraries.
- Guest instrumentation records GIF DMA chains, direct image uploads, draw-environment state, final display state,
  and a 512x256 RGBA framebuffer through HostFS.
- The raw capture converter joins DMA-chain segments and emits validated repository-owned `KHTRACE` files.
- The verified boot trace contains 1,725 GIF packets, 33,859 decoded register writes, 14 IMAGE transfers containing
  157,760 bytes, chronological GS environment snapshots, and the captured reference framebuffer.
- The GIF decoder accepts every packet in that real trace.
- The first replay implements only the observed context-1 SPRITE subset: untextured clears, PSMT4 plus CLUT,
  PSMCT24 framebuffer sampling, clamp, nearest/bilinear filtering, color modulation, ALPHA `0x44`, scissor, and
  offscreen-to-display presentation.
- SDL_GPU uploads and blits the independently reconstructed RGBA frame to the real swapchain without a shader
  dependency.
- Replay comparison and raw RGBA heatmap export are available from the `khpc` CLI.

The reconstructed Disney Interactive frame is recognizably correct but not yet pixel-exact:

```text
differing_pixels     5910 / 131072
max_channel_error     245
total_absolute_error  1744091
mean_absolute_error   3.32659
```

The remaining A1 correctness work is narrowly scoped to GS edge behavior: two reference scanlines not produced by
the current logical-framebuffer model, texture/raster phase at sprite edges, and exact fixed-point filtering
quantization. These are correctness gaps, not missing textures, commands, or capture state.

The gate before milestone **B — Guest memory and ELF execution** is to preserve the current real-capture/replay
workflow as a regression scenario and either make the frame exact or explicitly version the remaining compatibility
tolerance. PCSX2 remains an external oracle; no PCSX2 dump format or implementation code enters the project.

The first source-driven gameplay scene is also live:

- `khpc --scenario destiny-islands-shack --asset-root PATH` loads the original local `di00_01.bin`,
  `di00_01.img`, `xa_ex_0010.mdls`, and `xa_ex_0010.mset` assets. `di02.ard` remains the room's independently
  selected script/entity archive; the live game state proved that map index `D_002B868C == 0` selects `di00_01`,
  rather than deriving the map number from room index `D_002B8680 == 1`.
- The native KH1 map reader validates the sector and VIF tables, reconstructs triangle strips and double-sided
  faces, decodes vertex colors and fixed-point UVs, resolves texture-bank and CLUT references, and expands the
  indexed textures to RGBA.
- The shack shell currently contains 796 map meshes, 2,182 material submeshes, 38,246 triangles, and 53 referenced
  textures.
- The KH1 MDLS reader validates Sora's MOBJ tables, retains each single-weight VIF vertex's joint index,
  reconstructs 2,828 triangles across nine textured meshes, and decodes seven indexed 128x128 textures and
  their swizzled CLUTs.
- The MSET reader resolves standing-motion slot zero, validates its 293-joint MMTN record, and samples 154
  initial channels plus 154 F-curves and 622 constant, linear, or Hermite keys. Its multi-joint target chains
  keep the animated hands and feet aligned instead of applying unconstrained FK to those limbs.
- The interactive shell renders directly through SDL_GPU. Vertex/index buffers and decoded texture atlases are
  uploaded once. A persistent 293-matrix storage buffer is cycled and updated from the looping 60 Hz idle on
  each frame before the opaque depth-writing and translucent blended indexed draw passes. Camera movement still
  changes only the camera uniform.
- The CPU compatibility rasterizer remains only for deterministic raw-RGBA export and oracle comparisons; its
  Sora snapshot samples frame 50 captured from the stable shack save.
- The fixed view uses the game's `D_002DEC20` world-to-GS matrix captured from the stable shack save. Interactive
  `W/S`, `A/D`, and `Q/E` movement translates that camera; `R` restores the captured view without reparsing assets.
- Against the normalized PCSX2 oracle, the background-only mask has mean absolute RGB error 2.6303. Sora's
  textured geometry and standing motion are now present; the save-point effect, interaction marker, and HUD
  remain absent.

Gameplay `KHTRACE` capture remains blocked at the current interposed `sceDmaSend` boundary. The next recorder must
store tag roots with bounded writes, immediately resume the original submission, and drain completed chains only
after the game's normal synchronization. This does not block source-driven asset loading or native scene work.
