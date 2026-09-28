/* Main-exec range [80023BF0,80024054) from the SLUS executable.
 * SHA256(span)=0d32c46ad602a2671366afa55165c1d2d4ebf697b401e1e8578fc28b9a6689a6.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80023BF0 - byte-exact against retail at -O2 (tools/register_match.py). */

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

/* func_80023BF0 (main, src/800.c, 281 ins) -- MATCH, closeness 0.
 * Real TU (rtu_match --tu src/800.c) agrees: MATCH.  Came in at 18 (the S79w opus
 * draft) / 11 (the S80 permuter waypoint, which was semantically UNSOUND -- it had
 * sunk `m24 = 0xFFFFFF` into the `c == 0x3870` arm of the sprite loop, leaving the
 * mask register undefined on any first iteration that takes the other arm).
 *
 * ============================================================================
 * WHAT CLOSED IT: THE OT LINK IS A libgpu P_TAG 24-BIT BITFIELD, NOT A MASK/OR
 * ============================================================================
 * Cookbook §364 + the func_8017FD64 addendum (L30700) describe this residual
 * EXACTLY and this function is a third witness for the -O2 half of it:
 *
 *   symptom  : a hand-written `(A & 0xFF000000) | (B & 0xFFFFFF)` OT link that
 *              plateaus at closeness 10-18, where every remaining row is
 *              (a) the paired lui/ori mask registers two-cycle-swapped against
 *                  the OT-slot pointer ($t3 <-> $t4 here), and
 *              (b) the loop PREHEADER emitting the two mask constants BEFORE the
 *                  `sll/addu` that forms &otab[idx], where the target emits them
 *                  after -- in BOTH loop preheaders and again in the epilogue.
 *   fix      : write it as the bitfield store the SDK macro expands to
 *                  typedef struct { u32 addr : 24; u32 len : 8; } PTag;
 *                  ((PTag *)pkt)->addr = otab[idx].addr;   -- setaddr(p, getaddr(ot))
 *                  otab[idx].addr      = (u32)pkt;         -- setaddr(ot, p)
 *                  ((PTag *)pkt)->len  = 1;                -- was pkt[3] = 1
 *   mechanism: expand_assignment routes a bitfield destination through
 *              store_field -> store_fixed_bit_field, which expands the VALUE
 *              (the RHS bitfield EXTRACT: &otab[idx], lw, and-0xFFFFFF) before it
 *              touches the destination (lw pkt, and-0xFF000000, ior, sw).  That
 *              single ordering change does three things at once:
 *                * loop.c's movable list is built in body order, so the hoists
 *                  come out as [&otab[idx] ; 0xFFFFFF ; 0xFF000000] -- the
 *                  target's preheader order, in both arms;
 *                * expand_binop(ior_optab, temp, value) puts the DEST-masked word
 *                  first, giving the target's `or $v1,$v1,$v0` operand roles and
 *                  therefore its $v0/$v1 assignment;
 *                * the store-side `expand_and(value, mask)` is what emits the
 *                  target's `and $v1,$t1,$t3` (pkt & 0xFFFFFF) AHEAD of the slot
 *                  reload, which no hand-written spelling reproduces.
 *              Writing the OR by hand fixes the emitted body but is unreachable
 *              in the preheader: swapping the `|` operands to `(otab[idx] &
 *              0xFFFFFF) | (*(u32*)pkt & 0xFF000000)` DOES buy the target's hoist
 *              order (measured: the preheader goes byte-exact) but then inverts
 *              the body's two loads and the ior roles -- 35.  The two halves are
 *              mutually exclusive from a hand-written mask/or, and the bitfield
 *              satisfies both because the pass order, not the source order, is
 *              what differs.  §364's -O2 veto (MEM_IN_STRUCT_P letting the alias
 *              oracle CSE a global load across the tag store) does NOT bite here:
 *              the only global read near the links is D_800B9A02, loaded once in
 *              the prologue, so there is nothing to CSE away.
 *
 * The whole 90 -> 18 chain from the S79w draft was NOT wasted and is still load
 * bearing -- keep every one of these, each re-measured against this body:
 *  1. THE §194-A FENCE IN **BOTH** ARMS (the `__asm__ __volatile__("")` before
 *     `c = *prims;`).  Removing it: WIDTH, lhu != lbu.  It stops sched1 hoisting
 *     `lhu c` to the top of the block, which shortens c1's live_length 24 -> 16
 *     and lifts its allocno priority above giv1's -- the only way to the target's
 *     `c1 == arg0 == $a2` / `giv1 == $a3` / `x == $t0` triple.
 *  2. `code` SPLIT FROM ITS 0x74/0x76 BASE, accumulated compound
 *     (`code = b26<<16; code |= (b25<<8)|base; code |= b24;`) so the first insn's
 *     scratch is what set_preference (global.c:1535) hands `code`, plus
 *  3. `register u32 base __asm__("$3")`.  Still REQUIRED (dropping the pin
 *     re-colours the whole file from insn 9 on): base is a global allocno and so
 *     invisible to local-alloc, so only a hard reg makes regs_live_at see $v1
 *     occupied over the scratch's 2-insn window and push the scratch to $a0.
 *  4. THIRTEEN zero-byte fences after `pkt = D_800A5E60;` (pure §47 live-length
 *     arithmetic).  Re-measured on THIS body: 0 -> 15, 8 -> 13, 10/11/12 -> 7,
 *     13 -> MATCH.  13 is the minimum; 14 and 16 also match.
 * DROPPED as no longer needed once the bitfield lands (each re-measured MATCH):
 *     `register u32 m24 __asm__("$11")` (the 0xFFFFFF pin -- the bitfield hoists
 *     it into $t3 on its own, which is the point), and `register u32 e1
 *     __asm__("$4")` for 0xE1000015 (now a plain literal).
 *
 * STRUCTURE (inherited from S69/S76/S77/S79, all still byte-verified -- keep it):
 *   the dispatch is a balance_case_nodes median tree, source case order 0x1850,
 *   0x1858, 0x3870, 0x3871, 0x3872, default; 0x1850/0x1858 SHARE one body whose
 *   head is stolen into the beq delay slot (§164-36b); the emit block appears
 *   ONCE; packet fields are written PKT-RELATIVE so loop.c emits ONE combined
 *   giv; `c` is declared INSIDE each arm; `tpage` is built through the `tp` temp,
 *   never in place; and an intermediate the target computes in a SCRATCH register
 *   is a NESTED EXPRESSION, not a second assignment to the same variable.
 *   Do NOT introduce an explicit `u32 *ot = &otab[idx]` (function-scope, arm-local
 *   or pinned): re-measured here too, it is an extra global allocno, buys a 4th
 *   callee-saved register and costs +3 instructions (284).
 *
 * Symbols audited against this target's own relocation lines (law 1c): the .s
 * carries %hi/%lo of D_800AF630, D_800A6610, D_800B9A02, D_800A5E60 and no jal.
 */
extern u8 D_800AF630[];
extern u8 D_800A6610[];
extern u16 D_800B9A02;
extern u8 *D_800A5E60;

typedef struct { s16 vx, vy, vz, pad; } SVEC_80023BF0;

typedef struct { u32 addr : 24; u32 len : 8; } PTag_80023BF0;

#define SetRot_80023BF0(m) __asm__ volatile ( \
    "lw $12, 0(%0);"  "lw $13, 4(%0);"  "ctc2 $12, $0;"  "ctc2 $13, $1;" \
    "lw $12, 8(%0);"  "lw $13, 12(%0);" "lw $14, 16(%0);" \
    "ctc2 $12, $2;"   "ctc2 $13, $3;"   "ctc2 $14, $4" \
    : : "r"(m) : "$12", "$13", "$14")
#define SetTrans_80023BF0(m) __asm__ volatile ( \
    "lw $12, 20(%0);" "lw $13, 24(%0);" "ctc2 $12, $5;" \
    "lw $14, 28(%0);" "ctc2 $13, $6;"   "ctc2 $14, $7" \
    : : "r"(m) : "$12", "$13", "$14")

void func_80023BF0(s32 arg0)
{
    SVEC_80023BF0 v;
    u32 xy;
    u32 sxy2;
    u32 mac0;
    s32 z;
    u32 flags;
    u16 *prims;
    u16 b9;
    u16 idx;
    s32 x;
    s32 y;
    PTag_80023BF0 *otab;
    u8 *pkt;
    u32 code;
    s32 tpage;
    s32 tp;
    u8 *mat;
    register u32 base __asm__("$3");

    mat = D_800AF630;
    prims = *(u16 **)(arg0 + 0x20);
    b9 = D_800B9A02;
    flags = *(u32 *)(arg0 + 4);
    otab = (PTag_80023BF0 *)(b9 * 0x4000 + D_800A6610);

    if (flags & 0x4000000) {
        u8 *m = mat + 0x18;
        SetRot_80023BF0(m);
        SetTrans_80023BF0(m);
        v.vx = *(u16 *)(arg0 + 8) + *(u16 *)(arg0 + 0x2E);
        v.vy = *(u16 *)(arg0 + 0xA) + *(u16 *)(arg0 + 0x30);
        v.vz = *(u16 *)(arg0 + 0xC) + *(u16 *)(arg0 + 0x32);
        __asm__ volatile("lwc2 $0, 0(%0);lwc2 $1, 4(%0)" : : "r"(&v));
        __asm__ volatile("nop;nop;rtps");
        __asm__ volatile("swc2 $14, 0(%0)" : : "r"(&xy) : "memory");
        __asm__ volatile("swc2 $8, 0(%0)" : : "r"(&sxy2) : "memory");
        __asm__ volatile("cfc2 $12, $31;nop;sw $12, 0(%0)" : : "r"(&mac0) : "$12", "memory");
        __asm__ volatile("mfc2 $12, $19;nop;sra $12, $12, 2;sw $12, 0(%0)" : : "r"(&z) : "$12", "memory");
        if (z <= 0) {
            return;
        }
        idx = z + 1;
        {
            u32 t = xy;
            x = *(u16 *)(arg0 + 0xE) + t;
            y = t >> 16;
        }
    } else {
        x = *(u16 *)(arg0 + 0xE) + (*(u16 *)(arg0 + 8) + *(u16 *)(arg0 + 0x2E));
        idx = *(u16 *)(arg0 + 0x2C);
        y = *(u16 *)(arg0 + 0xA) + *(u16 *)(arg0 + 0x30);
    }

    tp = (*(u8 *)(arg0 + 0x27) + 0x100) << 6;
    if (*(u8 *)(arg0 + 0x27) < 0xE0) {
        tpage = tp | 0x16;
    } else {
        tpage = tp | 0x10;
    }
    pkt = D_800A5E60;
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");
        __asm__ __volatile__("");

    if (!(flags & 0x400000)) {
        u16 c;
        base = 0x74000000;
        if (flags & 0x40000000) {
            base = 0x76000000;
        }
        code = *(u8 *)(arg0 + 0x26) << 16;
        code = code | ((*(u8 *)(arg0 + 0x25) << 8) | base);
        code = code | *(u8 *)(arg0 + 0x24);
        __asm__ __volatile__("");
        c = *prims;
        if (c != 0xFFFF) {
            do {
                switch (c) {
                case 0x1850:
                case 0x1858:
                    *(u16 *)(pkt + 8) = x + 4;
                    *(u16 *)(pkt + 0xA) = y - 7;
                    break;
                case 0x3870:
                    x += 7;
                    prims++;
                    continue;
                case 0x3871:
                    x += 4;
                    prims++;
                    continue;
                case 0x3872:
                    x += 2;
                    prims++;
                    continue;
                default:
                    *(u16 *)(pkt + 8) = x;
                    x += 7;
                    *(u16 *)(pkt + 0xA) = y;
                    break;
                }
                *(u32 *)pkt = 0x3000000;
                *(u32 *)(pkt + 4) = code;
                *(u16 *)(pkt + 0xC) = *prims++;
                *(u16 *)(pkt + 0xE) = tpage;
                ((PTag_80023BF0 *)pkt)->addr = otab[idx].addr;
                otab[idx].addr = (u32)pkt;
                pkt += 0x10;
            } while ((c = *prims) != 0xFFFF);
        }
    } else {
        u16 c;
        base = 0x64000000;
        if (flags & 0x40000000) {
            base = 0x66000000;
        }
        code = *(u8 *)(arg0 + 0x26) << 16;
        code = code | ((*(u8 *)(arg0 + 0x25) << 8) | base);
        code = code | *(u8 *)(arg0 + 0x24);
        __asm__ __volatile__("");
        c = *prims;
        if (c != 0xFFFF) {
            do {
                if (c == 0x3870) {
                    x += 0x10;
                    prims++;
                } else {
                    *(u16 *)(pkt + 8) = x;
                    x += 0x10;
                    *(u16 *)(pkt + 0xA) = y;
                    *(u32 *)pkt = 0x4000000;
                    *(u32 *)(pkt + 4) = code;
                    *(u16 *)(pkt + 0xC) = *prims++;
                    *(u16 *)(pkt + 0xE) = tpage;
                    *(u32 *)(pkt + 0x10) = 0x180010;
                    ((PTag_80023BF0 *)pkt)->addr = otab[idx].addr;
                    otab[idx].addr = (u32)pkt;
                    pkt += 0x14;
                }
            } while ((c = *prims) != 0xFFFF);
        }
    }

    ((PTag_80023BF0 *)pkt)->len = 1;
    *(u32 *)(pkt + 4) = ((flags >> 23) & 0x60) | 0xE1000015;
    ((PTag_80023BF0 *)pkt)->addr = otab[idx].addr;
    D_800A5E60 = pkt + 0x40;
    otab[idx].addr = (u32)pkt;
}
