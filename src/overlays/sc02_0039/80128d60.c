/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80128D60 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80018450(s32 a0, s32 a1);
extern void func_800183E0(s32 a0);

void func_80128D60(s32 a0, s32 *a1, s32 *a2) {
    a1[0] = (s32)a2;
    *(s16 *)((u8 *)a1 + 4) = 0;
    *(s16 *)((u8 *)a1 + 6) = a2[1] & 0x3F;
    if (a0 != 0) {
        func_80018450(a0, a2[0]);
    } else {
        func_800183E0(a2[0]);
    }
}
