/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017267C - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8017267C(s32 *a0) {
    return *(s32*)((s32)a0 + 0x1F4) & 0x8;
}
