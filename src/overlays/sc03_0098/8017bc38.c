/* sc03_0098: func_8017BC38 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
extern void (*D_801C546C[10])(int);

void func_8017BC38(int param_1)
{
    int i;
    void (**p)(int);
    i = 0;
    p = D_801C546C;
    do {
        if (*p != (void (*)(int))0) {
            (*p)(param_1);
        }
        i = i + 1;
        p = p + 1;
    } while (i < 10);
    return;
}
