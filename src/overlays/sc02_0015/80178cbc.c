/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178CBC - byte-exact against retail at -O2 (tools/register_match.py). */
extern short D_8019069C;
extern s32 D_8018FE78;

void func_80178CBC(s32 arg0, s32 arg1) {
    D_8018FE78 = arg1;
    do {
        func_80178D40(arg0, D_8018FE78);
    } while (D_8019069C == 3);
}
