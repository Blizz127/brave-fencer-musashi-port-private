/* sc03_0001: func_8018CDD8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
extern void func_8001CB00(int param_1, void *src, int len, int n);
extern unsigned char D_801EB36C;

void func_8018CDD8(int param_1)
{
    unsigned short uVar1;
    int iVar2;
    iVar2 = *(int *)(param_1 + 0x20);
    func_8001CB00(iVar2, &D_801EB36C, 0x280, 0x100);
    *(unsigned int *)(iVar2 + 4) = *(unsigned int *)(iVar2 + 4) | 0x70000000;
    uVar1 = *(unsigned short *)(param_1 + 0x2c);
    *(unsigned char *)(iVar2 + 0x27) = 0x9e;
    *(unsigned short *)(iVar2 + 0x2c) = 4;
    *(unsigned short *)(iVar2 + 0x1c) = uVar1;
    *(unsigned short *)(iVar2 + 0x1a) = uVar1;
    *(unsigned short *)(iVar2 + 0x18) = uVar1;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
    return;
}
