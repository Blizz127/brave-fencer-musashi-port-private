/* sc03_0001: func_8017DC50 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012CBCC(s32 a0);
extern void func_8012C218(void *a0);

void func_8017DC50(arg0)
s32 arg0;
{
    register s32 s0 __asm__("$16");
    s32 v0;
    s32 v1;
    register s32 a0 __asm__("$4");
    register s32 a1 __asm__("$5");
    s0 = arg0;
    v1 = func_8012CBCC(s0);
    v0 = v1 & 0x6000;
    if (v0 != 0) {
        *(s16 *)(s0 + 0x16) = -4;
    }
    v0 = v1 & 0x8000;
    if (v0 != 0) {
        v0 = *(s32 *)(s0 + 0x4);
        v1 = *(s32 *)(s0 + 0x10);
        a0 = *(s32 *)(s0 + 0x14);
        a1 = *(s32 *)(s0 + 0x18);
        v0 = v0 + v1;
        *(s32 *)(s0 + 0x4) = v0;
        v0 = *(s32 *)(s0 + 0x8);
        v1 = *(s32 *)(s0 + 0xC);
        v0 = v0 + a0;
        v1 = v1 + a1;
        *(s32 *)(s0 + 0x8) = v0;
        *(s32 *)(s0 + 0xC) = v1;
    }
    v0 = *(s32 *)(s0 + 0x1C) - 1;
    *(s32 *)(s0 + 0x1C) = v0;
    if (v0 == 0) {
        func_8012C218((void *)s0);
    }
}
