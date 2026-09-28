/* Overlay range [8012DE2C,8012DEB8) from MAIN.CD member 0012.
 * SHA256(span)=e58196d7b8fa9a6e57e5524d4a887069f1cfd018a98b9bae032b8d0c49976431.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012DE2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];

s32 func_8012DE2C(s32 a0) {

    extern u8 D_801202A0[];
    extern u8 * D_801840D4;
    extern u8 * D_801840D0;

    u8 *base;
    u8 *end;
    u8 *p;

    base = D_801202A0;
    end = base + 0x6480;
    D_801840D4 = base;
    D_801840D0 = ((u8 *)a0);

    while (D_801840D4 != end) {
        p = D_801840D4;
        if (*(u16 *)p != 0 && p != ((u8 *)a0)) {
            D_801840D4 = p + 0x10C;
            return p;
        }
        D_801840D4 += 0x10C;
    }
    D_801840D4 = 0;
    return 0;
}
