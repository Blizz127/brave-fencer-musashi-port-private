/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCCA0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CCE68(void);
extern u8 D_800CEBEC;
extern void func_8014659C(void);
extern void func_8001C810(s32, void *);
extern void func_800CCF58();
extern void func_800CCE88(s32);
extern s32 func_80146CA0(void *);
extern void func_800CCE68();

void func_800CCCA0(s32 param_1) {
    register s32 p1 __asm__("$17");  
    register s32 iVar1 __asm__("$16");  

    p1 = param_1;
    iVar1 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(p1 + 0x20) = iVar1;
    if (iVar1 != 0) {
        func_8001C810(iVar1, &D_800CEBEC);
        *(u32 *)(iVar1 + 4) |= 0x40010000;
        func_800CCF58(iVar1, 0);
        func_800CCE88(p1);
        *(s16 *)(p1 + 0x60) = 0;
        ((s32 (*)(void *))func_80146CA0)(p1);
    } else {
        ((void (*)(s32))func_800CCE68)(p1);
    }
}
