/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80146E98(s32 a0);

void func_800CB2B4(s32 *a0) {
    s32 *s1;

    s1 = (s32 *)a0[0x20 / 4];
    if (func_80146E98((s32)a0) != 0) {
        func_80146CA0(a0);
    } else if (a0[0x1C / 4] & 1) {
        s1[1] |= 0x80000000;
    } else {
        s1[1] &= 0x7FFFFFFF;
    }
}
