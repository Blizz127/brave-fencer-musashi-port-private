/* Owner re-derivation from retail assembly (clean room, clean input set; D2 grouped GTE macros). */
/* Object-to-GTE matrix setup: builds the object's rotation matrix from its angle vector,
 * scales its columns by the two scale fields (third axis fixed at 0x1000), adds the object
 * position as the translation and loads the result into the GTE. */
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
} Obj;

extern void func_8004978C(void *rot, void *m);

void func_8001D70C(Obj *o)
{
    Mat m;
    Mat s;
    s32 pad[2]; /* unused: keeps retail's 0x60-byte frame (8 bytes between s and the saved registers) */

    func_8004978C(&o->rot[0], &m);
    s.m[0][0] = o->sx;
    s.m[0][1] = 0;
    s.m[0][2] = 0;
    s.m[1][0] = 0;
    s.m[1][1] = o->sy;
    s.m[1][2] = 0;
    s.m[2][0] = 0;
    s.m[2][1] = 0;
    s.m[2][2] = 0x1000;

    gte_g_ld_rot(&m);

    gte_g_ld_col(&s.m[0][0]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(&m.m[0][0]);

    gte_g_ld_col(&s.m[0][1]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(&m.m[0][1]);

    gte_g_ld_col(&s.m[0][2]);
    gte_nop();
    gte_nop();
    gte_rtir12();
    gte_g_st_col(&m.m[0][2]);

    m.t[0] = o->x;
    m.t[1] = o->y;
    m.t[2] = o->z;
    gte_g_ld_rot(&m);
    gte_g_ld_trans(&m);
}
