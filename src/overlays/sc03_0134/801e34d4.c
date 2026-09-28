/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E34D4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801E9E38;
extern s32 D_801E9E3C;

void func_801E34D4(s32 arg0) {
    extern s32 D_801E9E38;
    extern s32 D_801E9E3C;
    register s32 p __asm__("$3") = D_801E9E38;
    *(s16 *)(arg0 + 0xFC) = 1;
    {
        register s32 q __asm__("$4") = D_801E9E3C;
        *(s16 *)(p + 0xFC) = 3;
        *(s16 *)(q + 0xFC) = 3;
    }
}
