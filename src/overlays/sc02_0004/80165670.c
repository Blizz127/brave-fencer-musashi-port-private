/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165670 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80078EC8;
extern s32 D_801809DC[];

void func_80165670(s32 a0, s32 a1) {
    D_80078EC8 = D_801809DC[a1 & 0x7F];
}
