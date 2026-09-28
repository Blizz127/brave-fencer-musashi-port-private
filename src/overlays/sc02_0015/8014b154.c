/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B154 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8014B154(s32 *a0) {
    return *(s32*)((s32)a0 + 0x44) & 0x80;
}
