/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016084C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8016084C(s32 *a0) {

    extern void (*D_80180768[])(void);
    D_80180768[*(u16 *)((s32)a0 + 0x2)]();
}
