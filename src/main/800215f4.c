/* Main-exec range [800215F4,80021D38) from the SLUS executable.
 * SHA256(span)=9da16416ec06d6dbff7d3ffc0038cb06e32e4a9bb7a011fe1e1ee1752d9df434.
 * Word export for the native seam; the body below keeps its
 * own oracle match claim (registry-verified, untouched). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800215F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif
/* GTE instruction macros (vendor/bfm-decomp/include/gte_macros.inc) for GNU as. */
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro rtps\n"
    "    cop2op 0x01, 0x01\n"
    ".endm\n"
    ".macro rtpt\n"
    "    cop2op 0x02, 0x30\n"
    ".endm\n"
    ".macro nclip\n"
    "    cop2op 0x14, 0x06, sf = 0\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

#define gte_ldv0(r0) __asm__ volatile (          \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 )"                           \
    :                                            \
    : "r"( r0 ) )
#define gte_ldv3(r0, r1, r2) __asm__ volatile (  \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 );"                          \
    "lwc2 $2, 0( %1 );"                          \
    "lwc2 $3, 4( %1 );"                          \
    "lwc2 $4, 0( %2 );"                          \
    "lwc2 $5, 4( %2 )"                           \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_rtps() __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt() __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_stsxy(r0) __asm__ volatile (         \
    "swc2 $14, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsxy3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $12, 0( %0 );"                         \
    "swc2 $13, 0( %1 );"                         \
    "swc2 $14, 0( %2 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )            \
    : "memory" )
#define gte_stopz(r0) __asm__ volatile (         \
    "swc2 $24, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
#define gte_stszotz(r0) __asm__ volatile (       \
    "mfc2 $12, $19;"                             \
    "nop;"                                       \
    "sra $12, $12, 2;"                           \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
typedef struct {
    s16 vx, vy, vz, pad;
} SV_215F4;
typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u8  pad08[6];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ u8  pad10[14];
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ u8  *unk20;
    /* 0x24 */ u8  pad24[8];
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u16 unk32;
    /* 0x34 */ s32 unk34;
} Obj_215F4;
extern u8 D_800A6610[];
extern u16 D_800B9A02;
extern void func_8001E094(s32 arg0);
extern void func_8001E378(s32 param_1);
extern void func_800226C0();
extern void func_80023138(s32 *arg0, u8 *col, u8 *pts, u32 *ot);

void func_800215F4(Obj_215F4 *obj)
{
    SV_215F4 v[4];              /* 0x10 */
    s32 xy[36];                 /* 0x30 */
    s32 flag;                   /* 0xC0 */
    s32 otz;                    /* 0xC4 */
    s32 flag2;                  /* 0xC8 */

    u32 *ot;
    u8 *vp;
    /* pinned to the registers the target itself allocates (cookbook 179-F / 347) */
    register s32 i   __asm__("$8");   /* $t0  loop counter, every loop */
    register u8  *q  __asm__("$7");   /* $a3  loop1/3 walked ptr */
    register s32 o1  __asm__("$9");   /* $t1 */
    register s32 o2  __asm__("$10");  /* $t2 */
    register s32 d1  __asm__("$11");  /* $t3 */
    register s32 d2  __asm__("$12");  /* $t4 */
    register s32 d3  __asm__("$13");  /* $t5 */
    register u8  *xb __asm__("$14");  /* $t6 */
    register SV_215F4 *pv1 __asm__("$25");
    register SV_215F4 *pv2 __asm__("$24");
    register SV_215F4 *pv3 __asm__("$15");
    register u16 bx  __asm__("$5");
    register u16 by  __asm__("$4");
    register u16 bz  __asm__("$6");
    register u8  *rs __asm__("$3");
    /* loop2 */
    register SV_215F4 *pw1 __asm__("$13");
    register u8  *xb2 __asm__("$11");
    register s32 *pf  __asm__("$10");
    register s32 *dzp __asm__("$9");
    register s32 e    __asm__("$7");
    register u8  *rw  __asm__("$6");
    /* The three clamp sites: `x & 0xFFF` is computed SEPARATELY IN EACH ARM,
     * never hoisted above the `== 0xC000` test.  reorg then merges the two
     * identical copies into the bne's delay slot -- which is the only way the
     * andi can reuse the $v0 that held the 0xC000 compare constant (a hoisted
     * copy is born BEFORE the bne, so it overlaps the constant and has to take
     * a third register).  In the two inner loops the temp additionally has to
     * be PINNED off c2: fill_slots_from_thread rejects a delay-slot candidate
     * that sets a resource the opposite arm still reads, so an in-place
     * `andi $a0,$a0,0xFFF` over c2's own $a0 blocks the merge and costs +2.
     * `oz` likewise stops the otz load coalescing into dz's pinned $v1. */
    /* loop4 */
    register SV_215F4 *pw4 __asm__("$11");
    register u8  *xb4 __asm__("$10");
    /* loopC */
    register SV_215F4 *pa1 __asm__("$24");
    register SV_215F4 *pa2 __asm__("$15");
    register SV_215F4 *pa3 __asm__("$14");
    register u8  *xbc __asm__("$13");
    register s32 dc3 __asm__("$12");
    register s32 oc2 __asm__("$11");
    register s32 oc1 __asm__("$10");
    register u8  *qc __asm__("$9");
    register u32 dm __asm__("$2");
    register s32 oz __asm__("$2");
    u16 qx;
    u32 k;
    register s32 *pd __asm__("$4");
    register s32 dz __asm__("$3");
    register u32 c2 __asm__("$4");
    s32 *pz;
    u32 t, c;

    ot = (u32 *)(D_800A6610 + D_800B9A02 * 0x4000);
    vp = obj->unk20;
    if (obj->unk34 != 0) {
        func_8001E094((s32)obj);
    } else {
        func_8001E378((s32)obj);
    }

    if (obj->unk04 & 0x100) {
        v[2].vx = 0x10;
        v[3].vx = -0x10;
        v[1].vy = -0x13;
        v[3].vy = 8;
        v[2].vy = 8;
        v[1].vx = 0;
        v[3].vz = 0;
        v[2].vz = 0;
        v[1].vz = 0;
        gte_ldv3(&v[1], &v[2], &v[3]);
        gte_rtpt();
        gte_stflg(&flag);
        if (flag & ~0x1000) {
            return;
        }
        gte_nclip();
        gte_stopz(&otz);
        if (otz <= 0) {
            return;
        }
    }

    v[0].vx = obj->unk2E;
    v[0].vy = obj->unk30;
    v[0].vz = obj->unk32;
    gte_ldv0(&v[0]);
    gte_rtps();
    gte_stsxy(&xy[0]);
    gte_stflg(&flag);
    gte_stszotz(&otz);
    if (flag & ~0x1000) {
        return;
    }

    t = otz + 1;
    c = obj->unk2C;
    if (c & 0xC000) {
        if ((c & 0xC000) == 0xC000) {
            t -= c & 0xFFF;
            if ((s32)t < 0) {
                t = 0;
            }
        } else {
            t += c & 0xFFF;
        }
    }
    if (t < 0x1000) {
        i = 0;
        if ((obj->unk1E & 0x8000) || obj->unk0E != 0) {
            pv1 = &v[1];
            pv2 = &v[2];
            pv3 = &v[3];
            xb = (u8 *)xy;
            d3 = 0x14;
            d2 = 0xC;
            d1 = 4;
            o2 = 0x10;
            o1 = 8;
            q = vp;
            do {
                bx = v[0].vx;
                qx = *(u16 *)(q + 0x10);
                bz = v[0].vz;
                by = v[0].vy;
                v[1].vx = bx + qx;
                v[1].vy = by + *(u16 *)(q + 0x12);
                v[1].vz = bz;
                rs = vp + o1;
                v[2].vx = bx + *(u16 *)(rs + 0x10);
                v[2].vy = by + *(u16 *)(rs + 0x12);
                v[2].vz = bz;
                rs = vp + o2;
                v[3].vx = bx + *(u16 *)(rs + 0x10);
                v[3].vy = by + *(u16 *)(rs + 0x12);
                v[3].vz = bz;
                gte_ldv3(pv1, pv2, pv3);
                gte_rtpt();
                gte_stsxy3(xb + d1, xb + d2, xb + d3);
                d3 += 0x18;
                d2 += 0x18;
                d1 += 0x18;
                o2 += 0x18;
                o1 += 0x18;
                i += 6;
                q += 0x18;
            } while (i < 12);

            i = 1;
            pw1 = &v[1];
            xb2 = (u8 *)xy;
            pf = &flag2;
            dzp = &xy[13];
            e = 8;
            rw = vp + 4;
            do {
                v[1].vx = v[0].vx + *(u16 *)(rw + 0x10);
                v[1].vy = v[0].vy + *(u16 *)(rw + 0x12);
                v[1].vz = v[0].vz;
                gte_ldv0(pw1);
                gte_rtps();
                gte_stsxy(xb2 + e);
                gte_stflg(pf);
                pz = &otz;
                gte_stszotz(pz);
                oz = otz;
                dz = oz + 1;
                c2 = obj->unk2C;
                if (c2 & 0xC000) {
                    k = 0xC000;
                    if ((c2 & 0xC000) == k) {
                        dm = c2 & 0xFFF;
                        dz -= dm;
                        if (dz < 1) {
                            dz = 0;
                        }
                    } else {
                        dm = c2 & 0xFFF;
                        dz += dm;
                    }
                }
                if (dz >= 0x1000) {
                    k = 0xFFF;
                    dz = k;
                }
                pz = &dzp[i >> 1];
                *pz = dz;
                e += 8;
                i += 2;
                rw += 8;
            } while (i < 12);

            if (obj->unk0E != 0) {
                i = 0;
                pv1 = &v[1];
                pv2 = &v[2];
                pv3 = &v[3];
                xb = (u8 *)xy;
                d3 = 0x5C;
                d2 = 0x54;
                d1 = 0x4C;
                o2 = 0x10;
                o1 = 8;
                q = vp;
                v[0].vz = v[0].vz + obj->unk0E;
                do {
                    bx = v[0].vx;
                    qx = *(u16 *)(q + 0x10);
                    bz = v[0].vz;
                    by = v[0].vy;
                    v[1].vx = bx + qx;
                    v[1].vy = by + *(u16 *)(q + 0x12);
                    v[1].vz = bz;
                    rs = vp + o1;
                    v[2].vx = bx + *(u16 *)(rs + 0x10);
                    v[2].vy = by + *(u16 *)(rs + 0x12);
                    v[2].vz = bz;
                    rs = vp + o2;
                    v[3].vx = bx + *(u16 *)(rs + 0x10);
                    v[3].vy = by + *(u16 *)(rs + 0x12);
                    v[3].vz = bz;
                    gte_ldv3(pv1, pv2, pv3);
                    gte_rtpt();
                    gte_stsxy3(xb + d1, xb + d2, xb + d3);
                    d3 += 0x18;
                    d2 += 0x18;
                    d1 += 0x18;
                    o2 += 0x18;
                    o1 += 0x18;
                    i += 6;
                    q += 0x18;
                } while (i < 12);

                i = 1;
                pw4 = &v[1];
                xb4 = (u8 *)xy;
                dzp = &xy[13];
                e = 0x50;
                rw = vp + 4;
                do {
                    v[1].vx = v[0].vx + *(u16 *)(rw + 0x10);
                    v[1].vy = v[0].vy + *(u16 *)(rw + 0x12);
                    v[1].vz = v[0].vz;
                    gte_ldv0(pw4);
                    gte_rtps();
                    gte_stsxy(xb4 + e);
                    pz = &flag2;
                    gte_stflg(pz);
                    pz = &otz;
                    gte_stszotz(pz);
                    oz = otz;
                    dz = oz + 1;
                    c2 = obj->unk2C;
                    if (c2 & 0xC000) {
                        k = 0xC000;
                        if ((c2 & 0xC000) == k) {
                            dm = c2 & 0xFFF;
                            dz -= dm;
                            if (dz < 1) {
                                dz = 0;
                            }
                        } else {
                            dm = c2 & 0xFFF;
                            dz += dm;
                        }
                    }
                    if (dz >= 0x1000) {
                        k = 0xFFF;
                        dz = k;
                    }
                    pd = &dzp[i >> 1];
                    if (dz < *pd) {
                        *pd = dz;
                    }
                    e += 8;
                    i += 2;
                    rw += 8;
                } while (i < 12);
                func_80023138((s32 *)obj, vp, (u8 *)xy, ot);
            } else {
                func_800226C0((s32 *)obj, vp, (u8 *)xy, ot);
            }
        } else {
            pa1 = &v[1];
            pa2 = &v[2];
            pa3 = &v[3];
            xbc = (u8 *)xy;
            dc3 = 0xC;
            oc2 = 8;
            oc1 = 4;
            qc = vp;
            do {
                bx = v[0].vx;
                qx = *(u16 *)(qc + 0x10);
                bz = v[0].vz;
                by = v[0].vy;
                v[1].vx = bx + qx;
                v[1].vy = by + *(u16 *)(qc + 0x12);
                v[1].vz = bz;
                rs = vp + oc1;
                v[2].vx = bx + *(u16 *)(rs + 0x10);
                v[2].vy = by + *(u16 *)(rs + 0x12);
                v[2].vz = bz;
                rs = vp + oc2;
                v[3].vx = bx + *(u16 *)(rs + 0x10);
                v[3].vy = by + *(u16 *)(rs + 0x12);
                v[3].vz = bz;
                gte_ldv3(pa1, pa2, pa3);
                gte_rtpt();
                gte_stsxy3(xbc + oc1, xbc + oc2, xbc + dc3);
                dc3 += 0xC;
                oc2 += 0xC;
                oc1 += 0xC;
                i += 3;
                qc += 0xC;
            } while (i < 12);
            func_800226C0((s32 *)obj, vp, (u8 *)xy, ot + t);
        }
    }
}
