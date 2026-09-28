/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E288C - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801E288C(void) {

    extern s16 D_801EA554;
    extern void (*D_801E5B7C[])(void);
    extern s16 D_801EA556;

    D_801E5B7C[D_801EA554]();
    return (unsigned)D_801EA556 >> 31;
}
