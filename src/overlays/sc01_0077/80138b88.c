/* sc01_0077: func_80138B88 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80138B88(s32 a0) {
    s32 a1;
    if (*(s32*)(a0 + 0x8) & 0x2000) {
        *(s16*)(a0 + 0x4) = 0xD;
    } else {
        *(s16*)(a0 + 0x4) = 0xC;
        *(s32*)(a0 + 0x8) &= ~0x1000;
        a1 = *(s32*)(a0 + 0x40);
        if (a1 != 0) {
            if (*(u16*)(a0 + 0x18) != 0) {
                *(s16*)a1 = 3;
            }
        }
    }
}
