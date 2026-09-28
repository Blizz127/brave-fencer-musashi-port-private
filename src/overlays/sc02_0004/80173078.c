/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173078 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_80173078(void *a0) {

    extern void (*D_801812A8[])(void);
    D_801812A8[*(u8 *)((s32)a0 + 0x214)]();
}
