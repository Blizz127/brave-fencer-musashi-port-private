/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2784 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E2784(void *a0) {

    extern void (*D_801E30A0[])(void);
    D_801E30A0[*(u8 *)((s32)a0 + 0x15)]();
}
