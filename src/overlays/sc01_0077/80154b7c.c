/* sc01_0077: func_80154B7C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;

void func_80154B7C(u8 *a0, s32 a1) {
    *(s32 *)(a0 + 0xD0) = a1;
    *(s16 *)(a0 + 0xD6) = 1;
    *(s16 *)(a0 + 0xD4) = 1;
    a0[0xD8] = 0;
    a0[0xD9] = 0;
}
