/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012C31C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80120194[];

s32 func_8012C31C(void) {
    s32 a0;
    s32 v1;
    a0 = (s32)D_80120194;
    v1 = a0 + 0x6480;
    if (v1 != a0) {
        do {
            if (*(u16 *)v1 == 0) {
                return v1;
            }
            v1 -= 0x10C;
        } while (v1 != a0);
    }
    return 0;
}
