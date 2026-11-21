import sys, struct, rabbitizer
ELF = r'C:/Users/you/Downloads/Kingdom Hearts (Europe)/extracted/SCES_509.67'
d = open(ELF,'rb').read()
BASE, OFF = 0x100000, 0x80
def word(va): return struct.unpack_from('<I', d, OFF + va - BASE)[0]
def dis(va, n):
    out=[]
    for i in range(n):
        a = va + 4*i
        ins = rabbitizer.Instruction(word(a), vram=a, category=rabbitizer.InstrCategory.R5900)
        out.append(f'{a:08X}  {ins.disassemble()}')
    return out
if __name__ == '__main__':
    for arg in sys.argv[1:]:
        va, n = arg.split(':'); print('\n'.join(dis(int(va,16), int(n)))); print()
