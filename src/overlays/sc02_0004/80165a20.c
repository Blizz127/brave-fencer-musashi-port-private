/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165A20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80165A50(s32);
extern void func_80165A78(s32);

s32 func_80165A20(s32 a0) {
    func_80165A78(a0);
    return func_80165A50(a0);
}
