/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012BD14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80013350(s32 a0, void *a1);
extern u8 D_80126B5C;

void func_8012BD14(s32 a0) {
    func_80013350(a0 + 4, &D_80126B5C);
}
