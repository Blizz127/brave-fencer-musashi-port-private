/* sc01_0077: func_801599E0 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_80159A20();
void func_80159A20(unsigned char *param_1);

void func_801599E0(void *a0) {
    func_80159A20(a0);
    *(u8 *)((s32)a0 + 0x4D) += 1;
}
