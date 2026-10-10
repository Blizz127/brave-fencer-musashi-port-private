/* sc03_0098: func_8012A6D0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_80047D3C(s32 a0);
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012A6D0(void* a0, void* a1)
{
    s32 s0 = a0;
    s32 s1 = a1;
    s32 dy = *(s16 *)(s0 + 0x4) - *(s16 *)(s1 + 0x4);
    s32 dx = *(s16 *)(s0 + 0x0) - *(s16 *)(s1 + 0x0);
    s32 d;
    d = func_80047D3C(dy * dy + dx * dx);
    return (s16)func_8004CFEC(*(s16 *)(s0 + 0x2) - *(s16 *)(s1 + 0x2), (s16)d);
}
