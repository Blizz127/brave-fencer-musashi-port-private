/* sc01_0077: func_8013C9C4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern s32 D_801D9568;
extern void func_80019064(void *a0);
s32 func_80019198();
extern M2C_UNK D_80062BC0;
extern s32 D_801D9568;
extern s8 D_801D956C;
extern s8 D_801D956D;

void func_8013C9C4(void * arg0)
{
    D_801D9568 = arg0;
    D_801D956C = 0;
    D_801D956D = 0;
    if (func_80019198() == 0) {
        func_80019064(&D_80062BC0);
    }
}
