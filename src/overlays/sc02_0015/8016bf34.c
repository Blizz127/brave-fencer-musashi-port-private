/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BF34 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8016BF34(void *a0) {
    *(s16 *)((s32)a0 + 0x12) = *(u16 *)((s32)a0 + 0x6);
    *(s16 *)((s32)a0 + 0x16) = *(u16 *)((s32)a0 + 0xA);
    *(s16 *)((s32)a0 + 0x1A) = *(u16 *)((s32)a0 + 0xE);
}
