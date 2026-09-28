/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80148FA0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80148FA0(s32 a0) {
    return (a0 + 0x600) & 0xFFF;
}
