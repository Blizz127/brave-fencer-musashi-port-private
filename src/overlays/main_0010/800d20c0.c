/* Exact overlay word export for [800D20C0,800D21C4) from MAIN.CD member0010
 * (extracted/overlays/main/0010.bin offset 0x232C8, load base 800AEDF8).
 * SHA256(span)=cf5a42fb0734c353157003758b0077573595f640363a0ddfff4b3bc910ca23a1.
 * Word export only: the native seam executes the member's own words. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D20C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } SVECTOR;
typedef struct {
    u16 x;   /* 0x0 */
    u16 y;   /* 0x2 */
    u16 z;   /* 0x4 */
} Pos800D20C0;
typedef struct {
    u8  pad[0x5C];
    s32 t5C;  /* 0x5C */
    s32 t60;  /* 0x60 */
    s32 t64;  /* 0x64 */
} Tgt800D20C0;
extern Tgt800D20C0 *D_801151D4;
extern long func_80047E98(SVECTOR *a, SVECTOR *b);

void func_800D20C0(Pos800D20C0 *arg0, SVECTOR *arg1, s16 arg2) {
    SVECTOR local;
    Tgt800D20C0 *p = D_801151D4;
    s32 dx, dy, dz;
    s32 shift;

    { s32 tx = p->t5C; dx = tx - arg0->x; }
    local.vx = dx;
    { s32 ty = p->t60; dy = ty - arg0->y; }
    local.vy = dy;
    { s32 tz = p->t64; dz = tz - arg0->z; }
    local.vz = dz;

    if (((u32)((dx + 0x3FFF) & 0xFFFF) < 0x7FFF) &&
        ((u32)((dy + 0x3FFF) & 0xFFFF) < 0x7FFF) &&
        ((u32)((dz + 0x3FFF) & 0xFFFF) < 0x7FFF)) {
        /* keep computed deltas */
    } else {
        local.vz = 0;
        local.vx = 0;
        local.vy = -0xFFF;
    }

    /* MATCH lever (permuter): arg2 declared `s16` (not s32) + per-delta ptr-field
     * temps `{s32 t = p->tNN; d = t - arg0->f;}` reproduce the target's ptr-first
     * load order AND the dy->a3 / dz->a0 register allocation.  Both levers needed. */
    func_80047E98(&local, arg1);

    shift = arg2 & 0xFFFF;
    arg0->x += arg1->vx >> shift;
    arg0->y += arg1->vy >> shift;
    arg0->z += arg1->vz >> shift;
}
