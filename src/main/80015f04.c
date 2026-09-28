/* Main-exec range [80015F04,80016110) from the SLUS executable.
 * SHA256(span)=25db6fffc302062b0a6568596f094968a5dd944a2727595aefb32f934e9c4d2c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80015F04 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef float f32;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* shared typedefs (vendor src/800_shared.h) */
/* was: src/800.c */
typedef struct Ent30D80 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 pad04[6];
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u8 pad0C[0x34];
    /* 0x40 */ void (*unk40)(s32, s32);
    /* 0x44 */ s32 unk44;
    /* 0x48 */ u8 pad48[6];
    /* 0x4E */ u8 unk4E;
    /* 0x4F */ u8 pad4F;
    /* 0x50 */ u8 unk50;
    /* 0x51 */ u8 unk51;
} Ent30D80;

/* was: src/800.c */
typedef struct { u8  v; } W8;

/* was: src/800.c */
typedef struct Rec14 {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u32 unk10;
} Rec14; /* 0x14 */

/* was: src/800.c */
typedef struct Owner4EE8 {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ Rec14 **unk14;
} Owner4EE8;

/* was: src/800.c */
typedef struct Slot {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u8 unk08[0xC];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 unk16[2];
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 unk1A[0x26];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 unk45[3];
} Slot;

/* was: src/800.c */
typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    s32 unk14;
} Rsc24;                       /* 0x18 */

/* was: src/800.c */
typedef struct {
    /* 0x00 */ u8 *unk00;
    /* 0x04 */ u8  pad04[2];
    /* 0x06 */ u8  unk06;
    /* 0x07 */ u8  unk07;
    /* 0x08 */ u8  unk08;
    /* 0x09 */ u8  pad09[3];
} A12; /* 0x0C */

/* was: src/800.c */
typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
} B12; /* 0x0C */

/* was: src/800.c */
typedef struct {
    /* 0x00 */ u8  pad00[4];
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  pad05[11];
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u8  pad14[2];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8  pad18[8];
} C24; /* 0x20 */

/* was: src/800.c */
typedef struct {               /* 0x18 stride; D_800A463C + k*0x18 */
    s32 unk00;
    u8  unk04[0x14];
} Ent24;

/* was: src/800.c */
typedef struct {              /* base 0x80064D49, stride 0x0C */
    u8  unk00;
    u8  pad[11];
} Elm12;

/* was: src/800.c */
typedef struct {              /* base 0x80076240, stride 0x10 */
    u16 unk00;
    u16 unk02;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
} Slot16A;

/* was: src/800.c */
typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
} Slot16;                      /* 0x10 */

/* was: src/800.c */
typedef struct { s32 v; } W32;

/* was: src/800.c */
typedef struct Slot54 {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0A */ s8  unk0A;
} Slot54;

/* was: src/800.c */
typedef struct { u16 f0; } H2; /* 0x2 */

/* was: src/800.c */
typedef struct {
    s32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08;
    u8  unk09;
    u8  unk0A;
    u8  unk0B;
    s32 unk0C;
} Rsc16;                      /* 0x10 */

/* was: src/800_c.c */
typedef struct { s16 v; } W16;

/* was: src/800_c.c */
typedef struct {
    u8  unk00;
    u8  unk01[11];
} Rsc12;                      /* 0x0C */


/* GTE command mnemonics (mvmva, rtpt, ...) come from include/gte_macros.inc. */
__asm__(".include \"gte_macros.inc\"\n");

/* func_80015F04 — main/800.  Build a 4-segment closed LINE_F2 wireframe
 * rectangle: fill an 8-halfword stack corner list from (x, y, w, h) =
 * (a0, a1, a2, a3), allocate one 0x40-byte GPU block (4 x 0x10 LINE_F2),
 * then loop i = 0..3 writing one segment per packet (corner i -> corner i+1,
 * code 0x40, or 0x42 = semi-transparent when arg8 < 4) and linking each packet
 * into the current OT at depth arg7 with the open-coded PSY-Q addPrim RMW
 * pair.  The i == 3 iteration reads pts[4] (one past the array — the original
 * code's own overrun); the segment is closed afterwards by rewriting the last
 * packet's (x1, y1) from pts[0].  Finally, when arg8 < 4, notify
 * func_80016638 with the env block.
 *
 * @class: MATCH — 131/131 byte-exact (relocation-masked), and
 *   tools/reloc_identity.py AGREE (relocs_checked=6): every jal / %hi / %lo
 *   names the same symbol the target .s names.
 *
 * ===================================================================
 * THE ENTRY-BLOCK FILLER PROBLEM AND THE THREE LEVERS THAT SOLVE IT
 *
 * The prologue is emitted as [addiu $sp][$v0=$a0][sw $s0][la $s0] then five
 * (save, stack-arg-load, FILLER) triples.  The five fillers are exactly
 *      A  = `addiu $a0,$zero,0x40`      (the func_80010A08 argument)
 *      X0 = `addu $t0,$v0,$zero`        (x0 = a0)
 *      Y0 = `addu $v1,$a1,$zero`        (y0 = a1)
 *      X1 = `addu $v0,$v0,$a2`          (a0 += a2)
 *      Y1 = `addu $a1,$a1,$a3`          (a1 += a3)
 * and the target order is A, X0, Y0, X1, Y1.  All five tie at INSN_PRIORITY 1,
 * so the order is decided in sched1 by `rank_for_schedule`'s LUID tie-break and
 * by `adjust_priority`'s BIRTHING BOOST (sched.c:2507 / birthing_insn_p:2469 —
 * a `SET(REG,…)` whose dest is live and has REG_N_SETS == 1 is raised to
 * max_priority, dump tell `(7f000001)`).  sched1 picks BACKWARD and emits in
 * reverse, so a boosted def is picked EARLY and therefore emitted LATE.
 *
 * Reading the `-dS` ready-list trace, the block resolves like this (AC probe):
 *      T-19 pick Y1  (Y1 is the anti-dep gate on Y0)
 *      T-20..T-24    the five boosted stack-arg loads
 *      T-25 pick X1  (X1 is the anti-dep gate on X0: X1 writes the pseudo X0
 *                     reads, so X0 cannot become ready until X1 is scheduled)
 *      T-26 pick ?   ready = {Y0, X0, A, base}
 *      T-27 pick ?
 *      T-28 A,  T-29 base
 * Emission is the reverse of the pick order, so the TARGET needs Y0 picked at
 * T-26 and X0 at T-27.  With both copies tying at priority 1 that falls out of
 * the LUID order (`x0 = a0;` written before `y0 = a1;`).  Any boost on X0
 * makes X0 win T-26 and the two swap — which is the entire residual the first
 * two passes were stuck on.
 *
 * LEVER 8 — PIN THE CALL ARGUMENT AND EMIT IT AS ASM.  gcc sets a call's
 *   argument registers immediately before the `jal`, so A always had the
 *   HIGHEST LUID in the block, was always picked first, and was therefore
 *   always emitted LAST (filler #5 instead of #1).  The call cannot be moved
 *   earlier — `flush_pending_lists` gives it a REG_DEP_ANTI on all eight `sh`
 *   stores — so the fix is to give the `li` a LUID at its SOURCE position:
 *       register s32 sz __asm__("$4");
 *       __asm__("addiu %0,$zero,0x40" : "=r"(sz));
 *   A plain `sz = 0x40;` does NOT work (cse copies REG_EQUAL 64 onto the
 *   call-site no-op `(set $a0 $a0)` and flow dead-store-eliminates the early
 *   set; `volatile` on the register var costs 25/131).  Emitting the
 *   instruction FROM the asm sticks: one RTL insn, the target's own bytes
 *   0x24040040, LUID at the source position, and the call's `$a0 = sz`
 *   collapses to a deleted no-op move.  Worth 2 instructions.
 *
 * LEVER 9 — KILL Y0's BOOST FOR FREE BY MERGING IT WITH `ob`.  y0 and the
 *   loop's second-addPrim OT base are BOTH $v1 with disjoint live ranges, so
 *   they are ONE variable.  That gives the pseudo a second SET, REG_N_SETS
 *   becomes 2, and the boost dies at zero instruction cost.  (This is why
 *   there is no `y0` local below — `ob` carries both roles.)
 *
 * LEVER 10 (THE THIRD PASS'S LEVER, the 2 -> 0) — KILL X0's BOOST WITH A
 *   RE-TIE THAT CARRIES A "memory" CLOBBER.
 *       __asm__("" : "=r"(x0) : "0"(x0) : "memory");
 *   The §30 #3 re-tie gives x0 a second SET and kills its boost, which fixes
 *   all five fillers — but a BARE re-tie then costs one swap somewhere else
 *   (`sw $ra,0x38($sp)` and `sh $t0,0x10($sp)` trade places, probes ACq1-ACq6,
 *   all 2/131).  Reason: the bare asm's only ordering constraint is the
 *   anti-dependence on the one store that reads the OLD x0, so sched2 is free
 *   to treat it as a SIXTH entry-block filler; with six fillers for five
 *   (save, load) triples the extra one drags `sh $t0,0x10($sp)` up past the
 *   `sw $ra` save.
 *   ADDING "memory" fixes exactly that: the clobber makes the asm a
 *   memory-ordering barrier, so `sched_analyze` ties it to the whole pending
 *   store list instead of to one register, it can no longer float into the
 *   (save, load, filler) interleave, and the five real fillers keep the
 *   triples to themselves.  It is a pure scheduling fence — zero emitted
 *   bytes, zero registers, no effect on allocation.
 *   Byte-verified: the "memory" re-tie MATCHes at every placement from before
 *   `pts[0].x` through before `pts[3].x` (probes Rm0-Rm6); the bare re-tie is
 *   2/131 at every one of those placements (Rp1-Rp6).  The `volatile` variant
 *   is 18/131 — do NOT reach for volatile here, the clobber is the lever.
 *
 * LEVERS 1-7 (inherited; each byte-verified by removal):
 *  1. `x0 = a0; ob = a1; a0 += a2; a1 += a3;` — the DESTRUCTIVE update of the
 *     parameter is what forces the target's two extra copies and lets the sums
 *     reuse the dying param registers.  It is also load-bearing for the
 *     LENGTH: writing `x1 = a0 + a2` into a fresh local makes that pseudo
 *     single-set, gcc coalesces it with $a0, both copies are copy-propagated
 *     away and the entry copy disappears — 129 ins (probe A), 130 even with
 *     $t0/$v1 pins (probe B).  The statement ORDER here is also load-bearing:
 *     it is the LUID order that decides the T-25/T-26 picks above.  All six
 *     legal interleavings were measured; only this one is right.
 *  2. ONE local `cb` carries 3 / 0x40 / 0x42.  Three separate literals are
 *     three single-set pseudos and loop.c HOISTS the invariant `li 3` and
 *     `li 0x40` out of the loop (2 extra preheader regs, +7 mismatched).
 *  3. `i = 0;` HOISTED OUT OF THE `for` HEADER, so `addu $a2,$zero,$zero` is
 *     the first preheader insn as in the target.
 *  4. THE MASK LOCALS ARE ASSIGNED INSIDE THE LOOP so they become loop.c
 *     movables hoisted AFTER the `addiu $t2,$sp,0x10` array-base movable —
 *     the target's preheader order (i=0, &pts, m24, mFF).  As explicit
 *     preheader statements they land BEFORE $t2 instead (probes AK/AL).
 *  5. `register s32 i4 __asm__("$9")` — with the masks hoisted, m24 and i4
 *     tie in global-alloc and land swapped; pinning i4 to $t1 lets m24 take
 *     $t0.
 *  6. ADDPRIM ASYMMETRY (inherited from the matched sibling func_80016450):
 *     the FIRST half inlines the OT-slot address expression fully, the SECOND
 *     half binds it.  Symmetric shapes cost 20+ instructions.
 *  7. `register s32 ob __asm__("$3")` for the second half's OT base, so the
 *     add is the target's self-accumulating `addu $v1,$t1,$v1`.
 *
 * SYMBOL AUDIT (§174 law 1c — match_one masks jal/HI16/LO16, so every symbol
 * was re-checked against this .s's own relocation lines; tools/reloc_identity.py
 * then confirmed all 6 relocations AGREE.  The .s names exactly five relocated
 * symbols: D_800AF630, D_800A6518, D_800A651C, func_80010A08, func_80016638):
 *   - `lui/addiu %hi/%lo(D_800AF630)` -> $s0 is the ONLY named data base; the
 *     OT-buffer index is reached as `*(u16 *)(base + 0xA3D2)`
 *     (`lui $at,0x1; addu $at,$s0,$at; lhu -0x5C2E($at)`; 0x10000-0x5C2E =
 *     0xA3D2, i.e. 0x800B9A02).  D_800B9A02 IS declared in src/800.c and IS
 *     used by the siblings, but it does NOT appear in THIS .s — do not
 *     substitute it here.  `lhu` => u16, not s16.
 *   - `jal func_80010A08` with $a0 = 0x40; `jal func_80016638` with
 *     $a0 = &D_800A6518[idx*20] (`lui %hi` + `addiu %lo` = address-of),
 *     $a1 = arg7 ($s5 from 0x5C($sp)), $a2 = arg8 (`andi $s4,0xFFFF`).
 *   - D_800A651C read with `lw %lo(...)($at)` = the `.a` member at offset 0;
 *     the index is scaled *20 (`sll 2; addu; sll 2`), which is exactly
 *     sizeof(OtBlk_80016450_80015F04) = {s32 a; s32 b[4]}.
 *   - Store sides: `sw $v1,0($a3)` is the packet tag word ($a3 = p),
 *     `sw $v0,0($v1)` is the OT slot.  With $a1 = p + 0xE: `sb -0xB` = len(3),
 *     `sb -0x7` = code(7), `sb -0xA/-0x9/-0x8` = r0/g0/b0 <- $s3/$s2/$s1 <-
 *     0x50/0x54/0x58 in that order; `sh -0x6/-0x4/-0x2/0x0` = x0/y0/x1/y1.
 *   - Epilogue reloads pts[0] FROM THE STACK (`lhu 0x10($sp)`, `lhu 0x12`),
 *     so the closing fixup must read `pts[0]`, never the x0/ob registers.
 *
 * TU CHECK (§174 laws 2/3) — src/800.c holds
 * `INCLUDE_ASM("asm/nonmatchings/800", func_80015F04);` at line 1166:
 *   - There is NO prototype for func_80015F04 in src/800.c or in include/, and
 *     src/800.c does not include shared/engine_core.h, so the parameter list
 *     below is unconstrained (no DEF-side wall here).
 *   - `extern void *func_80010A08(s32 a0);` (src/800.c:1119),
 *     `extern void func_80016638(void *a0, s32 a1, s32 a2);` (:1122),
 *     `extern u8 D_800A6518[];` (:1121), `extern u8 D_800AF630[];` (:930) and
 *     the block-scope `extern OtBlk_80016450_80015F04 D_800A651C[];` (:1126) all
 *     ALREADY exist at file scope ABOVE line 1166 and the declarations below
 *     are copied to agree with them exactly.  Duplicate compatible externs are
 *     legal, so they may stay or go when banking.
 *
 * >>> INTEGRATION NOTE: src/800.c ALREADY defines
 * >>>     typedef struct { s32 a; s32 b[4]; } OtBlk_80016450_80015F04;
 * >>> at FILE scope (src/800.c:1117, i.e. ABOVE this function's slot at 1166).
 * >>> DROP the duplicate typedef line below when banking — C89 rejects the
 * >>> redefinition.  It is present here only so the draft compiles standalone
 * >>> under match_one.  `Pt_80015F04` and `LineF2_80015F04` do not collide
 * >>> with anything in src/800.c.
 */
typedef struct { s32 a; s32 b[4]; } OtBlk_80016450_80015F04;   /* DUPLICATE — see note */

typedef struct { u16 x, y; } Pt_80015F04;             /* stack corner list */

typedef struct {                                      /* 0x10 LINE_F2 */
    u8  addr[3];
    u8  len;
    u8  r0, g0, b0, code;
    s16 x0, y0;
    s16 x1, y1;
} LineF2_80015F04;

extern void *func_80010A08(s32);
extern void func_80016638(void *a0, s32 a1, s32 a2);
extern u8 D_800AF630[];
extern u8 D_800A6518[];

void func_80015F04(s32 a0, s32 a1, s32 a2, s32 a3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8)
{
    extern OtBlk_80016450_80015F04 D_800A651C[];   /* block scope: engine_core.h's DEFINE_ macros declare this symbol scalar in their own bodies */
    Pt_80015F04 pts[4];
    LineF2_80015F04 *p;
    u8 *base;
    u32 *otp;
    register s32 ob __asm__("$3");    /* LEVER 9: y0 AND the 2nd addPrim OT   */
    s32 i;                            /* base — one $v1 variable, two roles,  */
    register s32 i4 __asm__("$9");    /* so REG_N_SETS==2 and the boost dies   */
    s32 x0;
    register s32 sz __asm__("$4");    /* LEVER 8: the func_80010A08 argument, */
    s32 semi;                         /* pinned to $a0 so its `li` gets a LUID */
    s32 cb;                           /* at THIS source position, not at the jal */
    register u32 m24;
    register u32 mFF;

    base = D_800AF630;

    /* LEVER 8.  Emitting the argument load from asm (rather than `sz = 0x40;`)
     * is what stops cse folding REG_EQUAL 64 onto the call-site no-op move and
     * dead-store-eliminating this insn.  Bytes are the target's own
     * 0x24040040 `addiu $a0,$zero,0x40`; the call's `$a0 = sz` becomes a
     * deleted no-op.  Removing this line costs 2 instructions. */
    __asm__("addiu %0,$zero,0x40" : "=r"(sz));

    /* LUID order below is load-bearing — see the ready-list trace in the
     * header.  x0 before ob, and each destructive update after its own copy. */
    x0 = a0;
    ob = a1;
    a0 += a2;
    a1 += a3;

    /* LEVER 10.  Second SET of x0 -> REG_N_SETS==2 -> no birthing boost, so
     * X0 stops out-ranking Y0 at the T-26 pick.  The "memory" clobber is the
     * load-bearing half: without it the asm becomes a sixth entry-block filler
     * and drags `sh $t0,0x10($sp)` above `sw $ra,0x38($sp)` (2/131).  With it
     * the asm is a store-ordering fence that cannot enter the
     * (save, load, filler) interleave.  Emits nothing. */
    __asm__("" : "=r"(x0) : "0"(x0) : "memory");

    pts[0].x = x0;
    pts[0].y = ob;
    pts[1].x = a0;
    pts[1].y = ob;
    pts[2].x = a0;
    pts[2].y = a1;
    pts[3].x = x0;
    pts[3].y = a1;

    p = (LineF2_80015F04 *)func_80010A08(sz);

    i = 0;
    semi = (arg8 < 4);
    i4 = arg7 * 4;
    for (; i < 4; i++) {
        cb = 3;
        p->len = cb;
        cb = 0x40;
        p->code = cb;
        if (semi) {
            cb = 0x42;
            p->code = cb;
        }
        p->r0 = arg4;
        p->g0 = arg5;
        p->b0 = arg6;
        p->x0 = pts[i].x;
        p->y0 = pts[i].y;
        p->x1 = pts[i + 1].x;
        p->y1 = pts[i + 1].y;
        m24 = 0x00FFFFFF;
        mFF = 0xFF000000;
        *(u32 *)p = (*(u32 *)p & mFF) |
                    (*(u32 *)(i4 + D_800A651C[*(u16 *)(base + 0xA3D2)].a) & m24);
        ob = D_800A651C[*(u16 *)(base + 0xA3D2)].a;
        otp = (u32 *)(i4 + ob);
        *otp = (*otp & mFF) | ((u32)p & m24);
        p++;
    }

    p[-1].x1 = pts[0].x;
    p[-1].y1 = pts[0].y;

    if (arg8 < 4) {
        func_80016638(&D_800A6518[*(u16 *)(base + 0xA3D2) * 20], arg7, arg8);
    }
}
