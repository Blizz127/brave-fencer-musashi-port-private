/* sc01_0077: func_8016F410 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern s32 func_8016F44C(s32 a0);
extern void func_8016F470(s32 a0);
s32 func_8016F44C(s32 a0);
void func_8016F470(s32 a0);

s32 func_8016F410(s32 a0) {
    if (func_8016F44C(a0) == 0) {
        return 0;
    }
    func_8016F470(a0);
    return 1;
}
