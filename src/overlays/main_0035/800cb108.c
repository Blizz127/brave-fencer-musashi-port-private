/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB108 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CB1F8(void *a0);
extern void func_80154A74(s32 *a0, s16 a1);

void func_800CB108(s32 *a0) {
    func_80154A74(a0, 17);
    func_800CB1F8(a0);
}
