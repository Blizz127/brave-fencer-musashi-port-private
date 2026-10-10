/* sc01_0077: func_8017EE20 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012AD50(void *a0);

void func_8017EE20(void *a0) {
    *(s32 *)((s32)a0 + 0x1C) = 1;
    func_8012AD50(a0);
}
