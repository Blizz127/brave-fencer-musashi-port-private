/* sc03_0098: func_8017B8E8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
typedef struct { unsigned char b[8]; } S8_8017B8E8;
extern s16 D_801C549C;
extern s16 D_801C5494;

s32 func_8017B8E8(s32 src) {
    (*(S8_8017B8E8 *)&D_801C549C) = ((S8_8017B8E8 *)src)[0];
    (*(S8_8017B8E8 *)&D_801C5494) = ((S8_8017B8E8 *)src)[1];
}
