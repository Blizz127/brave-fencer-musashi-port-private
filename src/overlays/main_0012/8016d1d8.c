/* Overlay range [8016D1D8,8016D428) from MAIN.CD member 0012.
 * SHA256(span)=247ab08d966bd22dec4c47555f7d2a0bd9aff48da71926a3be5e0fccbf39e2b4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D1D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define ApplyMatrixSV func_80048FBC
#define RotMatrixYXZ func_80049A1C
#define rand func_8005C49C

extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_8001CD9C(int, void *);
extern void func_80147324(int);
extern int rand(void);
extern void RotMatrixYXZ(void *, void *);
extern void ApplyMatrixSV();

extern unsigned char D_80184851[];
extern unsigned char D_80184852;
extern unsigned char D_80184854;
extern unsigned char D_80184855;
extern unsigned char D_80184856;
extern unsigned char D_80184891[];
extern unsigned char D_80184892;
extern unsigned char D_80184894;
extern unsigned char D_80184895;
extern unsigned char D_80184896;

void func_8016D1D8(int param_1)
{
    int iVar5;
    int iVar2;
    unsigned int uVar3;
    short sVar4;
    short sv[4];
    int mtx[8];

    iVar5 = *(int *)(param_1 + 0x34);
    if (*(int *)(param_1 + 0x2c) == 0) {
        int pp;
        D_80184851[0] = 0xE0;
        D_80184852 = 0xE0;
        D_80184851[-1] = 0xE0;
        D_80184856 = 0;
        D_80184855 = 0;
        D_80184854 = 0;
        iVar5 = ((int (*)(void))func_801465C0)();
        if (iVar5 != 0) {
            *(int *)(param_1 + 0x20) = iVar5;
            func_800233CC(&D_80184851[-1], 0x28);
            func_8001CD9C(iVar5, &D_80184851[-1]);
            *(short *)(iVar5 + 0x1a) = 0x1400;
            *(unsigned int *)(iVar5 + 4) = *(unsigned int *)(iVar5 + 4) | 0x50000000;
            pp = *(int *)(param_1 + 0x30);
            *(unsigned short *)(param_1 + 0x28) = *(unsigned short *)(pp + 0x36);
            *(unsigned short *)(param_1 + 0x12) = *(unsigned short *)(pp + 6);
            *(short *)(param_1 + 0x16) = *(unsigned short *)(pp + 0xa) - 0x28;
            *(unsigned short *)(param_1 + 0x1a) = *(unsigned short *)(pp + 0xe);
            *(unsigned short *)(param_1 + 2) = *(unsigned short *)(param_1 + 2) + 1;
        }
        *(int *)(param_1 + 0x1c) = 8;
        func_80147324(0x647);
    } else {
        D_80184891[0] = 0xE0;
        D_80184892 = 0x20;
        D_80184891[-1] = 0x20;
        D_80184895 = 0;
        D_80184896 = 0;
        D_80184894 = 0;
        iVar2 = ((int (*)(void))func_801465C0)();
        if (iVar2 != 0) {
            *(int *)(param_1 + 0x20) = iVar2;
            func_800233CC(&D_80184891[-1], 0x18);
            func_8001CD9C(iVar2, &D_80184891[-1]);
            *(unsigned int *)(iVar2 + 4) = *(unsigned int *)(iVar2 + 4) | 0x50000000;
            *(unsigned short *)(param_1 + 6) = *(unsigned short *)(iVar5 + 6);
            *(unsigned short *)(param_1 + 0xa) = *(unsigned short *)(iVar5 + 0xa);
            *(unsigned short *)(param_1 + 0xe) = *(unsigned short *)(iVar5 + 0xe);
            uVar3 = rand();
            sv[0] = ((uVar3 & 0x7F) * 8) - 0x80;
            sv[1] = (uVar3 & 0x7F00) >> 3;
            sv[2] = 0;
            RotMatrixYXZ(sv, mtx);
            sv[1] = 0;
            sv[0] = 0;
            sv[2] = 0x240;
            ((void (*)(void *, void *, void *))ApplyMatrixSV)(mtx, sv, sv);
            *(int *)(param_1 + 0x10) = sv[0] << 12;
            *(int *)(param_1 + 0x14) = sv[1] << 12;
            sVar4 = (uVar3 & 0x3F0) + 0x200;
            *(int *)(param_1 + 0x18) = sv[2] << 12;
            *(short *)(iVar2 + 0x1a) = sVar4;
            *(short *)(iVar2 + 0x18) = sVar4;
            *(int *)(param_1 + 0x1c) = 0x10;
            *(short *)(param_1 + 2) = 2;
        }
    }
}
