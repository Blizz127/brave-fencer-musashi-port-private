/* Owner re-derivation from retail assembly (clean room, clean input set; D2/D4 grouped GTE macros). */
/* Per-part matrix setup for a zero-terminated list of 8-byte packed part records. For every
 * entry it unpacks the part's three angles, builds the rotation matrix (func_80020DA4), then
 * rotates its columns by two view matrices: unless skip is set, the first view matrix gives a
 * rotation-only result (o1, 0x20-byte records); the second gives the rotation plus the part
 * position (three signed bytes) rotated and translated by the second view matrix (o2, 0x20-byte
 * records, translation at +0x14). Up to seven parts use scratchpad buffers (returns 1); more
 * use the two RAM buffers (returns 0).
 *
 * 8-byte part record (retail reads):
 *   +0  b0   low nibble = bits 11..8 of ang[1], high nibble = bits 11..8 of ang[2]
 *   +1  b1   ang[1] bits 7..0
 *   +2  b2   ang[2] bits 7..0
 *   +3  s8 x, +4 s8 y, +5 s8 z   position (sign-extended; V0 is loaded straight from the bytes)
 *   +6  u16  ang[0] (all 16 bits kept; func_80020DA4 masks with 0xFFF) */
#include "psx_types.h"
#include "gte_ops.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Mat;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    s8 pos[3];
    u16 a0;
} Part8;

extern Mat D_80074818[];
extern Mat D_80075018[];
extern void func_80020DA4(u16 *ang, s16 *m);

s32 func_80020A28(u32 *list, Part8 *p, Mat *a, Mat *b, s32 skip)
{
    Mat tmp;
    u16 ang[3];
    Mat *o1;
    Mat *o2;
    u16 *c1;
    u16 *c2;
    s32 n;
    s32 ret;
    u32 w;

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
        /* ang[0] is stored before the word is loaded (retail: sh 0x30(sp) precedes lw 0(p));
         * byte 1 is written as (w >> 8) & 0xFF and is the first use of w: the compiler emits it
         * as lbu 1(p) next to the kept lw and does not fold it onto the p+3 giv (probably a
         * combine narrowing after loop.c; not dump-verified), while the nibbles and byte 2
         * stay on the word register (lw 0(p)). */
        ang[0] = p->a0;
        w = *(u32 *)p;
        ang[1] = ((w >> 8) & 0xFF) | ((w & 0xF) << 8);
        ang[2] = ((w >> 16) & 0xFF) | ((w & 0xF0) << 4);
        func_80020DA4(ang, &tmp.m[0][0]);
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
        gte_g_ld_bv0(p->pos); /* p->pos is the p+3 giv: addiu s3,s4,3 before the loop */
        gte_nop();
        gte_nop();
        gte_rtv0tr();
        /* as in func_80020248: the translation base reuses c1 (set more than once, so it is not a
         * loop giv); three separate &o2->t[0] operands would be strength-reduced into an extra
         * register and shift every s-register. */
        gte_swc2(25, 0, c1 = (u16 *)&o2->t[0]);
        gte_swc2(26, 4, c1);
        gte_swc2(27, 8, c1);
        o2++;
        p++;
    }
    return ret;
}
