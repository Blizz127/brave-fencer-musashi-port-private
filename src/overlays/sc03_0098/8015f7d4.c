/* sc03_0098: func_8015F7D4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;

s32 func_8015F7D4(s32 a0) {
    extern void (*D_80187CF8[])(void);
    D_80187CF8[*(u16 *)((s32)a0 + 0x2)]();
}
