/* Main-exec range [8005C43C,8005C46C) from the SLUS executable.
 * SHA256(span)=441e82c69f00d93c843e344a672dce86f79cb249a36130644c47bb595004cbdc.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
/* func_8005C43C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_800728A9[];

u8 func_8005C43C(u8 c) {
    if (D_800728A9[c] & 2) {
        c -= 0x20;
    }
    return c;
}
