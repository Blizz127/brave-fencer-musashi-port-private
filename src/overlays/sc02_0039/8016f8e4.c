/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F8E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80182568[])(void);

void func_8016F8E4(void *a0) {
    D_80182568[*(u8 *)((s32)a0 + 0x216)]();
}
