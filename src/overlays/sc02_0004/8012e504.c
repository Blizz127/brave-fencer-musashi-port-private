/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E504 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801202A0[];

s32 func_8012E504(s32 a0, s32 a1) {
    s32 p;
    s32 end;
    p = (s32)D_801202A0;
    end = (s32)D_801202A0 + 0x6480;
    for (; p != end; p += 0x10C) {
        if (p != a0) {
            if (*(u16*)p == a1) {
                return p;
            }
        }
    }
    return 0;
}
