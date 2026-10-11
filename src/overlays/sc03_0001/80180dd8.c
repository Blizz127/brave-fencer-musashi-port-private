/* sc03_0001: func_80180DD8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
s32 func_80180AC4(s32 a0);
extern s32 func_80180AC4(s32 a0);
extern s32 func_80180B5C(void *a0);

void func_80180DD8(int param_1)
{
    if (((int (*)(void))func_80180AC4)() != 0) {
        ((void (*)(int))func_80180B5C)(param_1);
    }
}
