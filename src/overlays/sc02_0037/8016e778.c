/* sc02_0037: func_8016E778 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AE5C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
extern void func_8016E7C8(int param_1, short *p1, unsigned int *p2);
void func_8016E7C8(int param_1, short *param_2, unsigned int *param_3);

void func_8016E778(int param_1)
{
    short local_18[3];
    unsigned int local_10;
    unsigned short uVar1;
    int iVar2;
    uVar1 = *(unsigned short *)(param_1 + 0x12);
    local_18[2] = uVar1;
    local_18[1] = uVar1;
    local_18[0] = uVar1;
    iVar2 = *(short *)(param_1 + 0x16);
    local_10 = iVar2 | (iVar2 << 16 | iVar2 << 8);
    func_8016E7C8(param_1, local_18, &local_10);
}
