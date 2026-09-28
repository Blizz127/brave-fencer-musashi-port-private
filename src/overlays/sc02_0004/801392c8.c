/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801392C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801395D4(void *);

void func_801392C8(void *a0) {
    func_801395D4(a0);
    *(s8 *)((s32)a0 + 0x1E) = 0;
    *(s16 *)((s32)a0 + 0x4) = 5;
}
