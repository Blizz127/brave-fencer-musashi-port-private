/* Exact retail word export for [800385C0,80038638); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800385C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

void func_800385C0(s16 a0)
{
    extern u8 D_800C6E2A[];
    extern u8 D_800B9ED2[];
    extern u8 D_800B9ED3[];
    register s32 a0v __asm__("$4");
    register u8 *v1 __asm__("$3");
    s32 a1;

    for (a1 = 0, v1 = D_800C6E2A; a1 < 0x10; a1++, v1 += 0x60) {
        if (v1[2] != 0 && *(s16 *)(*(s32 *)(v1 - 0xA) + 0x1F0) == a0v) {
            v1[2] = 0;
            v1[0] = 0;
        }
    }

    D_800B9ED2[((a0v << 7) - a0v) << 2] = 0;
    D_800B9ED3[((a0v << 7) - a0v) << 2] = 0;
}
