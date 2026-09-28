/* Main-exec range [8001AAD0,8001ABB4) from the SLUS executable.
 * SHA256(span)=48c04aae7f0758c43b24083f99e5623d374bb1a95a2212460c8f7b3583f1bd70.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001AAD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 D_800BA1B4;
extern u8 D_80062C38;
extern s32 func_8001ABBC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_8001AAD0(s32 arg0, s32 arg1) {
    s32 idx;

    switch (arg0) {
    case 0:
        idx = 9;
        break;
    case 1:
        idx = 10;
        break;
    case 2:
        idx = 11;
        break;
    case 3:
        idx = 12;
        break;
    case 4:
        idx = 13;
        break;
    case 5:
        idx = 14;
        break;
    case 6:
        idx = 15;
        break;
    case 7:
        idx = 16;
        break;
    case 8:
        idx = 17;
        break;
    case 9:
        idx = 18;
        break;
    case 10:
        idx = 19;
        break;
    case 11:
        idx = 20;
        break;
    default:
        idx = 0;
        break;
    }

    if (D_800BA1B4 == 5) {
        D_800BA1B4 = 0;
    }

    func_8001ABBC(3, arg1, (s32)(&D_80062C38 + idx * 0x30), 0, 0);
}
