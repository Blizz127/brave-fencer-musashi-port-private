/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014CA14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *D_8012707C;
extern void func_80147364();
extern u16 func_8014CA70(s32 a0, s32 a1);

s32 func_8014CA14(s32 a0, s32 a1) {
    u16 x = func_8014CA70(a0, a1);
    if (x == 0) {
        return 1;
    }
    if (x != (s32)D_8012707C) {
        func_80147364(x, 0);
        return 0;
    }
    D_8012707C = 0;
    return 0;
}
