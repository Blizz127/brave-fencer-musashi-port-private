/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174474 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80174474(void *a0) {

    extern void (*D_8018189C[])(void);
    D_8018189C[*(u8 *)((s32)a0 + 0x214)]();
}
