/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCD2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CCF58();
extern void func_800CCE88(s32);
extern s32 func_80146CA0(void *);
extern s32 func_800CCF30(void *a0);

void func_800CCD2C(s32 param_1) {
    register s32 p1 __asm__("$17");
    register s32 s0 __asm__("$16");
    s16 v0;

    p1 = param_1;
    s0 = *(s32 *)(p1 + 0x20);
    if (func_800CCF30((void *)param_1) == 0) {
        v0 = *(u16 *)(s0 + 0x18) + 0x100;
        *(s16 *)(s0 + 0x18) = v0;
        if (v0 >= 0x1001) {
            v0 = 0x1000;
            *(s16 *)(s0 + 0x18) = v0;
            func_80146CA0((void *)p1);
        }
        func_800CCF58(s0, *(s16 *)(s0 + 0x18));
        func_800CCE88(p1);
    }
}
