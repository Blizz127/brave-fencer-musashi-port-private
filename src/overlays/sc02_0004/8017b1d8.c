/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B1D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_80196350;
extern s16 D_801961B4;
extern u16 D_80196234;
extern u16 D_80196236;
extern u16 D_80196238;

void func_8017B1D8(void) {
    func_8012A418();
    D_80196350 = 0;
    D_801961B4 = 0;
    D_80196234 = D_80126B5E;
    D_80196236 = D_80126B62;
    D_80196238 = D_80126B66;
}
