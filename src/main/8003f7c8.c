/* Main-exec range [8003F7C8,8003F840) from the SLUS executable.
 * SHA256(span)=ab34f016e621694d4d9ed7196f2ca36668fce4fa0016ba9639d011634642c5ba.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003F7C8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A6510;
extern s16 D_800B9B3A;
extern void func_80040868(s32);
s16 func_8003F7C8(u16 voice)
{
    s16 v = voice;
    if (D_800A6510 == 1) {
        return -1;
    }
    D_800A6510 = 1;
    if ((u16)voice < 24) {
        D_800B9B3A = v;
        func_80040868(0);
        D_800A6510 = 0;
        return 0;
    }
    D_800A6510 = 0;
    return -1;
}
