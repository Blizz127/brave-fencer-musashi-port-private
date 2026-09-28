/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B1D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_80190628;
extern s16 D_8019028C;
extern u16 D_8019030C;
extern u16 D_8019030E;
extern u16 D_80190310;

void func_8017B1D8(void) {
    func_8012A418();
    D_80190628 = 0;
    D_8019028C = 0;
    D_8019030C = D_80126B5E;
    D_8019030E = D_80126B62;
    D_80190310 = D_80126B66;
}
