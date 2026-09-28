/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80154B98 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154BC8(void *a0, s32 a1, s32 a2);

void func_80154B98(void *a0, s32 a1, s32 a2) {
    if (*(s32 *)((s32)a0 + 0xD0) != a1) {
        func_80154BC8(a0, a1, a2);
    }
}
