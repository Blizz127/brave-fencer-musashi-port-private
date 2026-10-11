/* sc03_0001: func_8016BEA0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
typedef s32 M2C_UNK;
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern M2C_UNK D_801EDA84;
extern M2C_UNK D_801EDA88;
void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8016BEA0(s32 param_1)
{
    extern void func_8016BF50(void);
    int iVar2;
    unsigned short uVar1;
    iVar2 = *(int *)(((int)param_1) + 0x20);
    func_8016BF50();
    uVar1 = *(unsigned short *)(((int)param_1) + 0x10) - 0x18;
    *(unsigned short *)(((int)param_1) + 0x10) = uVar1;
    *(unsigned short *)(iVar2 + 0x1a) = *(unsigned short *)(iVar2 + 0x1a) + uVar1;
    *(unsigned short *)(iVar2 + 0x12) = (*(unsigned short *)(iVar2 + 0x12) + 0x22) & 0xfff;
    ((void (*)(int, void *, void *, int))func_8016BFA8)(((int)param_1), &(*(int *)&D_801EDA84), &(*(int *)&D_801EDA88), iVar2 + 0x18);
    if (*(short *)(iVar2 + 0x1a) < 0) {
        ((void (*)(int))func_80146C3C)(((int)param_1));
    }
}
