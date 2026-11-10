/* sc02_0037: func_801819B4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */


void func_801819B4(int param_1)
{
    int iVar1;
    iVar1 = *(int *)(param_1 + 0x1c) - 1;
    *(int *)(param_1 + 0x1c) = iVar1;
    if (*(int *)(param_1 + 0x1c) == 0) {
        *(short *)(param_1 + 2) = *(unsigned short *)(param_1 + 0x34);
    }
}
