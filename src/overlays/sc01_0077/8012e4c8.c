/* sc01_0077: func_8012E4C8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012E4C8(s32 a0) {
    s32 v1;
    s32 t;
    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1C) = 0x1000;
    *(s16 *)(v1 + 0x18) = 0x1000;
    *(s16 *)(a0 + 0x60) = 0;
    *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) | 1;
    t = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
    *(s16 *)(a0 + 0x5E) = 1;
    *(s16 *)(a0 + 0x62) = t + 0x800;
}
