/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016BFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016BFD0(s32 a0, s32 a1, s32 a2, s32 a3, void *a4);
extern s32 D_801955E8;

void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_8016BFD0(a0, a1, a2, a3, &D_801955E8);
}
