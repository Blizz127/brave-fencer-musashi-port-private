/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014168C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80115148[];
extern u8 D_80115149[];
extern u8 D_80115158[];

s16 func_8014168C(s16 a0) {
    s32 i = a0 * 2;
    return D_80115148[i] + D_80115149[i] * D_80115158[i];
}
