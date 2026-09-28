/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E57C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];

s32 func_8012E57C(s32 a0, s32 a1) {
    u8 *p = D_801202A0;
    u8 *end = D_801202A0 + 0x6480;
    if (p != end) {
        s32 key = (s16)a1;
        do {
            if (*(u16 *)(p + 0x0) == a0) {
                if (*(s16 *)(p + 0x70) == key) {
                    return (s32)p;
                }
            }
            p += 0x10C;
        } while (p != end);
    }
    return 0;
}
