/* sc01_0077: func_80147324 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void *D_8012707C;
extern void func_80147364();
extern void func_80147364();
extern void *D_8012707C;

void func_80147324(s32 arg0) {
    s32 temp_a0;
    temp_a0 = arg0 & 0xFFFF;
    if (temp_a0 == D_8012707C) {
        D_8012707C = 0;
        return;
    }
    func_80147364(temp_a0, 0);
}
