/* SC02 resident retail span [8015D414,8015D480). Offset 0x352BC at base 80128158.
 * SHA256(span)=23b113bafb1df54d252951a1145177965e1ba202702c1b46c8e798bc005d075a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FD30->D_80186620.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015D414 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern unsigned char D_80186620[];
extern void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_8015D414(int param_1)
{
    *(unsigned char *)(param_1 + 0x1bd) = 8;
    *(unsigned char **)(param_1 + 0x38) = D_80186620;
    *(short *)(param_1 + 0x138) = 0;
    *(short *)(param_1 + 0x13a) = 0;
    *(short *)(param_1 + 0x13c) = 0;
    *(short *)(param_1 + 0x13e) = 0;
    *(short *)(param_1 + 0xA) = *(short *)(param_1 + 0xA) + 0x48;
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) = 0;
    ((void (*)(void))func_801553C0)();
    func_80154A74(param_1, 0x11);
}
