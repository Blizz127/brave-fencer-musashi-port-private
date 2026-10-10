/* sc03_0098: func_80157808 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern int D_801C4358;
extern void (*D_8018762C[])(void);
extern int D_801C4358;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_80157808(void *param_1)
{
    D_8018762C[*(unsigned short *)((char *)param_1 + 2)]();
    D_801C4358 = D_801C4358 - 1;
    if (D_801C4358 == -1) {
        func_801599A4(param_1);
        func_80159B3C(param_1);
    }
}
