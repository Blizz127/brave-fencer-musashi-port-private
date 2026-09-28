/* Main-exec range [8003E310,8003E418) from the SLUS executable.
 * SHA256(span)=d00a8b49dfab820d5765b121c1f3cecf553587c5c2d7ee6305d39c3c565dcbb7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003E310 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u8 pad0[0x52]; s16 f52; s16 f54; u8 pad56[0x90 - 0x56]; s32 f90; u8 pad94[0xB0 - 0x94]; } SndSeq;
extern SndSeq *D_800C73D8[];
extern void func_8003E65C(s16, s16);
void func_8003E310(s16 sep, s16 seq)
{
    SndSeq *p = &D_800C73D8[sep][seq];
    s32 d = p->f90 - p->f54;
    s32 acc;

    if (d > 0) {
        if (p->f52 > 0) {
            p->f52--;
        } else if (p->f52 == 0) {
            p->f52 = p->f54;
            p->f90--;
        } else {
            p->f90 = d;
        }
    } else if (p->f54 >= p->f90) {
        acc = p->f90;
        do {
            do {
                func_8003E65C(sep, seq);
            } while (p->f90 == 0);
            acc += p->f90;
        } while (acc < p->f54);
        p->f90 = acc - p->f54;
    }
}
