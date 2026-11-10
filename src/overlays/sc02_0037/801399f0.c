/* sc02_0037: func_801399F0 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_801399F0(s32 a0) {
    s32 v1;
    if (*(s32*)(a0 + 0x0) == 0) return -1;
    v1 = *(s16*)(a0 + 0x4);
    if (v1 == 0) return -1;
    if (v1 == 0xE) return -1;
    if (v1 == 0xD) return *(s8*)(a0 + 0x1F);
    return 0;
}
