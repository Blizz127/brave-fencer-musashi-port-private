/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB55C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);

void func_800CB55C(s32 *arg0) {
    arg0[1] += arg0[4];
    arg0[3] += arg0[6];
    arg0[5] += 0xC000;
    arg0[2] += arg0[5];
    if (--arg0[7] == -1) {
        ((void (*)(s32))func_80146C3C)((s32)arg0);
    }
}
