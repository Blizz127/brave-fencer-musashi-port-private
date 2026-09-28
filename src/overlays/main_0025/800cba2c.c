/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBA2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s16 a1);

void func_800CBA2C(s32 *a0) {
    func_80146E90(a0, 8);
    func_80146CA0(a0);
}
