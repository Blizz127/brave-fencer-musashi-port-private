/* PsyCross-backed Psy-Q wrappers (status PSYCROSS in bfm_psyq_compat.def).
 *
 * Build with -DBFM_PLAT_WITH_PSYCROSS, C11, -include assert.h and
 * -I tools/third_party/psycross/include.
 *
 * GTE state: PsyCross's libgte works on the process-wide gteRegs bank that
 * port-int's gte_owner leases for the interpreter, so these calls share the
 * guest's cop2 state. Every wrapper that reads or writes that bank runs
 * inside bfm_psyq_gte_begin()/end() (the lease bridge) and refuses without
 * it. Pointer arguments are guest addresses (translated with size checks).
 * PsyCross declares some out-parameters as `long *` (8 bytes on LP64), so
 * those go through host temporaries and are stored back as 32-bit words. */
#include "bfm_psyq_compat.h"
#include "../bfm_plat_mods.h"
#ifdef MUSASHI_STRICT_NATIVE
#include "../../include/musashi_strict.h"
#endif

#include <psx/types.h>
#include <psx/libgte.h>
#include <psx/gtereg.h>
#include <psx/inline_c.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Defined in PsyCross LIBGTE.C but not declared in its libgte.h. Weak:
 * builds that replace PsyCross's LIBGTE with their own GTE owner (native
 * lane) don't link it, and the wrapper then refuses so the retail code
 * runs instead. */
#if defined(__GNUC__) || defined(__clang__)
extern MATRIX *CompMatrixLV(MATRIX *m0, MATRIX *m1, MATRIX *m2) __attribute__((weak));
#define BFM_HAVE_COMPMATRIXLV() (CompMatrixLV != NULL)
#else
extern MATRIX *CompMatrixLV(MATRIX *m0, MATRIX *m1, MATRIX *m2);
#define BFM_HAVE_COMPMATRIXLV() 1
#endif

#define A(n) bfm_psyq_arg(r, n)
#define P(addr, size) bfm_psyq_ptr((addr), (size))

static void put32(uint32_t addr, int32_t v) {
    uint8_t *p = (uint8_t *)P(addr, 4);
    if (!p) return;
    p[0] = (uint8_t)v; p[1] = (uint8_t)((uint32_t)v >> 8);
    p[2] = (uint8_t)((uint32_t)v >> 16); p[3] = (uint8_t)((uint32_t)v >> 24);
}

/* ---- stateless ---- */

/* ratan2 and RotMatrixX/Y/Z are exact HLE in bfm_psyq_libgte.c over the
 * guest's own tables: linking PsyCross's versions would pull LIBGTE.C's
 * rcossin/ratan tables (identical to the game's) into the port. */

/* RotMatrixYXZ is exact in bfm_psyq_libgte.c: PsyCross's differs from the
 * retail code by 1-2 in some entries. */

/* ---- GTE state (bridge) ---- */

#define GTE_BEGIN() do { if (!bfm_psyq_gte_begin()) return 0; } while (0)
#define GTE_END(cmds) bfm_psyq_gte_end(cmds)

int bfm_psyq_InitGeom(uint32_t *r) {
    (void)r;
    GTE_BEGIN();
    InitGeom();
    GTE_END(0);
    return 1;
}

/* 80053AD8 SetFarColor(r, g, b): FC = (r, g, b) << 4 (CTC2 21..23). Not a
 * compat row: the strict frame driver's GsInitGraph HLE calls it (B27). */
int bfm_psyq_SetFarColor(uint32_t *r) {
    GTE_BEGIN();
    SetFarColor((int)A(0), (int)A(1), (int)A(2));
    GTE_END(0);
    return 1;
}

int bfm_psyq_SetGeomOffset(uint32_t *r) {
    GTE_BEGIN();
    SetGeomOffset((int)(int16_t)A(0), (int)(int16_t)A(1));
    GTE_END(0);
    return 1;
}

int bfm_psyq_SetGeomScreen(uint32_t *r) {
    GTE_BEGIN();
    SetGeomScreen((int)(A(0) & 0xFFFFu));
    GTE_END(0);
    return 1;
}

int bfm_psyq_ReadGeomOffset(uint32_t *r) {
    int32_t ofx, ofy;
    if (!P(A(0), 4) || !P(A(1), 4)) return 0;
    GTE_BEGIN();
    ofx = (int32_t)C2_OFX >> 16;
    ofy = (int32_t)C2_OFY >> 16;
    GTE_END(0);
    put32(A(0), ofx);
    put32(A(1), ofy);
    return 1;
}

#define SET_MATRIX(fn, name)                                             \
    int name(uint32_t *r) {                                              \
        MATRIX *m = (MATRIX *)P(A(0), sizeof(MATRIX));                   \
        if (!m) return 0;                                                \
        GTE_BEGIN();                                                     \
        fn(m);                                                           \
        GTE_END(0);                                                      \
        return 1;                                                        \
    }
SET_MATRIX(SetRotMatrix, bfm_psyq_SetRotMatrix)
SET_MATRIX(SetTransMatrix, bfm_psyq_SetTransMatrix)
SET_MATRIX(SetLightMatrix, bfm_psyq_SetLightMatrix)
/* 800538BC SetColorMatrix: not a compat row, the strict driver calls it (B28) */
SET_MATRIX(SetColorMatrix, bfm_psyq_SetColorMatrix)

int bfm_psyq_ReadRotMatrix(uint32_t *r) {
    MATRIX *m = (MATRIX *)P(A(0), sizeof(MATRIX));
    if (!m) return 0;
    GTE_BEGIN();
    gte_ReadRotMatrix(m);
    gte_sttr(m->t);
    GTE_END(0);
    r[2] = A(0);
    return 1;
}

int bfm_psyq_MulMatrix0(uint32_t *r) {
    MATRIX *a = (MATRIX *)P(A(0), sizeof(MATRIX)), *b = (MATRIX *)P(A(1), sizeof(MATRIX));
    MATRIX *c = (MATRIX *)P(A(2), sizeof(MATRIX));
    if (!a || !b || !c) return 0;
    GTE_BEGIN();
    MulMatrix0(a, b, c);
    GTE_END(3);
    r[2] = A(2);
    return 1;
}

int bfm_psyq_MulRotMatrix(uint32_t *r) {
    MATRIX *m = (MATRIX *)P(A(0), sizeof(MATRIX));
    if (!m) return 0;
    GTE_BEGIN();
    MulRotMatrix(m);
    GTE_END(3);
    r[2] = A(0);
    return 1;
}

int bfm_psyq_CompMatrix(uint32_t *r) {
    MATRIX *a = (MATRIX *)P(A(0), sizeof(MATRIX)), *b = (MATRIX *)P(A(1), sizeof(MATRIX));
    MATRIX *c = (MATRIX *)P(A(2), sizeof(MATRIX));
    if (!a || !b || !c) return 0;
    GTE_BEGIN();
    CompMatrix(a, b, c);
    GTE_END(4);
    r[2] = A(2);
    return 1;
}

int bfm_psyq_CompMatrixLV(uint32_t *r) {
    MATRIX *a = (MATRIX *)P(A(0), sizeof(MATRIX)), *b = (MATRIX *)P(A(1), sizeof(MATRIX));
    MATRIX *c = (MATRIX *)P(A(2), sizeof(MATRIX));
    if (!a || !b || !c || !BFM_HAVE_COMPMATRIXLV()) return 0;
    GTE_BEGIN();
    CompMatrixLV(a, b, c);
    GTE_END(4);
    r[2] = A(2);
    return 1;
}

int bfm_psyq_ApplyRotMatrix(uint32_t *r) {
    SVECTOR *v0 = (SVECTOR *)P(A(0), sizeof(SVECTOR));
    VECTOR *v1 = (VECTOR *)P(A(1), sizeof(VECTOR));
    if (!v0 || !v1) return 0;
    GTE_BEGIN();
    ApplyRotMatrix(v0, v1);
    GTE_END(1);
    r[2] = A(1);
    return 1;
}

int bfm_psyq_ApplyRotMatrixLV(uint32_t *r) {
    VECTOR *v0 = (VECTOR *)P(A(0), sizeof(VECTOR));
    VECTOR *v1 = (VECTOR *)P(A(1), sizeof(VECTOR));
    if (!v0 || !v1) return 0;
    GTE_BEGIN();
    ApplyRotMatrixLV(v0, v1);
    GTE_END(3);
    r[2] = A(1);
    return 1;
}

int bfm_psyq_ApplyMatrixSV(uint32_t *r) {
    MATRIX *m = (MATRIX *)P(A(0), sizeof(MATRIX));
    SVECTOR *v0 = (SVECTOR *)P(A(1), sizeof(SVECTOR)), *v1 = (SVECTOR *)P(A(2), sizeof(SVECTOR));
    if (!m || !v0 || !v1) return 0;
    GTE_BEGIN();
    ApplyMatrixSV(m, v0, v1);
    GTE_END(1);
    r[2] = A(2);
    return 1;
}

int bfm_psyq_RotTransSV(uint32_t *r) {
    SVECTOR *v0 = (SVECTOR *)P(A(0), sizeof(SVECTOR)), *v1 = (SVECTOR *)P(A(1), sizeof(SVECTOR));
    long flag = 0;
    if (!v0 || !v1 || !P(A(2), 4)) return 0;
    GTE_BEGIN();
    RotTransSV(v0, v1, &flag);
    GTE_END(1);
    put32(A(2), (int32_t)flag);
    return 1;
}

/* RotTransPers*: PsyCross's own RotTransPers* store the PGXP float x-bits as
 * sxy when USE_PGXP is on (for its float-vertex renderer). The guest expects
 * the packed s16 screen coordinates, so these run the GTE operations on the
 * shared bank and read the integer results back from the registers:
 * SXY0..2 = data 12..14, IR0 = 8, SZ3 = 19, FLAG = control 31. */

static void ldv(int slot, const SVECTOR *v) {
    uint32_t xy = (uint32_t)(uint16_t)v->vx | ((uint32_t)(uint16_t)v->vy << 16);
    MTC2(xy, slot * 2);
    MTC2((uint32_t)(int32_t)v->vz, slot * 2 + 1);
}

/* RotTransPers(v0, sxy, p, flag) -> SZ3 >> 2 */
int bfm_psyq_RotTransPers(uint32_t *r) {
    SVECTOR *v0 = (SVECTOR *)P(A(0), sizeof(SVECTOR));
    int32_t sxy, p, flag, sz;
    if (!v0 || !P(A(1), 4) || !P(A(2), 4) || !P(A(3), 4)) return 0;
    GTE_BEGIN();
    ldv(0, v0);
    doCOP2(0x0180001);                     /* RTPS */
    sxy = (int32_t)MFC2(14);
    p = (int32_t)MFC2(8);
    flag = (int32_t)CFC2(31);
    sz = (int32_t)(MFC2(19) & 0xFFFFu) >> 2;
    GTE_END(1);
    put32(A(1), sxy);
    put32(A(2), p);
    put32(A(3), flag);
    r[2] = (uint32_t)sz;
    return 1;
}

/* RotTransPers3(v0, v1, v2, sxy0, sxy1, sxy2, p, flag) -> SZ3 >> 2 */
int bfm_psyq_RotTransPers3(uint32_t *r) {
    SVECTOR *v[3];
    int32_t sxy[3], p, flag, sz;
    unsigned i;
    for (i = 0; i < 3; i++)
        if (!(v[i] = (SVECTOR *)P(A(i), sizeof(SVECTOR)))) return 0;
    for (i = 3; i < 8; i++)
        if (!P(A(i), 4)) return 0;
    GTE_BEGIN();
    for (i = 0; i < 3; i++) ldv((int)i, v[i]);
    doCOP2(0x0280030);                     /* RTPT */
    for (i = 0; i < 3; i++) sxy[i] = (int32_t)MFC2(12 + (int)i);
    p = (int32_t)MFC2(8);
    flag = (int32_t)CFC2(31);
    sz = (int32_t)(MFC2(19) & 0xFFFFu) >> 2;
    GTE_END(1);
    for (i = 0; i < 3; i++) put32(A(3 + i), sxy[i]);
    put32(A(6), p);
    put32(A(7), flag);
    r[2] = (uint32_t)sz;
    return 1;
}

/* RTPT on v0..v2, RTPS on v3 (inside the bridge); integer results. */
static int32_t rtp4(SVECTOR *const v[4], int32_t sxy[4], int32_t *p, int32_t *flag) {
    unsigned i;
    for (i = 0; i < 3; i++) ldv((int)i, v[i]);
    doCOP2(0x0280030);                     /* RTPT */
    for (i = 0; i < 3; i++) sxy[i] = (int32_t)MFC2(12 + (int)i);
    *flag = (int32_t)CFC2(31);
    ldv(0, v[3]);
    doCOP2(0x0180001);                     /* RTPS */
    sxy[3] = (int32_t)MFC2(14);
    *p = (int32_t)MFC2(8);
    *flag |= (int32_t)CFC2(31);
    return (int32_t)(MFC2(19) & 0xFFFFu) >> 2;
}

/* RotNclip4(v0..v3, sxy0..sxy3, p, otz, flag) at 8004969C, exact to the
 * retail sequence: RTPT v0..v2, *flag = FLAG, NCLIP; MAC0 <= 0 returns MAC0
 * with nothing else stored. Otherwise SXY0..2 -> sxy0..2, RTPS v3,
 * SXY2 -> sxy3, IR0 -> *p, (u16)SZ3 >> 2 -> *otz, *flag = FLAG | the RTPT
 * FLAG, which is also the return value. */
int bfm_psyq_RotNclip4(uint32_t *r) {
    SVECTOR *v[4];
    int32_t sxy[4], p, otz, flag0, flag, mac0;
    unsigned i;
    for (i = 0; i < 4; i++)
        if (!(v[i] = (SVECTOR *)P(A(i), sizeof(SVECTOR)))) return 0;
    for (i = 4; i < 11; i++)
        if (!P(A(i), 4)) return 0;
    GTE_BEGIN();
    for (i = 0; i < 3; i++) ldv((int)i, v[i]);
    doCOP2(0x0280030);                     /* RTPT */
    flag0 = (int32_t)CFC2(31);
    doCOP2(0x1400006);                     /* NCLIP */
    mac0 = (int32_t)MFC2(24);
    if (mac0 <= 0) {
        GTE_END(2);
        put32(A(10), flag0);
        r[2] = (uint32_t)mac0;
        return 1;
    }
    for (i = 0; i < 3; i++) sxy[i] = (int32_t)MFC2(12 + (int)i);
    ldv(0, v[3]);
    doCOP2(0x0180001);                     /* RTPS */
    sxy[3] = (int32_t)MFC2(14);
    p = (int32_t)MFC2(8);
    otz = (int32_t)(MFC2(19) & 0xFFFFu) >> 2;
    flag = (int32_t)CFC2(31) | flag0;
    GTE_END(3);
    for (i = 0; i < 4; i++) put32(A(4 + i), sxy[i]);
    put32(A(8), p);
    put32(A(9), otz);
    put32(A(10), flag);
    r[2] = (uint32_t)flag;
    return 1;
}

/* RotTransPers4(v0..v3, sxy0..sxy3, p, flag) -> SZ3 >> 2 of v3 */
int bfm_psyq_RotTransPers4(uint32_t *r) {
    SVECTOR *v[4];
    int32_t sxy[4], p, flag, sz;
    unsigned i;
    for (i = 0; i < 4; i++)
        if (!(v[i] = (SVECTOR *)P(A(i), sizeof(SVECTOR)))) return 0;
    for (i = 4; i < 10; i++)
        if (!P(A(i), 4)) return 0;
    GTE_BEGIN();
    sz = rtp4(v, sxy, &p, &flag);
    GTE_END(2);
    for (i = 0; i < 4; i++) put32(A(4 + i), sxy[i]);
    put32(A(8), p);
    put32(A(9), flag);
    r[2] = (uint32_t)sz;
    return 1;
}


/* ---- native-lane inline GTE macros (B28; musashi_lane_gte_inline.h) ----
 * MATCH C in overlays embeds PsyQ inline_c.h as asm. The lane rewrites those
 * #defines to these helpers, which run the same MTC2/doCOP2/MFC2 sequence on
 * the shared gteRegs bank under the psyq GTE bridge (same lease as libgte). */
/* Fail closed: without the GTE lease a helper must not silently skip its
 * COP2 work (the lane would continue on stale registers). */
static int lane_gte_lease(void) {
    if (bfm_psyq_gte_begin()) return 1;
#ifdef MUSASHI_STRICT_NATIVE
    musashi_strict_abort("psyq_refused", "lane_gte_inline", 0);
#endif
    return 0;
}
static void lane_gte_ldv_slot(int slot, const void *p) {
    const uint16_t *s = (const uint16_t *)p;
    uint32_t xy = (uint32_t)s[0] | ((uint32_t)s[1] << 16);
    MTC2(xy, slot * 2);
    MTC2((uint32_t)(int32_t)(int16_t)s[2], slot * 2 + 1);
}
static void lane_gte_store32(void *p, uint32_t v) {
    uint8_t *b = (uint8_t *)p;
    b[0] = (uint8_t)v; b[1] = (uint8_t)(v >> 8);
    b[2] = (uint8_t)(v >> 16); b[3] = (uint8_t)(v >> 24);
}
void musashi_lane_gte_ldv0(const void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_ldv_slot(0, r0);
    bfm_psyq_gte_end(0);
}
static uint32_t lane_gte_load32(const void *p) {
    const uint8_t *b = (const uint8_t *)p;
    return (uint32_t)b[0] | ((uint32_t)b[1] << 8) | ((uint32_t)b[2] << 16) | ((uint32_t)b[3] << 24);
}
/* inline_c.h gte_ldlv0: VXY0 = (u16)v[0] | (u16)v[1] << 16 from a long
 * VECTOR's low halves (+0, +4), VZ0 = the word at +8 (lwc2 $1). */
void musashi_lane_gte_ldlv0(const void *r0) {
    const uint8_t *b = (const uint8_t *)r0;
    uint32_t xy = (uint32_t)(b[0] | (b[1] << 8)) | ((uint32_t)(b[4] | (b[5] << 8)) << 16);
    if (!lane_gte_lease()) return;
    MTC2(xy, 0);
    MTC2(lane_gte_load32(b + 8), 1);
    bfm_psyq_gte_end(0);
}
/* gte_ldclmv: IR1..IR3 = the u16 column at +0, +6, +12 of a MATRIX. */
void musashi_lane_gte_ldclmv(const void *r0) {
    const uint8_t *b = (const uint8_t *)r0;
    if (!lane_gte_lease()) return;
    MTC2((uint32_t)(b[0] | (b[1] << 8)), 9);
    MTC2((uint32_t)(b[6] | (b[7] << 8)), 10);
    MTC2((uint32_t)(b[12] | (b[13] << 8)), 11);
    bfm_psyq_gte_end(0);
}
/* gte_rtir: mvmva sf=1 mx=RT v=IR cv=none lm=0 (cop2 0x049E012). */
void musashi_lane_gte_rtir(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x049E012);
    bfm_psyq_gte_end(1);
}
/* gte_rt: mvmva sf=1 mx=RT v=V0 cv=TR lm=0 (cop2 0x0480012). */
void musashi_lane_gte_rtv0(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x0480012);
    bfm_psyq_gte_end(1);
}

/* inline_c.h gte_rtv0: mvmva sf=1 mx=RT v=V0 cv=none (no translation). */
void musashi_lane_gte_rtv0_notr(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x0486012);
    bfm_psyq_gte_end(1);
}
static void lane_gte_store16(void *p, uint32_t v) {
    uint8_t *b = (uint8_t *)p;
    b[0] = (uint8_t)v; b[1] = (uint8_t)(v >> 8);
}
/* gte_stclmv: the MATRIX column at +0, +6, +12 = IR1..IR3 (sh). */
void musashi_lane_gte_stclmv(void *r0) {
    uint8_t *b = (uint8_t *)r0;
    if (!lane_gte_lease()) return;
    lane_gte_store16(b + 0, MFC2(9));
    lane_gte_store16(b + 6, MFC2(10));
    lane_gte_store16(b + 12, MFC2(11));
    bfm_psyq_gte_end(0);
}
/* gte_stlvnl: MAC1..MAC3 (swc2 $25..$27) to a long VECTOR. */
void musashi_lane_gte_stlvnl(void *r0) {
    uint8_t *b = (uint8_t *)r0;
    if (!lane_gte_lease()) return;
    lane_gte_store32(b + 0, MFC2(25));
    lane_gte_store32(b + 4, MFC2(26));
    lane_gte_store32(b + 8, MFC2(27));
    bfm_psyq_gte_end(0);
}
/* gte_SetRotMatrix: CTC2 $0..$4 from the MATRIX words +0..+16. */
void musashi_lane_gte_SetRotMatrix(const void *r0) {
    const uint8_t *b = (const uint8_t *)r0;
    int k;
    if (!lane_gte_lease()) return;
    for (k = 0; k < 5; ++k) CTC2(lane_gte_load32(b + 4 * k), k);
    bfm_psyq_gte_end(0);
}
/* gte_SetTransMatrix: CTC2 $5..$7 from the MATRIX words +20..+28. */
void musashi_lane_gte_SetTransMatrix(const void *r0) {
    const uint8_t *b = (const uint8_t *)r0;
    int k;
    if (!lane_gte_lease()) return;
    for (k = 0; k < 3; ++k) CTC2(lane_gte_load32(b + 20 + 4 * k), 5 + k);
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_ldv3(const void *r0, const void *r1, const void *r2) {
    if (!lane_gte_lease()) return;
    lane_gte_ldv_slot(0, r0);
    lane_gte_ldv_slot(1, r1);
    lane_gte_ldv_slot(2, r2);
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_ldv3c(const void *r0) {
    const uint8_t *b = (const uint8_t *)r0;
    if (!lane_gte_lease()) return;
    lane_gte_ldv_slot(0, b + 0);
    lane_gte_ldv_slot(1, b + 8);
    lane_gte_ldv_slot(2, b + 16);
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_rtps(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x0180001);
    bfm_psyq_gte_end(1);
}
void musashi_lane_gte_rtpt(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x0280030);
    bfm_psyq_gte_end(1);
}
void musashi_lane_gte_nclip(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x01400006);
    bfm_psyq_gte_end(1);
}
void musashi_lane_gte_stsxy(void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(14));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsxy3(void *r0, void *r1, void *r2) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(12));
    lane_gte_store32(r1, MFC2(13));
    lane_gte_store32(r2, MFC2(14));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsxy3c(void *r0) {
    uint8_t *b = (uint8_t *)r0;
    if (!lane_gte_lease()) return;
    lane_gte_store32(b + 0, MFC2(12));
    lane_gte_store32(b + 4, MFC2(13));
    lane_gte_store32(b + 8, MFC2(14));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsz3(void *r0, void *r1, void *r2) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(17));
    lane_gte_store32(r1, MFC2(18));
    lane_gte_store32(r2, MFC2(19));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsz4(void *r0, void *r1, void *r2, void *r3) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(16));
    lane_gte_store32(r1, MFC2(17));
    lane_gte_store32(r2, MFC2(18));
    lane_gte_store32(r3, MFC2(19));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsxy0(void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(12));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsxy1(void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(13));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsz(void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(19));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stszotz(void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, (uint32_t)((int32_t)(MFC2(19) & 0xFFFFu) >> 2));
    bfm_psyq_gte_end(0);
}
/* MUSASHI_TRACE_GTEFLAG=1: histogram of FLAG values read by stflg (exit). */
static unsigned long g_flag_hist_n[64];
static uint32_t g_flag_hist_v[64];
static void flag_hist_dump(void) {
    int i;
    for (i = 0; i < 64 && g_flag_hist_n[i]; i++)
        fprintf(stderr, "native_boot: GTEFLAG %08x x%lu\n", g_flag_hist_v[i], g_flag_hist_n[i]);
}
static void flag_hist(uint32_t v) {
    static int on = -1;
    int i;
    if (on < 0) { on = getenv("MUSASHI_TRACE_GTEFLAG") != NULL; if (on) atexit(flag_hist_dump); }
    if (!on) return;
    for (i = 0; i < 64; i++) {
        if (!g_flag_hist_n[i]) { g_flag_hist_v[i] = v; g_flag_hist_n[i] = 1; return; }
        if (g_flag_hist_v[i] == v) { g_flag_hist_n[i]++; return; }
    }
}
void musashi_lane_gte_stflg(void *r0) {
    if (!lane_gte_lease()) return;
    flag_hist(CFC2(31));
    lane_gte_store32(r0, CFC2(31));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stopz(void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(24));
    bfm_psyq_gte_end(0);
}

/* inline_c.h gte_ldrgb: RGBC (data reg 6) = the word at r0. */
void musashi_lane_gte_ldrgb(const void *r0) {
    if (!lane_gte_lease()) return;
    MTC2(lane_gte_load32(r0), 6);
    bfm_psyq_gte_end(0);
}
/* gte_ncct: normal colour colour, triple (cop2 0x118043F). */
void musashi_lane_gte_ncct(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x118043F);
    bfm_psyq_gte_end(1);
}
/* gte_nccs: normal colour colour, single (cop2 0x108041B, gte_macros.inc
 * `cop2op 0x10,0x1B,lm=1`). */
void musashi_lane_gte_nccs(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x108041B);
    bfm_psyq_gte_end(1);
}
/* gte_strgb: the word at r0 = RGB2 (data reg 22). */
void musashi_lane_gte_strgb(void *r0) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(22));
    bfm_psyq_gte_end(0);
}
/* POLY_G3 stores: SXY0-2 to +8/+16/+24, RGB0-2 to +4/+12/+20. */
void musashi_lane_gte_stsxy3_g3(void *r0) {
    uint8_t *b = (uint8_t *)r0;
    if (!lane_gte_lease()) return;
    lane_gte_store32(b + 8, MFC2(12));
    lane_gte_store32(b + 16, MFC2(13));
    lane_gte_store32(b + 24, MFC2(14));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_avsz3(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x158002D);
    bfm_psyq_gte_end(1);
}
void musashi_lane_gte_avsz4(void) {
    if (!lane_gte_lease()) return;
    doCOP2(0x168002E);
    bfm_psyq_gte_end(1);
}
void musashi_lane_gte_stotz(void *r0) {        /* swc2 $7 */
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(7));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsxy2(void *r0) {       /* swc2 $14 */
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(14));
    bfm_psyq_gte_end(0);
}
static void lane_gte_stsxy3_at(void *r0, unsigned a, unsigned b, unsigned c) {
    uint8_t *p = (uint8_t *)r0;
    if (!lane_gte_lease()) return;
    lane_gte_store32(p + a, MFC2(12));
    lane_gte_store32(p + b, MFC2(13));
    lane_gte_store32(p + c, MFC2(14));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_stsxy3_f4(void *r0) { lane_gte_stsxy3_at(r0, 8, 12, 16); }
void musashi_lane_gte_stsxy3_ft4(void *r0) { lane_gte_stsxy3_at(r0, 8, 16, 24); }
void musashi_lane_gte_stsxy3_gt4(void *r0) { lane_gte_stsxy3_at(r0, 8, 20, 32); }
void musashi_lane_gte_strgb3(void *r0, void *r1, void *r2) {
    if (!lane_gte_lease()) return;
    lane_gte_store32(r0, MFC2(20));
    lane_gte_store32(r1, MFC2(21));
    lane_gte_store32(r2, MFC2(22));
    bfm_psyq_gte_end(0);
}
void musashi_lane_gte_strgb3_g3(void *r0) {
    uint8_t *b = (uint8_t *)r0;
    if (!lane_gte_lease()) return;
    lane_gte_store32(b + 4, MFC2(20));
    lane_gte_store32(b + 12, MFC2(21));
    lane_gte_store32(b + 20, MFC2(22));
    bfm_psyq_gte_end(0);
}

/* ---- libgs wrappers over the GTE (bridge) ---- */

/* GsSetLsMatrix(m) = SetRotMatrix(m); SetTransMatrix(m) */
int bfm_psyq_GsSetLsMatrix(uint32_t *r) {
    MATRIX *m = (MATRIX *)P(A(0), sizeof(MATRIX));
    if (!m) return 0;
    GTE_BEGIN();
    SetRotMatrix(m);
    SetTransMatrix(m);
    GTE_END(0);
    return 1;
}

/* GsSetProjection(h) = SetGeomScreen(h) */
int bfm_psyq_GsSetProjection(uint32_t *r) {
    GTE_BEGIN();
    SetGeomScreen((int)(A(0) & 0xFFFFu));
    GTE_END(0);
    return 1;
}

/* SetBackColor(r, g, b): RBK/GBK/BBK = component << 4 (retail func_800491FC) */
int bfm_psyq_SetBackColor(uint32_t *r) {
    GTE_BEGIN();
    CTC2(A(0) << 4, 13);
    CTC2(A(1) << 4, 14);
    CTC2(A(2) << 4, 15);
    GTE_END(0);
    return 1;
}

/* GsSetAmbient(r, g, b) = SetBackColor(r >> 4, g >> 4, b >> 4) */
int bfm_psyq_GsSetAmbient(uint32_t *r) {
    GTE_BEGIN();
    CTC2((uint32_t)(((int32_t)A(0) >> 4) << 4), 13);
    CTC2((uint32_t)(((int32_t)A(1) >> 4) << 4), 14);
    CTC2((uint32_t)(((int32_t)A(2) >> 4) << 4), 15);
    GTE_END(0);
    return 1;
}

/* ---- matrix helpers the libgs coordinate code uses ---- */

/* ApplyMatrixLV(m, v0, v1) */
int bfm_psyq_ApplyMatrixLV(uint32_t *r) {
    MATRIX *m = (MATRIX *)P(A(0), sizeof(MATRIX));
    VECTOR *v0 = (VECTOR *)P(A(1), 12), *v1 = (VECTOR *)P(A(2), 12);
    VECTOR out;
    if (!m || !v0 || !v1) return 0;
    GTE_BEGIN();
    ApplyMatrixLV(m, v0, &out);            /* temp: v1 may alias v0; pad not written */
    GTE_END(2);
    v1->vx = out.vx; v1->vy = out.vy; v1->vz = out.vz;
    r[2] = A(2);
    return 1;
}

/* The retail MulMatrix/MulMatrix2 (func_80048D9C/80048EAC) store only the
 * rotation: words 0..3 plus `swc2 IR3` at +0x10, so the pad becomes the sign
 * extension of m[2][2] and t is untouched. PsyCross's versions copy a whole
 * temporary MATRIX (t included, uninitialised) over the destination, so these
 * wrap them to restore t and set the pad the retail way. */
static void mul_rot_only(MATRIX *dst, MATRIX *a, MATRIX *b, int into_second) {
    int t[3];
    memcpy(t, dst->t, sizeof t);
    if (into_second) MulMatrix2(a, b); else MulMatrix(a, b);
    memcpy(dst->t, t, sizeof t);
    {
        uint8_t *m = (uint8_t *)(void *)dst;
        int16_t m22 = (int16_t)(m[0x10] | (m[0x11] << 8));
        m[0x12] = m[0x13] = (uint8_t)(m22 < 0 ? 0xFF : 0x00);
    }
}

/* MulMatrix(m0, m1): m0 = m0 * m1 */
int bfm_psyq_MulMatrix(uint32_t *r) {
    MATRIX *a = (MATRIX *)P(A(0), sizeof(MATRIX)), *b = (MATRIX *)P(A(1), sizeof(MATRIX));
    if (!a || !b) return 0;
    GTE_BEGIN();
    mul_rot_only(a, a, b, 0);
    GTE_END(3);
    r[2] = A(0);
    return 1;
}

/* MulMatrix2(m0, m1): m1 = m0 * m1 */
int bfm_psyq_MulMatrix2(uint32_t *r) {
    MATRIX *a = (MATRIX *)P(A(0), sizeof(MATRIX)), *b = (MATRIX *)P(A(1), sizeof(MATRIX));
    if (!a || !b) return 0;
    GTE_BEGIN();
    mul_rot_only(b, a, b, 1);
    GTE_END(3);
    r[2] = A(1);
    return 1;
}

/* 80052F04 GsSetLightMatrix(mp) (libgs4): retail is
 * SetLightMatrix(MulMatrix2(&GsLIGHTWSMATRIX, mp)) with GsLIGHTWSMATRIX at
 * D_800A63F0, so mp's rotation becomes LIGHTWS * mp (t kept, pad = the sign
 * extension of m[2][2], as MulMatrix2 stores it), the GTE rotation matrix is
 * left at LIGHTWS (MulMatrix2's ctc2 $0..$4) and the light matrix (ctc2
 * $8..$12) is the product. v0 stays mp. */
#define GS_LIGHTWSMATRIX 0x800A63F0u
int bfm_psyq_GsSetLightMatrix(uint32_t *r) {
    uint32_t mp = A(0);
    MATRIX *lw = (MATRIX *)P(GS_LIGHTWSMATRIX, sizeof(MATRIX));
    MATRIX *m = (MATRIX *)P(mp, sizeof(MATRIX));
    if (!lw || !m) return 0;
    GTE_BEGIN();
    mul_rot_only(m, lw, m, 1);
    SetLightMatrix(m);
    GTE_END(3);
    r[2] = mp;
    return 1;
}

/* ---- PushMatrix / PopMatrix on the retail guest-RAM stack ----
 * func_8004867C / func_8004871C: byte offset at D_8006DC18, 20 x 32-byte
 * slots at D_8006DC1C; a slot holds cop2 control 0..7 (rotation + translation)
 * as raw words. Overflow / underflow only print in the retail code. */
#define GTE_MSTACK_OFS  0x8006DC18u
#define GTE_MSTACK_BASE 0x8006DC1Cu
#define GTE_MSTACK_SIZE 0x280

static int get32(uint32_t a, uint32_t *v) {
    uint8_t *p = (uint8_t *)P(a, 4);
    if (!p) return 0;
    *v = (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
    return 1;
}

int bfm_psyq_PushMatrix(uint32_t *r) {
    uint32_t ofs;
    int i;
    (void)r;
    if (!get32(GTE_MSTACK_OFS, &ofs) || !P(GTE_MSTACK_BASE, GTE_MSTACK_SIZE)) return 0;
    /* full: the retail code saves $ra to D_8006DC0C and printf()s; let it */
    if ((int32_t)ofs >= GTE_MSTACK_SIZE) return 0;
    GTE_BEGIN();
    for (i = 0; i < 8; i++) put32(GTE_MSTACK_BASE + ofs + 4u * (uint32_t)i, (int32_t)CFC2(i));
    GTE_END(0);
    put32(GTE_MSTACK_OFS, (int32_t)(ofs + 0x20u));
    return 1;
}

int bfm_psyq_PopMatrix(uint32_t *r) {
    uint32_t ofs, w;
    int i;
    (void)r;
    if (!get32(GTE_MSTACK_OFS, &ofs) || !P(GTE_MSTACK_BASE, GTE_MSTACK_SIZE)) return 0;
    /* empty: the retail error path (saves $ra, printf) runs instead */
    if ((int32_t)ofs <= 0) return 0;
    if (ofs > GTE_MSTACK_SIZE) return 0;             /* corrupt offset: let the retail code decide */
    ofs -= 0x20u;
    GTE_BEGIN();
    put32(GTE_MSTACK_OFS, (int32_t)ofs);
    for (i = 0; i < 8; i++) {
        get32(GTE_MSTACK_BASE + ofs + 4u * (uint32_t)i, &w);
        CTC2(w, i);
    }
    GTE_END(0);
    return 1;
}

/* ---- GsGetLw / GsGetLs / GsGetLws ----
 * GsCOORDINATE2: +0 flag, +4 coord (local), +0x24 workm (cached world),
 * +0x44 param, +0x48 super. The walk follows the game's decomp of
 * func_80054514 exactly: the chain goes into the guest array D_800C6D48, the
 * cache stamp is the frame counter D_800C7C70, flag 0 marks a node dirty, a
 * root whose flag is neither restarts from the node above the deepest dirty
 * one (or reuses the input's cache when nothing is dirty). */
#define GS_COORD_CHAIN  0x800C6D48u
#define GS_FRAME_COUNT  0x800C7C70u
#define GS_WSMATRIX     0x800AE688u
#define GS_CHAIN_MAX    100

/* func_80053050: m1 = m1 (x) m2 (rotation product into m1, t1 += R1 * t2) */
static void coord_mul_into_first(MATRIX *m1, MATRIX *m2) {
    VECTOR v;
    ApplyMatrixLV(m1, (VECTOR *)(void *)m2->t, &v);
    mul_rot_only(m1, m1, m2, 0);
    m1->t[0] += v.vx; m1->t[1] += v.vy; m1->t[2] += v.vz;
}

/* func_80052FCC: m2 = m1 (x) m2 (rotation product into m2, t2 = R1 * t2 + t1) */
static void coord_mul_into_second(MATRIX *m1, MATRIX *m2) {
    VECTOR v;
    ApplyMatrixLV(m1, (VECTOR *)(void *)m2->t, &v);
    mul_rot_only(m2, m1, m2, 1);
    m2->t[0] = v.vx + m1->t[0]; m2->t[1] = v.vy + m1->t[1]; m2->t[2] = v.vz + m1->t[2];
}

static uint8_t *coord(uint32_t a) { return (uint8_t *)P(a, 0x4C); }
static uint32_t cflag(uint8_t *c) { return (uint32_t)c[0] | ((uint32_t)c[1] << 8) | ((uint32_t)c[2] << 16) | ((uint32_t)c[3] << 24); }
static void set_cflag(uint8_t *c, uint32_t v) { c[0] = (uint8_t)v; c[1] = (uint8_t)(v >> 8); c[2] = (uint8_t)(v >> 16); c[3] = (uint8_t)(v >> 24); }
static uint32_t csuper(uint8_t *c) { return (uint32_t)c[0x48] | ((uint32_t)c[0x49] << 8) | ((uint32_t)c[0x4A] << 16) | ((uint32_t)c[0x4B] << 24); }

/* Returns 1 with *out = the world matrix of `input`; 0 if a pointer is bad
 * (checked before anything is written). */
static int gs_get_lw(uint32_t input, MATRIX *out) {
    uint32_t chain[GS_CHAIN_MAX + 1], frame, a = input;
    int depth = 0, dirty = 100, n, i;
    uint8_t *c;
    /* validate the whole chain first so a refusal changes nothing */
    for (n = 0, a = input; ; n++) {
        if (n > GS_CHAIN_MAX || !(c = coord(a))) return 0;
        if (csuper(c) == 0) break;
        a = csuper(c);
    }
    if (!P(GS_COORD_CHAIN, 4u * (uint32_t)(n + 1)) || !get32(GS_FRAME_COUNT, &frame)) return 0;
    a = input;
    for (;;) {
        c = coord(a);
        chain[depth] = a;
        put32(GS_COORD_CHAIN + 4u * (uint32_t)depth, (int32_t)a);
        if (csuper(c) == 0) {
            if (cflag(c) == frame || cflag(c) == 0) {
                memcpy(c + 0x24, c + 4, 32);
                memcpy(out, c + 0x24, 32);
                set_cflag(c, frame);
            } else if (dirty == 100) {
                memcpy(out, coord(chain[0]) + 0x24, 32);
                depth = 0;
            } else {
                depth = dirty + 1;
                memcpy(out, coord(chain[depth]) + 0x24, 32);
            }
            break;
        }
        if (cflag(c) == frame) {
            memcpy(out, c + 0x24, 32);
            break;
        }
        if (cflag(c) == 0) dirty = depth;
        a = csuper(c);
        depth++;
    }
    for (i = depth; i > 0; i--) {
        uint8_t *node = coord(chain[i - 1]);
        coord_mul_into_first(out, (MATRIX *)(void *)(node + 4));
        memcpy(node + 0x24, out, 32);
        set_cflag(node, frame);
    }
    return 1;
}

/* GsGetLw(GsCOORDINATE2 *coord, MATRIX *m) */
int bfm_psyq_GsGetLw(uint32_t *r) {
    MATRIX *m = (MATRIX *)P(A(1), sizeof(MATRIX));
    MATRIX out;
    int ok;
    if (!m) return 0;
    GTE_BEGIN();
    ok = gs_get_lw(A(0), &out);
    if (ok) memcpy(m, &out, sizeof out);
    GTE_END(ok ? 5 : 0);
    return ok;
}

/* GsGetLs(coord, m): m = GsWSMATRIX (x) Lw */
int bfm_psyq_GsGetLs(uint32_t *r) {
    MATRIX *m = (MATRIX *)P(A(1), sizeof(MATRIX)), *ws = (MATRIX *)P(GS_WSMATRIX, sizeof(MATRIX));
    MATRIX out;
    int ok;
    if (!m || !ws) return 0;
    GTE_BEGIN();
    ok = gs_get_lw(A(0), &out);
    if (ok) {
        coord_mul_into_second(ws, &out);
        memcpy(m, &out, sizeof out);
    }
    GTE_END(ok ? 8 : 0);
    return ok;
}

/* GsGetLws(coord, lw, ls): lw = Lw; ls = GsWSMATRIX (x) Lw */
int bfm_psyq_GsGetLws(uint32_t *r) {
    MATRIX *lw = (MATRIX *)P(A(1), sizeof(MATRIX)), *ls = (MATRIX *)P(A(2), sizeof(MATRIX));
    MATRIX *ws = (MATRIX *)P(GS_WSMATRIX, sizeof(MATRIX));
    MATRIX out, s;
    int ok;
    if (!lw || !ls || !ws) return 0;
    GTE_BEGIN();
    ok = gs_get_lw(A(0), &out);
    if (ok) {
        memcpy(lw, &out, sizeof out);
        s = out;
        coord_mul_into_second(ws, &s);
        memcpy(ls, &s, sizeof s);
    }
    GTE_END(ok ? 8 : 0);
    return ok;
}

/* ReadGeomScreen() -> H (cfc2 $26) */
int bfm_psyq_ReadGeomScreen(uint32_t *r) {
    GTE_BEGIN();
    r[2] = CFC2(26);
    GTE_END(0);
    return 1;
}

/* ---- GsSortSprite ----
 * Follows the game's decomp of func_80051F34. GsSPRITE: +0 attribute,
 * +4 x y, +8 w h, +0xC tpage, +0xE u v, +0x10 cx cy, +0x14 r g b, +0x18 mx my,
 * +0x1C scalex scaley (s16), +0x20 rotate (s32, degrees * 4096).
 * Plain case (attribute bit 27, or no scale/rotate/flip): E1 + SPRT at
 * (x + ofs - mx, y + ofs - my). Otherwise the corners go through the GTE:
 * RotMatrix (0, 0, rotate / 360) from the guest table, ScaleMatrix
 * (scalex, scaley, 0), TransMatrix (x, y, H), SetRot/TransMatrix, RotTransPers4,
 * and a POLY_FT4 with flip-aware UVs. */
#define GS_OUT_PACKET_P 0x800A5E60u
#define GS_DRAW_OFS     0x800A6548u
#define GS_IDMATRIX     0x800AE620u

int bfm_psyq_GsSortSprite(uint32_t *r) {
    uint8_t *sp = (uint8_t *)P(A(0), 0x24), *ofs = (uint8_t *)P(GS_DRAW_OFS, 4);
    uint32_t pkt, attr, next;
    int32_t scale, rot, w, h, mx, my;
    uint8_t *pk;
    if (!sp || !ofs || !get32(GS_OUT_PACKET_P, &pkt) || !(pk = (uint8_t *)P(pkt, 40))) return 0;
    attr = (uint32_t)sp[0] | ((uint32_t)sp[1] << 8) | ((uint32_t)sp[2] << 16) | ((uint32_t)sp[3] << 24);
    w = (uint16_t)(sp[8] | (sp[9] << 8));
    h = (uint16_t)(sp[10] | (sp[11] << 8));
    if ((int32_t)attr < 0 || w == 0 || h == 0) return 1;
    scale = (int32_t)((uint32_t)sp[0x1C] | ((uint32_t)sp[0x1D] << 8) | ((uint32_t)sp[0x1E] << 16) | ((uint32_t)sp[0x1F] << 24));
    rot = (int32_t)((uint32_t)sp[0x20] | ((uint32_t)sp[0x21] << 8) | ((uint32_t)sp[0x22] << 16) | ((uint32_t)sp[0x23] << 24));
    mx = (int16_t)(sp[0x18] | (sp[0x19] << 8));
    my = (int16_t)(sp[0x1A] | (sp[0x1B] << 8));
    {
        uint32_t color = ((uint32_t)sp[0x16] << 16) | ((uint32_t)sp[0x15] << 8) | sp[0x14];
        uint32_t flags = ((attr >> 5) & 0x02000000u) | ((attr << 18) & 0x01000000u);
        uint32_t clut = ((uint32_t)(int32_t)(int16_t)(sp[0x12] | (sp[0x13] << 8)) << 22) |
                        (((uint32_t)(int32_t)(int16_t)(sp[0x10] | (sp[0x11] << 8)) << 12) & 0x3F0000u);
        uint32_t tpage = (uint32_t)(sp[0x0C] | (sp[0x0D] << 8));
        int simple = ((attr >> 27) & 1u) ||
                     (scale == 0x10001000 && rot == 0 && (attr & 0xC00000u) == 0);
        if (simple) {
            int16_t ox = (int16_t)(ofs[0] | (ofs[1] << 8)), oy = (int16_t)(ofs[2] | (ofs[3] << 8));
            int16_t x = (int16_t)(sp[4] | (sp[5] << 8)), y = (int16_t)(sp[6] | (sp[7] << 8));
            put32(pkt + 4, (int32_t)((tpage & 0x1Fu) | ((attr >> 17) & 0x180u) | 0xE1000200u | ((attr >> 23) & 0x60u)));
            put32(pkt + 8, (int32_t)(flags | 0x64000000u | color));
            put32(pkt + 12, (int32_t)(((uint32_t)(uint16_t)(x + ox - mx)) | ((uint32_t)(uint16_t)(y + oy - my) << 16)));
            put32(pkt + 16, (int32_t)(sp[0x0E] | ((uint32_t)sp[0x0F] << 8) | clut));
            put32(pkt + 20, (int32_t)((uint32_t)w | ((uint32_t)h << 16)));
            if (!bfm_psyq_gs_link(pkt, A(1), A(2), 5, &next)) return 0;
        } else {
            uint8_t m[32];
            SVECTOR c0, c1, c2, c3;
            SVECTOR *cv[4];
            int32_t sxy[4], p, flag, v3[3];
            uint8_t u0, u1, v0, v1;
            GTE_BEGIN();
            if (rot == 0) {
                uint8_t *id = (uint8_t *)P(GS_IDMATRIX, 32);
                if (!id) { GTE_END(0); return 0; }
                memcpy(m, id, 32);
            } else {
                int16_t ang[3];
                ang[0] = 0; ang[1] = 0; ang[2] = (int16_t)(rot / 360);
                memset(m, 0, sizeof m);
                if (!bfm_psyq_rotmatrix(ang, m)) { GTE_END(0); return 0; }
            }
            if (scale != 0x10001000) {
                v3[0] = (int16_t)(uint16_t)scale;
                v3[1] = (int16_t)(sp[0x1E] | (sp[0x1F] << 8));
                v3[2] = 0;
                bfm_psyq_scalematrix(m, v3);
            }
            v3[0] = (int16_t)(sp[4] | (sp[5] << 8));
            v3[1] = (int16_t)(sp[6] | (sp[7] << 8));
            v3[2] = (int32_t)CFC2(26);
            bfm_psyq_transmatrix(m, v3);
            SetRotMatrix((MATRIX *)(void *)m);
            SetTransMatrix((MATRIX *)(void *)m);
            c0.vx = (short)-mx; c0.vy = (short)-my; c0.vz = 0;
            c1.vx = (short)(w - mx); c1.vy = (short)-my; c1.vz = 0;
            c2.vx = (short)-mx; c2.vy = (short)(h - my); c2.vz = 0;
            c3.vx = (short)(w - mx); c3.vy = (short)(h - my); c3.vz = 0;
            cv[0] = &c0; cv[1] = &c1; cv[2] = &c2; cv[3] = &c3;
            rtp4(cv, sxy, &p, &flag);
            GTE_END(2);
            if (attr & 0x800000u) { u0 = (uint8_t)(sp[0x0E] + (uint8_t)w - 1); u1 = sp[0x0E]; }
            else { u0 = sp[0x0E]; u1 = (uint8_t)(sp[0x0E] + (uint8_t)w - 1); }
            if (attr & 0x400000u) { v0 = (uint8_t)(sp[0x0F] + (uint8_t)h - 1); v1 = sp[0x0F]; }
            else { v0 = sp[0x0F]; v1 = (uint8_t)(sp[0x0F] + (uint8_t)h - 1); }
            put32(pkt + 4, (int32_t)(flags | 0x2C000000u | color));
            put32(pkt + 8, sxy[0]);
            put32(pkt + 12, (int32_t)(u0 | ((uint32_t)v0 << 8) | clut));
            put32(pkt + 16, sxy[1]);
            put32(pkt + 20, (int32_t)(u1 | ((uint32_t)v0 << 8) | ((tpage & 0x1Fu) << 16) |
                                      ((attr >> 1) & 0x01800000u) | ((attr >> 7) & 0x600000u)));
            put32(pkt + 24, sxy[2]);
            put32(pkt + 28, (int32_t)(u0 | ((uint32_t)v1 << 8)));
            put32(pkt + 32, sxy[3]);
            put32(pkt + 36, (int32_t)(u1 | ((uint32_t)v1 << 8)));
            if (!bfm_psyq_gs_link(pkt, A(1), A(2), 9, &next)) return 0;
        }
        put32(GS_OUT_PACKET_P, (int32_t)next);
    }
    return 1;
}

/* ---- libgs preset sorters (0x8004A414..0x8004CFEC, GsSortObject5's
 * per-type routines) --------------------------------------------------------
 *
 * Called by GsSortObject5 through the guest tables at 0x800A2CF0 as
 *   fn(prim, vert_top, normal_top, packet, n, shift, ot)        (lit slots)
 * and return prim + n * prim_size. Per primitive they transform the TMD
 * vertices (RTPT, plus RTPS for the 4th of a quad), cull on FLAG bit 31 and
 * NCLIP <= 0, take the OT index from AVSZ3/AVSZ4, run NCCS/NCCT for the lit
 * (light 0) slot, rewrite the preset packet's XY (and RGB) words and link it:
 *   slot = ot->org + (((OTZ - ot->offset_word) >> shift) & 0xFFFF) * 4
 *   tag  = len << 24 | (old & 0xFFFFFF); slot = (old & 0xFF000000) | (pkt & 0xFFFFFF)
 * The packet pointer moves by the double-buffered packet stride. GTE
 * commands and register loads keep the retail order (including where RGBC
 * is loaded and the 4th vertex goes into V0 ahead of the NCLIP test), so the
 * cop2 bank ends in the same state. Reconstructed from the retail
 * instruction stream; no Psy-Q source. */
enum { GS5_RGBC_AFTER_RTPT, GS5_RGBC_AFTER_NCLIP, GS5_RGBC_AFTER_RTPS, GS5_RGBC_BEFORE_NCC };
typedef struct Gs5Prim {
    uint8_t quad, gouraud, lit, textured, rgbc_at;
    uint8_t rtps_flag;  /* quads: the RTPS FLAG really is tested (see below) */
    uint8_t psize, pstride, taglen;
    uint8_t vofs[4];    /* u16 vertex index offsets in the TMD primitive */
    uint8_t nofs[4];    /* u16 normal index offsets (lit) */
    uint8_t xy[4];      /* packet XY word offsets */
    uint8_t rgb[4];     /* packet RGB word offsets (lit) */
} Gs5Prim;

static int gs5_ldv(int slot, uint32_t base, uint32_t idx) {
    const void *p = P(base + idx * 8u, 8);
    if (!p) return 0;
    lane_gte_ldv_slot(slot, p);
    return 1;
}
static uint32_t gs5_u16(uint32_t a) {
    const uint8_t *p = (const uint8_t *)P(a, 2);
    return p ? (uint32_t)(p[0] | (p[1] << 8)) : 0u;
}
static int gs5_rgbc(const Gs5Prim *d, uint32_t prim) {
    if (d->textured) {
        const uint8_t *c = (const uint8_t *)P(prim + 3u, 1);
        if (!c) return 0;
        MTC2(0x00808080u | ((uint32_t)c[0] << 24), 6);
    } else {
        const uint8_t *c = (const uint8_t *)P(prim + 4u, 4);
        if (!c) return 0;
        MTC2((uint32_t)c[0] | ((uint32_t)c[1] << 8) | ((uint32_t)c[2] << 16) | ((uint32_t)c[3] << 24), 6);
    }
    return 1;
}

/* MUSASHI_TRACE_GS5RUN=1: per-descriptor flag-cull / nclip-cull / linked counts. */
static struct { const void *d; unsigned long fl, nc, ln; uint32_t code; } g_gsr[24];
static int g_gsr_on = -1;
static void gsr_dump(void) {
    int i;
    for (i = 0; i < 24 && g_gsr[i].d; i++)
        fprintf(stderr, "native_boot: GS5RUN d=%p psize=%u flagcull=%lu nclipcull=%lu linked=%lu pktcode=%02x\n",
                g_gsr[i].d, ((const Gs5Prim *)g_gsr[i].d)->psize, g_gsr[i].fl, g_gsr[i].nc, g_gsr[i].ln, g_gsr[i].code);
}
static int gsr_slot(const void *d) {
    int i;
    if (g_gsr_on < 0) { g_gsr_on = getenv("MUSASHI_TRACE_GS5RUN") != NULL; if (g_gsr_on) atexit(gsr_dump); }
    if (!g_gsr_on) return -1;
    for (i = 0; i < 24; i++) { if (!g_gsr[i].d) g_gsr[i].d = d; if (g_gsr[i].d == d) return i; }
    return -1;
}

static int gs5_run(const Gs5Prim *d, uint32_t *r) {
    int gsr = gsr_slot(d);
    uint32_t prim = A(0), vert = A(1), norm = A(2), pkt = A(3);
    uint32_t n = A(4), shift = A(5), ot = A(6);
    uint32_t org, ofsw, cmds = 0, i;
    /* The light-2 (no lighting) routines sit in the same lit slots and take
     * the same arguments; they just never read normal_top. */
    if (n == 0) { r[2] = prim; return 1; }
    {
        const uint8_t *o = (const uint8_t *)P(ot + 4u, 8);
        if (!o) return 0;
        org = (uint32_t)o[0] | ((uint32_t)o[1] << 8) | ((uint32_t)o[2] << 16) | ((uint32_t)o[3] << 24);
        ofsw = (uint32_t)o[4] | ((uint32_t)o[5] << 8) | ((uint32_t)o[6] << 16) | ((uint32_t)o[7] << 24);
    }
    if (!P(prim, (uint32_t)d->psize * n)) return 0;
    GTE_BEGIN();
#define GS5_FAIL() do { GTE_END(cmds); return 0; } while (0)
    for (i = 0; i < n; ++i, prim += d->psize, pkt += d->pstride) {
        uint32_t otz, slot, old, k;
        uint8_t *sp, *pp;
        for (k = 0; k < 3u; ++k)
            if (!gs5_ldv((int)k, vert, gs5_u16(prim + d->vofs[k]))) GS5_FAIL();
        doCOP2(0x0280030); cmds++;                                    /* RTPT */
        if (d->lit && d->rgbc_at == GS5_RGBC_AFTER_RTPT && !gs5_rgbc(d, prim)) GS5_FAIL();
        if ((int32_t)CFC2(31) < 0) { if (gsr >= 0) g_gsr[gsr].fl++; continue; }
        doCOP2(0x1400006); cmds++;                                    /* NCLIP */
        if (d->lit && d->rgbc_at == GS5_RGBC_AFTER_NCLIP && !gs5_rgbc(d, prim)) GS5_FAIL();
        if (d->quad && !gs5_ldv(0, vert, gs5_u16(prim + d->vofs[3]))) GS5_FAIL();
        if ((int32_t)MFC2(24) <= 0) { if (gsr >= 0) g_gsr[gsr].nc++; continue; }
        if (!(pp = (uint8_t *)P(pkt, (uint32_t)d->taglen * 4u + 4u))) GS5_FAIL();
        if (d->quad) {
            for (k = 0; k < 3u; ++k) lane_gte_store32(pp + d->xy[k], MFC2(12 + k));
            doCOP2(0x0180001); cmds++;                                /* RTPS */
            if (d->lit && d->rgbc_at == GS5_RGBC_AFTER_RTPS && !gs5_rgbc(d, prim)) GS5_FAIL();
            if (d->lit && d->gouraud) {
                if (!gs5_ldv(1, norm, gs5_u16(prim + d->nofs[1])) ||
                    !gs5_ldv(2, norm, gs5_u16(prim + d->nofs[2]))) GS5_FAIL();
            }
            /* G4/GT4 light-0 read FLAG with CFC2 straight into the BLTZ's
             * load-delay slot, so the branch tests the earlier (non-negative)
             * RTPT FLAG: the RTPS result is never culled there. */
            if (d->rtps_flag && (int32_t)CFC2(31) < 0) continue;
            doCOP2(0x168002E); cmds++;                                /* AVSZ4 */
        } else {
            doCOP2(0x158002D); cmds++;                                /* AVSZ3 */
        }
        if (d->lit) {
            if (d->gouraud && !d->quad) {
                for (k = 0; k < 3u; ++k)
                    if (!gs5_ldv((int)k, norm, gs5_u16(prim + d->nofs[k]))) GS5_FAIL();
            } else {
                if (!gs5_ldv(0, norm, gs5_u16(prim + d->nofs[d->gouraud ? 3 : 0]))) GS5_FAIL();
                if (d->rgbc_at == GS5_RGBC_BEFORE_NCC && !gs5_rgbc(d, prim)) GS5_FAIL();
            }
        }
        otz = MFC2(7);
        if (d->lit) {
            if (d->gouraud && !d->quad) {
                doCOP2(0x118043F); cmds++;                            /* NCCT */
            } else {
                doCOP2(0x108041B); cmds++;                            /* NCCS */
                if (d->gouraud) {                                     /* quad: 4th colour, then NCCT */
                    lane_gte_store32(pp + d->rgb[3], MFC2(22));
                    if (!gs5_ldv(0, norm, gs5_u16(prim + d->nofs[0]))) GS5_FAIL();
                    doCOP2(0x118043F); cmds++;
                }
            }
        }
        slot = org + (((otz - ofsw) >> (shift & 31u)) & 0xFFFFu) * 4u;
        if (!(sp = (uint8_t *)P(slot, 4))) GS5_FAIL();
        old = (uint32_t)sp[0] | ((uint32_t)sp[1] << 8) | ((uint32_t)sp[2] << 16) | ((uint32_t)sp[3] << 24);
        lane_gte_store32(pp, ((uint32_t)d->taglen << 24) | (old & 0x00FFFFFFu));
        lane_gte_store32(sp, (old & 0xFF000000u) | (pkt & 0x00FFFFFFu));
        if (gsr >= 0) { g_gsr[gsr].ln++; g_gsr[gsr].code = pp[7]; }
        if (d->quad) lane_gte_store32(pp + d->xy[3], MFC2(14));
        else for (k = 0; k < 3u; ++k) lane_gte_store32(pp + d->xy[k], MFC2(12 + k));
        if (d->lit) {
            if (d->gouraud) for (k = 0; k < 3u; ++k) lane_gte_store32(pp + d->rgb[k], MFC2(20 + k));
            else lane_gte_store32(pp + d->rgb[0], MFC2(22));
        }
    }
#undef GS5_FAIL
    GTE_END(cmds);
    r[2] = prim;
    return 1;
}

/* Gs5Prim: quad, gouraud, lit, textured, rgbc_at, rtps_flag, psize, packet stride, tag len,
 *         vertex idx offsets, normal idx offsets, packet XY offsets, packet RGB offsets */
static const Gs5Prim bfm_psyq_gs5_f3_nl_d = {0, 0, 0, 0, 0, 0,                    16, 40,  4, {10, 12, 14, 0},  {0},              {8, 12, 16, 0},   {0}};
static const Gs5Prim bfm_psyq_gs5_f3_l_d = {0, 0, 1, 0, GS5_RGBC_AFTER_RTPT, 0,  16, 40,  4, {10, 12, 14, 0},  {8, 0, 0, 0},     {8, 12, 16, 0},   {4, 0, 0, 0}};
static const Gs5Prim bfm_psyq_gs5_f4_nl_d = {1, 0, 0, 0, 0, 1,                    20, 48,  5, {10, 12, 14, 16}, {0},              {8, 12, 16, 20},  {0}};
static const Gs5Prim bfm_psyq_gs5_f4_l_d = {1, 0, 1, 0, GS5_RGBC_AFTER_RTPT, 1,  20, 48,  5, {10, 12, 14, 16}, {8, 0, 0, 0},     {8, 12, 16, 20},  {4, 0, 0, 0}};
static const Gs5Prim bfm_psyq_gs5_g3_nl_d = {0, 1, 0, 0, 0, 0,                    20, 56,  6, {10, 14, 18, 0},  {0},              {8, 16, 24, 0},   {0}};
static const Gs5Prim bfm_psyq_gs5_g3_l_d = {0, 1, 1, 0, GS5_RGBC_AFTER_NCLIP, 0, 20, 56,  6, {10, 14, 18, 0},  {8, 12, 16, 0},   {8, 16, 24, 0},   {4, 12, 20, 0}};
static const Gs5Prim bfm_psyq_gs5_g4_nl_d = {1, 1, 0, 0, 0, 1,                    24, 72,  8, {10, 14, 18, 22}, {0},              {8, 16, 24, 32},  {0}};
static const Gs5Prim bfm_psyq_gs5_g4_l_d = {1, 1, 1, 0, GS5_RGBC_BEFORE_NCC, 0,  24, 72,  8, {10, 14, 18, 22}, {8, 12, 16, 20},  {8, 16, 24, 32},  {4, 12, 20, 28}};
static const Gs5Prim bfm_psyq_gs5_ft3_nl_d = {0, 0, 0, 1, 0, 0,                    24, 64,  7, {18, 20, 22, 0},  {0},              {8, 16, 24, 0},   {0}};
static const Gs5Prim bfm_psyq_gs5_ft3_l_d = {0, 0, 1, 1, GS5_RGBC_AFTER_RTPT, 0,  24, 64,  7, {18, 20, 22, 0},  {16, 0, 0, 0},    {8, 16, 24, 0},   {4, 0, 0, 0}};
static const Gs5Prim bfm_psyq_gs5_ft4_nl_d = {1, 0, 0, 1, 0, 1,                    32, 80,  9, {22, 24, 26, 28}, {0},              {8, 16, 24, 32},  {0}};
static const Gs5Prim bfm_psyq_gs5_ft4_l_d = {1, 0, 1, 1, GS5_RGBC_AFTER_RTPS, 1,  32, 80,  9, {22, 24, 26, 28}, {20, 0, 0, 0},    {8, 16, 24, 32},  {4, 0, 0, 0}};
static const Gs5Prim bfm_psyq_gs5_gt3_nl_d = {0, 1, 0, 1, 0, 0,                    28, 80,  9, {18, 22, 26, 0},  {0},              {8, 20, 32, 0},   {0}};
static const Gs5Prim bfm_psyq_gs5_gt3_l_d = {0, 1, 1, 1, GS5_RGBC_AFTER_RTPT, 0,  28, 80,  9, {18, 22, 26, 0},  {16, 20, 24, 0},  {8, 20, 32, 0},   {4, 16, 28, 0}};
static const Gs5Prim bfm_psyq_gs5_gt4_nl_d = {1, 1, 0, 1, 0, 1,                    36, 104, 12, {22, 26, 30, 34}, {0},             {8, 20, 32, 44},  {0}};
static const Gs5Prim bfm_psyq_gs5_gt4_l_d = {1, 1, 1, 1, GS5_RGBC_AFTER_RTPT, 0,  36, 104, 12, {22, 26, 30, 34}, {20, 24, 28, 32}, {8, 20, 32, 44},  {4, 16, 28, 40}};

int bfm_psyq_gs5_f3_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_f3_nl_d, r); }
int bfm_psyq_gs5_f3_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_f3_l_d, r); }
int bfm_psyq_gs5_f4_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_f4_nl_d, r); }
int bfm_psyq_gs5_f4_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_f4_l_d, r); }
int bfm_psyq_gs5_g3_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_g3_nl_d, r); }
int bfm_psyq_gs5_g3_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_g3_l_d, r); }
int bfm_psyq_gs5_g4_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_g4_nl_d, r); }
int bfm_psyq_gs5_g4_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_g4_l_d, r); }
int bfm_psyq_gs5_ft3_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_ft3_nl_d, r); }
int bfm_psyq_gs5_ft3_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_ft3_l_d, r); }
int bfm_psyq_gs5_ft4_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_ft4_nl_d, r); }
int bfm_psyq_gs5_ft4_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_ft4_l_d, r); }
int bfm_psyq_gs5_gt3_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_gt3_nl_d, r); }
int bfm_psyq_gs5_gt3_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_gt3_l_d, r); }
int bfm_psyq_gs5_gt4_nl(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_gt4_nl_d, r); }
int bfm_psyq_gs5_gt4_l(uint32_t *r) { return gs5_run(&bfm_psyq_gs5_gt4_l_d, r); }

/* ---- libgs OBJT2 sorters (0x8004D6BC..0x800505B8, func_80057094's
 * per-type routines) ----------------------------------------------------------
 *
 * Called by func_80057094 through the guest tables at 0x800A2BC0 as
 *   fn(prim, vert_top, normal_top, packet, n, shift, ot, scratch)   (lit slots)
 *   fn(prim, vert_top, packet, n, shift, ot, scratch)               (no-light slots)
 * They build fresh GPU packets at `packet` (one per visible primitive) from n
 * TMD primitives, link them into the OT and return the new packet pointer.
 * Each routine is described as the retail sequence of GTE loads/commands,
 * cull tests (FLAG bit 31 after RTPT/RTPS, NCLIP MAC0 <= 0) and packet
 * stores, so writes made before a cull (and the cop2 bank) end up exactly as
 * retail leaves them. Colour/command words:
 *   RAWABE  word | ABE << 25                (ABE = the libgs word at 0x800C6D24)
 *   NLTEX   (word & 0xFFFFFF) | ((mode | ABE << 1) & 0xFE) << 24  (mode = TMD byte 3, sign-extended)
 *   TEX     (mode | ABE << 1) << 24 | 0x808080
 *   GT3L2   ((mode & 2) | ABE << 1) << 24 | 0x25808080   (light-2 GT3 -> POLY_FT3)
 *   GT4L2   ((mode & 2) | ABE << 1) << 24 | 0x2D808080   (light-2 GT4 -> POLY_FT4)
 * Link: slot = ot->org + (((OTZ - ot->offset) >> shift) & 0xFFFF) * 4;
 *   tag = len << 24 | (old & 0xFFFFFF); slot = (old & 0xFF000000) | (pkt & 0xFFFFFF).
 * Reconstructed from the retail instruction stream; no Psy-Q source. */
enum { OT2_LDV = 1, OT2_LDN, OT2_CMD, OT2_FLAG, OT2_MAC0, OT2_MTC2, OT2_PKW, OT2_ST, OT2_LINK, OT2_END };
enum { OT2_RAW, OT2_RAWABE, OT2_NLTEX, OT2_TEX, OT2_GT3L2, OT2_GT4L2 };
typedef struct Ot2Op { uint8_t op, a, kind, b; uint32_t w; } Ot2Op;
typedef struct Ot2Prim { uint8_t lit, step; const Ot2Op *ops; } Ot2Prim;

#define LV(s, o) {OT2_LDV, s, 0, o, 0}
#define LN(s, o) {OT2_LDN, s, 0, o, 0}
#define RTPT {OT2_CMD, 0, 0, 0, 0x0280030u}
#define RTPS {OT2_CMD, 0, 0, 0, 0x0180001u}
#define NCLIP {OT2_CMD, 0, 0, 0, 0x1400006u}
#define AVSZ3 {OT2_CMD, 0, 0, 0, 0x158002Du}
#define AVSZ4 {OT2_CMD, 0, 0, 0, 0x168002Eu}
#define NCCS {OT2_CMD, 0, 0, 0, 0x108041Bu}
#define NCCT {OT2_CMD, 0, 0, 0, 0x118043Fu}
#define FLAG {OT2_FLAG, 0, 0, 0, 0}
#define MAC0 {OT2_MAC0, 0, 0, 0, 0}
#define MT(r, k, o) {OT2_MTC2, r, OT2_##k, o, 0}
#define PW(p, k, o) {OT2_PKW, p, OT2_##k, o, 0}
#define ST(p, r) {OT2_ST, p, 0, r, 0}
#define LINK(n) {OT2_LINK, n, 0, 0, 0}
#define END(n) {OT2_END, n, 0, 0, 0}
#define SXY3(a, b, c) ST(a, 12), ST(b, 13), ST(c, 14)

static const Ot2Op kOt2F3nl[] = {LV(0, 8), LV(1, 10), LV(2, 12), RTPT, MT(22, RAWABE, 4), FLAG, NCLIP, MAC0, AVSZ3,
    LINK(4), ST(4, 22), SXY3(8, 12, 16), END(20)};
static const Ot2Op kOt2F3l2[] = {LV(0, 10), LV(1, 12), LV(2, 14), RTPT, MT(22, RAWABE, 4), FLAG, NCLIP, MAC0, AVSZ3,
    LINK(4), ST(4, 22), SXY3(8, 12, 16), END(20)};
static const Ot2Op kOt2F3l0[] = {LV(0, 10), LV(1, 12), LV(2, 14), RTPT, MT(6, RAWABE, 4), FLAG, NCLIP, MAC0, AVSZ3,
    LN(0, 8), NCCS, LINK(4), SXY3(8, 12, 16), ST(4, 22), END(20)};
static const Ot2Op kOt2F4nl[] = {LV(0, 8), LV(1, 10), LV(2, 12), RTPT, MT(22, RAWABE, 4), FLAG, NCLIP, LV(0, 14), MAC0,
    ST(4, 22), SXY3(8, 12, 16), RTPS, FLAG, AVSZ4, ST(20, 14), LINK(5), END(24)};
static const Ot2Op kOt2F4l2[] = {LV(0, 10), LV(1, 12), LV(2, 14), RTPT, MT(22, RAWABE, 4), FLAG, NCLIP, LV(0, 16), MAC0,
    ST(4, 22), SXY3(8, 12, 16), RTPS, FLAG, AVSZ4, ST(20, 14), LINK(5), END(24)};
static const Ot2Op kOt2F4l0[] = {LV(0, 10), LV(1, 12), LV(2, 14), RTPT, MT(6, RAWABE, 4), FLAG, NCLIP, LV(0, 16), MAC0,
    SXY3(8, 12, 16), RTPS, FLAG, AVSZ4, LN(0, 8), NCCS, LINK(5), ST(20, 14), ST(4, 22), END(24)};
static const Ot2Op kOt2G3nl[] = {LV(0, 16), LV(1, 18), LV(2, 20), RTPT, MT(20, RAWABE, 4), MT(21, RAW, 8), MT(22, RAW, 12),
    FLAG, NCLIP, MAC0, AVSZ3, ST(4, 20), ST(12, 21), ST(20, 22), SXY3(8, 16, 24), LINK(6), END(28)};
static const Ot2Op kOt2G3l2[] = {LV(0, 10), LV(1, 14), LV(2, 18), RTPT, MT(20, RAWABE, 4), FLAG, NCLIP, MAC0, AVSZ3,
    LINK(6), ST(4, 20), ST(12, 20), ST(20, 20), SXY3(8, 16, 24), END(28)};
static const Ot2Op kOt2G3l0[] = {LV(0, 10), LV(1, 14), LV(2, 18), RTPT, FLAG, NCLIP, MT(6, RAWABE, 4), MAC0, AVSZ3,
    LN(0, 8), LN(1, 12), LN(2, 16), NCCT, LINK(6), SXY3(8, 16, 24), ST(4, 20), ST(12, 21), ST(20, 22), END(28)};
static const Ot2Op kOt2G4nl[] = {LV(0, 20), LV(1, 22), LV(2, 24), RTPT, FLAG, NCLIP, LV(0, 26), MAC0, SXY3(8, 16, 24),
    RTPS, PW(4, RAWABE, 4), PW(12, RAW, 8), PW(20, RAW, 12), FLAG, AVSZ4, PW(28, RAW, 16), ST(32, 14), LINK(8), END(36)};
static const Ot2Op kOt2G4l2[] = {LV(0, 10), LV(1, 14), LV(2, 18), RTPT, MT(20, RAWABE, 4), FLAG, NCLIP, LV(0, 22), MAC0,
    SXY3(8, 16, 24), RTPS, FLAG, AVSZ4, LINK(8), ST(4, 20), ST(12, 20), ST(20, 20), ST(28, 20), ST(32, 14), END(36)};
static const Ot2Op kOt2G4l0[] = {LV(0, 10), LV(1, 14), LV(2, 18), RTPT, FLAG, NCLIP, LV(0, 22), MAC0, SXY3(8, 16, 24),
    RTPS, MT(6, RAWABE, 4), LN(1, 12), LN(2, 16), FLAG, AVSZ4, LN(0, 20), NCCS, ST(28, 22), LN(0, 8), NCCT, LINK(8),
    ST(32, 14), ST(4, 20), ST(12, 21), ST(20, 22), END(36)};
static const Ot2Op kOt2Ft3nl[] = {LV(0, 20), LV(1, 22), LV(2, 24), RTPT, MT(22, NLTEX, 16), PW(12, RAW, 4), PW(20, RAW, 8),
    PW(28, RAW, 12), FLAG, NCLIP, MAC0, AVSZ3, LINK(7), ST(4, 22), SXY3(8, 16, 24), END(32)};
static const Ot2Op kOt2Ft3l2[] = {LV(0, 18), LV(1, 20), LV(2, 22), RTPT, PW(12, RAW, 4), PW(20, RAW, 8), PW(28, RAW, 12),
    PW(4, TEX, 0), FLAG, NCLIP, MAC0, AVSZ3, LINK(7), SXY3(8, 16, 24), END(32)};
static const Ot2Op kOt2Ft3l0[] = {LV(0, 18), LV(1, 20), LV(2, 22), RTPT, MT(6, TEX, 0), PW(12, RAW, 4), PW(20, RAW, 8),
    PW(28, RAW, 12), FLAG, NCLIP, MAC0, AVSZ3, LN(0, 16), NCCS, LINK(7), SXY3(8, 16, 24), ST(4, 22), END(32)};
static const Ot2Op kOt2Ft4nl[] = {LV(0, 24), LV(1, 26), LV(2, 28), RTPT, PW(4, NLTEX, 20), FLAG, NCLIP, LV(0, 30), MAC0,
    SXY3(8, 16, 24), RTPS, PW(12, RAW, 4), PW(20, RAW, 8), PW(28, RAW, 12), PW(36, RAW, 16), FLAG, AVSZ4, ST(32, 14),
    LINK(9), END(40)};
static const Ot2Op kOt2Ft4l2[] = {LV(0, 22), LV(1, 24), LV(2, 26), RTPT, FLAG, NCLIP, LV(0, 28), MAC0, SXY3(8, 16, 24),
    RTPS, PW(12, RAW, 4), PW(20, RAW, 8), PW(28, RAW, 12), PW(36, RAW, 16), PW(4, TEX, 0), FLAG, AVSZ4, ST(32, 14),
    LINK(9), END(40)};
static const Ot2Op kOt2Ft4l0[] = {LV(0, 22), LV(1, 24), LV(2, 26), RTPT, MT(6, TEX, 0), FLAG, NCLIP, LV(0, 28), MAC0,
    SXY3(8, 16, 24), RTPS, PW(12, RAW, 4), PW(20, RAW, 8), PW(28, RAW, 12), PW(36, RAW, 16), FLAG, AVSZ4, LN(0, 20),
    NCCS, LINK(9), ST(32, 14), ST(4, 22), END(40)};
static const Ot2Op kOt2Gt3nl[] = {LV(0, 28), LV(1, 30), LV(2, 32), RTPT, MT(20, NLTEX, 16), MT(21, RAW, 20),
    MT(22, RAW, 24), PW(12, RAW, 4), PW(24, RAW, 8), PW(36, RAW, 12), FLAG, NCLIP, MAC0, AVSZ3, SXY3(8, 20, 32),
    ST(4, 20), ST(16, 21), ST(28, 22), LINK(9), END(40)};
static const Ot2Op kOt2Gt3l2[] = {LV(0, 18), LV(1, 22), LV(2, 26), RTPT, MT(20, RAW, 4), MT(21, RAW, 8), MT(22, RAW, 12),
    PW(4, GT3L2, 0), FLAG, NCLIP, MAC0, AVSZ3, ST(12, 20), ST(20, 21), ST(28, 22), SXY3(8, 16, 24), LINK(7), END(32)};
static const Ot2Op kOt2Gt3l0[] = {LV(0, 18), LV(1, 22), LV(2, 26), RTPT, MT(6, TEX, 0), FLAG, NCLIP, MAC0, AVSZ3,
    LN(0, 16), LN(1, 20), LN(2, 24), NCCT, LINK(9), PW(12, RAW, 4), PW(24, RAW, 8), PW(36, RAW, 12), SXY3(8, 20, 32),
    ST(4, 20), ST(16, 21), ST(28, 22), END(40)};
static const Ot2Op kOt2Gt4nl[] = {LV(0, 36), LV(1, 38), LV(2, 40), RTPT, MT(20, NLTEX, 20), MT(21, RAW, 24),
    MT(22, RAW, 28), MT(6, RAW, 32), FLAG, NCLIP, LV(0, 42), MAC0, SXY3(8, 20, 32), RTPS, FLAG, AVSZ4, PW(12, RAW, 4),
    PW(24, RAW, 8), PW(36, RAW, 12), PW(48, RAW, 16), ST(44, 14), ST(4, 20), ST(16, 21), ST(28, 22), ST(40, 6),
    LINK(12), END(52)};
static const Ot2Op kOt2Gt4l2[] = {LV(0, 22), LV(1, 26), LV(2, 30), RTPT, FLAG, NCLIP, LV(0, 34), MAC0, SXY3(8, 16, 24),
    RTPS, PW(4, GT4L2, 0), FLAG, AVSZ4, PW(12, RAW, 4), PW(20, RAW, 8), PW(28, RAW, 12), PW(36, RAW, 16), ST(32, 14),
    LINK(9), END(40)};
static const Ot2Op kOt2Gt4l0[] = {LV(0, 22), LV(1, 26), LV(2, 30), RTPT, MT(6, TEX, 0), FLAG, NCLIP, LV(0, 34), MAC0,
    SXY3(8, 20, 32), RTPS, LN(1, 24), LN(2, 28), FLAG, AVSZ4, LN(0, 32), NCCS, PW(12, RAW, 4), PW(24, RAW, 8),
    PW(36, RAW, 12), PW(48, RAW, 16), ST(40, 22), LN(0, 20), NCCT, LINK(12), ST(44, 14), ST(4, 20), ST(16, 21),
    ST(28, 22), END(52)};

static int ot2_word(uint8_t kind, uint32_t prim, uint8_t off, uint32_t abe, uint32_t *out) {
    const uint8_t *p;
    uint32_t w = 0, mode;
    if (!(p = (const uint8_t *)P(prim, 4u))) return 0;
    mode = (uint32_t)(int32_t)(int8_t)p[3];
    if (kind == OT2_RAW || kind == OT2_RAWABE || kind == OT2_NLTEX) {
        const uint8_t *q = (const uint8_t *)P(prim + off, 4u);
        if (!q) return 0;
        w = (uint32_t)q[0] | ((uint32_t)q[1] << 8) | ((uint32_t)q[2] << 16) | ((uint32_t)q[3] << 24);
    }
    switch (kind) {
    case OT2_RAW: *out = w; break;
    case OT2_RAWABE: *out = w | (abe << 25); break;
    case OT2_NLTEX: *out = (w & 0x00FFFFFFu) | (((mode | (abe << 1)) >> 1) << 25); break;
    case OT2_TEX: *out = ((mode | (abe << 1)) << 24) | 0x00808080u; break;
    case OT2_GT3L2: *out = (((mode & 2u) | (abe << 1)) << 24) | 0x25808080u; break;
    default: *out = (((mode & 2u) | (abe << 1)) << 24) | 0x2D808080u; break;
    }
    return 1;
}

static int ot2_run(const Ot2Prim *d, uint32_t *r) {
    const uint32_t lit = d->lit;
    uint32_t prim = A(0), vert = A(1), norm = lit ? A(2) : 0u, pk = A(lit ? 3 : 2);
    uint32_t n = A(lit ? 4 : 3), shift = A(lit ? 5 : 4), ot = A(lit ? 6 : 5);
    uint32_t org, ofsw, abe, cmds = 0, i;
    if (n == 0) { r[2] = pk; return 1; }
    {
        const uint8_t *o = (const uint8_t *)P(ot + 4u, 8);
        const uint8_t *g = (const uint8_t *)P(0x800C6D24u, 4);
        if (!o || !g) return 0;
        org = (uint32_t)o[0] | ((uint32_t)o[1] << 8) | ((uint32_t)o[2] << 16) | ((uint32_t)o[3] << 24);
        ofsw = (uint32_t)o[4] | ((uint32_t)o[5] << 8) | ((uint32_t)o[6] << 16) | ((uint32_t)o[7] << 24);
        abe = (uint32_t)g[0] | ((uint32_t)g[1] << 8) | ((uint32_t)g[2] << 16) | ((uint32_t)g[3] << 24);
    }
    if (!P(prim, (uint32_t)d->step * n)) return 0;
    GTE_BEGIN();
#define OT2_FAIL() do { GTE_END(cmds); return 0; } while (0)
    for (i = 0; i < n; ++i, prim += d->step) {
        const Ot2Op *op;
        uint8_t *pp = NULL;
        for (op = d->ops;; ++op) {
            uint32_t w;
            if (op->op == OT2_PKW || op->op == OT2_ST || op->op == OT2_LINK) {
                if (!pp && !(pp = (uint8_t *)P(pk, 52u))) OT2_FAIL();
            }
            switch (op->op) {
            case OT2_LDV:
            case OT2_LDN:
                if (!gs5_ldv(op->a, op->op == OT2_LDV ? vert : norm, gs5_u16(prim + op->b))) OT2_FAIL();
                continue;
            case OT2_CMD: doCOP2(op->w); cmds++; continue;
            case OT2_FLAG: if ((int32_t)CFC2(31) < 0) break; continue;
            case OT2_MAC0: if ((int32_t)MFC2(24) <= 0) break; continue;
            case OT2_MTC2:
                if (!ot2_word(op->kind, prim, op->b, abe, &w)) OT2_FAIL();
                MTC2(w, op->a);
                continue;
            case OT2_PKW:
                if (!ot2_word(op->kind, prim, op->b, abe, &w)) OT2_FAIL();
                lane_gte_store32(pp + op->a, w);
                continue;
            case OT2_ST: lane_gte_store32(pp + op->a, MFC2(op->b)); continue;
            case OT2_LINK: {
                uint32_t slot = org + (((MFC2(7) - ofsw) >> (shift & 31u)) & 0xFFFFu) * 4u, old;
                uint8_t *sp = (uint8_t *)P(slot, 4);
                if (!sp) OT2_FAIL();
                old = (uint32_t)sp[0] | ((uint32_t)sp[1] << 8) | ((uint32_t)sp[2] << 16) | ((uint32_t)sp[3] << 24);
                lane_gte_store32(pp, ((uint32_t)op->a << 24) | (old & 0x00FFFFFFu));
                lane_gte_store32(sp, (old & 0xFF000000u) | (pk & 0x00FFFFFFu));
                continue;
            }
            default: pk += op->a; break;   /* OT2_END */
            }
            break;
        }
    }
#undef OT2_FAIL
    GTE_END(cmds);
    r[2] = pk;
    return 1;
}

static const Ot2Prim kOt2PF3nl = {0, 16, kOt2F3nl}, kOt2PF3l2 = {1, 16, kOt2F3l2}, kOt2PF3l0 = {1, 16, kOt2F3l0};
static const Ot2Prim kOt2PF4nl = {0, 16, kOt2F4nl}, kOt2PF4l2 = {1, 20, kOt2F4l2}, kOt2PF4l0 = {1, 20, kOt2F4l0};
static const Ot2Prim kOt2PG3nl = {0, 24, kOt2G3nl}, kOt2PG3l2 = {1, 20, kOt2G3l2}, kOt2PG3l0 = {1, 20, kOt2G3l0};
static const Ot2Prim kOt2PG4nl = {0, 28, kOt2G4nl}, kOt2PG4l2 = {1, 24, kOt2G4l2}, kOt2PG4l0 = {1, 24, kOt2G4l0};
static const Ot2Prim kOt2PFt3nl = {0, 28, kOt2Ft3nl}, kOt2PFt3l2 = {1, 24, kOt2Ft3l2}, kOt2PFt3l0 = {1, 24, kOt2Ft3l0};
static const Ot2Prim kOt2PFt4nl = {0, 32, kOt2Ft4nl}, kOt2PFt4l2 = {1, 32, kOt2Ft4l2}, kOt2PFt4l0 = {1, 32, kOt2Ft4l0};
static const Ot2Prim kOt2PGt3nl = {0, 36, kOt2Gt3nl}, kOt2PGt3l2 = {1, 28, kOt2Gt3l2}, kOt2PGt3l0 = {1, 28, kOt2Gt3l0};
static const Ot2Prim kOt2PGt4nl = {0, 44, kOt2Gt4nl}, kOt2PGt4l2 = {1, 36, kOt2Gt4l2}, kOt2PGt4l0 = {1, 36, kOt2Gt4l0};
#undef LV
#undef LN
#undef RTPT
#undef RTPS
#undef NCLIP
#undef AVSZ3
#undef AVSZ4
#undef NCCS
#undef NCCT
#undef FLAG
#undef MAC0
#undef MT
#undef PW
#undef ST
#undef LINK
#undef END
#undef SXY3

int bfm_psyq_ot2_f3_nl(uint32_t *r) { return ot2_run(&kOt2PF3nl, r); }
int bfm_psyq_ot2_f3_l2(uint32_t *r) { return ot2_run(&kOt2PF3l2, r); }
int bfm_psyq_ot2_f3_l0(uint32_t *r) { return ot2_run(&kOt2PF3l0, r); }
int bfm_psyq_ot2_f4_nl(uint32_t *r) { return ot2_run(&kOt2PF4nl, r); }
int bfm_psyq_ot2_f4_l2(uint32_t *r) { return ot2_run(&kOt2PF4l2, r); }
int bfm_psyq_ot2_f4_l0(uint32_t *r) { return ot2_run(&kOt2PF4l0, r); }
int bfm_psyq_ot2_g3_nl(uint32_t *r) { return ot2_run(&kOt2PG3nl, r); }
int bfm_psyq_ot2_g3_l2(uint32_t *r) { return ot2_run(&kOt2PG3l2, r); }
int bfm_psyq_ot2_g3_l0(uint32_t *r) { return ot2_run(&kOt2PG3l0, r); }
int bfm_psyq_ot2_g4_nl(uint32_t *r) { return ot2_run(&kOt2PG4nl, r); }
int bfm_psyq_ot2_g4_l2(uint32_t *r) { return ot2_run(&kOt2PG4l2, r); }
int bfm_psyq_ot2_g4_l0(uint32_t *r) { return ot2_run(&kOt2PG4l0, r); }
int bfm_psyq_ot2_ft3_nl(uint32_t *r) { return ot2_run(&kOt2PFt3nl, r); }
int bfm_psyq_ot2_ft3_l2(uint32_t *r) { return ot2_run(&kOt2PFt3l2, r); }
int bfm_psyq_ot2_ft3_l0(uint32_t *r) { return ot2_run(&kOt2PFt3l0, r); }
int bfm_psyq_ot2_ft4_nl(uint32_t *r) { return ot2_run(&kOt2PFt4nl, r); }
int bfm_psyq_ot2_ft4_l2(uint32_t *r) { return ot2_run(&kOt2PFt4l2, r); }
int bfm_psyq_ot2_ft4_l0(uint32_t *r) { return ot2_run(&kOt2PFt4l0, r); }
int bfm_psyq_ot2_gt3_nl(uint32_t *r) { return ot2_run(&kOt2PGt3nl, r); }
int bfm_psyq_ot2_gt3_l2(uint32_t *r) { return ot2_run(&kOt2PGt3l2, r); }
int bfm_psyq_ot2_gt3_l0(uint32_t *r) { return ot2_run(&kOt2PGt3l0, r); }
int bfm_psyq_ot2_gt4_nl(uint32_t *r) { return ot2_run(&kOt2PGt4nl, r); }
int bfm_psyq_ot2_gt4_l2(uint32_t *r) { return ot2_run(&kOt2PGt4l2, r); }
int bfm_psyq_ot2_gt4_l0(uint32_t *r) { return ot2_run(&kOt2PGt4l0, r); }

/* ---- libgs OBJT2 gradation sorters (0x80057928..0x80058890) ---------------
 *
 * func_80057094 sends lit F3/G3/F4/G4 primitives with flag bit 2 (per-vertex
 * colours in the TMD) to the light-indexed tables at 0x800A2CC0/CCC/CD8/CE4:
 *   fn(prim, vert_top, normal_top, packet, n, shift, ot, scratch)
 * These are compiled C, not hand-written GTE code: they keep their state in
 * the scratch block (+12 shift, +16 ot->org, +24 MAC0 then OTZ, FLAG at +36
 * (triangles) / +40 (quads), the OT slot pointer at +52 / +56, and for the
 * flat light-0 versions the first colour at +0), take the OT index as
 * (OTZ >> shift) without the OT offset word, and store the slot as
 * (packet & 0xFFFFFF). Light 0 runs NCCS once per vertex colour (RGBC from the
 * TMD, the matching normal into V0); light 2 copies the TMD colours. Output is
 * POLY_G3 / POLY_G4. Reconstructed from the retail instruction stream;
 * same-input differential vs retail in a scratch probe. */
typedef struct GrdPrim {
    uint8_t quad, lit0, flat, step;
    uint8_t vofs[4], nofs[4];
} GrdPrim;

static int grd_get32(uint32_t a, uint32_t *v) {
    const uint8_t *p = (const uint8_t *)P(a, 4);
    if (!p) return 0;
    *v = (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
    return 1;
}
static int grd_put32(uint32_t a, uint32_t v) {
    uint8_t *p = (uint8_t *)P(a, 4);
    if (!p) return 0;
    lane_gte_store32(p, v);
    return 1;
}
static int grd_put8(uint32_t a, uint8_t v) {
    uint8_t *p = (uint8_t *)P(a, 1);
    if (!p) return 0;
    *p = v;
    return 1;
}

static int grd_run(const GrdPrim *d, uint32_t *r) {
    uint32_t prim = A(0), vert = A(1), norm = A(2), pk = A(3);
    const int32_t n = (int32_t)A(4);
    const uint32_t shift = A(5), ot = A(6), scr = A(7);
    const uint32_t fofs = d->quad ? 40u : 36u, sofs = d->quad ? 56u : 52u, len = d->quad ? 8u : 6u;
    uint32_t org, cmds = 0, w, v, k;
    int32_t i;
    if (!grd_get32(ot + 4u, &org) || !grd_put32(scr + 12u, shift) || !grd_put32(scr + 16u, org)) return 0;
    if (n <= 0) { r[2] = pk; return 1; }
    GTE_BEGIN();
#define GRD_FAIL() do { GTE_END(cmds); return 0; } while (0)
#define GRD(x) do { if (!(x)) GRD_FAIL(); } while (0)
    for (i = 0; i < n; ++i, prim += d->step) {
        uint32_t slot, sh, mode;
        const uint8_t *hp;
        for (k = 0; k < 3u; ++k) GRD(gs5_ldv((int)k, vert, gs5_u16(prim + d->vofs[k])));
        doCOP2(0x0280030); cmds++;                                    /* RTPT */
        GRD(hp = (const uint8_t *)P(prim, 4));
        mode = hp[3];
        if (d->lit0) {
            if (d->flat) {
                GRD(grd_get32(prim + 4u, &w) && grd_put32(scr, w) && grd_put8(scr + 3u, (uint8_t)(mode | 0x10u)));
            }
        } else {
            GRD(grd_get32(prim + 4u, &w));
            if (d->flat) GRD(grd_put32(pk + 4u, w & 0x00FFFFFFu) && grd_put8(pk + 7u, (uint8_t)(mode | 0x10u)));
            else GRD(grd_put32(pk + 4u, w));
        }
        v = CFC2(31);
        GRD(grd_put32(scr + fofs, v));
        if (v & 0x80000000u) continue;
        doCOP2(0x1400006); cmds++;                                    /* NCLIP */
        if (!d->lit0) GRD(grd_get32(prim + 8u, &w) && grd_put32(pk + 12u, w));
        v = MFC2(24);
        GRD(grd_put32(scr + 24u, v));
        if ((int32_t)v <= 0) continue;
        GRD(grd_put32(pk + 8u, MFC2(12)) && grd_put32(pk + 16u, MFC2(13)) && grd_put32(pk + 24u, MFC2(14)));
        if (d->quad) {
            GRD(gs5_ldv(0, vert, gs5_u16(prim + d->vofs[3])));
            doCOP2(0x0180001); cmds++;                                /* RTPS */
            if (!d->lit0) GRD(grd_get32(prim + 12u, &w) && grd_put32(pk + 20u, w));
            v = CFC2(31);
            GRD(grd_put32(scr + fofs, v));
            if (v & 0x80000000u) continue;
            GRD(grd_put32(pk + 32u, MFC2(14)));
            doCOP2(0x168002E); cmds++;                                /* AVSZ4 */
            if (!d->lit0) GRD(grd_get32(prim + 16u, &w) && grd_put32(pk + 28u, w));
        } else {
            doCOP2(0x158002D); cmds++;                                /* AVSZ3 */
            if (!d->lit0) GRD(grd_get32(prim + 12u, &w) && grd_put32(pk + 20u, w));
        }
        GRD(grd_put32(scr + 24u, MFC2(7)));
        if (d->lit0) {
            static const uint8_t kOut[4] = {4, 12, 20, 28};
            for (k = 0; k < (d->quad ? 4u : 3u); ++k) {
                if (k == 0 && d->flat) GRD(grd_get32(scr, &w));
                else GRD(grd_get32(prim + 4u + k * 4u, &w));
                MTC2(w, 6);
                GRD(gs5_ldv(0, norm, gs5_u16(prim + d->nofs[k])));
                doCOP2(0x108041B); cmds++;                            /* NCCS */
                if (k == 0) {
                    GRD(grd_get32(scr + 24u, &v) && grd_get32(scr + 12u, &sh) && grd_get32(scr + 16u, &org));
                    slot = org + (uint32_t)((int32_t)v >> (sh & 31u)) * 4u;
                    GRD(grd_put32(scr + sofs, slot));
                } else if (k == 1) {
                    GRD(grd_get32(scr + sofs, &slot) && grd_get32(slot, &w));
                    GRD(grd_put32(pk, (w & 0x00FFFFFFu) | (len << 24)));
                } else if (k == 2) {
                    GRD(grd_get32(scr + sofs, &slot) && grd_put32(slot, pk & 0x00FFFFFFu));
                }
                GRD(grd_put32(pk + kOut[k], MFC2(22)));
            }
        } else {
            GRD(grd_get32(scr + 24u, &v) && grd_get32(scr + 12u, &sh) && grd_get32(scr + 16u, &org));
            slot = org + (uint32_t)((int32_t)v >> (sh & 31u)) * 4u;
            GRD(grd_put32(scr + sofs, slot) && grd_get32(slot, &w));
            GRD(grd_put32(pk, (w & 0x00FFFFFFu) | (len << 24)));
            GRD(grd_get32(scr + sofs, &slot) && grd_put32(slot, pk & 0x00FFFFFFu));
        }
        pk += d->quad ? 36u : 28u;
    }
#undef GRD
#undef GRD_FAIL
    GTE_END(cmds);
    r[2] = pk;
    return 1;
}

/* quad, lit0, flat, step, vertex offsets, normal offsets (per colour) */
static const GrdPrim kGrdG3l0 = {0, 1, 0, 28, {18, 22, 26, 0}, {16, 20, 24, 0}};
static const GrdPrim kGrdG3l2 = {0, 0, 0, 28, {18, 22, 26, 0}, {0}};
static const GrdPrim kGrdF3l0 = {0, 1, 1, 24, {18, 20, 22, 0}, {16, 16, 16, 0}};
static const GrdPrim kGrdF3l2 = {0, 0, 1, 24, {18, 20, 22, 0}, {0}};
static const GrdPrim kGrdF4l0 = {1, 1, 1, 32, {22, 24, 26, 28}, {20, 20, 20, 20}};
static const GrdPrim kGrdF4l2 = {1, 0, 1, 32, {22, 24, 26, 28}, {0}};
static const GrdPrim kGrdG4l0 = {1, 1, 0, 36, {22, 26, 30, 34}, {20, 24, 28, 32}};
static const GrdPrim kGrdG4l2 = {1, 0, 0, 36, {22, 26, 30, 34}, {0}};

int bfm_psyq_grd_g3_l0(uint32_t *r) { return grd_run(&kGrdG3l0, r); }
int bfm_psyq_grd_g3_l2(uint32_t *r) { return grd_run(&kGrdG3l2, r); }
int bfm_psyq_grd_f3_l0(uint32_t *r) { return grd_run(&kGrdF3l0, r); }
int bfm_psyq_grd_f3_l2(uint32_t *r) { return grd_run(&kGrdF3l2, r); }
int bfm_psyq_grd_f4_l0(uint32_t *r) { return grd_run(&kGrdF4l0, r); }
int bfm_psyq_grd_f4_l2(uint32_t *r) { return grd_run(&kGrdF4l2, r); }
int bfm_psyq_grd_g4_l0(uint32_t *r) { return grd_run(&kGrdG4l0, r); }
int bfm_psyq_grd_g4_l2(uint32_t *r) { return grd_run(&kGrdG4l2, r); }


/* MUSASHI_TRACE_DRAWOTAG helper: the GTE control state at the traced OT
 * (rotation, translation, OFX/OFY, H). Diagnostic only. */
void bfm_psyq_gte_trace(void) {
    int i;
    uint32_t c[32];
    if (!bfm_psyq_gte_begin()) return;
    for (i = 0; i < 32; i++) c[i] = CFC2(i);
    bfm_psyq_gte_end(0);
    fprintf(stderr, "native_boot: OT_TRACE gte rt=%08x %08x %08x %08x %08x tr=%d,%d,%d "
            "ofx=%d ofy=%d h=%u dqa=%d dqb=%d zsf3=%d zsf4=%d flag=%08x\n",
            c[0], c[1], c[2], c[3], c[4], (int32_t)c[5], (int32_t)c[6], (int32_t)c[7],
            (int32_t)c[24] >> 16, (int32_t)c[25] >> 16, c[26] & 0xFFFFu,
            (int16_t)c[27], (int32_t)c[28], (int16_t)c[29], (int16_t)c[30], c[31]);
}
