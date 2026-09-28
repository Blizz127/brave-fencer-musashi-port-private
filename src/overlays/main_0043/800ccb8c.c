/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCB8C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCB8C(void *a0) {

    extern void (*D_800CD6DC[])(void);
    s32 e;

    e = *(u16 *)((s32)a0 + 0x2) - 2;
    D_800CD6DC[e]();
}
