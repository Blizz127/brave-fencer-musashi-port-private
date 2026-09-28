/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801479BC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801479BC(s32 a0, s32 a1, s32 a2) {
    s32 v0 = *(s32*)(a0 + 0x28) + a1;
    *(s32*)(a0 + 0x28) = v0;
    if (a1 < 0) {
        if (!(-a2 < v0)) {
            *(s32*)(a0 + 0x28) = -a2;
            return;
        }
    }
    if (a1 > 0) {
        if (!(*(s32*)(a0 + 0x28) < a2)) {
            *(s32*)(a0 + 0x28) = a2;
        }
    }
}
