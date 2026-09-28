/* Main-exec range [8003EBB0,8003EC10) from the SLUS executable.
 * SHA256(span)=d57cbf3c5f28a5ace3a3caa42f86925a99196619401460e1f39cc7aeefdb0c51.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003EBB0 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u8 pad0[0x14]; u8 unk14; u8 pad15[0x98 - 0x15]; u32 unk98; u8 padC[0xB0 - 0x9C]; } SndSeq;
extern SndSeq *D_800C73D8[];
void func_8003EBB0(s16 sep, s16 seq)
{
    SndSeq *p = &D_800C73D8[sep][seq];

    p->unk14 = 1;
    D_800C73D8[sep][seq].unk98 &= ~8;
}
