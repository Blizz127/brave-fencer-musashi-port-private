/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E3424 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801E3424(s32 param_1) {
    extern s32 D_801E9E38;
    extern s32 D_801E9E3C;
    struct S_801E3424 { u8 pad[0xFC]; s16 f; } *a, *b;
    a = (struct S_801E3424 *) D_801E9E38;
    b = (struct S_801E3424 *) D_801E9E3C;
    *(s16 *)(param_1 + 0xFC) = 1;
    a->f = 0;
    b->f = 0;
}
