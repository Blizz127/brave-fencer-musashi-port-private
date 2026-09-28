/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBAF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CBBF8();
extern s32 func_80146E98(s32 a0);

void func_800CBAF4(void *a0)
{
    s32 s0;
    extern s32 func_80146E98(s32 a0);
    extern void func_800CBBF8();

    s0 = *(s32 *)((s32)a0 + 0x10);
    if (func_80146E98((s32)a0) != 0) {
        func_800CBBF8();
    } else if (s0 != 0) {
        *(u16 *)((s32)s0 + 0x1A) = *(u16 *)((s32)s0 + 0x1A) - 0x400;
    }
}
