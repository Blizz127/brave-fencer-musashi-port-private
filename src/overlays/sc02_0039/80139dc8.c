/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139DC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_8012811A;

void func_80139DC8(void) {
    s32 i = 0x287;
    s16 *p = &D_8012811A;
    do {
        *p = 0;
        i--;
        p = (s16 *)((s32)p - 2);
    } while (i >= 0);
}
