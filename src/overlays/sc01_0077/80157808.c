/* sc01_0077: func_80157808 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int D_801D9650;
extern void (*D_80188E28[])(void);
extern int D_801D9650;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_80157808(void *param_1)
{
    D_80188E28[*(unsigned short *)((char *)param_1 + 2)]();
    D_801D9650 = D_801D9650 - 1;
    if (D_801D9650 == -1) {
        func_801599A4(param_1);
        func_80159B3C(param_1);
    }
}
