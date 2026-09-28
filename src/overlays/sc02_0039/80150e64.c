/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150E64 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80150EC4(s32 a, s32 b);
extern void func_80150EC4(s32 a0, s32 a1);

void func_80150E64(s32 a0) {
    func_80150EC4(a0, 0xD);
}
