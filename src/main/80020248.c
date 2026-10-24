/* Owner re-derivation from retail assembly (clean room, clean input set; D2 grouped GTE macros). */
/* Builds per-part matrices: for every entry of a zero-terminated list, builds the part's rotation
 * matrix from its three angles (func_80020DA4), then rotates its columns by two view matrices.
 * Unless skip is set, the first view matrix gives a rotation-only result; the second gives the
 * rotation plus the part position rotated and translated by the second view matrix. Up to seven
 * parts use scratchpad buffers (returns 1); more use the two RAM buffers (returns 0). */
#include "psx_types.h"
#include "gte_ops.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Mat;

typedef struct {
    u32 xy;
    s16 z;
    u16 ang[3];
} Part;

extern Mat D_80074818[];
extern Mat D_80075018[];
extern void func_80020DA4(u16 *ang, s16 *m);

s32 func_80020248(u32 *list, Part *p, Mat *a, Mat *b, s32 skip)
{
    Mat tmp;
    Mat *o1;
    Mat *o2;
    u16 *c1;
    u16 *c2;
    s32 n;
    s32 ret;
    u32 xy;

    ret = 0;
    n = 0;
    while (*list++ != 0) {
        n++;
    }
    if (n >= 8) {
        o1 = D_80074818;
        o2 = D_80075018;
    } else {
        o1 = (Mat *)0x1F800000;
        o2 = (Mat *)0x1F8000E0;
        ret = 1;
    }
    while (--n != -1) {
        func_80020DA4(p->ang, &tmp.m[0][0]);
        xy = p->xy;
        tmp.t[0] = xy & 0xFFFF;
        tmp.t[1] = xy >> 16;
        tmp.t[2] = p->z;
        if (skip == 0) {
            gte_g_ld_rot(a);

            gte_g_ld_col(&tmp.m[0][0]);
            gte_nop();
            gte_nop();
            gte_rtir12();
            gte_g_st_col(&o1->m[0][0]);

            gte_g_ld_col(&tmp.m[0][1]);
            gte_nop();
            gte_nop();
            gte_rtir12();
            gte_g_st_col(c1 = (u16 *)o1 + 1);

            gte_g_ld_col(&tmp.m[0][2]);
            gte_nop();
            gte_nop();
            gte_rtir12();
            gte_g_st_col(c2 = (u16 *)o1 + 2);

            o1++;
        }
        gte_g_ld_rot(b);

        gte_g_ld_col(&tmp.m[0][0]);
        gte_nop();
        gte_nop();
        gte_rtir12();
        gte_g_st_col(&o2->m[0][0]);

        gte_g_ld_col(&tmp.m[0][1]);
        gte_nop();
        gte_nop();
        gte_rtir12();
        gte_g_st_col(c1 = (u16 *)o2 + 1);

        gte_g_ld_col(&tmp.m[0][2]);
        gte_nop();
        gte_nop();
        gte_rtir12();
        gte_g_st_col(c2 = (u16 *)o2 + 2);

        gte_g_ld_trans(b);
        gte_g_ld_lv0(&tmp.t[0]);
        gte_nop();
        gte_nop();
        gte_rtv0tr();
        /* the translation base reuses c1: a variable set more than once is not a loop giv, while three
         * separate &o2->t[0] operands are strength-reduced into an extra register (not retail) */
        gte_swc2(25, 0, c1 = (u16 *)&o2->t[0]);
        gte_swc2(26, 4, c1);
        gte_swc2(27, 8, c1);
        o2++;
        p++;
    }
    return ret;
}
