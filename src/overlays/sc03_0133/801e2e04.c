/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2E04 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E2E04(s32 a0) {
    extern s32 D_801E31FC[];
    extern s32 D_801E37C0;
    extern s32 D_801E3210[];
    extern s32 D_801E322C[];

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        s32 v0 = func_80184428();
        *(s32 *)(a0 + 0xE4) = D_801E31FC[v0];
    } else if (v1 < 0x384) {
        if ((u32)(v1 - 0x136) < 0x122) {
            *(s32 *)(a0 + 0xE4) = (s32)&D_801E37C0;
        } else {
            s32 v0 = func_801844F8();
            *(s32 *)(a0 + 0xE4) = D_801E3210[v0];
        }
    } else {
        s32 v0 = func_8018456C();
        *(s32 *)(a0 + 0xE4) = D_801E322C[v0];
        func_801845C8();
    }
}
