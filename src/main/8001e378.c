/* Owner re-derivation from retail assembly (clean room, clean input set; D2 grouped GTE macros). */
/* Object-to-view matrix setup: builds the object's rotation matrix from its angle vector,
 * scales its columns by the three scale fields, uses the object position as translation,
 * composes the result with the global view matrix D_800AF648 (rotation product, and the
 * rotated translation plus the view translation) and loads it into the GTE. */
#include "psx_types.h"
#include "gte_ops.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Mat;

typedef struct {
    u8 pad0[8];
    s16 x;
    s16 y;
    s16 z;
    u16 padE;
    s16 rot[3];
    u16 pad16;
    u16 sx;
    u16 sy;
    u16 sz;
} Obj;

extern Mat D_800AF648;
extern void func_8004978C(void *rot, void *m);

void func_8001E378(Obj *o)
{
    Mat s;
    Mat m;
    Mat *mp;
    Mat *cam;
    u16 *c1;
    u16 *c2;

    mp = &m;
    func_8004978C(&o->rot[0], mp);
    s.m[0][0] = o->sx;
    s.m[0][1] = 0;
    s.m[0][2] = 0;
    s.m[1][0] = 0;
    s.m[1][1] = o->sy;
    s.m[1][2] = 0;
    s.m[2][0] = 0;
    s.m[2][1] = 0;
    s.m[2][2] = o->sz;
    cam = &D_800AF648;

    /* object matrix times the scale matrix, column by column; the column pointers are formed
     * in the store operands so they land between the mvmva and the store group, as in retail */
    gte_g_ld_rot(mp);

    gte_g_ld_col(&s.m[0][0]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(&mp->m[0][0]);

    gte_g_ld_col(&s.m[0][1]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(c1 = (u16 *)mp + 1);

    gte_g_ld_col(&s.m[0][2]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(c2 = (u16 *)mp + 2);

    m.t[0] = o->x;
    m.t[1] = o->y;
    m.t[2] = o->z;

    /* view matrix times the result, in place */
    gte_g_ld_rot(cam);

    gte_g_ld_col(mp);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(mp);

    gte_g_ld_col(c1);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(c1);

    gte_g_ld_col(c2);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(c2);

    /* position rotated by the view matrix plus the view translation */
    gte_g_ld_trans(cam);
    gte_g_ld_lv0(&m.t[0]);
    gte_nop();
    gte_nop();
    gte_rtv0tr();
    gte_swc2(25, 0, &m.t[0]);
    gte_swc2(26, 4, &m.t[0]);
    gte_swc2(27, 8, &m.t[0]);

    gte_g_ld_rot(mp);
    gte_g_ld_trans(mp);
}
