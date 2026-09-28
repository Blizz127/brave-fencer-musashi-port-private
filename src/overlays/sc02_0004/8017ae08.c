/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017AE08 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 func_80174764(void);

s32 func_8017AE08(void) {
    return ((s32 (*)(void))func_80174764)() == 1;
}
