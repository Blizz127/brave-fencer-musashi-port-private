/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174EF0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012A018(s32 a, s32 b);
extern s32 D_8012697C;
extern u16 D_80126980;
extern s32 func_80174F28(void *a0);

void func_80174EF0(s32 a0, s16 a1) {
    D_8012697C = a0;
    D_80126980 = a1;
    func_8012A018((s32)func_80174F28, 1);
}
