/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDA14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8014C088(s32 a0, s32 a1);

void func_800CDA14(s32 a0) {
    s32 v1;

    v1 = func_8014C088(a0, 0x13);
    if (v1 != 0) {
        *(s16 *)(v1 + 0x60) = 1;
    }
}
