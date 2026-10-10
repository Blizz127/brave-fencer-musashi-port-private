/* sc01_0077: func_8013A9B4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A9F8(s32 a0, s32 a1);
extern void func_8013A9F8(s32 a0, s32 a1);
void func_8013A9F8(s32 a0, s32 a1);

void func_8013A9B4(s32 a0, s32 a1) {
    *(s16 *)(a1 + 0x2) = 0;
    *(s32 *)(a1 + 0x4) = a0;
    *(s32 *)(a0 + 0x40) = a1;
    *(s16 *)(a1 + 0x0) = 1;
    *(s16 *)(a1 + 0xC) = 0;
    *(s16 *)(a1 + 0xE) = 0;
    func_8013A9F8(a1, *(u16 *)(a0 + 0x18));
}
