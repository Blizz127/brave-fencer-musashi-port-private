/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E3080 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801E256C;

void func_801E3080(void) {
    extern s32 D_801E256C;
    extern s32 D_801E249C;
    *(s32 *)(D_801E256C + 4) = D_801E249C;
}
