/* sc03_0001: func_8016C49C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern void func_801465C0(void);
extern s32 D_8011D030;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_80016714(void *a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void func_80049A1C(void *a0, void *a1);
extern void func_80048EAC(void *a0, void *a1);
extern void func_80146C3C(void);
extern void func_800D23D0(void *a0);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_801465C0(void);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void *, unsigned short);
extern void func_80016714(void *a0, s32 a1);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_801465C0(void);
extern void func_80146C3C(void);

s32 func_8016C49C(s32 param_1_arg) {
    extern s32 func_80047E98(void *, void *);
    extern void func_8001CD9C(s32, void *);
    extern void func_8016CF04(s32, s32);
    extern u8 D_801EDAA0[];
    extern u8 D_801EDB60;
    register u16 *param_1 __asm__("$17") = ((u16 *)param_1_arg);
    int iVar5;
    int iVar6;
    u16 sv[4];
    s32 mat[8];
    short sVar1;
    iVar5 = *(int *)(param_1 + 0x18);
    iVar6 = *(int *)(param_1 + 0x1a);
    param_1[0x14] = *(u16 *)(iVar5 + 0x36);
    if ((*(u32 *)(param_1 + 0x16) & 0x8000) == 0) {
        short iVar4 = 0;
        u16 *psVar3 = (u16 *)&D_8011D030;
        do {
            if (psVar3 != param_1 && *psVar3 == 0x30) {
                ((void(*)(void *))func_80146C3C)(psVar3);
            }
            iVar4 = iVar4 + 1;
            psVar3 = psVar3 + 0x2c;
        } while (iVar4 < 0x1e);
        D_801EDAA0[1] = 0xff;
        D_801EDAA0[2] = 0x10;
        D_801EDAA0[0] = 0x10;
        D_801EDAA0[6] = 0;
        D_801EDAA0[5] = 0;
        D_801EDAA0[4] = 0;
        ((void(*)(void *, s32))func_800233CC)(D_801EDAA0, 10);
        sv[0] = *(u16 *)(iVar5 + 6) - *(u16 *)(iVar6 + 6);
        {
            int t = *(u16 *)(iVar6 + 0xa) + 0x28;
            sv[1] = *(u16 *)(iVar5 + 0xa) - t;
        }
        sv[2] = *(u16 *)(iVar5 + 0xe) - *(u16 *)(iVar6 + 0xe);
        func_80047E98(sv, sv);
        param_1[3] = *(u16 *)(iVar5 + 6) + ((s16)sv[0] >> 9);
        param_1[5] = *(u16 *)(iVar5 + 0xa) + (((s16)sv[1] >> 9) - 0x28);
        param_1[7] = *(u16 *)(iVar5 + 0xe) + ((s16)sv[2] >> 9);
        ((void(*)(void *))func_800D23D0)(sv);
        sv[0] = 0;
        ((void(*)(void *, void *))func_80049A1C)(sv, param_1 + 0x1c);
        ((void(*)(void *, s32))func_80016714)(&D_801EDB60, 0x620);
        ((s32(*)(s32, void *, s32, s32, s32, s32, s32))func_80146A6C)(0x32, param_1, 0, 0, 0, 0, *(int *)(param_1 + 0x18));
        sVar1 = 5;
    } else {
        int iVar5b = ((s32(*)())func_801465C0)();
        u32 uVar2;
        if (iVar5b == 0) {
            return;
        }
        func_8001CD9C(iVar5b, D_801EDAA0);
        *(u32 *)(iVar5b + 4) |= 0x50000000;
        uVar2 = ((int(*)())func_8005C49C)();
        sv[0] = (uVar2 & 0x7f) * 8 - 0x80;
        sv[1] = ((uVar2 & 0x7f00) >> 4) - 0x400;
        sv[2] = 0;
        ((void(*)(void *, void *))func_80049A1C)(sv, mat);
        ((void(*)(void *, void *))func_80048EAC)(param_1 + 0x1c, mat);
        sv[1] = 0;
        sv[0] = 0;
        sv[2] = 0xb;
        ((void(*)(void *, void *, void *))func_80048FBC)(mat, sv, sv);
        param_1[9] = sv[0];
        param_1[0xb] = sv[1];
        param_1[0xd] = sv[2];
        *(int *)(param_1 + 0x10) = iVar5b;
        *(int *)(param_1 + 0xe) = 8;
        func_8016CF04((s32)param_1, 0);
        *(int *)(param_1 + 0x16) = 0;
        sVar1 = param_1[1] + 1;
    }
    param_1[1] = sVar1;
}
