/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012DE2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];

s32 func_8012DE2C(s32 a0) {
    extern u8 * D_801BD5BC;
    extern u8 * D_801BD5B8;

    u8 *base;
    u8 *end;
    u8 *p;

    base = D_801202A0;
    end = base + 0x6480;
    D_801BD5BC = base;
    D_801BD5B8 = ((u8 *)a0);

    while (D_801BD5BC != end) {
        p = D_801BD5BC;
        if (*(u16 *)p != 0 && p != ((u8 *)a0)) {
            D_801BD5BC = p + 0x10C;
            return p;
        }
        D_801BD5BC += 0x10C;
    }
    D_801BD5BC = 0;
    return 0;
}
