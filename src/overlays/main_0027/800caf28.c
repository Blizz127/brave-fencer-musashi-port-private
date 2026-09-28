/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_800CAFEC();

void func_800CAF28(s32 *a0) {
    func_80147078(a0, 32);
    ((void (*)(void *))func_800CAFEC)(a0);
}
