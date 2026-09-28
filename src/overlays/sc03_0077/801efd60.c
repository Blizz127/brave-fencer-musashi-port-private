/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFD60 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_80187890(void);
extern s32 func_80187904(void);
extern void func_80187960(void);

void func_801EFD60(s32 a0) {

    extern s32 D_801F01E0[];
    extern s32 D_801F01F4[];
    extern s32 D_801F0210[];
    extern s32 D_801F745C;

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        s32 v0;
        if (D_801F745C < 0x14) {
            v0 = 0;
        } else if (D_801F745C < 0x46) {
            v0 = 1;
        } else if (D_801F745C < 0x64) {
            v0 = 2;
        } else if (D_801F745C < 0x82) {
            v0 = 3;
        } else {
            v0 = 4;
        }
        *(s32 *)(a0 + 0xE4) = D_801F01E0[v0];
    } else if (v1 < 0x384) {
        s32 v0 = func_80187890();
        *(s32 *)(a0 + 0xE4) = D_801F01F4[v0];
    } else {
        s32 v0 = func_80187904();
        *(s32 *)(a0 + 0xE4) = D_801F0210[v0];
        func_80187960();
    }
}
