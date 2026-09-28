/* Main-exec range [80037F3C,80037FC4) from the SLUS executable.
 * SHA256(span)=8004fc1584076b89c9b36eb3de45f567c758290743fbe4dcb337104988552922.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037F3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

void func_80037F3C(void)
{

    extern u8 D_800C6DD0[];
    extern void func_8003B250(s32, void *);

    register u8 *p __asm__("$16");
    register s32 i __asm__("$17");
    u8 *base;

    base = D_800C6DD0;
    i = 0;
    p = base + 0x5E;
    do {
        if (p[-4] != 0 && p[-1] != 0) {
            func_8003B250(i, base + 0x10);
            *(u32 *)(p - 0x4A) = 0;
            p[-1] = 0;
            p[0] = 0;
        }
        i++;
        p += 0x60;
        base += 0x60;
    } while (i < 0x10);
}
