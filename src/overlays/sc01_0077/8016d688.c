/* sc01_0077: func_8016D688 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void *, unsigned short);
extern u8 D_801D9C20[];
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern void func_8001CD9C(int, void*);
extern unsigned char D_801D9C20[];
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern void func_8001CD9C(int, void *);

void func_8016D688(int param_1)
{
    int iVar2;
    int iVar3;
    D_801D9C20[1] = 0xe0;
    D_801D9C20[2] = 0xe0;
    D_801D9C20[0] = 0xe0;
    D_801D9C20[6] = 0;
    D_801D9C20[5] = 0;
    D_801D9C20[4] = 0;
    iVar2 = ((int (*)(void))func_801465C0)();
    if (iVar2 != 0) {
        *(int *)(param_1 + 0x20) = iVar2;
        ((void (*)(void *, int))func_800233CC)(D_801D9C20, 0x28);
        func_8001CD9C(iVar2, D_801D9C20);
        *(unsigned short *)(iVar2 + 0x1a) = 0x1400;
        *(unsigned int *)(iVar2 + 4) = *(unsigned int *)(iVar2 + 4) | 0x50000000;
        iVar3 = *(int *)(param_1 + 0x30);
        *(unsigned short *)(param_1 + 0x28) = *(unsigned short *)(iVar3 + 0x36);
        *(unsigned short *)(param_1 + 0x12) = *(unsigned short *)(iVar3 + 6);
        *(short *)(param_1 + 0x16) = *(unsigned short *)(iVar3 + 0xa) - 0x28;
        *(unsigned short *)(param_1 + 0x1a) = *(unsigned short *)(iVar3 + 0xe);
        *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
    }
    return;
}
