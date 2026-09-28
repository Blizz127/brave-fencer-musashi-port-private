/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012CB64 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8012CB64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    register s32 v0 __asm__("$2");
    register s32 v1 __asm__("$3");
    v0 = 0;
    v1 = *(s16*)arg0;
    if (((arg1 <= v1) && (v1 < arg2)) && (arg3 <= *(s16*)(arg0 + 4))) {
        v0 = *(s16*)(arg0 + 4) < arg4;
    }
    return v0;
}
