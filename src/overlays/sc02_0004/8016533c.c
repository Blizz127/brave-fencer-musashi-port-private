/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016533C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern u8 D_80078EC1;
extern s32 func_801659DC(u8 *a0);
extern u8 D_80126CF8;
extern s32 func_801659DC();

void func_8016533C(void) {
    D_80126CF8 = D_80078EC1;
    func_801659DC((u8 *)&D_80126B58);
}
