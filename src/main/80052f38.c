/* Main-exec range [80052F38,80052FCC) from the SLUS executable.
 * SHA256(span)=3360c187cf55c2daa8ba2a479b3e16fc2cc5e48fe9274fcfa31942ae54911eb0.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80052F38 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
extern void func_800484EC(MATRIX *, s32 *, s32 *);
extern void func_8004818C(MATRIX *, MATRIX *, MATRIX *);
void func_80052F38(MATRIX *m1, MATRIX *m2, MATRIX *m3)
{
    func_800484EC(m1, m2->t, m3->t);
    func_8004818C(m1, m2, m3);
    m3->t[0] += m1->t[0];
    m3->t[1] += m1->t[1];
    m3->t[2] += m1->t[2];
}
