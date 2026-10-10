/* sc01_0077: func_8012BA10 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 x, s32 y);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern u16 D_80126B66;
extern u16 D_80126B5E;
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012BA10(s32 arg0, s32 arg1) {
    extern u16 D_80126B5E;
    extern u16 D_80126B66;
    register s32 d __asm__("$16");
    s32 s1ang;
    s32 u5; s32 u6; s32 iVar4; s32 q; s32 t;
    d = arg1;
    s1ang = *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12);
    u5 = (func_8004CFEC(*(s16 *)(arg0 + 0xE) - (s16)D_80126B66, (s16)D_80126B5E - *(s16 *)(arg0 + 6)) - 0x400) & 0xFFF;
    __asm__ __volatile__("" : : "r"(u5));
    d = (s16)d;
    u6 = s1ang & 0xFFF;
    if (u6 == u5) return 0;
    iVar4 = u5 - u6;
    if (iVar4 > 0x800) { t = u6 + 0x1000; iVar4 = u5 - t; }
    if (iVar4 < -0x800) { t = u6 - 0x1000; iVar4 = u5 - t; }
    if (iVar4 >= 0) { q = iVar4 / d; if (q == 0) q = 1; }
    else { q = iVar4 / d; if (q == 0) q = -1; }
    return q;
}
