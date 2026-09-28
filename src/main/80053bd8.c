/* Main-exec range [80053BD8,80053CF8) from the SLUS executable.
 * SHA256(span)=9dad37683509c56a456988f04b7ffa0fe888d79ba44b96855b4c56c5369f1d07.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80053BD8 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
s32 func_80053BD8(MATRIX *m, s16 sx, s16 sy, s16 sz)
{
    s32 r = 0;

    if (sx != 0x1000) {
        m->m[0][0] = m->m[0][0] * sx >> 12;
        m->m[1][0] = m->m[1][0] * sx >> 12;
        m->m[2][0] = m->m[2][0] * sx >> 12;
        r = 1;
    }
    if (sy != 0x1000) {
        m->m[0][1] = m->m[0][1] * sy >> 12;
        m->m[1][1] = m->m[1][1] * sy >> 12;
        m->m[2][1] = m->m[2][1] * sy >> 12;
        r = 1;
    }
    if (sz != 0x1000) {
        m->m[0][2] = m->m[0][2] * sz >> 12;
        m->m[1][2] = m->m[1][2] * sz >> 12;
        m->m[2][2] = m->m[2][2] * sz >> 12;
        r = 1;
    }
    return r;
}
