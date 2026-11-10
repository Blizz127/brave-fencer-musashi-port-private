/* sc02_0037: func_8012EECC from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_8002A4FC(s32 a0);

s32 func_8012EECC(s32 a0) {
    s32 n = a0 * func_8002A4FC(a0);
    return a0 - (n * 100) / 7680;
}
