/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012C044 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80013478(s32 a0, s32 a1);
extern s16 D_80126CAC;
extern s32 D_801274D4;
extern s32 D_801274E0;

s32 func_8012C044(s32 a0) {
    s32 (*fp)(void) = (s32 (*)(void))D_801274D4;
    if (fp != 0) {
        return fp();
    }
    return func_80013478(a0 + 4, (s32)&D_80126CAC) >= D_801274E0;
}
