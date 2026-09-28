/* Main-exec range [8003EAB4,8003EBB0) from the SLUS executable.
 * SHA256(span)=313b5eea33364601805618768eeebb9b89b12e51c5c28924b994c4d6d3bb166b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003EAB4 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u8 *read; u8 *f4; u8 pad8[0x14 - 8]; u8 f14; u8 pad15[0x20 - 0x15]; u8 f20; u8 f21; u8 pad22[0x98 - 0x22]; u32 f98; u8 pad9C[0xB0 - 0x9C]; } SndSeq;
extern SndSeq *D_800C73D8[];
void func_8003EAB4(s16 sep, s16 seq)
{
    SndSeq *p = &D_800C73D8[sep][seq];

    p->f20 = 1;
    p->f21 = 0;
    D_800C73D8[sep][seq].f98 &= ~0x100;
    D_800C73D8[sep][seq].f98 &= ~8;
    D_800C73D8[sep][seq].f98 &= ~2;
    D_800C73D8[sep][seq].f98 &= ~4;
    D_800C73D8[sep][seq].f98 &= ~0x200;
    p->read = p->f4;
    p->f14 = 1;
    D_800C73D8[sep][seq].f98 |= 1;
}
