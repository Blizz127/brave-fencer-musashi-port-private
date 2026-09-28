/* Main-exec range [8003D9CC,8003DA1C) from the SLUS executable.
 * SHA256(span)=6e80098d10569f4ef6e4048dfcc17639c124f9a303c3233806cf3dd041fbb7bf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003D9CC - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_8006B8F8;
extern void (*D_8006B8EC)(void);
void func_8003D9CC(void)
{
    if (D_8006B8F8 == 0) {
        D_8006B8F8 = 1;
    } else {
        D_8006B8F8 = 0;
        D_8006B8EC();
    }
}
