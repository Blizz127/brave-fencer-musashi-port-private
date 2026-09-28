/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80154B4C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154B7C(u8 *a0, s32 a1);

void func_80154B4C(u8 *a0, s32 a1) {
    if (*(s32 *)(a0 + 0xD0) != a1) {
        func_80154B7C(a0, a1);
    }
}
