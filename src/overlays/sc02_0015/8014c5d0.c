/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C5D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_8017FE8C;
extern s32 func_8014C5FC(s32 a0, s32 a1, void *a2);

s16 func_8014C5D0(s32 a0, s32 a1) {
    return func_8014C5FC(a0, a1, &D_8017FE8C);
}
