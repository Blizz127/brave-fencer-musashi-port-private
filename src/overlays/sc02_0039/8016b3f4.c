/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016B3F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8016B448(s32, s32);
extern s32 func_8016BA48(s32 a0);

void func_8016B3F4(s32 a0) {
    func_8016B448(a0, 1);
    func_8016BA48(a0);
}
