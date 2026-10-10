/* sc03_0098: func_8016004C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern u8 D_800B9A17;

void func_8016004C(s32 a0) {
    *(s32 *)((s32)a0 + 0x184) = 0;
    *(s16 *)((s32)a0 + 0x18A) = 0;
    *(s16 *)((s32)a0 + 0x188) = 0;
    *(s32 *)((s32)a0 + 0x44) &= ~0x10;
    D_800B9A17 = 1;
}
