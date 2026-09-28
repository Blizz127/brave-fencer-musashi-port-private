/* Overlay range [8017DD28,8017DF18) from MAIN.CD member 0012.
 * SHA256(span)=6cffc999246d9e4de0e07f6c2509bfd0bc6d745aad664c52c3b1fecba9238235.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DD28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_8017DD28 @ 0x8017DD28 — ov_MAIN_012 / jr_8017CF3C, 124 ins, frame 0x30.
 * Family exemplar (reach x5, zero prior cracks).
 *
 * WHAT IT DOES.  Fills one 0x14-byte SPRT (tag 0x04000000, rgb/code 0x64808080,
 * u0/v0 = 0x70/0x10, clut 0x4056, w/h = 0x10/0x10) whose x/y come from the
 * current HUD panel's Prim4 (D_80115134[D_8011511A].f18), offset by a table
 * value when D_8011512C == 1.  Links it into the OT with the psyq addPrim
 * idiom, advances past it, has func_8005A600 (SetDrawTPage-shaped, 2 words)
 * write the next primitive, links THAT one too, and returns the write cursor.
 *
 * STEP-0 SIBLING (cookbook §160g) — the whole prim fill + the PTag bitfield
 * addPrim were copy-edited from the already-banked, SAME-OVERLAY
 *   src/ov_MAIN_012/ov_MAIN_012_jr_8013F350.c:1746  func_80140D68
 * which has the identical 0x04000000 / 0x70 / 0x10 / 0x64808080 / 0x4056 /
 * 0x10 / 0x10 store sequence and the identical
 *   ((PTag *)out)->addr = ((PTag *)(D_800AE7BC[*pb].ot + 2))->addr;
 *   ((PTag *)(D_800AE7BC[*pb].ot + 2))->addr = (u32)out;
 * pair.  Only the 24-bit-bitfield spelling emits exactly two `and`s per half.
 *
 * THE THREE LEVERS (each byte-measured with tools/match_one.py):
 *
 *  [L1] `out += 5;` IN PLACE, never `p = out + 5;`.  A second pointer local is
 *       a 5th callee-saved allocno: frame stays 0x30 but the target's four
 *       ($s0..$s3) become five ($s0..$s4) and every save/restore shifts.
 *       125 ins / 115 mismatched -> 123 / 33.
 *
 *  [L2] `d = n - 0x60;` INTO ITS OWN LOCAL, then `q->f0 + d`.  Writing the
 *       obvious `q->f0 + (n - 0x60)` lets fold reassociate the constant onto
 *       the OTHER addend — `addiu $v0,$v0,-0x60` on the lhu result — and
 *       writing `n -= 0x60;` makes it a single pseudo, so the subtract is
 *       in-place (`addiu $a0,$a0,-0x60`) and floats up ~10 slots because its
 *       destination is free early.  Only a distinct, single-set pseudo gives
 *       the target's `addiu $v1,$a0,-0x60`, which cannot be scheduled before
 *       `sw $v1,0x4($s3)` frees $v1 — and that one anchor pins the whole
 *       lui/ori/li/move ordering of the fill block.  26 mismatched -> 16.
 *
 *  [L3] The LAST addPrim write-half must keep its loaded word in $v0 through
 *       the `or`, so the return value `addiu $v0,$s3,0x8` cannot be scheduled
 *       into the load-delay slot.  With the plain bitfield spelling gcc puts
 *       that word in $v1/$a0, $v0 falls free, sched2 hoists the return insn
 *       into the slot, and the target's `nop` after `lw $v1,%lo(D_800AE7BC)`
 *       disappears — a LENGTH-DRIFT of exactly -1 that no amount of statement
 *       reordering fixes.  `register u32 v __asm__("$2")`, REUSED for the
 *       or-result, is the only lever that holds it.  16 mismatched -> MATCH.
 *       (Ablated: pinning `op` to $3 and `pb` to $18 are NOT needed once [L3]
 *       is in; both were removed and the gate still reads MATCH.)
 *
 * §94 TYPE-CARRY: every typedef here is BLOCK-scope on purpose — extract_unit
 * carries file-scope externs but drops file-scope typedefs, so the four
 * mechanical siblings would sweep 0/4 if these lived at file scope.
 */

s32 *func_8017DD28(s32 *out) {
    typedef struct { u32 addr : 24; u32 len : 8; } PTag_8017DD28;
    typedef struct { u32 *ot; u32 pad[4]; } Env_8017DD28;   /* 0x14 stride */
    typedef struct { u16 f0; u16 f2; } Prim4_8017DD28;
    typedef struct {
        s16 f0;                     /* 0x00 */
        s16 f2;                     /* 0x02 */
        void *f4;                   /* 0x04 */
        void *f8;                   /* 0x08 */
        s16 fC;                     /* 0x0C */
        s16 fE;                     /* 0x0E */
        s16 f10;                    /* 0x10 */
        s16 f12;                    /* 0x12 */
        void *f14;                  /* 0x14 */
        Prim4_8017DD28 *f18;        /* 0x18 */
        void *f1C;                  /* 0x1C */
    } Panel_8017DD28;               /* 0x20 stride */

    extern Env_8017DD28 D_800AE7BC[];
    extern short D_800B9A02;
    extern Panel_8017DD28 *D_80115134;
    extern u16 D_8011511A;
    extern s16 D_8011512C;
    extern u16 D_80115116;
    extern u16 D_80182798[];
    extern s32 func_8005A600(s32, s32, s32, s32, s32);

    Prim4_8017DD28 *q;
    volatile u16 *pb;
    s32 n;
    s32 d;

    /* `lh` on a u16-declared symbol: the address cast, not a second decl —
       the TU already fixes D_8011511A as u16 at file scope. */
    q = D_80115134[*(s16 *)&D_8011511A].f18;
    if (D_8011512C == 1) {
        n = D_80182798[D_80115116 & 7];
    } else {
        n = 0;
    }

    out[0] = 0x04000000;
    *((u8 *)out + 0xC) = 0x70;
    *((u8 *)out + 0xD) = 0x10;
    out[1] = 0x64808080;
    pb = (volatile u16 *)&D_800B9A02;
    *(u16 *)((u8 *)out + 0xE) = 0x4056;

    d = n - 0x60;                                   /* [L2] */
    *(s16 *)((u8 *)out + 0x8) = q->f0 + d;
    *(s16 *)((u8 *)out + 0xA) = q->f2 - 2;
    *(s16 *)((u8 *)out + 0x12) = 0x10;
    *(s16 *)((u8 *)out + 0x10) = 0x10;

    ((PTag_8017DD28 *)out)->addr =
        ((PTag_8017DD28 *)(D_800AE7BC[*pb].ot + 2))->addr;
    ((PTag_8017DD28 *)(D_800AE7BC[*pb].ot + 2))->addr = (u32)out;

    out += 5;                                       /* [L1] */
    func_8005A600((s32)out, 0, 0, 0x15, 0);

    ((PTag_8017DD28 *)out)->addr =
        ((PTag_8017DD28 *)(D_800AE7BC[*pb].ot + 2))->addr;
    {
        u32 *op;
        register u32 v __asm__("$2");               /* [L3] */
        op = D_800AE7BC[*pb].ot;
        v = op[2];
        v = (v & 0xFF000000) | (((u32)out) & 0xFFFFFF);
        op[2] = v;
    }

    return out + 2;
}
