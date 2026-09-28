/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013767C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);

s32 func_8013767C(s32 a0) {
    s32 s0 = func_801399A8();
    if (s0 != 0) {
        func_801377B4(a0, 0, s0);
    }
    return s0;
}
