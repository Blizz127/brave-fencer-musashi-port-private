/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171C64 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146D90(s32 a0);
extern void func_80146D90(int);
extern void func_80146D90(s32);
extern void func_80171EC8(s32 a0);

s32 func_80171C64(s32 param_1, s32 param_2)
{
    register s32 s __asm__("$17") = param_1;
    register s32 d __asm__("$16") = param_2;
    u8 v;
    ((void (*)(void))func_80171EC8)();
    v = *(u8 *)(s + 0x20C);
    *(u8 *)(s + 0x20C) = v + 1;
    if ((v & 0xFF) == (d & 0xFF)) {
        func_80146D90(s);
        return 1;
    }
    return 0;
}
