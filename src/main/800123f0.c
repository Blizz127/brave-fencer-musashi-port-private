/* Owner re-derivation from retail assembly (clean room, clean input set; D2 grouped GTE macros). */
/* Post-multiplies the 3x3 rotation matrix m by a rotation about Z (angle, 4096 = 1.0): builds the Z matrix in a
 * frame-local matrix from func_8004787C/func_80047948 (sin/cos), loads m into the GTE rotation registers,
 * rotates each column of the local matrix by it and stores the three results back into the columns of m,
 * then hands m to func_8001282C. */
#include "psx_types.h"
#include "gte_ops.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Matrix;

extern s32 func_8004787C(s32 angle);
extern s32 func_80047948(s32 angle);
extern void func_8001282C(Matrix *m);

void func_800123F0(Matrix *m, s32 angle)
{
    Matrix r;
    s32 s;
    s32 c;

    s = func_8004787C(angle);
    c = func_80047948(angle);
    r.m[0][0] = c;
    r.m[0][1] = -s;
    r.m[0][2] = 0;
    r.m[1][0] = s;
    r.m[1][1] = c;
    r.m[1][2] = 0;
    r.m[2][0] = 0;
    r.m[2][1] = 0;
    r.m[2][2] = 0x1000;

    gte_g_ld_rot(m);

    gte_g_ld_col(&r.m[0][0]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(&m->m[0][0]);

    gte_g_ld_col(&r.m[0][1]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(&m->m[0][1]);

    gte_g_ld_col(&r.m[0][2]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(&m->m[0][2]);

    func_8001282C(m);
}
