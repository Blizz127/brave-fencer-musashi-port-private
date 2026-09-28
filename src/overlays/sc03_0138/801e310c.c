/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E310C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E310C(void *a0) {

    extern void (*D_801E35A8[])(void);
    D_801E35A8[*(u16 *)((s32)a0 + 0x2)]();
}
