/* sc03_0098: func_8017EEF8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
extern void func_8012A568(void (*a0)(void));
extern void func_8013B7F4(void *a0, int a1);

int func_8017EEF8(int param_1)
{
    extern unsigned char D_80188F7C[];
    int iVar1;
    iVar1 = *(int *)(D_80188F7C + param_1 * 4);
    func_8013B7F4((void *)iVar1, 0);
}
