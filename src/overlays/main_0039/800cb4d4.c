/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4D4 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CB4D4(s32 a0) {
    extern u8 D_801202A0[];
    extern u8 D_80126720[];
    extern void func_80015978(s32 a0, s32 *a1);
    extern s32 func_8012E778(s32 a0, s32 a1);
    extern s32 func_8014C308(s32 a0, s32 a1, s32 a2, s32 a3);
    extern s32 func_80013328(s32 *a0, s32 *a1);

    u8 *p;
    u8 *q;
    s32 buf[2];
    s32 best;
    u8 *bestp;
    s16 r;

    bestp = 0;
    best = 0x7FFFFFFF;
    p = D_801202A0;
    while (p < D_801202A0 + 0x6480) {
        if (*(u16 *)(p + 0) != 0x282) {
            q = p + 4;
            func_80015978((s32)q, buf);
            if (func_8012E778((s32)p, 0x8C00B4) == 1) {
                if (func_8014C308(a0, (s32)p, 0x2B, 0x40) != 0) {
                    r = func_80013328((s32 *)(a0 + 4), (s32 *)q);
                    if (r < best) {
                        best = r;
                        bestp = p;
                    }
                }
            }
        }
        p += 0x10C;
    }
    return (s32)bestp;
}
