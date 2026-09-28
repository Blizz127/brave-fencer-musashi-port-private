/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD010 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_800CD1A8(void);
extern void func_80146578(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800CD204();
extern u8 D_800CD66C;

void func_800CD010(s32 param_1)
{
    register s32 p1 __asm__("$17");   
    register s32 iVar1 __asm__("$16");   

    p1 = param_1;
    iVar1 = ((s32 (*)(void))func_80146578)();
    *(s32 *)(p1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        func_8001CC3C(iVar1, (s32)&D_800CD66C, 0x220, 0x168);
        *(u8 *)(iVar1 + 0x27) = 0x24;
        *(u8 *)(iVar1 + 0x24) = 0xFF;
        *(u8 *)(iVar1 + 0x25) = 0x40;
        *(u8 *)(iVar1 + 0x26) = 0x40;
        *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        *(s16 *)(iVar1 + 0x10) = *(s32 *)(p1 + 0x50) << 10;
        *(s16 *)(p1 + 0x60) = *(s32 *)(p1 + 0x50) << 10;
        ((void (*)(s32))func_800CD204)(p1);
        ((void (*)(void *))func_80146CA0)((void *)p1);
    } else {
        ((void (*)(s32))func_800CD1A8)(p1);
    }
}
