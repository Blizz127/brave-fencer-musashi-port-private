/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CF114 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800D3C0C;
extern s32 func_8001ABBC(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 *arg4);
extern s32 D_800C7C60;
extern s32 *D_800C7C64;
extern s32 D_800A2E20;
extern u8 D_800AE840[];

void func_800CF114(void) {
    if (D_800D3C0C == 0) {
        s32 *p = &D_800C7C60;
        *p = 0;
        D_800C7C64 = &D_800A2E20;
        if (func_8001ABBC(0, 0, D_800AE840, 0, p) != 0) {
            D_800D3C0C = 1;
        }
    }
}
