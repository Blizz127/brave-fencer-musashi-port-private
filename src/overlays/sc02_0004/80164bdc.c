/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164BDC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146578(void);
extern void func_80146CA0(void *a0);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);
extern void func_80164DD0(s32 a0);
extern void func_80164DB0(void);
extern u8 D_801951C0;
extern u8 D_801951C1;
extern u8 D_801951C2;
extern u8 D_801951C3;
extern u8 D_801951C4;
extern u8 D_801951C5;
extern u8 D_801951C6;
extern u8 D_801951C7;

void func_80164BDC(s32 param_1)
{
    register s32 p1   __asm__("$17");   
    register s32 iVar1 __asm__("$16");   
    register s32 base __asm__("$18");   

    p1 = param_1;
    iVar1 = ((s32 (*)(void))func_80146578)();
    base = (s32)&D_801951C0;
    *(s32 *)(p1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        func_8001CD50(iVar1, base);
        ((void (*)(s32, s32))func_800233CC)(base, 0x60);
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        D_801951C1 = 0xf0;
        *(u8 *)base = 0xf0;
        D_801951C2 = 0xc0;
        D_801951C6 = 0;
        D_801951C5 = 0;
        D_801951C4 = 0;
        D_801951C7 = 0;
        D_801951C3 = 0;
        *(s16 *)(iVar1 + 0x1e) = 0xccc;
        *(s16 *)(iVar1 + 0x10) = 0x400;
        *(s16 *)(p1 + 0x60) = 0x700;
        *(s16 *)(p1 + 0x62) = -0x60;
        func_80164DD0(p1);
        ((void (*)(s32))func_80146CA0)(p1);
    } else {
        ((void (*)(s32))func_80164DB0)(p1);
    }
}
