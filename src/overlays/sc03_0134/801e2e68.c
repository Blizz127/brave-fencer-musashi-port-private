/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2E68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_80184428(s32);
extern s32 func_801844F8(void);
extern s32 func_8018456C(void);
extern void func_801845C8(void);

void func_801E2E68(s32 a0) {

    extern s32 D_801E3724[];
    extern s32 D_801E3738[];
    extern s32 D_801E3754[];

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        s32 v0 = ((s32 (*)(void))func_80184428)();
        *(s32 *)(a0 + 0xE4) = D_801E3724[v0];
    } else if (v1 < 0x384) {
        s32 v0 = func_801844F8();
        *(s32 *)(a0 + 0xE4) = D_801E3738[v0];
    } else {
        s32 v0 = func_8018456C();
        *(s32 *)(a0 + 0xE4) = D_801E3754[v0];
        func_801845C8();
    }
}
