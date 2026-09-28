/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F410 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8016F44C(s32 a0);
extern void func_8016F470(s32 a0);

s32 func_8016F410(s32 a0) {
    if (func_8016F44C(a0) == 0) {
        return 0;
    }
    func_8016F470(a0);
    return 1;
}
