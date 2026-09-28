/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80149284 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80149284(s32 *a0, s32 a1) {
    return *(s32*)((s32)a0 + 0x1DC) & a1;
}
