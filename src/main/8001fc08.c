/* Main-exec range [8001FC08,80020248) from the SLUS executable.
 * SHA256(span)=988ccf15b7f42064a00b3dfc57012efac4690cae0e8e684e0aa78d5076a541e0.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001FC08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_8001FC08 — the src/800.c model/actor DRAW dispatcher (400 ins, binary main).
 *
 * Builds the object's world matrix (func_80020DA4 + optional func_80020F34 scale),
 * copies it back into the object at +0x34, then walks the NULL-terminated primitive
 * list at +0x24 calling per-mode add-prim helpers.  mode (+0x02) selects the emitter:
 * 0 -> func_80057094, 1 -> func_80027BF0 (first two only) / func_80055D40,
 * 5 -> func_800243EC, 6 -> func_800CAE80.
 *
 * match_one: MATCH, 400/400 ins, closeness 0.
 *
 * ---- INTEGRATION: RESOLVED (S77w) -------------------------------------------
 * The previous MATCH of this function (S76, closeness 0) could not BANK.  Cause,
 * now measured rather than guessed: it carried its own
 * `typedef struct {...} MTX_80020248;` plus `extern MTX_80020248 D_80074818[]/
 * D_80075018[]` at FILE scope, and the TU declares those very names 15 lines
 * BELOW this function's INCLUDE_ASM (src/800.c:11213 / :11221-2).  Splicing the
 * draft in and running the real cpp+cc1 gave THREE HARD ERRORS (cc1 rc=33 vs the
 * unmodified TU's rc=0):
 *     conflicting types for `MTX_80020248' / `D_80074818' / `D_80075018'
 * Two same-TU anonymous struct typedefs are never compatible types in C89, so no
 * spelling of a duplicate file-scope typedef can work; the old note's "hoist the
 * TU's block above the INCLUDE_ASM" would edit shared carve state for one draft.
 *
 * THE FIX, and why it is sound: gcc-2.7.2 raises "conflicting types" (error) only
 * for a redeclaration in the SAME scope.  Across scopes it degrades to
 * "type mismatch with previous external decl" (a WARNING — the same class the
 * unmodified TU already emits for func_80012E0C/func_80013028).  So this draft
 *   (a) names its own layout-identical struct `MTX_8001FC08`, never MTX_80020248, and
 *   (b) declares `D_80074818` / `D_80075018` at BLOCK scope inside the function.
 * Measured after the change: cc1 rc=0, exactly 4 added warnings, 0 errors, and the
 * whole-TU .text is BYTE-IDENTICAL to the all-INCLUDE_ASM build once the linker
 * resolves D_1F800020 (= 0x1F800020, per build/us/SLUS_007.26.map:4858) — no other
 * function in src/800.c shifts by a byte.  Nothing in src/ needs touching.
 *
 * The callee externs stay deliberately UNPROTOTYPED `f()` forms (C89-compatible
 * with every later prototype in the TU), which is what lets this function call
 * func_80021050 / func_80021120 with more arguments than their later same-TU
 * definitions declare — the target really does set those registers (lever 3).
 *
 * LAW 1c VERIFIED BY HAND (match_one masks relocations, so MATCH alone proves
 * nothing about symbol identity).  Against this target's OWN relocation lines:
 *   - 26 `jal` targets, identical in name AND order;
 *   - 16 HI16/LO16 relocs, identical in name AND order (D_800B9A02, D_80062BA8,
 *     D_800A6518, D_800A5BD0, D_80074818 x2, D_80075018 x2);
 *   - all 16 internal `j` destinations decoded and equal (the §195-D blind spot,
 *     which match_one, the permuter scorer and every similarity tier cannot see);
 *   - the four words splat prints as %hi/%lo(D_1F800020) are NOT a real symbol —
 *     they are `lui $s1,0x1F80` (the 0x1F800000 scratchpad literal) and the
 *     `rm++` +0x20 pointer increment, which splat mis-paired into one fake
 *     symbol whose value happens to agree.  ROM 3C111F80 / 26310020 at words
 *     180/239/262/375; this draft emits those same four words directly.
 * ------------------------------------------------------------------------------
 *
 * LEVERS THAT MOVED THE BYTES (each byte-measured; 1-3 took the standing best
 * from closeness 33 to 0, and are kept verbatim from the S76 attempt):
 *
 *  0. (carried from the previous attempt, all still required)
 *     - the 0x18..0xC7 locals area is ONE address-taken aggregate;
 *     - `s32 mode`, NOT `u16 mode` (as u16 it loses its global allocno);
 *     - struct copies must be <= 32 B (`obj->mm.a = L.mm.a;` twice, never
 *       `obj->mm = L.mm`, which becomes a block_move loop);
 *     - `if (f() == 0) { main-RAM } else { scratchpad }` — the ZERO test is the
 *       fall-through arm for BOTH func_80020248 and func_80020A28;
 *     - `objs & 0xFEFFFFFF` must be a NAMED local computed BEFORE the
 *       `if (flags & 0x40)` (gcc-2.7.2 has no PRE);
 *     - the 0x7F000000 tag mask is computed BEFORE the 0x80FFFFFF mask.
 *
 *  1. *** THE 8-BYTE SPILL SLOT.  sp+0xC8 and sp+0xD0 are NOT struct members —
 *     they are two SPILLED PSEUDOS. ***  `ot` (= D_80062BA8) and `spr` (= the
 *     +0x80 handle) are ordinary long-lived locals; $s0-$s7 + $fp are already
 *     taken by obj/om, objs/rm, mode, list, flags, sp5, otp, attr and fpc — nine
 *     values — so these two are the 10th/11th and reload spills them.
 *     The TELL, and the reason this is not guesswork: reload's `alter_reg` calls
 *     `assign_stack_local (mode, size, -1)`, and align == -1 means
 *     `alignment = BIGGEST_ALIGNMENT` (8 on MIPS) with `size = CEIL_ROUND(size,8)`
 *     — so every 4-byte spill slot occupies EIGHT bytes.  That is exactly why the
 *     target's slots are 8 apart (0xC8, 0xD0) with 0xCC and 0xD4 never touched,
 *     while the declared aggregate ends at 0xC8 (0x18 + 0xB0) and the saves start
 *     at 0xD8: 0x18 args + 0xB0 aggregate + 0x10 spills + 0x28 saves = 0x100.
 *     ANY 4-byte gap in a frame otherwise packed at 4 is a spill slot, not a pad.
 *     A spilled pseudo also RE-LOADS at every use, which is what the previous
 *     attempt was faking with a `volatile` struct member.
 *     Worth 11 instructions on its own (33 -> 22): it takes both slots out of
 *     local-alloc's pool, so reload picks their registers ($t0) instead of $v0.
 *
 *  2. *** THE PRE-PROLOGUE LOAD IS NOT A WALL — it is an $a0 ANTI-DEPENDENCE. ***
 *     The target opens with `lui/lhu $v1, D_800B9A02` BEFORE `addiu $sp,$sp,-0x100`.
 *     The previous attempt proved from the -dR sched2 dump that no statement order
 *     reaches it and filed it as the §41b "global load above the RTL prologue"
 *     wall (20 of its 33).  That reading was wrong.  sched2 weaves body insns into
 *     the RTL prologue freely (S7); the load is one insn (the -G0 macro form,
 *     length 2), it depends on nothing, and it floats to the very top of the block
 *     — UNLESS it lands in $a0, because the param copy `addu $s0,$a0,$zero` READS
 *     $a0 and pins it below.  So the fix is two independent moves that must be
 *     made TOGETHER:
 *       (a) make `otp = &D_800A6518[D_800B9A02 * 20];` the FIRST statement (LUID), and
 *       (b) get the value out of $a0 — which lever 1 does for free: once `ot` is a
 *           spilled pseudo it leaves local-alloc's pool, so the index temp takes
 *           $v1 instead and nothing anchors it.
 *     Either alone is worthless (statement-first alone MEASURED 33 -> 50).
 *     Together: 22 -> 4.  The `sll/addu/sll` scaling chain stays behind at its own
 *     priority (load-fed, pri 2), which is why the target shows the load at idx 0
 *     and its own multiply at idx 22.
 *
 *  3. *** `func_80021120(&L.cnt, L.lp)` — the guard value IS the second argument. ***
 *     The last 4: the target reads sp+0xC0 into $a1 at the two func_80021120 guards
 *     but into $v0 at the two func_8002109C guards.  $a1 is unreachable by
 *     local-alloc's scan-from-$v0 unless the pseudo carries a COPY SUGGESTION to a
 *     hard reg (`qty_phys_copy_sugg`) — i.e. unless that very value is passed to the
 *     call as arg 1.  Passing it makes the test load land in $a1 and coalesces the
 *     copy away at zero cost.  func_8002109C's guard does NOT pass it, and stays $v0
 *     — which is the control that proves the mechanism rather than a coincidence.
 *     (The same reading explains the extra argument at func_80021050/func_80021008.)
 *     A `register s16 * __asm__("$5")` pin also reaches MATCH, but this is the form
 *     the original had: no pin, no asm.  4 -> 0.
 */

typedef struct { s16 m[3][3]; s32 t[3]; } MTX_8001FC08;             /* 0x20 */
typedef struct { MTX_8001FC08 a; MTX_8001FC08 b; } MTX2_8001FC08;   /* 0x40 */

typedef struct {
/* 0x00 */ u16 h00;
/* 0x02 */ u16 mode;
/* 0x04 */ u32 attr;
/* 0x08 */ s16 x;
/* 0x0A */ s16 y;
/* 0x0C */ s16 z;
/* 0x0E */ u16 h0E;
/* 0x10 */ s16 rot[3];
/* 0x16 */ u16 h16;
/* 0x18 */ s16 scale[3];
/* 0x1E */ u16 h1E;
/* 0x20 */ u32 objs;
/* 0x24 */ s32 *list;
/* 0x28 */ s32 w28;
/* 0x2C */ u16 flags;
/* 0x2E */ u16 idx;
/* 0x30 */ s32 w30;
/* 0x34 */ MTX2_8001FC08 mm;
/* 0x74 */ s32 w74;
/* 0x78 */ s32 w78;
/* 0x7C */ s32 w7C;
/* 0x80 */ s32 w80;
} OBJ_8001FC08;

typedef struct {
/* 0x00 */ s32 attr;
/* 0x04 */ s32 u04;
/* 0x08 */ s32 u08;
/* 0x0C */ s32 u0C;
/* 0x10 */ s32 u10;
/* 0x14 */ s32 u14;
/* 0x18 */ MTX_8001FC08 m0;
/* 0x38 */ MTX_8001FC08 m1;
/* 0x58 */ s32 f;
/* 0x5C */ MTX2_8001FC08 mm;
/* 0x9C */ s32 u9C;
/* 0xA0 */ s32 uA0;
/* 0xA4 */ s32 uA4;
/* 0xA8 */ s16 *lp;
/* 0xAC */ s32 cnt;
} LOC_8001FC08;   /* 0xB0 */

extern u8  D_800A6518[];
extern u8  D_800A5BD0[];
extern u16 D_800B9A02;
extern s32 D_80062BA8;

extern void func_80020DA4();
extern void func_80020F34();
extern s32  func_80020248();
extern void func_80020598();
extern s32  func_80020A28();
extern void func_80054AAC();
extern s32  func_80021174();
extern void func_80021008();
extern void func_80021050();
extern void func_8002109C();
extern void func_80021120();
extern void func_80056F18();
extern void func_80052F04();
extern void func_80052E38();
extern void func_80057094();
extern void func_80055D40();
extern void func_80027BF0();
extern void func_800243EC();
extern void func_800CAE80();

void func_8001FC08(OBJ_8001FC08 *obj)
{
    LOC_8001FC08 L;
    extern MTX_8001FC08 D_80074818[];
    extern MTX_8001FC08 D_80075018[];
    MTX_8001FC08 *rm;
    MTX_8001FC08 *om;
    s32 *list;
    u8 *sp5;
    u8 *otp;
    u32 attrv;
    u32 objs;
    u32 w;
    u32 m;
    u32 tag;
    u32 n;
    s32 mode;
    u16 flags;
    u32 fpc;
    s32 ot;
    s32 spr;

    otp = &D_800A6518[D_800B9A02 * 20];
    attrv = obj->attr;
    mode = obj->mode;
    flags = obj->flags;
    L.uA0 = obj->w78;
    ot = D_80062BA8;
    L.f = 0;

    if (flags & 1) {
        obj->flags &= ~1;
        L.mm.a = obj->mm.a;
    } else {
        func_80020DA4((s32)obj->rot, (s32)&L.mm.a);
        L.mm.a.t[0] = obj->x;
        L.mm.a.t[1] = obj->y;
        L.mm.a.t[2] = obj->z;
    }

    spr = 0;
    if (flags & 0x20) {
        spr = obj->w80;
    }
    if (flags & 0x80) {
        if (spr != 0) {
            L.lp = (s16 *)(obj->w80 + 0x30);
        } else {
            L.lp = (s16 *)obj->w80;
        }
    } else {
        L.lp = 0;
    }
    L.cnt = 0;
    fpc = 0;
    if (flags & 0x10) {
        func_80020F34((s32)&L.mm.a, (s32)obj->scale);
    }

    func_80054AAC((s32)&L.f, (s32)&L.m0, (s32)&L.m1);

    obj->mm.a = L.mm.a;
    obj->mm.b = L.mm.b;

    list = obj->list;
    if (list == 0) {
        return;
    }
    objs = obj->objs;
    if (objs == 0) {
        return;
    }
    if (func_80021174(obj->w28, (s32)&L.mm.b.t[0]) == 0) {
        return;
    }

    if (mode == 1 || mode == 6) {
        sp5 = &D_800A5BD0[obj->idx * 20];
        L.attr = attrv;
        L.u10 = 0;
    } else {
        L.attr = attrv;
    }

    if (spr != 0) {
        func_80021008(spr);
    }

    if ((objs & 0x01000000) == 0 && (flags & 0x40) == 0) {
        if (func_80020248(list, objs, (s32)&L.m0, (s32)&L.m1, attrv & 0x40) == 0) {
            rm = D_80074818;
            om = D_80075018;
        } else {
            rm = (MTX_8001FC08 *)0x1F800000;
            om = (MTX_8001FC08 *)0x1F8000E0;
        }
        w = *list;
        if (w != 0) {
            do {
                tag = w & 0x7F000000;
                m = w & 0x80FFFFFF;
                if (tag != 0x01000000) {
                    func_80056F18(m + 0xC, (s32)&L, 0);
                    if ((attrv & 0x40) == 0) {
                        func_80052F04(rm);
                    }
                    func_80052E38(om);
                    if (L.lp != 0) {
                        func_8002109C(L.cnt, &L.lp);
                    }
                    if (mode == 0) {
                        func_80057094((s32)&L, (s32)otp, 0, ot);
                    } else if (mode == 5) {
                        func_800243EC((s32)&L, (s32)otp, 0);
                    }
                }
                if (L.lp != 0) {
                    func_80021120(&L.cnt, L.lp);
                }
                list++;
                rm++;
                om++;
                w = *list;
            } while (w != 0);
        }
    } else {
        n = objs & 0xFEFFFFFF;
        if (flags & 0x40) {
            func_80020598(list, n, (s32)&L.m0, (s32)&L.m1);
            rm = D_80074818;
            om = D_80075018;
        } else {
            if (func_80020A28(list, n, (s32)&L.m0, (s32)&L.m1,
                              attrv & 0x40) == 0) {
                rm = D_80074818;
                om = D_80075018;
            } else {
                rm = (MTX_8001FC08 *)0x1F800000;
                om = (MTX_8001FC08 *)0x1F8000E0;
            }
        }
        w = *list;
        if (w != 0) {
            do {
                tag = w & 0x7F000000;
                m = w & 0x80FFFFFF;
                if (tag == 0x01000000) {
                    if (mode == 1 || mode == 6) {
                        sp5 += 0x14;
                    }
                } else {
                    if (mode == 0 || mode == 5) {
                        func_80056F18(m + 0xC, (s32)&L, 0);
                    } else if (mode == 1 || mode == 6) {
                        L.u08 = *(s32 *)(sp5 + 8);
                        L.u0C = *(s32 *)(sp5 + 0xC);
                        sp5 += 0x14;
                    } else {
                        L.u08 = m;
                    }
                    if ((attrv & 0x40) == 0) {
                        func_80052F04(rm);
                    }
                    func_80052E38(om);
                    if ((flags & 0x40) == 0 && L.lp != 0) {
                        func_8002109C(L.cnt, &L.lp);
                    }
                    if (mode == 0) {
                        func_80057094((s32)&L, (s32)otp, 0, ot);
                    } else if (mode == 1) {
                        if (fpc < 2) {
                            func_80027BF0((s32)&L, (s32)otp, 0);
                            fpc++;
                        } else {
                            func_80055D40((s32)&L, (s32)otp, 0, ot);
                        }
                    } else if (mode == 6) {
                        func_800CAE80((s32)&L, (s32)otp, 0);
                    } else if (mode == 5) {
                        func_800243EC((s32)&L, (s32)otp, 0);
                    }
                }
                if ((flags & 0x40) == 0 && L.lp != 0) {
                    func_80021120(&L.cnt, L.lp);
                }
                list++;
                rm++;
                om++;
                w = *list;
            } while (w != 0);
        }
    }

    if (spr != 0) {
        func_80021050(spr);
    }
}
