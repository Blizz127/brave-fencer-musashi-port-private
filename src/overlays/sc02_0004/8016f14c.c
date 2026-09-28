/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F14C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80148634(void *a0);

void func_8016F14C(void *a0) {
    s32 v1 = *(s32 *)((u8 *)a0 + 0x1F8);
    s32 fp = v1 & 0x80FFFFFF;
    if (v1 != 0) {
        if (v1 & 0x1000000) {
            func_80148634(a0);
        }
        ((void (*)(void *))fp)(a0);
    }
}
