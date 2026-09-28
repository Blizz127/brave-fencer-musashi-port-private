/* Main-exec range [8001BADC,8001BB60) from the SLUS executable.
 * SHA256(span)=b909afa18cff70984aa827361035edcf81b1d006e037152add1f2d9604b5cba9.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001BADC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_80074808;

s32 func_8001BADC(s32 arg0, s32 arg1) {
    register s32 level __asm__("$10");
    register s32 i __asm__("$8");
    register s32 mask __asm__("$11");
    register s32 off __asm__("$9");
    register s32 top __asm__("$12");
    register s32 colbase __asm__("$13");
    register s32 c __asm__("$6");
    register s32 p __asm__("$5");
    s32 color;
    s32 *addr;

    level = arg0;
    i = 0;
    mask = -(arg1 != 0);
    colbase = 0x62000000;
    top = 29;
    off = 0;
    while (i < 15) {
        c = 0;
        if (i < level) {
            c = mask & 8;
        }
        color = (c << 16) | ((c << 8) | colbase) | c;
        p = D_80074808;
        addr = (s32 *)(p + off);
        addr[2] = color;
        addr = (s32 *)(p + (top - i) * 20);
        addr[2] = color;
        i++;
        off += 20;
    }
    return level >= 44;
}
