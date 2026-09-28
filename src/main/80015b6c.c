/* Main-exec range [80015B6C,80015D4C) from the SLUS executable.
 * SHA256(span)=66e85fd30d77c376692991344d02c30c8e6a17d81447d29cd9fcb53d43bae035.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80015B6C - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* func_80015B6C — main/800.  Allocate one 0x34-byte GPU packet from the frame
 * heap (func_80010A08) holding three primitives and link all three, in order,
 * into the current double-buffer's ordering table at depth 0xFFF
 * (*(u32 *)(D_800A651C[D_800B9A02].a + 0x3FFC)) with the open-coded PSY-Q
 * addPrim RMW pair (tag = {addr:24, len:8}), exactly as the matched sibling
 * func_80015D4C in this TU does:
 *
 *   +0x00  DR_MODE-style header : tag.len = 1, code word 0xE1000000
 *   +0x08  POLY_G4 gradient quad: tag.len = 8, code 0x38, corners
 *          (x,y) (x+w,y) (x,y+h) (x+w,y+h), top colour c1/c2/c3 on v0+v1,
 *          bottom colour c4/c5/c6 on v2+v3
 *   +0x2C  DR_MODE-style trailer: tag.len = 1, code word 0xE1000200
 *
 * ===================================================================
 * WHY THE ODD-LOOKING SOURCE (all five levers were byte-verified; six earlier
 * attempts plateaued at 20..47 without them, see the journal notes)
 * ===================================================================
 *
 * 1. THE CORNER COPIES (`vx`/`vy`) + THE ZERO-BYTE INVALIDATORS.
 *    The target keeps the ORIGINAL x,y in scratch regs (addu $a0,$s1,$zero /
 *    addu $v1,$s2,$zero) and then DESTROYS $s1/$s2 with the sums
 *    (addu $s1,$s1,$t1).  That shape needs a source-level copy + an in-place
 *    `x += w_`.  But cse.c's canon_reg rewrites every use of `vx` back to `x`
 *    while `x` is still unmodified (make_regs_eqv keeps the FIRST reg of the
 *    quantity canonical, and a copy that dies inside the block can never
 *    become canonical), which silently turned `sh $a0,0x8` into `sh $s1,0x8`
 *    and deleted the `vy` copy outright (119 ins).
 *    Moving the `+=` above the stores does defeat cse, but it also shortens
 *    w_/h_'s live ranges, and local-alloc's priority
 *    (log2(n_refs)*n_refs/live_length) then hands w_/h_ the last two
 *    callee-saved registers and SPILLS TWO COLOURS (+5 ins).  The target
 *    spills w_/h_ to 0x10/0x18(sp) instead.
 *    THE FIX that satisfies both: keep the `+=` in its natural late place and
 *    kill the cse equivalence with a zero-byte opaque copy on x and y —
 *    `__asm__("" : "=r"(x) : "0"(x));`.  It emits nothing, re-defines x's
 *    quantity so canon_reg stops substituting, and leaves the live ranges
 *    (hence the spill decision) untouched.
 *
 * 2. THE `__asm__ __volatile__("")` SCHEDULING FENCES.  gcc-2.7.2's sched1
 *    gives the block-2 compute chain (the corner copies, the two `+=`, the
 *    packet-tag load, the 0xE1000200 constant) a longer path to the end of
 *    the block than the twelve leaf colour `sb`s, so it hoists ALL of it in
 *    front of the colours — and, without the first fence, hoists the trailer's
 *    `lui 0xE100` all the way to the top of the post-call region.  Source
 *    order alone is INERT against this (measured: colours-first and
 *    colours-last both give the same schedule).  The four empty volatile asms
 *    partition block 2 into exactly the target's five phases:
 *      colours | v0/v1 corners | tag load + x += w_ + v1/v2 | y += h_ + v3
 *      | the addPrim pair.
 *    They cost nothing: the load-delay slots the fences would otherwise strand
 *    are filled from inside each phase (the tag load fills the first reload's
 *    slot, `and $a2,$a2,$a3` the second's), which is exactly what the target
 *    does at 0x80015C88 and 0x80015CA0.
 *
 * 3. `tag2` PINNED TO $6 ($a2) — the load-bearing regalloc lever, the same one
 *    func_80015D4C's header documents.  Left alone, the block-2 tag lands in
 *    $a0, i.e. in the register the vx copy has just vacated, which drags
 *    `sh $a0,0x8` and `sh $a0,0x18` in front of the colour block and lets the
 *    trailer constant float free.  With the tag in $a2 the vx copy stays live
 *    across the colours and the schedule falls into place.
 *
 * 4. `tag2` IS REUSED FOR THE 0xE1000200 TRAILER WORD, and the assignment sits
 *    AFTER the packet-tag store.  gcc splits a large `li` into lui+ori only
 *    after reload, so sched2 hoists the `lui` as far as the register lets it:
 *    reusing $a2 pins it to the slot right after `sw $a2,0x0($v0)` — 0x80015CC8
 *    in the target.  Declaring a second constant, or assigning it earlier,
 *    moves the whole and/or chain out of $a2 (measured 5..36 mismatched).
 *
 * 5. `pmask` (the addPrim address mask) IS A NAMED LOCAL so that the second
 *    RMW's `and $a0,$v0,$a1` can still be scheduled INSIDE the first RMW
 *    (0x80015CB8) while fence 4 keeps the trailer's `lui` behind the store.
 *    Without it the fence would drag that `and` out with everything else.
 *
 * `mFF` stays a pinned local ($7/$a3): unpinning it re-shuffles the four
 * post-call constants (measured 15 mismatched).  `one`/`m24`/`otp`'s pins were
 * measured INERT and dropped.
 *
 * @class: MATCH — 120/120 byte-exact under tools/match_one.py AND
 *   tools/rtu_match.py (whole-TU splice), and tools/reloc_identity.py AGREEs
 *   (relocs_checked=3): jal func_80010A08, %hi/%lo(D_800B9A02) via lhu (u16,
 *   per the TU's own declaration at src/800.c:2655), %hi/%lo(D_800A651C) via
 *   lw (the `.a` member at offset 0, 20-byte stride).
 */

extern void *func_80010A08(s32 a0);
extern u16 D_800B9A02;

void func_80015B6C(s32 x, s32 y, s32 w_, s32 h_, u8 c1, u8 c2, u8 c3, u8 c4, u8 c5, u8 c6)
{
    extern struct { s32 a; s32 b[4]; } D_800A651C[];   /* block scope, like func_80016450's sibling at src/800.c:3454 */
    s32 otp;
    u8 *p;
    register u32 mFF __asm__("$7");
    s32 vx, vy;
    u32 pmask;
    register u32 tag2 __asm__("$6");

    otp = D_800A651C[D_800B9A02].a;
    p = (u8 *)func_80010A08(0x34);
    mFF = 0xFF000000;

    p[3] = 1;
    *(u32 *)(p + 4) = 0xE1000000;
    *(u32 *)p = (*(u32 *)p & mFF) | (*(u32 *)(otp + 0x3FFC) & 0xFFFFFF);
    *(u32 *)(otp + 0x3FFC) = (*(u32 *)(otp + 0x3FFC) & mFF) | ((u32)p & 0xFFFFFF);

    p += 8;
    p[3] = 8;
    vx = x;
    p[7] = 0x38;
    __asm__ __volatile__("");
    vy = y;
    __asm__("" : "=r"(x) : "0"(x));
    __asm__("" : "=r"(y) : "0"(y));
    p[4] = c1; p[5] = c2; p[6] = c3;
    p[0xC] = c1; p[0xD] = c2; p[0xE] = c3;
    p[0x14] = c4; p[0x15] = c5; p[0x16] = c6;
    p[0x1C] = c4; p[0x1D] = c5; p[0x1E] = c6;
    *(s16 *)(p + 8) = vx;
    *(s16 *)(p + 0xA) = vy;
    __asm__ __volatile__("");
    tag2 = *(u32 *)p;
    x += w_;
    *(s16 *)(p + 0x10) = x;
    *(s16 *)(p + 0x12) = vy;
    *(s16 *)(p + 0x18) = vx;
    __asm__ __volatile__("");
    y += h_;
    *(s16 *)(p + 0x1A) = y;
    *(s16 *)(p + 0x20) = x;
    *(s16 *)(p + 0x22) = y;
    pmask = (u32)p & 0xFFFFFF;
    *(u32 *)p = (tag2 & mFF) | (*(u32 *)(otp + 0x3FFC) & 0xFFFFFF);
    __asm__ __volatile__("");
    tag2 = 0xE1000200;
    *(u32 *)(otp + 0x3FFC) = (*(u32 *)(otp + 0x3FFC) & mFF) | pmask;

    p += 0x24;
    p[3] = 1;
    *(u32 *)(p + 4) = tag2;
    *(u32 *)p = (*(u32 *)p & mFF) | (*(u32 *)(otp + 0x3FFC) & 0xFFFFFF);
    *(u32 *)(otp + 0x3FFC) = (*(u32 *)(otp + 0x3FFC) & mFF) | ((u32)p & 0xFFFFFF);
}
