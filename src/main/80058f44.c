/* Main-exec range [80058F44,80058F70) from the SLUS executable.
 * SHA256(span)=22889462dff9f64b9d44aeb687752f3932c9ea6966836adce80d2237e6c891bc.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058F44 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u32 tag; u32 code[1]; } DR_TPAGE;
#define get_mode(dfe, dtd, tpage) \
    ((0xE1000000) | ((dtd) ? 0x0200 : 0) | ((dfe) ? 0x0400 : 0) | ((tpage) & 0x9FF))
void func_80058F44(DR_TPAGE *p, s32 dfe, s32 dtd, s32 tpage)
{
    ((u8 *)p)[3] = 1;
    p->code[0] = get_mode(dfe, dtd, tpage);
}
