/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801724EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80013450(s32);

s32 func_801724EC(s32 a0) {
    return func_80013450(a0 + 4) < 0x10;
}
