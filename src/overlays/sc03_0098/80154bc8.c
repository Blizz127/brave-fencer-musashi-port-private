/* sc03_0098: func_80154BC8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;

void func_80154BC8(void *a0, s32 a1, s32 a2) {
    *(s32 *)((s32)a0 + 0xD0) = a1;
    *(s16 *)((s32)a0 + 0xD6) = 1;
    *(s16 *)((s32)a0 + 0xD4) = 1;
    *(s8 *)((s32)a0 + 0xD8) = a2;
    *(s8 *)((s32)a0 + 0xD9) = a2;
}
