/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFF08 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801EFF08(void) {
    extern s32 D_801EF3EC;
    extern s32 D_801EF31C;
    *(s32 *)(D_801EF3EC + 4) = D_801EF31C;
}
