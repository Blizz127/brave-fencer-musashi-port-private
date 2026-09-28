/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B1D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_801A0D88;
extern s16 D_801A0BE4;
extern u16 D_801A0C64;
extern u16 D_801A0C66;
extern u16 D_801A0C68;

void func_8017B1D8(void) {
    func_8012A418();
    D_801A0D88 = 0;
    D_801A0BE4 = 0;
    D_801A0C64 = D_80126B5E;
    D_801A0C66 = D_80126B62;
    D_801A0C68 = D_80126B66;
}
