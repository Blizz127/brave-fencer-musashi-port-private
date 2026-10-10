/* sc01_0077: func_80184278 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef void (*code_fn)(void);
extern s32 func_8012B4B8();
extern s32 func_8012B4B8();
extern code_fn D_8018AE88[];
extern s32 func_8012B4B8();

void func_80184278(int param_1)
{
    D_8018AE88[*(unsigned short *)(param_1 + 2)]();
    ((void (*)(int))func_8012B4B8)(param_1);
    return;
}
