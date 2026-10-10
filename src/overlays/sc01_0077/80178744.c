/* sc01_0077: func_80178744 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

void func_80178744(s32 a0, s32 a1) {
    s32 v0;
    s16 sv;
    if (*(s32 *)(a0 + 0x6C) != 0) {
        func_80178744(*(s32 *)(a0 + 0x6C), a1);
    }
    v0 = *(s32 *)(a0 + 0x20);
    sv = a1;
    *(s16 *)(v0 + 0x1C) = sv;
    *(s16 *)(v0 + 0x1A) = sv;
    *(s16 *)(v0 + 0x18) = sv;
    if (a1 == 0x1000) {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = *(u16 *)(v1 + 0x2C) & 0xFFEF;
    } else {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = *(u16 *)(v1 + 0x2C) | 0x10;
    }
}
