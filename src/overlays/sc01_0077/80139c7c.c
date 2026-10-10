/* sc01_0077: func_80139C7C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80139C7C(u8 *a0) {
    s32 a1;
    if (*(u8 *)(a0 + 0x20) != 0) {
        if (*(u8 *)(a0 + 0x22) & 0x8) {
            a1 = (*(s16 *)(a0 + 0x34) + 0x28) >> 1;
        } else {
            a1 = ((*(s16 *)(a0 + 0x34) + 0x28) >> 1) - 0x28;
        }
    } else {
        a1 = (s32)(*(u16 *)(a0 + 0x34) << 16) >> 17;
    }
    *(s16 *)(a0 + 0x30) = *(u16 *)(a0 + 0x24) - a1;
    *(s16 *)(a0 + 0x32) = *(u16 *)(a0 + 0x26) - ((s32)(*(u16 *)(a0 + 0x36) << 16) >> 17);
}
