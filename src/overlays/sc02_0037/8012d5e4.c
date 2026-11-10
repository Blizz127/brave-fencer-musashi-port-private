/* sc02_0037: func_8012D5E4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_80126B98;
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);

s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (func_8012DEB8(a0, a1, a2) != 0) {
        D_80126B98 = a3;
        return 1;
    }
    return 0;
}
