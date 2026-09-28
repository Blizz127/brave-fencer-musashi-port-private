/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801614E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801615C4(void *a0, s32 a1);
extern int func_80161888(int param_1, unsigned int param_2);

void func_801614E4(void *a0) {
    func_80161888(a0, func_801615C4(a0, 0));
}
