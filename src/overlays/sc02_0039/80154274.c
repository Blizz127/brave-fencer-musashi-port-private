/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80154274 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801542A4();

void func_80154274(s32 *a0, s32 a1) {
    if (*(s32 *)((s32)a0 + 0xB4) != a1) {
        func_801542A4();
    }
}
