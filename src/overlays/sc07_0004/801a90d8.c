/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A90D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A90D8;
extern int func_8005C49C(void);
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s16 D_80126B5E;
extern s16 D_80126B66;
extern Mtx32_801A90D8 D_800AE620;
typedef struct { s16 vx, vy, vz, pad; } SV_801A90D8;

void func_801A90D8(s32 a0)
{
    s16 dx;
    s16 dz;
    s32 distSq;
    s32 s2;

    dx = D_80126B5E;
    dz = D_80126B66;
    distSq = dx * dx + dz * dz;
    s2 = *(s32 *)(a0 + 0xCC);          /* the mirrored/render node */

    *(s16 *)(a0 + 0xA) = (s16)-0x500;  /* y */

    if ((func_8005C49C() & 0xF) != 0 || 0xF8100 < distSq) {
        Mtx32_801A90D8 mtx;
        SV_801A90D8 vin;
        SV_801A90D8 vout;
        s32 ang;
        s32 r2;

        ang = func_8005C49C();
        mtx = D_800AE620;              /* 8-word template copy to sp+0x10 */
        func_8004A0DC(ang & 0xFF8, &mtx);
        /* BOTH zero stores are written BEFORE the func_8005C49C() call: cc1 emits them
         * in source order ahead of the jal and reorg then lifts the LAST one
         * (vin.vx, sp+0x30) into the call's delay slot, leaving vin.vy
         * (sp+0x32) plain above it — exactly the target's split.  Writing
         * vin.vx AFTER the call instead leaves it stranded below and costs the
         * 7-instruction rotation this draft's predecessor carried. */
        vin.vy = 0;
        vin.vx = 0;
        r2 = func_8005C49C();
        vin.vz = -(r2 & 0x3F8);
        func_80048FBC(&mtx, &vin, &vout);
        *(s16 *)(a0 + 0x6) = vout.vx + 0x90;   /* x */
        *(s16 *)(a0 + 0xE) = vout.vz;          /* z */
    } else {
        *(u16 *)(a0 + 0x6) = (u16)D_80126B5E + 0x90;
        *(u16 *)(a0 + 0xE) = (u16)D_80126B66;
    }

    *(u16 *)(s2 + 0x8) = *(u16 *)(a0 + 0x6);
    *(u16 *)(s2 + 0xA) = *(u16 *)(a0 + 0xA);
    *(u16 *)(s2 + 0xC) = *(u16 *)(a0 + 0xE);
    *(s32 *)(a0 + 0x14) = 0x200000;
    *(s32 *)(a0 + 0x10) = (s32)0xFFFA0000;
    *(s32 *)(a0 + 0x1C) = 0;
    /* Likewise before the call: a0[0x84]=8 is the last pre-jal store, so reorg
     * takes it as the delay filler and `sw zero,0x1C(a0)` stays plain above.
     * No `register ... __asm__("$4")` pin is needed — once the store order is
     * right, optimize_reg_copy_1 (§193-D) re-bases the whole block onto $a0
     * by itself. */
    *(s16 *)(a0 + 0x84) = 8;
    func_8012AD44((s32 *)a0, 1);
}
