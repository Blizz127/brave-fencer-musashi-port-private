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

#include <psx/types.h>
#include <psx/libgte.h>
#include <psx/gtereg.h>
#include <psx/inline_c.h>

#include <string.h>

/* Defined in PsyCross LIBGTE.C but not declared in its libgte.h. */
extern MATRIX *CompMatrixLV(MATRIX *m0, MATRIX *m1, MATRIX *m2);

#define A(n) bfm_psyq_arg(r, n)
#define P(addr, size) bfm_psyq_ptr((addr), (size))

static void put32(uint32_t addr, int32_t v) {
    uint8_t *p = (uint8_t *)P(addr, 4);
    if (!p) return;
    p[0] = (uint8_t)v; p[1] = (uint8_t)((uint32_t)v >> 8);
    p[2] = (uint8_t)((uint32_t)v >> 16); p[3] = (uint8_t)((uint32_t)v >> 24);
}

/* ---- stateless ---- */

int bfm_psyq_ratan2(uint32_t *r) {
    r[2] = (uint32_t)ratan2((int)(int32_t)A(0), (int)(int32_t)A(1));
    return 1;
}

#define ROT1(fn, name)                                                   \
    int name(uint32_t *r) {                                              \
        MATRIX *m = (MATRIX *)P(A(1), sizeof(MATRIX));                   \
        if (!m) return 0;                                                \
        fn((int)(int32_t)A(0), m);                                       \
        r[2] = A(1);                                                     \
        return 1;                                                        \
    }
ROT1(RotMatrixX, bfm_psyq_RotMatrixX)
ROT1(RotMatrixY, bfm_psyq_RotMatrixY)
ROT1(RotMatrixZ, bfm_psyq_RotMatrixZ)

int bfm_psyq_RotMatrixYXZ(uint32_t *r) {
    SVECTOR *v = (SVECTOR *)P(A(0), sizeof(SVECTOR));
    MATRIX *m = (MATRIX *)P(A(1), sizeof(MATRIX));
    if (!v || !m) return 0;
    RotMatrixYXZ(v, m);
    r[2] = A(1);
    return 1;
}

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
    if (!a || !b || !c) return 0;
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
    for (i = 0; i < 3; i++) ldv((int)i, v[i]);
    doCOP2(0x0280030);                     /* RTPT */
    for (i = 0; i < 3; i++) sxy[i] = (int32_t)MFC2(12 + (int)i);
    flag = (int32_t)CFC2(31);
    ldv(0, v[3]);
    doCOP2(0x0180001);                     /* RTPS */
    sxy[3] = (int32_t)MFC2(14);
    p = (int32_t)MFC2(8);
    flag |= (int32_t)CFC2(31);
    sz = (int32_t)(MFC2(19) & 0xFFFFu) >> 2;
    GTE_END(2);
    for (i = 0; i < 4; i++) put32(A(4 + i), sxy[i]);
    put32(A(8), p);
    put32(A(9), flag);
    r[2] = (uint32_t)sz;
    return 1;
}
