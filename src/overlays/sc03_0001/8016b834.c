/* sc03_0001: func_8016B834 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void *, unsigned short);
extern int *D_8019072C[];
extern unsigned short D_80190734[];
extern unsigned short D_8019073C[];
extern unsigned char D_801ED950[];

int func_8016B834(int param_1, int param_2) {
    int *puVar3;
    int *puVar2;
    int iVar1;
    puVar2 = (int *)(D_801ED950 + param_2 * 0x40);
    puVar3 = D_8019072C[*(int *)(param_1 + 0x2c)];
    iVar1 = ((int (*)(void))func_801465C0)();
    if (iVar1 != 0) {
        func_8001CD9C(iVar1, puVar2);
        func_800233CC(puVar2, D_80190734[param_2]);
        puVar2[0] = *(int *)((int)puVar3 + param_2 * 8);
        puVar2[1] = *(int *)((int)puVar3 + param_2 * 8 + 4);
        *(unsigned int *)(iVar1 + 4) = *(unsigned int *)(iVar1 + 4) | 0x50040000;
        *(short *)(iVar1 + 0x1e) = D_8019073C[param_2];
    }
    return iVar1;
}
