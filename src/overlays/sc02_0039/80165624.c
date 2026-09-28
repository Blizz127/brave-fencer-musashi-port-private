/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80165624 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern s16 D_80078EB8;
extern u8 func_80165658(s32 a0, s32 a1);

s32 func_80165624(s32 a0) {
    return (u32)(u16)D_80078EB8 < (u32)(func_80165658(a0, D_80078EC1 & 0x7F) & 0x7F);
}
