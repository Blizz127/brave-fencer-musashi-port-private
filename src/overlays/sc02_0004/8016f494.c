/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F494 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80175414(s32 _arg0);
extern s32 func_8016F4C4(s32);

s32 func_8016F494(s32 a0) {
    func_80175414(a0);
    return func_8016F4C4(a0);
}
