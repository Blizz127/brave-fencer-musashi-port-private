/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014A638 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8014A638(s32 arg0) {
    s16 v;
    if (*(s32 *)((s32)arg0 + 0x44) & 0x10) {
        v = *(u16 *)((s32)arg0 + 0x188) - 4;
        *(s16 *)((s32)arg0 + 0x188) = v;
        if (v < 0) {
            *(s16 *)((s32)arg0 + 0x188) = 0;
        }
    }
}
