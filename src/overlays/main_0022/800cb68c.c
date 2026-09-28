/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB68C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define RotMatrixY func_8004A0DC
#define rand func_8005C49C
extern void func_800233CC(void *, unsigned short);
typedef struct { s32 w[8]; } Blk20_800CB68C;
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_801465C0(void);

void func_800CB68C(s32 param_1)
{

    extern u16 D_80126B5E;
    extern u16 D_80126B62;
    extern u16 D_80126B66;
    extern void func_800CBAA4(s32);
    extern void RotMatrixY(s32 a0, void *a1);
    extern u8 D_800CBDB0;
    extern u8 D_800CBDB1;
    extern u8 D_800CBDB2;
    extern u8 D_800CBDB4;
    extern u8 D_800CBDB5;
    extern u8 D_800CBDB6;

    s32 iVar8;
    short sVar1;

    iVar8 = *(s32 *)((u8 *)((void *)param_1) + 0x34);
    if ((*(u32 *)((u8 *)((void *)param_1) + 0x2c) & 0x8000) == 0) {
        register s32 iNew __asm__("$17");
        s32 base;
        iNew = ((s32(*)())func_801465C0)();
        if (iNew == 0) {
            return;
        }
        base = (s32)&D_800CBDB0;
        D_800CBDB2 = 0xc0;
        *(u8 *)base = 0xc0;
        D_800CBDB1 = 0;
        D_800CBDB6 = 0;
        D_800CBDB5 = 0;
        D_800CBDB4 = 0;
        ((void(*)(void *, unsigned short))func_800233CC)((void *)base, 0x40);
        func_8001CD50(iNew, base);
        *(s32 *)(iNew + 0x34) = (s32)((u8 *)((void *)param_1) + 0x38);
        *(s16 *)(iNew + 0x1a) = 0;
        *(s16 *)(iNew + 0x18) = 0;
        *(u32 *)(iNew + 4) = *(u32 *)(iNew + 4) | 0x50000000;
        ((void (*)(void *))func_800CBAA4)(((void *)param_1));
        {
            register s32 t10 __asm__("$3");
            t10 = 0x10;
            *(s32 *)((u8 *)((void *)param_1) + 0x20) = iNew;
            *(s32 *)((u8 *)((void *)param_1) + 0x1c) = t10;
        }
        sVar1 = *(u16 *)((u8 *)((void *)param_1) + 2) + 1;
    } else {
        short asStack_60[20];
        Blk20_800CB68C localMatrix;
        s32 uVar2;
        extern s32 D_800AE620;
        extern s32 rand(void);
        extern void ApplyMatrixSV(void *a0, void *a1, void *a2);

        asStack_60[0] = 0;
        asStack_60[1] = 0;
        asStack_60[2] = 0x20;
        localMatrix = (*(Blk20_800CB68C*)&D_800AE620);
        uVar2 = ((s32(*)())rand)();
        RotMatrixY((uVar2 & 0x7f00) >> 3, &localMatrix);
        ApplyMatrixSV(&localMatrix, asStack_60, asStack_60);
        *(s16 *)((u8 *)((void *)param_1) + 6) = D_80126B5E + asStack_60[0];
        *(s16 *)((u8 *)((void *)param_1) + 0xa) = D_80126B62 - ((u16)uVar2 & 0x3f);
        *(s16 *)((u8 *)((void *)param_1) + 0xe) = D_80126B66 + asStack_60[2];
        *(Blk20_800CB68C *)((u8 *)((void *)param_1) + 0x38) = *(Blk20_800CB68C *)((u8 *)iVar8 + 0x38);
        *(s32 *)((u8 *)((void *)param_1) + 0x2c) = 0x1000;
        *(s32 *)((u8 *)((void *)param_1) + 0x30) = 0xff;
        *(s32 *)((u8 *)((void *)param_1) + 0x1c) = 0x10;
        __asm__ __volatile__("" ::: "memory");
        sVar1 = 4;
    }
    *(s16 *)((u8 *)((void *)param_1) + 2) = sVar1;
}
