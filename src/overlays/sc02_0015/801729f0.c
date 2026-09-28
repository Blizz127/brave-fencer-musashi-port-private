/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801729F0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801729F0(void *a0) {

    extern void (*D_801817DC[])(void);
    D_801817DC[*(u8 *)((s32)a0 + 0x214)]();
}
