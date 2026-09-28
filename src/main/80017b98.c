/* Main-exec range [80017B98,80017D98) from the SLUS executable.
 * SHA256(span)=52c684c1a109ead90be33be634327b5dc7577d488250c1f674c419bbf22da269.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80017B98 - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* vendor TU-level declarations this function needs */
typedef struct { s32 a; s32 b[4]; } OtBlk_80016450;

/* func_80017B98 — main/800: build one 0x2C-byte GPU packet holding a PSY-Q SPRT
 * (code 0x64) preceded by an E1 draw-mode word, fill it from the caller's
 * 0x1C-byte sprite-request block (== engine_types.h T8016EC0C, the struct
 * func_8016EC0C fills before calling here), then link it into the current
 * double-buffer's OT at depth `otz` with the open-coded PSY-Q addPrim() RMW pair.
 *
 * Packet layout (prim = the 0x2C alloc; sp = (SPRT *)(prim + 4)):
 *   prim+0x00  u32 tag        = 0x05000000   (len 5, addr filled by addPrim)
 *   sp +0x00   u32 tag        = 0xE1000000 | tpage bits   (GP0 E1 draw mode)
 *   sp +0x04   r0,g0,b0,code  = 0x64<<24 | b<<16 | g<<8 | b   (NOTE: r0 == b0 ==
 *                               src->b at +0x12; src->r at +0x10 is never read)
 *   sp +0x08   x0,y0          = src->x - src->w/2, src->y - src->h/2
 *   sp +0x0C   u0,v0,clut
 *   sp +0x10   w,h
 *
 * @class: was regalloc-order + IOR-tree reassociation
 * @stuck: none — MATCH (128 ins), byte-exact under match_one.
 *
 * LEVERS (each verified by removing it and re-scoring):
 *  1. `sp->code = 0x64;` must sit AFTER the `sp->tag = ...` statement (51 -> 36).
 *     Source order is the sched1 tie-break that lets the three tag operand loads
 *     hoist above the code sb, which is what fixes the whole temp-register naming
 *     of the tag chain.  (cookbook §175 lever A: statement order.)
 *  2. THE CONSTANT 0x64000000 MUST BE A LOCAL VARIABLE, NOT A LITERAL.  Written
 *     literally, gcc-2.7.2's fold `associate` rewrites  X | (Y | C)  into
 *     (X | C) | Y  — it emits `or (b<<16), C` first, where the target emits
 *     `or (g<<8), C` first.  split_tree() only pulls a constant that is a DIRECT
 *     operand, so binding it to `u32 code` (a VAR_DECL at tree level, folded back
 *     to the same `lui` by RTL cse) leaves the source tree untouched.  51 -> 35
 *     with the correct or-tree.  (`+ 0x64000000` also blocks the rewrite but
 *     emits `addu` instead of `or` — 1 permanent mismatch.)
 *  3. `t = (n + 0x100) << 6;` must be its own local.  Inline in the ternary, gcc
 *     folds (n+0x100)<<6 | 0x16 into `sll n,6` + `ori 0x4016` (2 ins, wrong
 *     shape); the shared temp keeps the target's addiu/sll/ori triple.
 *  4. The clut value needs its own local `cl` too — otherwise cse carries the
 *     `sp = prim+4` equivalence into the join block and rewrites the store as
 *     0x12(prim) instead of the target's 0xE(sp).  (1 ins.)
 *  5. The 0xFF000000 / 0x00FFFFFF masks must be LOCALS (m24/mFF), not literals:
 *     as locals their `lui` is a join-block insn that delay-slot-fills the otz
 *     clamp branch; as literals they are rematerialised per use and reorg
 *     duplicates `sll d4,2` into the delay slot instead.  Same lever as
 *     func_80016450 in this file.
 *  6. `d4 += D_800A651C[...].a;` (self-accumulate) reproduces `addu $a1,$a1,$v0`
 *     — the second addPrim half reusing the depth*4 register.  Operand order
 *     `d4 + D_800A651C[...].a` (not the reverse) gives `addu $v0,$a1,$v0`.
 *     Both inherited from func_80016450's header.
 *  7. `*(u32 *)prim` / `*(u32 *)&sp->r0`, never a struct member, wherever the
 *     store has to kill CSE — that is what forces the two reloads of
 *     `s->flags` (0x14) and the two reloads of the D_800AF630 index.
 *
 * PIN-TRIM LOG (all re-scored; four pins are the verified minimum):
 *   drop `m24` $6 pin                 — MATCH  (dropped)
 *   drop `mFF` $7 pin                 — MATCH  (dropped)
 *   drop both mask pins together      — MATCH  <= this file
 *   drop `d4` $5 pin alone            — MATCH, but 13/11/16 mismatched in every
 *                                       combination with a mask pin dropped, so
 *                                       it is kept (it is what makes otz land in
 *                                       $a1 and the masks in $a2/$a3)
 *   drop `pv` $4 pin                  — 4 mismatched
 *   drop `bb` $5 pin                  — 5 mismatched
 *   drop `pbase` $17 pin              — 126 ins, 124 mismatched (D_800AF630 base
 *                                       must live in a callee-saved reg)
 *   pin `prim` to $8                  — 28 mismatched (never pin prim; it lands
 *                                       in $t0 by itself once d4/masks are pinned)
 *
 * SYMBOL AUDIT (§174 law 1c, done after MATCH) — every symbol re-checked against
 * asm/nonmatchings/800/func_80017B98.s's own relocation lines:
 *   jal func_80010A08 (0x83AC)  •  %hi/%lo(D_800AF630) -> $s1 (0x8468/0x846C),
 *   dereferenced at $s1+0x10000-0x5C2E == 0x800B9A02, the same u16 frame index
 *   src/boot.c reads as `*(u16 *)(p + 0xA3D2)`  •  %hi/%lo(D_800A651C) via `lw`,
 *   twice (0x8514/0x851C and 0x8558/0x8560).  No other relocations exist.
 *   Store sides: `sw $a0,0($t0)` is the packet tag, `sw $v0,0($a1)` is the OT
 *   slot, `sw $v1,0x8($t0)`/`sw $v0,4($a0)` are both the r0g0b0code word.
 *   Load sides: the colour word takes 0x12 ($a1) TWICE (low byte and byte 2) and
 *   0x11 ($v0) once — src->r at 0x10 is genuinely never read by this function.
 *
 * BANK NOTE (§174 law 2): src/800.c already defines
 *     typedef struct { s32 a; s32 b[4]; } OtBlk_80016450;      (file scope)
 * and both func_80015D4C and func_80016450 declare
 *     extern OtBlk_80016450 D_800A651C[];                      (block scope)
 * This draft reuses THAT name so the third block-scope extern agrees with them
 * (a differently-named but structurally identical typedef only produces
 * "type mismatch with previous external decl" warnings, but agreeing is free).
 * ==> DROP the OtBlk_80016450 typedef line below when banking into src/800.c;
 *     it is present only so this file compiles standalone under match_one.
 * src/800.c also already declares `extern void *func_80010A08(s32 a0);` (L694)
 * — adopted verbatim.  D_800AF630 is not declared anywhere in that TU nor in any
 * header it includes, so the `extern u8 D_800AF630[];` below is the canonical
 * repo-wide form (src/boot.c L14/L37, every ov_* sibling).
 * src/800.c contains no prototype for func_80017B98 itself, so the definition's
 * `void func_80017B98(void *arg0)` is unconstrained (law 3 clear); it matches the
 * callers' `extern void func_80017B98(void *a0);`.
 */

/* DROP WHEN BANKING — already defined at file scope in src/800.c */

/* PSY-Q SPRT laid at prim+4; its `tag` word doubles as the E1 draw-mode command */
typedef struct {
    /* 0x00 */ u32 tag;
    /* 0x04 */ u8  r0, g0, b0, code;
    /* 0x08 */ s16 x0, y0;
    /* 0x0C */ u8  u0, v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ u16 w, h;
} Sprt_80017B98;

/* the caller's request block == engine_types.h T8016EC0C */
typedef struct {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
    /* 0x04 */ s32 otz;
    /* 0x08 */ u16 w;
    /* 0x0A */ u16 h;
    /* 0x0C */ u16 u;
    /* 0x0E */ u16 v;
    /* 0x10 */ u8  r;
    /* 0x11 */ u8  g;
    /* 0x12 */ u8  b;
    /* 0x13 */ u8  pad13;
    /* 0x14 */ u32 flags;
    /* 0x18 */ u8  tp;
    /* 0x19 */ u8  pad19[3];
} Src_80017B98;

extern void *func_80010A08(s32 a0);
extern u8 D_800AF630[];

void func_80017B98(void *arg0)
{
    extern OtBlk_80016450 D_800A651C[];   /* block scope: matches func_80015D4C / func_80016450 in this TU */
    Src_80017B98 *s = (Src_80017B98 *)arg0;
    u8 *prim;
    Sprt_80017B98 *sp;
    register u8 *pbase __asm__("$17");
    u32 n;
    u32 t;
    u32 m24;
    u32 mFF;
    register u32 pv __asm__("$4");
    register s32 d4 __asm__("$5");

    prim = (u8 *)func_80010A08(0x2C);
    *(u32 *)prim = 0x05000000;
    sp = (Sprt_80017B98 *)(prim + 4);
    sp->tag = ((s->flags >> 23) & 0x60) | ((s->v >> 4) & 0x10) |
              ((s->u >> 8) & 0xF) | ((s->v & 0x200) << 2) | 0xE1000000;
    sp->code = 0x64;
    {
        u32 code = 0x64000000;
        register u32 bb __asm__("$5") = s->b;
        *(u32 *)&sp->r0 = (bb << 16) | ((s->g << 8) | code) | bb;
    }
    sp->x0 = s->x - (s->w >> 1);
    sp->y0 = s->y - (s->h >> 1);
    sp->u0 = s->u;
    pbase = D_800AF630;
    sp->v0 = s->v;
    n = s->tp;
    t = (n + 0x100) << 6;
    {
        u16 cl = (n < 0xE0) ? (t | 0x16) : (t | 0x10);
        sp->clut = cl;
    }
    sp->w = s->w;
    sp->h = s->h;
    if (s->flags & 0x40000000) {
        *(u32 *)&sp->r0 = *(u32 *)&sp->r0 | 0x02000000;
    }
    d4 = s->otz;
    if (d4 >= 0x1000) {
        d4 = 0xFFF;
    }
    m24 = 0x00FFFFFF;
    mFF = 0xFF000000;
    d4 = d4 * 4;
    pv = *(u32 *)prim;
    *(u32 *)prim = (pv & mFF) |
        (*(u32 *)(d4 + D_800A651C[*(u16 *)(pbase + 0xA3D2)].a) & m24);
    d4 += D_800A651C[*(u16 *)(pbase + 0xA3D2)].a;
    *(u32 *)d4 = (*(u32 *)d4 & mFF) | ((u32)prim & m24);
}
