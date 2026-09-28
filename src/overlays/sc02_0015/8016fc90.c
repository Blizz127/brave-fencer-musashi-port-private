/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FC90 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void (*D_801816D8[])(void);

void func_8016FC90(void *a0) {
    D_801816D8[*(u8 *)((s32)a0 + 0x216)]();
}
