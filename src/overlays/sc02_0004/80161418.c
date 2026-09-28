/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161418 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801615C4(void *a0, s32 a1);
extern s32 func_8016163C(s32 a0, u32 a1);

void func_80161418(void *a0) {
    func_8016163C(a0, func_801615C4(a0, 0));
}
