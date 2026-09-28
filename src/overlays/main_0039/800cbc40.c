/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBC40 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CBC40(void *arg0, s32 arg1) {
    void *v1 = *(void **)((s32)arg0 + 0x20);
    u16 v0 = *(u16 *)((s32)v1 + 0x1A) - arg1;
    *(u16 *)((s32)v1 + 0x1A) = v0;
    *(u16 *)((s32)v1 + 0x18) = v0;
}
