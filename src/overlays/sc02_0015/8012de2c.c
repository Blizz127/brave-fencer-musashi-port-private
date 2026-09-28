/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012DE2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];

s32 func_8012DE2C(s32 a0) {
    extern u8 * D_8018F014;
    extern u8 * D_8018F010;

    u8 *base;
    u8 *end;
    u8 *p;

    base = D_801202A0;
    end = base + 0x6480;
    D_8018F014 = base;
    D_8018F010 = ((u8 *)a0);

    while (D_8018F014 != end) {
        p = D_8018F014;
        if (*(u16 *)p != 0 && p != ((u8 *)a0)) {
            D_8018F014 = p + 0x10C;
            return p;
        }
        D_8018F014 += 0x10C;
    }
    D_8018F014 = 0;
    return 0;
}
