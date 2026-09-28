/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFC6C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_801877C0(void);
extern s32 func_80187890(void);
extern s32 func_80187904(void);
extern void func_80187960(void);

void func_801EFC6C(s32 a0) {
    extern s32 D_801F0094[];
    extern s32 D_801F0734;
    extern s32 D_801F00A8[];
    extern s32 D_801F00C4[];

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        s32 v0 = func_801877C0();
        *(s32 *)(a0 + 0xE4) = D_801F0094[v0];
    } else if (v1 < 0x384) {
        if ((u32)(v1 - 0x136) < 0x122) {
            *(s32 *)(a0 + 0xE4) = (s32)&D_801F0734;
        } else {
            s32 v0 = func_80187890();
            *(s32 *)(a0 + 0xE4) = D_801F00A8[v0];
        }
    } else {
        s32 v0 = func_80187904();
        *(s32 *)(a0 + 0xE4) = D_801F00C4[v0];
        func_80187960();
    }
}
