/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80151944 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_80151944(void *a0) {

    extern void (*D_80180E0C[])(void);
    D_80180E0C[*(u16 *)((s32)a0 + 0x2)]();
}
