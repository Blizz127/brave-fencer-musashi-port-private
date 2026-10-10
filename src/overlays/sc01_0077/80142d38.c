/* sc01_0077: func_80142D38 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);

s32 func_80142D38(s32 *a0) {
    if (func_8012BEE8((s32)a0) == 1) {
        return 1;
    }
    if (a0[0x1C / 4] & 1) {
        ((s32 *)a0[0x20 / 4])[1] |= 0x80000000;
    } else {
        ((s32 *)a0[0x20 / 4])[1] &= 0x7FFFFFFF;
    }
    return 0;
}
