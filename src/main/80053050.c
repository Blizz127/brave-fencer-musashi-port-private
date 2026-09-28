/* Exact retail word export for [80053050,80053178); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80053050 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
typedef struct { s32 vx, vy, vz, pad; } VECTOR;
extern void func_800484EC(MATRIX *, s32 *, VECTOR *);
extern void func_80048D9C(MATRIX *, MATRIX *);
void func_80053050(MATRIX *m1, MATRIX *m2)
{
    VECTOR v;

    func_800484EC(m1, m2->t, &v);
    func_80048D9C(m1, m2);
    m1->t[0] = v.vx + m1->t[0];
    m1->t[1] = v.vy + m1->t[1];
    m1->t[2] = v.vz + m1->t[2];
}
