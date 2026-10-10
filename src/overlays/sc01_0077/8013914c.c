/* sc01_0077: func_8013914C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80139220(s32 a0);
s32 func_80139220(s32 a0);

s32 func_8013914C(s32 a0, s32 a1) {
    s32 t;
    if ((s32)*(u16 *)(a0 + 0x14) >= *(s16 *)(a0 + 0x2C)) {
        if (func_80139220(a0) != 0) {
            return 1;
        }
    }
    t = *(u16 *)(a0 + 0x14);
    *(s16 *)(a1 + 0x0) = *(u16 *)(a0 + 0x38) + (((u32)(t * 3)) >> 1);
    t = *(u16 *)(a0 + 0x12);
    *(s16 *)(a1 + 0x2) = *(u16 *)(a0 + 0x3A) + ((t * 3) << 2);
    *(s16 *)(a0 + 0x14) = *(u16 *)(a0 + 0x14) + 1;
    return 0;
}
