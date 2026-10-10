/* sc01_0077: func_801442F8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern void (*D_801884B8[])();

void func_801442F8(int param_1)
{
    int iVar1;
    D_801884B8[*(u16 *)(param_1 + 2)]();
    iVar1 = *(int *)(param_1 + 0x1c) + 1;
    *(int *)(param_1 + 0x1c) = iVar1;
    if (0x1d < iVar1) {
        func_8012C218(param_1);
    }
}
