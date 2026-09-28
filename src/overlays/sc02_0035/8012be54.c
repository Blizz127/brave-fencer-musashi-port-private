/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BE54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void func_8012BE98(s32 a0, u16 *a1);

void func_8012BE54(s32 a0) {
    u16 sp[3];
    sp[0] = D_80126B5E;
    sp[1] = D_80126B62;
    sp[2] = D_80126B66;
    func_8012BE98(a0, sp);
}
