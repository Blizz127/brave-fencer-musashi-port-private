/* Main-exec range [8003A0E4,8003A234) from the SLUS executable.
 * SHA256(span)=bc583279b050683e7d37424fa3cf1cee40ae15539e133d41bda01d2c1bdde595.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003A0E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u16 D_8006AB30[];
extern u16 D_8006ABD8[];
extern u8 D_800C6DD0[];

void func_8003A0E4(void *arg0, s16 arg1) {
    u8 *src;
    u8 *t2;
    u8 *t1;
    u8 *a2;
    u8 *a1;
    s32 i;
    s32 pan;
    u32 vol;
    u32 tmp;
    u32 prod;

    t2 = (u8 *)arg0 + (arg1 * 26 + 26);
    t1 = t2 + 9;
    src = *(u8 **)arg0;
    *(u32 *)arg0 = (u32)src + 1;
    *(s16 *)(t2 + 2) = src[0] & 0x7F;
    for (i = 0; i < 16; i++) {
        if (*t1++ != 0) {
            a2 = D_800C6DD0 + i * 0x60;
            vol = *(s16 *)(a2 + 4) << 8;
            pan = *(s16 *)(t2 + 2);
            if (pan >= 65) {
                vol += (u32)((pan - 64) * a2[0x59] * 4);
            } else if (pan < 64) {
                vol -= (u32)((64 - pan) * a2[0x58] * 4);
            }
            tmp = *(s32 *)(a2 + 0x54) - 0x3C00;
            vol -= tmp;
            a1 = a2 + 0x10;
            if (vol >= 0x5301) {
                *(s16 *)(a2 + 0x24) = 0x3FFF;
            } else {
                prod = D_8006AB30[vol >> 8];
                prod *= D_8006ABD8[(vol & 0xFE) / 2];
                *(s16 *)(a2 + 0x24) = prod >> 15;
            }
            *(u32 *)(a1 + 4) |= 0x10;
            a2[0x5D] = 1;
        }
    }
}
