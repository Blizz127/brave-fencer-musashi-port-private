/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA584 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);

s32 func_801AA584(s32 a0) {
    s16 local_10[3]; /* sp+0x10 */
    s16 local_18[3]; /* sp+0x18 */
    s32 v0;

    local_18[0] = 0x18;
    local_10[0] = 0x18;
    local_18[1] = -0x30;
    local_10[1] = 0;
    local_18[2] = -0x20;
    local_10[2] = -0x20;

    v0 = func_8012DEB8(a0, (s32)local_10, (s32)local_18);

    if (v0 == 0) {
        local_18[0] = -0x18;
        local_10[0] = -0x18;
        v0 = func_8012DEB8(a0, (s32)local_10, (s32)local_18);
        return (v0 != 0) ? 1 : 0;
    }

    return 1;
}
