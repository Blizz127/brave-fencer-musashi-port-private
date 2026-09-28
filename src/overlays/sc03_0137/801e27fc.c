/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E27FC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E27FC(void *a0) {

    extern void (*D_801E2FD4[])(void);
    D_801E2FD4[*(u8 *)((s32)a0 + 0x214)]();
}
