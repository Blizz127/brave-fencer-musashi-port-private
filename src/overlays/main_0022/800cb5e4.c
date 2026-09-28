/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB5E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 a0);
extern void func_80146C3C();

void func_800CB5E4(void *a0) {
    s32 v0;
    s32 v1;

    v0 = *(s32 *)((s32)a0 + 0x1C) << 9;
    v1 = *(s32 *)((s32)a0 + 0x20);
    *(u16 *)(v1 + 0x1A) = v0;
    *(u16 *)(v1 + 0x18) = v0;
    if (func_80146E98((s32)a0) != 0) {
        func_80146C3C(a0);
    }
}
