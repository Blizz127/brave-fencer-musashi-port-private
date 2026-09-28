/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E544 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];

s32 func_8012E544(s32 a0) {
    s32 a1;
    s32 v1;
    v1 = (s32)D_801202A0;
    a1 = v1 + 0x6480;
    if (v1 != a1) {
        do {
            if (*(u16 *)v1 == a0) {
                return v1;
            }
            v1 += 0x10C;
        } while (v1 != a1);
    }
    return 0;
}
