/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B00C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014B034(s32 arg0);

void func_8014B00C(s32 arg0) {
    func_8014B034(arg0 * 60);
}
