/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3180 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A3180;
typedef struct { s16 vx, vy, vz, pad; } SVec_801A3180;
typedef struct { s32 vx, vy, vz, pad; } Vec32_801A3180;
extern u16 D_8019FF8A;
extern s16 D_80126B5E;
extern s16 D_80126B66;
extern void func_801A41CC(void);
extern void func_8012AD80(s32 a0);
extern s32 func_801A3594(void *a0);
extern void func_801A34C4(s32 a0);
extern s32 func_80047D3C(s32 a0);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_80048FBC(void *a0, void *a1, void *a2);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_801A34FC(s32 arg0, u16 *arg1);

void func_801A3180(s32 arg0, s32 arg1) {
    /* D_800AE620 is the shared 32-byte matrix global, declared at BLOCK scope
     * exactly as md_SC07_004.c:1127-1133 does: the file-scope spelling this TU
     * settles on (`extern Mtx32_801A90D8 D_800AE620;`) lives below, and a second
     * file-scope spelling is a hard `conflicting types` error in gcc-2.7.2. */
    extern s32 D_800AE620[8];
    Mtx32_801A3180 m;      /* sp+0x10 */
    SVec_801A3180 sp30;    /* sp+0x30 */
    SVec_801A3180 sp38;    /* sp+0x38 */
    Vec32_801A3180 sp40;   /* sp+0x40 */
    s32 dist0;
    s32 var_s2;
    s16 var_s3;
    /* NARROW LOCAL (cookbook 194-B/162j1): `var_a0` and `sd` are s16 so their
     * defining copies are (set (reg:HI) (subreg:HI …)) — SET_SRC is a SUBREG, so
     * local-alloc.c:1002-1007 never calls optimize_reg_copy_1 and the later uses
     * keep reading the PRE-copy register ($v1 / $a0) exactly as the target does. */
    s16 var_a0;
    s16 sd;
    s32 raw;
    s32 diff;
    s32 dist;
    s16 t1;
    s16 t2;

    if (D_8019FF8A & 0x40) {
        func_801A41CC();
        func_8012AD80(arg0);
        if (func_801A3594((void *)arg0)) {
            func_801A34C4(arg0);
        }
        return;
    }
    t1 = D_80126B5E;
    t2 = D_80126B66;
    dist0 = func_80047D3C(t1 * t1 + t2 * t2);
    if (dist0 < 0x100) {
        sp30.vz = 0;
        sp30.vy = 0;
        sp30.vx = 0;
    } else {
        m = *(Mtx32_801A3180 *)&D_800AE620;
        func_8004A0DC((func_8004CFEC(-D_80126B66, D_80126B5E) - 0x400) & 0xFFF, &m);
        sp38.vy = 0;
        sp38.vx = 0;
        /* Tested `>=` (not `< 0x301`): gcc branches on the false arm, so this
         * spelling puts the -0x300 arm in the `j`'s delay slot, as the target has. */
        if (dist0 - 0x100 >= 0x301) {
            sp38.vz = -0x300;
        } else {
            sp38.vz = 0x100 - dist0;
        }
        func_80048FBC(&m, &sp38, &sp30);
    }
    /* `raw` (the raw return, $v0) is consumed by the subtraction; `var_s3` is the
     * s16 copy that survives the calls in $s3 and is sign-extended at its use. */
    raw = func_8012B744((void *)(arg0 + 4), &sp30);
    var_s3 = raw;
    diff = (raw - *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12)) & 0xFFF;
    var_a0 = diff;
    if (diff >= 0x800) {
        var_a0 = diff | 0xF000;
    }
    /* if/else (not `sd = var_a0;` + `if`): the copy has to sit BELOW the sign
     * test so optimize_reg_copy_1's forward scan cannot rewrite the test's
     * operand (cookbook 165-33); reorg then parks it in the bgez delay slot. */
    if (var_a0 < 0) {
        sd = -var_a0;
    } else {
        sd = var_a0;
    }
    var_s2 = sd;
    if (var_s2 >= 0x401) {
        return;
    }
    dist = func_80047D3C((sp30.vx - *(s16 *)(arg0 + 6)) * (sp30.vx - *(s16 *)(arg0 + 6)) +
                         (sp30.vz - *(s16 *)(arg0 + 0xE)) * (sp30.vz - *(s16 *)(arg0 + 0xE)));
    sp40.vy = 0;
    sp40.vx = 0;
    if (!(D_8019FF8A & 0x80) && dist >= 0x101 && var_s2 < 0x300) {
        D_8019FF8A |= 0x40;
        func_801A34FC(arg0, (u16 *)&sp30);
        D_8019FF8A |= 0x10;
        sp40.vz = 0xFFF00000;
    } else {
        sp40.vz = -((0x400 - sd) * arg1);
    }
    m = *(Mtx32_801A3180 *)&D_800AE620;
    func_8004A0DC(var_s3, &m);
    func_800484EC((s32)&m, (s32)&sp40, (s32)&sp40);
    *(s32 *)(arg0 + 0x10) = sp40.vx;
    *(s32 *)(arg0 + 4) += sp40.vx;
    *(s32 *)(arg0 + 0x18) = sp40.vz;
    *(s32 *)(arg0 + 0xC) += sp40.vz;
}
