/* sc02_0037: func_8016D688 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8016AE5C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern void func_8001CD9C(int, void*);
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_8001CD9C(int, void *);
extern unsigned char D_801C8B49[];
extern unsigned char D_801C8B4A;
extern unsigned char D_801C8B4C;
extern unsigned char D_801C8B4D;
extern unsigned char D_801C8B4E;

void func_8016D688(int param_1)
{
    int iVar2;
    int iVar3;
    D_801C8B49[0] = 0xE0;
    D_801C8B4A = 0xE0;
    D_801C8B49[-1] = 0xE0;
    D_801C8B4E = 0;
    D_801C8B4D = 0;
    D_801C8B4C = 0;
    iVar2 = ((int (*)(void))func_801465C0)();
    if (iVar2 != 0) {
        *(int *)(param_1 + 0x20) = iVar2;
        func_800233CC(&D_801C8B49[-1], 0x28);
        func_8001CD9C(iVar2, &D_801C8B49[-1]);
        *(unsigned short *)(iVar2 + 0x1A) = 0x1400;
        *(unsigned int *)(iVar2 + 4) = *(unsigned int *)(iVar2 + 4) | 0x50000000;
        iVar3 = *(int *)(param_1 + 0x30);
        *(unsigned short *)(param_1 + 0x28) = *(unsigned short *)(iVar3 + 0x36);
        *(unsigned short *)(param_1 + 0x12) = *(unsigned short *)(iVar3 + 6);
        *(short *)(param_1 + 0x16) = *(unsigned short *)(iVar3 + 0xA) - 0x28;
        *(unsigned short *)(param_1 + 0x1A) = *(unsigned short *)(iVar3 + 0xE);
        *(unsigned short *)(param_1 + 2) = *(unsigned short *)(param_1 + 2) + 1;
    }
}
