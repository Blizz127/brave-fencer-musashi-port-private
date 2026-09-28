/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80147788 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80147788(void *a0, s32 a1) {
    void *v1 = *(void **)((s32)a0 + 0x20);
    *(s16 *)((s32)v1 + 0x10) = (*(u16 *)((s32)v1 + 0x10) + a1) & 0xFFF;
}
