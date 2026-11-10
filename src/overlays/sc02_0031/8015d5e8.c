/* SC02 resident retail span [8015D5E8,8015D738). Offset 0x35490 at base 80128158.
 * SHA256(span)=4a55b22d4c00758b68562d47d536bb329cea5433d330cc7a83f619e205b4216d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180C60->D_80187550.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015D5E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern void func_80154A74(int, int);
extern s32 func_80161208();
extern void func_80154150(int, int);
extern void func_80146CA0(void *a0);
extern void func_80149374(int, int);
extern unsigned char D_80187550[];

void func_8015D5E8(int param_1)
{
    int iVar1;
    int iVar2;

    if (((int (*)(int))func_80161B18)(param_1) != 0)
        return;
    if (((int (*)(int))func_80161B84)(param_1) != 0)
        return;
    if ((*(unsigned short *)(param_1 + 0xb8) & 0x4000) != 0)
        func_80154A74(param_1, 0x17);
    if (((int (*)(int))func_80161208)(param_1) != 0)
        return;
    if (*(unsigned short *)(param_1 + 0xb8) == 0x8000) {
        *(int *)(param_1 + 0x234) = *(int *)(param_1 + 0x234) + -3;
        func_80154150(param_1, 0x1a);
        ((void (*)(int))func_80146CA0)(param_1);
    } else {
        iVar1 = *(int *)(param_1 + 0x178);
        if (iVar1 != 0) {
            iVar2 = *(int *)(param_1 + 0x234);
            *(int *)(param_1 + 0x234) = iVar2 + 1;
            *(short *)(iVar1 + 6) =
                (short)((signed char)D_80187550[iVar2] +
                        *(unsigned short *)(*(int *)(iVar1 + 0x78) + 0xc));
            iVar2 = *(int *)(param_1 + 0x234);
            *(int *)(param_1 + 0x234) = iVar2 + 1;
            *(short *)(iVar1 + 10) =
                (short)((signed char)D_80187550[iVar2] +
                        *(unsigned short *)(*(int *)(iVar1 + 0x78) + 0xe));
            iVar2 = *(int *)(param_1 + 0x234);
            *(int *)(param_1 + 0x234) = iVar2 + 1;
            *(short *)(iVar1 + 0xe) =
                (short)((signed char)D_80187550[iVar2] +
                        *(unsigned short *)(*(int *)(iVar1 + 0x78) + 0x10));
            func_80149374(param_1, iVar1 + 4);
        }
    }
}
