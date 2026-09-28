/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFAC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAFAC(void *a0) {

    extern void (*D_800CBC9C[])(void);
    D_800CBC9C[*(u16 *)((s32)a0 + 0x2)]();
}
