/* Main-exec range [80058BF4,80058C34) from the SLUS executable.
 * SHA256(span)=989e22de97bafa071af6e3638dbec38c1545850e3aac1e25377883f8434f3acc.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"

/* func_80058BF4 - byte-exact against retail (tools/register_match.py). */

extern s32 (*D_80072784)(char *, ...);
extern char D_80073F98[];
void func_80058BF4(u16 clut)
{
    D_80072784(D_80073F98, (clut & 0x3F) << 4, (clut & 0xFFFF) >> 6);
}
