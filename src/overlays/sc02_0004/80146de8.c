/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146DE8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3) {
    *(s32*)((s32)a0 + 0x24) = a1;
    *(s32*)((s32)a0 + 0x28) = a2;
    *(s32*)((s32)a0 + 0x2C) = a3;
}
