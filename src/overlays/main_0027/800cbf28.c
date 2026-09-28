/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBF28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_800CC004();
extern u32 D_800CC250;
extern u32 D_800CC254;
extern s32 func_80146578(void);
extern void func_8001CD04(s32, s32);
extern void func_800233CC(s32, s32);
extern void func_800CC024();

void func_800CBF28(s32 p1)
{
    s32 v0;
    s32 r;
    register s32 base __asm__("$17");   

    v0 = ((s32 (*)(void))func_80146578)();
    base = (s32)&D_800CC250;
    __asm__("" : "=r"(r) : "0"(v0));
    *(s32 *)(p1 + 0x20) = v0;
    if (v0 != 0) {
        func_8001CD04(v0, base);
        if (*(s32 *)(p1 + 0x50) == 0) {
            func_800233CC(base, 0x20);
            D_800CC254 = 0;
            *(u32 *)base = 0x202000;
        }
        *(s16 *)(p1 + 0x60) = 0;
        *(u32 *)(r + 4) |= 0x50000000;
        func_800CC024(p1);
        func_80146CA0((void *)p1);
    } else {
        func_800CC004(p1);
    }
}
