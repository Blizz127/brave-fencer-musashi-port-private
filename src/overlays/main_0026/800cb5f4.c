/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB5F4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB5F4(s32 a0) {
    extern void func_80146EC0(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void (*D_800CBB38[])(void);
    extern u8 D_800CBB40;
    func_80146EC0(*(s32 *)(a0 + 0x4C), a0 + 4, (s32)&D_800CBB40, (s32)&D_800CBB38);
}
