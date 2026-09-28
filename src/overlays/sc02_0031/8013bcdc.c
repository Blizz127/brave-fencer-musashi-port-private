/* SC02 resident image [8013BCDC,8013BD34) at overlay base 0x80128158.
 * SHA256(span)=28ffc39ad693e34f94af653d088a80007673d3e1ed875850e555b55409fb5ef1.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013BCDC - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8013BCDC(void) {

    extern s32 D_801853C4;
    s32 pad[4];
    if (D_801853C4 != 0) {
        ((void (*)(void))D_801853C4)();
    }
}
