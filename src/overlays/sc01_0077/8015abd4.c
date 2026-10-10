/* sc01_0077: func_8015ABD4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_80029178(s32 arg);
extern s32 func_8016F1AC(void);
extern s32 func_80029178(s32 a0);
extern s32 func_80029178(s32);
extern s32 func_8016F1AC(void);
extern s32 func_80029178(s32 a0);
extern s32 D_8011F9C4;

s32 func_8015ABD4(s32 a0, s32 a1, s32 a2) {
    if (func_8016F1AC() != 0) {
        return 0;
    }
    if (a2 < a1) {
        if (D_8011F9C4 == 0) {
            return 0;
        }
        if ((func_80029178(0x21) & 0xFF) != 0) {
            return 0;
        }
    }
    return 1;
}
