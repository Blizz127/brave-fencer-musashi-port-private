/* Owner re-derivation from retail assembly (clean room, clean input set; D2 grouped GTE macros). */
/* Rotation about the Y axis: builds the rotation matrix from the sine (func_8004787C) and
 * cosine (func_80047948) of the angle, multiplies it into m column by column through the
 * GTE (m = m * R), then hands m to func_8001282C. Declared void like func_8001282C and every
 * owner caller; the retail v0 on return is only func_80013ED0's last lhu. */
#include "psx_types.h"
#include "gte_ops.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Mat;

extern s32 func_8004787C(s32 a);
extern s32 func_80047948(s32 a);
extern void func_8001282C(Mat *m);

void func_80012558(Mat *m, s32 a)
{
    Mat r;
    s16 sn, cs;

    sn = func_8004787C(a);
    cs = func_80047948(a);
    r.m[0][0] = cs;
    r.m[0][1] = 0;
    r.m[0][2] = sn;
    r.m[1][0] = 0;
    r.m[1][1] = 0x1000;
    r.m[1][2] = 0;
    r.m[2][0] = -sn;
    r.m[2][1] = 0;
    r.m[2][2] = cs;

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
