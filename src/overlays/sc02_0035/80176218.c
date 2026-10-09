/* SC02.CD member35 [80176218,80176734): twin of main_0012 80176218 (src/overlays/main_0012/80176218.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80176218,80176734) from MAIN.CD member 0012.
 * SHA256(span)=6d6719e8e7cfc6304153166f1bcc46c9b353a9670e1f4a95940030e54d605508.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80176218 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { short vx, vy, vz, pad; } SVECTOR;

typedef struct {
    SVECTOR v[4];               /* 0x00 */
    s32 f0, f1, f2, f3, f4, f5; /* 0x20..0x37 */
    u8  f6;                     /* 0x38 */
    u8  pad[7];                 /* -> 0x40 */
} Prim_8016E7C8_80176218;


// @class: regalloc-order
// @stuck: none — MATCH (327/327 ins, match_one MATCH; symcheck SYMS-OK 18 symbols)
//
// STRUCTURE (byte-derived, all verified against the .s):
//   $s3=st=&D_8011F7A8 (int base), $s1=st+0x48 (cach), $s2=st+0xE0 (flag), $s5=&(*(u8 *)D_80078E78) (src), $s4=param.
//   6 HUD fields synced src->cach with a chg-flag at [flag]: pairs 0x3A/0x3C and 0x3E/0x40, then 0x14(s32),
//   0x34(u16)+0x42(u8), 0x1A(s16), 0x4A(u8). Each: `if (cach==src) { if(!chg) goto skip; chg=0; } else {adjust}` + draw.
// KEY FINDINGS (reusable):
//   * Base MUST be `s32`, and the index expr written OFFSET-FIRST (`((p<<16)>>14) + st + 0x18`) — a `u8*` base
//     yields `addu rd,st,off`; the target is `addu rd,off,st`. Matches Ghidra's `(...>>0xe) + -0x7fee0840`.
//   * buf is 24 bytes, NOT Ghidra's 32: MIPS STARTING_FRAME_OFFSET = outgoing_args_size(20), so get_frame_size()
//     counts the 4-byte args-alignment gap. var=MIPS_STACK_ALIGN(4+24)=32 -> 32+24+28 -> 0x58. buf[32] gives 0x60.
//   * Block 1 uses RAW GLOBALS (D_8011F82C...) -> absolute lui/%lo; the ne-block uses `st+0x82`/`st+0x11C`
//     ($s3-relative) — both byte-confirmed; cse blocks end at labels so each region picks its own form.
//   * `ne` pinned to $v0 (+6 aligned).
//
// THE TWO LEVERS THAT CLOSED IT (SESSION-21, both byte-proven here; 18 -> 7 -> 3 -> 1 -> 0):
//   (L1) BLOCK-5 STORE DUPLICATED INTO BOTH ARMS (`if (f&1) *(e+0x32A)=0x200; else *(e+0x32A)=...+0x65;`)
//        instead of computing a phi `sv` and storing once after the merge.  Reason: sched1 is a BACKWARD list
//        scheduler and a store is a memory-unit user, so `potential_hazard` floats it to the FRONT of the
//        backward ready list => it is EMITTED ~8 insns late, which stretches the `sv`/`e` live ranges over
//        $v0/$v1/$a0/$a1 and pushes them out to $a2/$a3.  Writing the store in both arms lets cross_jump
//        merge the common tail, so the store lands first at the merge label, `sv`->$v0 and `e`->$a0, and the
//        `lui $a0` anti-dependence then PINS the schedule.  (18 mismatches -> 7.)
//   (L2) THE COMMUTATIVE-ADD OPERAND SWAP.  Target is `addu $a1,$s0,$v0` = plus(ret1, ret2) into a FRESH
//        non-call-crossing quantity that inherits the $a1 arg copy-suggestion.  Plain `sum = i6 + i4` lets
//        local_alloc TIE the dest to the dying `i6` (which crosses call2) => the whole chain is forced
//        call-saved => `addu $s0,$s0,$v0` (3 mismatched).  Accumulating (`i4 = i6 + i4`) frees $a1 but
//        expand_binop SWAPS a commutative op when target==op1, printing `addu $a1,$v0,$s0` (1 mismatched).
//        Fix: route the second call's value through a copy temp first —
//            sum = i4;  i4 = i6 + sum;
//        target(i4) != op1(sum) at EXPAND time so no swap; cse then folds sum back and deletes the copy.
//        => `addu $a1,$s0,$v0`.  MATCH.

extern void  func_80176FF4(s32);
extern void  func_80177340(s32);
extern u32   func_801783D0(s32, s32);
extern void  func_80177F84(s32, s32);
extern void func_80177DA8(u8 * p, u32 v, s32 idx);
extern void func_80177AD4(int, unsigned int);
extern s32   func_80024054(u8 *, u8 *);
extern u32 *func_80178298(u32*, u8*, short, short);
extern s32   func_8005A600(s32, s32, s32, s32, s32);

void func_80176218(s32 param_1)
{

    extern u16 D_80078EB2;
    extern u16 D_8011F82A;
    extern u16 D_8011F82C;
    extern s16 D_80078EB4;
    extern u16 D_8011F8C4;
    extern u8  D_8011F7A8;   /* st base  ($s3) */
    extern u8 D_80078E78[];   /* cur base ($s5) */
    extern u8  D_80187C6C[];
    extern u8 *D_80187BF0[];
    s32 st   = (s32)&D_8011F7A8;   /* $s3 */
    s32 cach = st + 0x48;          /* $s1 */
    s32 flag = st + 0xE0;          /* $s2 */
    s32 cur  = (s32)&(*(u8 *)D_80078E78);   /* $s5 */
    u8 buf[24];
    s32 ne;
    s32 t;
    u16 sA;

    /* ---- block 1: raw-global pair 0x3A/0x3C ---- */
    sA = D_80078EB2;
    t = (sA != D_8011F82A);
    if (D_8011F82C == (*(u16 *)&D_80078EB4)) {
        ne = t;
        if (ne == 0 && D_8011F8C4 == 0) goto L340;
    } else {
        s32 d = (s16)(D_8011F82C - (*(u16 *)&D_80078EB4));
        u16 nv;
        if (d < 0) {
            if (d < -10) nv = D_8011F82C + 2;
            else         nv = D_8011F82C + 1;
        } else {
            if (d > 10)  nv = D_8011F82C - 2;
            else         nv = D_8011F82C - 1;
        }
        D_8011F82C = nv;
        *(u16 *)(flag + 0x3C) = 1;
        *(u16 *)(cach + 0x3A) = *(u16 *)(cur + 0x3A);
        goto L328;
    }
    if (ne) {
        *(u16 *)(st + 0x82)  = sA;
        *(u16 *)(st + 0x11C) = 1;
    } else {
        *(u16 *)(st + 0x11C) = 0;
    }
L328:
    func_80176FF4(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18));
L340:

    /* ---- block 2: pair 0x3E/0x40 ---- */
    sA = *(u16 *)(cur + 0x3E);
    t = (sA != *(u16 *)(cach + 0x3E));
    if (*(u16 *)(cach + 0x40) == *(u16 *)(cur + 0x40)) {
        ne = t;
        if (ne == 0 && *(u16 *)(flag + 0x40) == 0) goto L444;
    } else {
        s32 d = (s16)(*(u16 *)(cach + 0x40) - *(u16 *)(cur + 0x40));
        u16 nc;
        if (d < 0) {
            if (d < -10) nc = *(u16 *)(cach + 0x40) + 2;
            else         nc = *(u16 *)(cach + 0x40) + 1;
        } else {
            if (d > 10)  nc = *(u16 *)(cach + 0x40) - 2;
            else         nc = *(u16 *)(cach + 0x40) - 1;
        }
        *(u16 *)(cach + 0x40) = nc;
        *(u16 *)(flag + 0x40) = 1;
        *(u16 *)(cach + 0x3E) = *(u16 *)(cur + 0x3E);
        goto L3E8;
    }
    if (ne) {
        *(u16 *)(cach + 0x3E) = sA;
        *(u16 *)(flag + 0x40) = 1;
    } else {
        *(u16 *)(flag + 0x40) = 0;
    }
L3E8:
    {
        s32 s0b = ((param_1 << 16) >> 14) + st;
        u16 cc;
        s32 pp;
        func_80177340(*(s32 *)(s0b + 0x18) + 0x104);
        cc = *(u16 *)(cach + 0x40);
        pp = *(s32 *)(s0b + 0x28);
        if (cc < 100)
            *(u8 *)(pp + 0x5D) = D_80187C6C[cc / 5];
        else
            *(u8 *)(pp + 0x5D) = 0;
    }
L444:

    /* ---- block 3: field 0x14 (s32) ---- */
    if (*(s32 *)(cach + 0x14) == *(s32 *)(cur + 0x14)) {
        if (*(s32 *)(flag + 0x14) == 0) goto L4D0;
        *(s32 *)(flag + 0x14) = 0;
        goto L4A8;
    } else {
        s32 d = *(s32 *)(cur + 0x14) - *(s32 *)(cach + 0x14);
        s32 nd;
        if (d > 0) {
            if (d < 10) nd = *(s32 *)(cach + 0x14) + 1;
            else        nd = *(s32 *)(cach + 0x14) + 10;
        } else {
            if (d < -9) nd = *(s32 *)(cach + 0x14) - 10;
            else        nd = *(s32 *)(cach + 0x14) - 1;
        }
        *(s32 *)(cach + 0x14) = nd;
        *(s32 *)(flag + 0x14) = 1;
    }
L4A8:
    {
        u32 r = func_801783D0(*(s32 *)(cach + 0x14), 0);
        func_80177F84(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18) + 0x208, r);
    }
L4D0:

    /* ---- block 4: field 0x34 (u16) + 0x42 (u8) ---- */
    if (*(u16 *)(cur + 0x34) != *(u16 *)(cach + 0x34)) {
        *(u16 *)(cach + 0x34) = *(u16 *)(cur + 0x34);
        *(u16 *)(flag + 0x34) = 1;
        *(u8 *)(cach + 0x42) = *(u8 *)(cur + 0x42);
    } else {
        if (*(u16 *)(flag + 0x34) == 0) goto L558;
        *(u16 *)(flag + 0x34) = 0;
    }
    {
        u16 e = 999;
        s16 r;
        if (*(u16 *)(cach + 0x34) < 1000) e = *(u16 *)(cach + 0x34);
        r = (s16)func_801783D0((s16)e, 4);
        func_80177DA8(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18) + 0x294,
                      (s32)r, *(u8 *)(cach + 0x42));
    }
L558:

    /* ---- block 5: field 0x1A (s16) ---- */
    if (*(s16 *)(cach + 0x1A) != *(s16 *)(cur + 0x1A)) {
        *(s16 *)(cach + 0x1A) = *(s16 *)(cur + 0x1A);
        *(s16 *)(flag + 0x1A) = 1;
    } else {
        if (*(s16 *)(flag + 0x1A) == 0) goto L63C;
        *(s16 *)(flag + 0x1A) = 0;
    }
    {
        u16 f = *(u16 *)(cach + 0x1A);
        s32 e = *(s32 *)(((param_1 << 16) >> 14) + st + 0x18);
        s32 i6, i4, sum;
        /* L1: the store is written into BOTH arms so cross_jump merges the tail (see header). */
        if (f & 1) *(s16 *)(e + 0x32A) = 0x200;
        else       *(s16 *)(e + 0x32A) = *(u16 *)(st + 0x16) + 0x65;
        {
            s32 t = (((s16)f / 15) & 3) * 15;
            i6 = func_801783D0(((s16)f / 15) * 0x10000 >> 0x12, 8);
            i4 = func_801783D0((t * 0x10000) >> 16, 0);
        }
        /* L2: copy temp defeats expand_binop's commutative swap; cse folds it back (see header). */
        sum = i4;
        i4 = i6 + sum;
        ((void (*)(s32, s32))func_80177AD4)(*(s32 *)(((param_1 << 16) >> 14) + st + 0x18) + 800,
                      i4 * 0x10000 >> 0x10);
    }
L63C:

    /* ---- block 6: field 0x4A (u8) ---- */
    if (*(u8 *)(cur + 0x4A) != *(u8 *)(cach + 0x4A)) {
        *(u8 *)(cach + 0x4A) = *(u8 *)(cur + 0x4A) & 0x7F;
        *(u8 *)(flag + 0x4A) = 1;
    } else {
        if (*(u8 *)(flag + 0x4A) == 0) return;
        *(u8 *)(flag + 0x4A) = 0;
    }
    {
        s32 s0b = ((param_1 << 16) >> 14) + st;
        u8 *arg = D_80187BF0[*(u8 *)(cach + 0x4A)];
        u32 *p = (u32 *)(*(s32 *)(s0b + 0x18) + 900);
        func_80024054(arg, buf);
        p = ((u32 * (*)(u32 *, u8 *, s32, s32))func_80178298)(p, buf,
                          (s16)(*(u16 *)(st + 0x14) + 0x39),
                          (s16)(*(u16 *)(st + 0x16) + 0x5B));
        func_8005A600((s32)p, 0, 0, 0x15, 0);
        *p = ((u32)((u8 *)p - 0x14) & 0xffffff) | 0x2000000;
        *(u32 **)(s0b + 0x20) = p;
    }
}
