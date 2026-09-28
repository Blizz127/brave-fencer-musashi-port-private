/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D1D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { int a[8]; } MTX_L1;
typedef struct { short vx, vy, vz, pad; } SVEC_L1;
extern void func_801465C0(void);
extern void func_800233CC(void*, unsigned short);
extern void func_8001CD9C(int, void*);
extern void func_80147324(int a);
extern int  func_8005C49C(void);
extern void func_80049A1C(void *a, void *b);
extern void func_80048FBC(void *a, void *b, void *c);

void func_8016D1D8(int param_1) {

    extern u8 D_80195A38[];
    extern u8 D_80195A78[];
    int iVar5;
    int iVar2;
    u16 uVar1;
    unsigned int uVar3;
    short sVar4;
    SVEC_L1 sv;
    MTX_L1 mtx;

    iVar5 = *(int *)(param_1 + 0x34);
    if (*(int *)(param_1 + 0x2c) == 0) {
        D_80195A38[1] = 0xE0;
        D_80195A38[2] = 0xE0;
        D_80195A38[0] = 0xE0;
        D_80195A38[6] = 0;
        D_80195A38[5] = 0;
        D_80195A38[4] = 0;
        iVar5 = ((int (*)(void))func_801465C0)();
        if (iVar5 != 0) {
            int pp;
            *(int *)(param_1 + 0x20) = iVar5;
            ((void (*)(void *, int))func_800233CC)(D_80195A38, 0x28);
            ((void (*)(void *, void *))func_8001CD9C)((void *)iVar5, D_80195A38);
            *(short *)(iVar5 + 0x1a) = 0x1400;
            *(u32 *)(iVar5 + 4) |= 0x50000000;
            pp = *(int *)(param_1 + 0x30);
            *(u16 *)(param_1 + 0x28) = *(u16 *)(pp + 0x36);
            *(u16 *)(param_1 + 0x12) = *(u16 *)(pp + 6);
            *(short *)(param_1 + 0x16) = *(u16 *)(pp + 0xa) - 0x28;
            uVar1 = *(u16 *)(pp + 0xe);
            *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
            *(u16 *)(param_1 + 0x1a) = uVar1;
        }
        *(int *)(param_1 + 0x1c) = 8;
        func_80147324(0x647);
    } else {
        D_80195A78[1] = 0xE0;
        D_80195A78[2] = 0x20;
        D_80195A78[0] = 0x20;
        D_80195A78[5] = 0;
        D_80195A78[6] = 0;
        D_80195A78[4] = 0;
        iVar2 = ((int (*)(void))func_801465C0)();
        if (iVar2 != 0) {
            *(int *)(param_1 + 0x20) = iVar2;
            ((void (*)(void *, int))func_800233CC)(D_80195A78, 0x18);
            ((void (*)(void *, void *))func_8001CD9C)((void *)iVar2, D_80195A78);
            *(u32 *)(iVar2 + 4) |= 0x50000000;
            *(u16 *)(param_1 + 6) = *(u16 *)(iVar5 + 6);
            *(u16 *)(param_1 + 0xa) = *(u16 *)(iVar5 + 0xa);
            *(u16 *)(param_1 + 0xe) = *(u16 *)(iVar5 + 0xe);
            uVar3 = func_8005C49C();
            sv.vx = ((uVar3 & 0x7F) * 8) - 0x80;
            sv.vy = (uVar3 & 0x7F00) >> 3;
            sv.vz = 0;
            func_80049A1C(&sv, &mtx);
            sv.vy = 0;
            sv.vx = 0;
            sv.vz = 0x240;
            func_80048FBC(&mtx, &sv, &sv);
            *(int *)(param_1 + 0x10) = (int)sv.vx << 0xc;
            *(int *)(param_1 + 0x14) = (int)sv.vy << 0xc;
            sVar4 = (uVar3 & 0x3F0) + 0x200;
            *(int *)(param_1 + 0x18) = (int)sv.vz << 0xc;
            *(short *)(iVar2 + 0x1a) = sVar4;
            *(short *)(iVar2 + 0x18) = sVar4;
            *(int *)(param_1 + 0x1c) = 0x10;
            *(short *)(param_1 + 2) = 2;
        }
    }
}
