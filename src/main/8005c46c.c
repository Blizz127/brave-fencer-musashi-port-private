/* Main-exec range [8005C46C,8005C49C) from the SLUS executable.
 * SHA256(span)=4fd82ee3052d119b266ae770b01d431c4a2555110fc036a158d6f96f9d38433b.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
/* func_8005C46C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800728A9[];

u8 func_8005C46C(u8 c) {
    if (D_800728A9[c] & 1) {
        c += 0x20;
    }
    return c;
}
