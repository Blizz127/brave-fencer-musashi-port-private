/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F324 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8015F324(s32 *a0) {

    extern void (*D_8018067C[])(void);
    D_8018067C[*(u16 *)((s32)a0 + 0x2)]();
}
