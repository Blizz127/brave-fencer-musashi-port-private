/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142414 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012C588(s32 a0, s32 a1);

void func_80142414(s32 a0, s16 a1) {
    s32 v0;
    v0 = func_8012C588(0x13, a0);
    if (v0 != 0) {
        *(s16*)(v0 + 0x52) = a1;
    }
}
