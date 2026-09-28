/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F764 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80171928(void *a0);

void func_8016F764(void *a0) {
    s32 v0 = *(s32 *)((u8 *)a0 + 0x200) - 1;
    *(s32 *)((u8 *)a0 + 0x200) = v0;
    if (v0 == -1) {
        func_80171928(a0);
    }
}
