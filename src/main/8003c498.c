/* Exact retail word export for [8003C498,8003C4F0); EXE and assembly verified. */
extern unsigned int func_8003AF4C(int, unsigned int);
extern unsigned short D_8006B564;
extern int D_8006B574;
unsigned int func_8003C498(unsigned int address)
{
    unsigned int result;
    if (address - 0x1010U <= 0x7EFE8U) {
        D_8006B564 = func_8003AF4C(-1, address);
        result = D_8006B564 << D_8006B574;
    } else {
        result = 0;
    }
    return result;
}
