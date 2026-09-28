/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCEB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801477E8(s32 *a0, s32 a1);

void func_800CCEB8(void *arg0) {
    func_801477E8((s32 *)arg0, 0xFFEA0000);
    *(s16 *)((s32)arg0 + 2) = 2;
}
