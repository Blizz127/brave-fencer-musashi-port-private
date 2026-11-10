/* sc02_0037: func_8012A79C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);

s16 func_8012A79C(s16 *a0, s16 *a1) {
    s16 x0 = a0[0];
    s16 x1 = a1[0];
    s16 y0 = a0[2];
    s16 y1 = a1[2];
    return func_8004CFEC(x0 - x1, y0 - y1);
}
