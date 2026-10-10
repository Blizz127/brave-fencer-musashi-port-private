/* sc03_0098: func_8017CD9C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
extern void func_8017D030(int);
void func_8017D030(int param_1);

void func_8017CD9C(int param_1)
{
    int iVar1;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = iVar1 + 1;
    if (iVar1 < 0xc) {
        *(unsigned short *)(param_1 + 0x12) = *(unsigned short *)(param_1 + 0x12) + 0xe0;
    } else {
        *(int *)(param_1 + 0x1c) = 0;
        *(unsigned short *)(param_1 + 2) = *(unsigned short *)(param_1 + 2) + 1;
    }
    func_8017D030(param_1);
    return;
}
