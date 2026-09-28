/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF56C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801858CC(s32);

void func_801EF56C(void *a0, void *a1, void *a2) {
    ((void (*)(void *, void *, void *))func_801858CC)(a0, a1, a2);
}
