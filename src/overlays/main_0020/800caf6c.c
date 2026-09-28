/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF6C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_800CAFA0(void *a0);

void func_800CAF6C(s32 *a0) {
    func_80147078(a0, 31);
    func_800CAFA0(a0);
}
