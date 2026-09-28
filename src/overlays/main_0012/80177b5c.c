/* Overlay range [80177B5C,80177DA8) from MAIN.CD member 0012.
 * SHA256(span)=919bbd1da96631d5c76e8153345aac34d01214c7786078a79360e95e93317a12.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80177B5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { short vx, vy, vz, pad; } SVECTOR;

typedef struct {
    SVECTOR v[4];               /* 0x00 */
    s32 f0, f1, f2, f3, f4, f5; /* 0x20..0x37 */
    u8  f6;                     /* 0x38 */
    u8  pad[7];                 /* -> 0x40 */
} Prim_8016E7C8_80177B5C;

/* func_80177B5C - MATCH (147/147 ins), wave23.
 *
 * Seed: .run/near6/func_80177B5C_ils.c (permuter-improved, closeness 7).
 * Two residual clusters remained; both cracked, each by a sourced gcc-2.7.2 mechanism.
 *
 * CLUSTER C (idx 86-89) - the "cl | ((n*8+8) | 0x4000)" re-association.
 *   NOT a cse fold. It happens in the FRONT END: fold-const.c fold(), the `associate:`
 *   arm at :3685. For `A | (X | C)`, split_tree(arg1) (:3759, decomposer at :882) splits
 *   arg1 into var=X / con=C because TREE_CONSTANT(op1) holds, then rebuilds it as
 *   `(A | C) | X` at :3785. Verified in the FIRST RTL dump (t.i.rtl insn 215 already
 *   reads `(ior v1 16384)`), so no RTL-level lever (the cse if/else diamond, tie or
 *   volatile barriers, operand swap, shift-vs-multiply) can ever reach it.
 *   ANTIDOTE: hoist the inner IOR into its own statement. The outer arg1 is then a
 *   VAR_DECL, split_tree returns 0, and the associate arm is skipped. (This function
 *   already proved the shape at `tt = uv | 0x1000; p[3] = cl | tt;`, which matched.)
 *
 *   That exposed a REGALLOC residual: the chain landed in $a3 (`sll a3,a3,3`) instead
 *   of $v0. Cause: `n` was pinned to a HARD reg, and local-alloc.c combine_regs():1798
 *   unconditionally records a dying hard-reg SOURCE in qty_phys_sugg[] for the dest
 *   pseudo, so the shift dest inherited $a3. A *pseudo* source cannot do that - :1763
 *   bails when reg_qty[ureg] < 0 (i.e. not block-local), and the target's `n` crosses
 *   the join, so it is exactly such a pseudo.
 *   ANTIDOTE: move the pin off `n` (which dies into the shift) onto `nn` (the tested
 *   value). `nn` pinned to $2 keeps the two distinct so the `addu $a3,$v0,$zero` copy
 *   survives (combine_regs :1841 refuses to tie when the DEST is non-block-local),
 *   while `n` stays a pseudo and the shift chain gets an ordinary local quantity ->
 *   $v0 - which also restores the target schedule, because the $v0 anti-dependence on
 *   `sw $v0,-0x4($a1)` is what stops sched2 hoisting the chain above the store.
 *   [7 -> 8 -> 3]
 *
 * CLUSTER B (idx 24-27) - `lui $t0,0x300` two slots early.
 *   Pure sched1 LUID tie-break, read straight off the -da trace (t.i.sched, T-36):
 *   ready = { 58 (7f000001), 72 (7f000001), ... } - insn 58 (lui $t0) IS birthing-
 *   boosted (sched.c birthing_insn_p:2469 works on hard regs too; reg_n_sets[$t0]==1),
 *   so 58/71/72 all tie at max_priority and rank_for_schedule:2427 falls through to
 *   DESCENDING LUID. Source order put `ca = 0x3000000;` before the mask, so
 *   LUID(58) < LUID(72) and the lui was placed first.
 *   (The companion mask 0xFFFFFF correctly stays at idx 6-7 because lui+ori is TWO
 *   sets of $t1 -> reg_n_sets==2 -> no boost -> it sinks to the block head. Same
 *   mechanism, opposite sign - the model predicts both.)
 *   ANTIDOTE: split the mask into its own statement (`gg`) and materialise the
 *   constant BETWEEN it and the OR, so expand emits addiu, and, lui, or in that order
 *   and LUID(58) > LUID(72). Sweeping the plain statement position of `ca = ...` was
 *   inert (all 11 slots scored 3) - only interposing the temp moves the LUID past the
 *   AND. [3 -> 0]
 *
 * Dead ends measured, not guessed: pin nv to $2 = 27; reuse tt = 24; reuse uv = 29;
 * two-step |= = 15; unpin n = 84 (146 ins, the copy coalesces away); unpin ca = 139;
 * ca as a bare literal = 139 (145 ins - cse merges it with the loop copy, so the hard
 * pin is what keeps the pre-loop and in-loop constants separate); both literal = 143;
 * `(ca = 0x3000000)` as an assignment-EXPRESSION = 114 (148 ins, extra move); reusing
 * the existing `g` for the mask temp instead of a fresh one = 8 (g has a 2nd set later).
 */
u32 *func_80177B5C(p, bits, tbli, x, y)
u32 *p;
u32 bits;
s32 tbli;
s32 x;
s32 y;
{

    extern u8 D_80181B64[];
register u32 bb __asm__("$14");
  u32 *q;
register u32 v __asm__("$25");
register u32 cl __asm__("$3");
register u32 cs __asm__("$5");
register u32 ca __asm__("$8");
  s16 i;
  u32 mk1;
  u32 cc1;
  u32 flag;
register u32 nn __asm__("$2");
  u32 n;
register u32 t __asm__("$13");
  u32 col;
  u32 uv;
  u32 tt;
  u32 nv;
  u32 x1;
  u32 x2;
  u32 w;
  u32 g;
  u32 gg;
  u32 w3;
register u32 yr __asm__("$16");
register u32 yt __asm__("$4");
register u32 tr __asm__("$21");
register u32 xr __asm__("$17");
register u32 c3 __asm__("$18");
register s32 ff __asm__("$19");
register s32 two __asm__("$20");
  yt = y;
  tr = tbli;
__asm__("" : "=r"(tr) : "0"(tr));
  xr = x;
__asm__("" : "=r"(xr) : "0"(xr));
  mk1 = 0xFFFFFF;
  cc1 = 0x74808080;
  bb = bits;
  t = x + 0xE;
  flag = 0x1000000;
  i = 0;
  two = 2;
  ff = 255;
  ;
  v = D_80181B64[(s16) tbli];
  gg = ((u32) (p - 5)) & mk1;
  ca = 0x3000000;
  p[0] = gg | ca;
  x1 = (x - 3) & 0xFFFF;
  x2 = (x + 5) & 0xFFFF;
  p[1] = cc1;
  yr = yt;
__asm__("" : "=r"(yr) : "0"(yr));
  yt = (s16) yt;
  cs = (yt + 1) << 16;
  w = cs | x1;
__asm__("" : "=r"(w) : "0"(w));
  cl = ((v << 6) | 0x4016) << 16;
  p[2] = w;
  p[3] = cl | 0x1800;
  p += 5;
  p[0] = (((u32) (p - 5)) & mk1) | ca;
  p[1] = cc1;
  p[2] = cs | x2;
  p[3] = cl | 0x1808;
  p += 5;
  q = p;
  yt = yt << 16;
  {
    for (; i < 3; i++)
    {
      nn = ((bb << 16) >> 18) >> 10;
      n = nn;
      if (((nn != 0) || (i == two)) || (i == ff))
      {
        flag = 0;
      }
      q[0] = (((u32) (q - 5)) & 0xFFFFFF) | 0x3000000;
      q[2] = (yt | (t & 0xFFFF)) | flag;
      col = 0x74808080;
      q[1] = col;
      nv = ((n * 8) + 8) | 0x4000;
      q[3] = cl | nv;
      q += 5;
      t += 8;
      bb <<= 4;
    }

  }
  p = q;
__asm__("" : "=r"(v) : "0"(v));
  g = (((u32) (p - 5)) & 0xFFFFFF) | 0x3000000;
__asm__ __volatile__("");
  cs = yr << 16;
  p[0] = g;
  w3 = cs | ((xr + 0x2A) & 0xFFFF);
__asm__ __volatile__("");
  cl = ((v << 6) | 0x4016) << 16;
  uv = ((s16) tr) << 4;
  p[2] = w3;
  tt = uv | 0x1000;
  p[1] = col;
  p[3] = cl | tt;
  p += 5;
  p[0] = (((u32) (p - 5)) & 0xFFFFFF) | 0x3000000;
__asm__ __volatile__("");
  cs = cs | ((xr + 0x32) & 0xFFFF);
  uv = uv | 0x1008;
  cl = cl | uv;
  p[1] = col;
  p[2] = cs;
  p[3] = cl;
  p += 5;
__asm__("" :: "r"(tr), "r"(xr));
  return p;
}
