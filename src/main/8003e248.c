/* Main-exec range [8003E248,8003E2E4) from the SLUS executable.
 * SHA256(span)=44e908b0224ffcbb18b50177e85747fbd148f6c531eb05e307ee60d97f101e47.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003E248 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u8 pad0[0x14]; u8 unk14; u8 pad15[0x98 - 0x15]; u32 unk98; u8 padC[0xB0 - 0x9C]; } SndSeq;
extern SndSeq *D_800C73D8[];
extern void func_80041448(s16);
void func_8003E248(s16 sep, s16 seq)
{
    SndSeq *p = &D_800C73D8[sep][seq];

    func_80041448(sep | (seq << 8));
    p->unk14 = 0;
    D_800C73D8[sep][seq].unk98 &= ~2;
}
