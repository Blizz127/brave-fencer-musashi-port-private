/* Main-exec range [80037EA0,80037F3C) from the SLUS executable.
 * SHA256(span)=50ac7998b3117ad9942bc55d300d1231f38c65ce6084760a7d9bb160a66507a8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037EA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800C6E2E[];

void func_80037EA0(void)
{
    extern void func_8003D3B4(s32, s32);
    register u8 *p __asm__("$16");
    register s32 i __asm__("$17");
    register u32 mask __asm__("$18");

    i = 0;
    mask = 0xFFF9FFFF;
    p = D_800C6E2E;
    do {
        if (p[-4] != 0 && p[-1] == 0 && p[0] != 0) {
            func_8003D3B4(i, 8);
            *(u32 *)(p - 0x4A) &= mask;
            p[0] = 0;
        }
        i++;
        p += 0x60;
    } while (i < 0x10);
}
