/* sc03_0001: func_8017F1F0 from Druthulu/BFM-decomp src/ov_SC03_001, rewritten
 * to return its value as s32 (upstream used a $v0 register-asm idiom).
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 D_801EEAEC[];

s32 func_8017F1F0(s32 a0, s32 a1)
{
    s32 x = D_801EEAEC[0];
    s32 y = a1;
    s32 d;
    if (y < a0) {
        if (x < y) {
            x = x + 0x5A0;
        }
        y = y + 0x5A0;
    }
    if (a0 >= x) return -1;
    if (x >= y) return -1;
    d = x - a0;
    if (d < 16) return d * 2;
    d = y - x;
    if (d < 16) return d * 2;
    return 31;
}
