/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8D70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80115158[];

s32 func_801E8D70(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 *arg4) {
    s32 ret;
    s16 var;
    u8 thr;

    *arg4 = 0x808080;
    ret = 0;
    thr = D_80115158[arg2 * 2];
    if (arg1 < 5) {
        if (arg1 > 0) {
            var = arg3;
        } else if (arg1 == 0) {
            goto end;
        } else {
            var = arg3;
        }
    } else if (arg1 == 5) {
        goto end;
    } else {
        var = arg3;
    }
    if (var < thr) {
        ret = *(s32 *)(arg0 + var * 4);
    }
end:
    return ret;
}
