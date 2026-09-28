/* Main-exec range [80058B94,80058BF4) from the SLUS executable.
 * SHA256(span)=7a53b65c1a0d04d197aacbe86e0aeb8cf758102ede4a93a47890f49fbdb88785.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058B94 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 (*D_80072784)(char *, ...);
extern char D_80073F80[];
void func_80058B94(u16 tpage)
{
    D_80072784(D_80073F80, (tpage >> 7) & 3, (tpage >> 5) & 3, (tpage << 6) & 0x7C0,
               ((tpage << 4) & 0x100) + ((tpage >> 2) & 0x200));
}
