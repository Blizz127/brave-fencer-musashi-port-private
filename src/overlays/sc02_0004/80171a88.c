/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171A88 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80171A88(s32 a0) {
    s32 v0;
    v0 = *(s32*)(a0 + 0x200);
    if (!v0) goto ret1;
    *(s32*)(a0 + 0x200) = v0 - 1;
    return (u32)(v0 - 1) < 1;
ret1:
    return 1;
}
