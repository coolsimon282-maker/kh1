import struct, collections, os, re
WSL_HOME = r'\\wsl.localhost\Ubuntu\home\you'

def elf_functions(elf):
    """{address: (matched?)} for every function-start symbol in the game's code range. A function still in
    assembly has a '<name>.NON_MATCHING' label at its address (splat's nonmatching macro)."""
    b = open(elf, 'rb').read()
    shoff, = struct.unpack_from('<I', b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from('<HHH', b, 0x2E)
    secs = [struct.unpack_from('<IIIIIIIIII', b, shoff + i * shentsize) for i in range(shnum)]
    symtab = [s for s in secs if s[1] == 2][0]
    stroff = secs[symtab[6]][4]
    names = collections.defaultdict(list)
    for off in range(symtab[4], symtab[4] + symtab[5], 16):
        nm, val, size, info, other, shndx = struct.unpack_from('<IIIBBH', b, off)
        e = b.index(b'\0', stroff + nm)
        names[val].append(b[stroff + nm:e].decode('latin-1'))
    return names

if __name__ == '__main__':
    names = elf_functions(os.path.join(WSL_HOME, 'kh1-decomp-build', 'build', 'fm', 'SLPS_251.98.elf'))
    code = {v: n for v, n in names.items() if 0x100000 <= v < 0x272c70}
    um = {v for v, n in code.items() if any(x.endswith('.NON_MATCHING') for x in n)}
    fn = {v for v, n in code.items() if any(re.match(r'^(func_|fm_func_|[A-Za-z_]\w*$)', x) and not x.startswith(('D_', 'jtbl_', '.L', 'L')) for x in n)}
    print('code addresses', len(code), 'function-like', len(fn), 'still asm', len(um), 'matched', len(fn - um))
    print([n for v, n in sorted(code.items())[:8]])
