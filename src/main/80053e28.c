/* Exact retail word export for [80053E28,80053EEC); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80053E28 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
extern MATRIX D_800AE620;
void func_80053E28(MATRIX *m, s16 s, s16 c, u8 axis)
{
    *m = D_800AE620;
    switch (axis) {
    case 'x':
    case 'X':
        m->m[1][1] = c;
        m->m[2][2] = c;
        m->m[1][2] = -s;
        m->m[2][1] = s;
        break;
    case 'y':
    case 'Y':
        m->m[0][0] = c;
        m->m[2][2] = c;
        m->m[0][2] = s;
        m->m[2][0] = -s;
        break;
    case 'z':
    case 'Z':
        m->m[0][0] = c;
        m->m[1][1] = c;
        m->m[0][1] = -s;
        m->m[1][0] = s;
        break;
    }
}
