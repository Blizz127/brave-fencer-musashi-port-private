/* Main-exec range [8003EA04,8003EAB4) from the SLUS executable.
 * SHA256(span)=029de41112355ac1b9490c6d8d6cac948851670f732c869c7f7ff6919bce1339.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003EA04 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u8 *read; u8 pad4[0x88 - 4]; s32 delta; u8 pad8C[0xB0 - 0x8C]; } SndSeq;
extern SndSeq *D_800C73D8[];
s32 func_8003EA04(s16 sep, s16 seq)
{
    SndSeq *p = &D_800C73D8[sep][seq];
    u32 v;
    u32 c;

    v = *p->read++;
    if (v == 0) {
        return 0;
    }
    if (v & 0x80) {
        v &= 0x7F;
        do {
            c = *p->read++;
            v = (v << 7) + (c & 0x7F);
        } while (c & 0x80);
    }
    p->delta += v * 10;
    return v * 10;
}
