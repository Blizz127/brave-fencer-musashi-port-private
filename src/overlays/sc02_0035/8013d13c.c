/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D13C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801BD6A4;
extern void func_8013D9B0();

s32 func_8013D13C(void) {
    func_8013D9B0();
    return D_801BD6A4;
}
