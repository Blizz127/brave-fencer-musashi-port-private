/* sc02_0037: func_8013A9F8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8013A9F8(s32 a0, s32 a1) {
    s32 orig = a1;
    a1 -= 2;
    a1 &= 0xFFFF;
    if ((u32)a1 < 5) {
        s32 b = orig & 0xFFFF;
        b -= 2;
        b <<= 10;
        *(s16*)(a0 + 0xE) = b;
    }
}
