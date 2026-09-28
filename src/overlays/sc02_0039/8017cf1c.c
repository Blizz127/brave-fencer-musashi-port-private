/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017CF1C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80182B4C[])(void);

void func_8017CF1C(void *a0) {
    D_80182B4C[*(u8 *)((s32)a0 + 0x15)]();
}
