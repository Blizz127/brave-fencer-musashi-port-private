/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B12C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern s32 func_8014B154(s32 *a0);

void func_8014B12C(void) {
    func_8014B154(&D_80126B58);
}
