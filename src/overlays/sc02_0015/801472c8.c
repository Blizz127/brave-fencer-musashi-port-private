/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801472C8 - byte-exact against retail at -O2 (tools/register_match.py). */
struct S;
struct S {
    u8  pad0[0x7E];  
    u16 f7E;         
};

s32 func_801472C8(struct S *a0) {
    return a0->f7E = a0->f7E | 0x2;
}
