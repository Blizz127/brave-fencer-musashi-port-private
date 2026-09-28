/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015FAAC - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8015FAAC(s32 *a0) {

    extern void (*D_80181AE0[])(void);
    D_80181AE0[*(u16 *)((s32)a0 + 0x2)]();
}
