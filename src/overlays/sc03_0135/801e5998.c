/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E5998 - byte-exact against retail at -O2 (tools/register_match.py). */
void *func_801E585C(void);

s32 func_801E5998(s32 a0) {
    extern s32 D_801EADF0;
    extern s32 D_801EAC78;
    extern s32 D_801EAC74;
    s32 s0;
    s32 v0;
    s32 v1;
    s32 limit;
    func_801E585C();
    s0 = a0;
    v0 = D_801EADF0;
    if (v0 > 0) {
        v1 = 0;
        limit = v0 * 16;
        do {
            if (*(s32 *)((s32)&D_801EAC78 + v1) == s0) {
                return *(s32 *)((s32)&D_801EAC74 + v1);
            }
            v1 += 16;
        } while (v1 < limit);
    }
    return 0;
}
