/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB9B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);
extern void func_800CBA0C(s32 param_1);

void func_800CB9B4(s32 *arg0) {
    arg0[7] = arg0[7] + 1;
    if (arg0[7] < 2) {
        *(u32 *)&arg0[12] >>= 1;
        func_800CBA0C((s32)arg0);
    } else {
        func_80146C3C();
    }
}
