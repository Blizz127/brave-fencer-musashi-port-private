/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D6AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800495EC(s32 a0, s32 a1, s32 a2);

u32 func_8017D6AC(s16 *param_1, s16 *param_2, s16 *param_3) {
    s16 ax, ay, bx, by, cx, cy;
    register s32 la __asm__("$8");
    register s32 lb __asm__("$7");
    register s32 lc __asm__("$3");
    u32 r;
    s32 pad[2];
    cx = param_3[0];
    bx = param_2[0];
    if (cx < bx) {
        return 0;
    }
    __asm__ __volatile__("" : : "r"(la), "r"(lb), "r"(lc));
    ax = param_1[0];
    if (ax < cx) {
        return 1;
    }
    do {
        cy = param_3[2];
        ay = param_1[1];
        if (cy > ay) {
            return 0;
        }
        by = param_2[1];
        if (by <= cy) {
            la = (u16)ax;
            lb = (u16)bx;
            lc = (u16)cx;
            __asm__ __volatile__("" : : "r"(ax), "r"(bx), "r"(cx));
            r = func_800495EC(la | ((u16)ay << 16), lb | ((u16)by << 16),
                              lc | ((u16)cy << 16));
            return ~r >> 31;
        }
        return 1;
    } while (0);
}
