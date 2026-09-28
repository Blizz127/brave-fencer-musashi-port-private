/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2ED8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_801844F8(void);
extern s32 func_8018456C(void);
extern void func_801845C8(void);

void func_801E2ED8(s32 a0) {

    extern s32 D_801EA5A4;
    extern s32 D_801E3328[];
    extern s32 D_801E333C[];
    extern s32 D_801E3358[];

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        s32 x = D_801EA5A4;
        s32 idx;
        if (x < 0x14) {
            idx = 0;
        } else if (x < 0x46) {
            idx = 1;
        } else if (x < 0x64) {
            idx = 2;
        } else if (x < 0x82) {
            idx = 3;
        } else {
            idx = 4;
        }
        *(s32 *)(a0 + 0xE4) = D_801E3328[idx];
    } else if (v1 < 0x384) {
        s32 v0 = func_801844F8();
        *(s32 *)(a0 + 0xE4) = D_801E333C[v0];
    } else {
        s32 v0 = func_8018456C();
        *(s32 *)(a0 + 0xE4) = D_801E3358[v0];
        func_801845C8();
    }
}
