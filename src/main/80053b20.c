/* Exact retail word export for [80053B20,80053BD8); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80053B20 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX;
extern s32 func_80047948(s32);
extern s32 func_8004787C(s32);
extern void func_80048D9C(MATRIX *, MATRIX *);
void func_80053B20(MATRIX *mp, s32 angle)
{
    MATRIX m;
    s32 a = angle / 360;
    s32 c;
    s16 s;

    c = func_80047948(a);
    s = func_8004787C(a);

    if (angle) {
        m.m[0][0] = c;
        m.m[0][1] = -s;
        m.m[0][2] = 0;
        m.m[1][0] = s;
        m.m[1][1] = c;
        m.m[1][2] = 0;
        m.m[2][0] = 0;
        m.m[2][1] = 0;
        m.m[2][2] = 0x1000;
        m.t[0] = 0;
        m.t[1] = 0;
        m.t[2] = 0;
        func_80048D9C(mp, &m);
    }
}
