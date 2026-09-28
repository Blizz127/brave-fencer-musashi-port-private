/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFC60 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014CB1C(void);

s32 func_801EFC60(void) {
    return (u32)func_8014CB1C() != 0;
}
