/* SC02.CD member35: func_8017D368 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
extern void func_8012A568(void (*a0)(void));
extern void func_8013B7F4(void *a0, int a1);

int func_8017D368(int param_1)
{
    extern unsigned char D_80187F3C[];
    int iVar1;
    iVar1 = *(int *)(D_80187F3C + param_1 * 4);
    func_8013B7F4((void *)iVar1, 0);
}
