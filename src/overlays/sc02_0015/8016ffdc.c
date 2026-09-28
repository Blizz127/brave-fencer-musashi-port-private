/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FFDC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_80181704[])(void);

void func_8016FFDC(void *a0) {
    D_80181704[*(u8 *)((s32)a0 + 0x216)]();
}
