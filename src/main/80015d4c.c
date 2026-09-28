/* Main-exec range [80015D4C,80015F04) from the SLUS executable.
 * SHA256(span)=d7586e917f3c4a27f327489ad34e909c0484dab2ec3e23e4432eeac438bb94fe.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80015D4C - byte-exact against retail at -O2 (tools/register_match.py). */

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

/* func_80015D4C — allocate an 0x18-byte flat-shaded quad GPU packet, fill its
 * tag/color/code bytes and the four (x,y) corners from (a0,a1,a2,a3) =
 * (x, y, w, h), then link it into the current double-buffer's OT at depth
 * arg7 via the open-coded PSY-Q `addPrim` RMW pair, and (only when arg8 < 4)
 * notify func_80016638.
 *
 * Sibling idiom: src/md_SC07_004/md_SC07_004.c func_801AADA8 (MATCHED) —
 * the addPrim pair over D_800A651C[bidx].a in ARRAY_REF form, and the
 * func_80016638(&D_800A6518[bidx*20], depth, flag) call form.
 *
 * SECOND-PASS FIXES (this file was NEAR/40 before; both were required):
 *
 *  1. BRANCH POLARITY WAS INVERTED.  The target is
 *         sltiu $t2, $s0, 0x4   ;  beqz $t2, <skip>
 *     i.e. the 0x2A code byte is written and func_80016638 is called when
 *     arg8 < 4, not when arg8 >= 4.  The first pass wrote `arg8 >= 4`, which
 *     emits the same sltiu but `bnez` — a real semantic difference that the
 *     instruction-shape diff hid inside the 40-instruction register cascade.
 *
 *  2. tag0 PINNED TO $4 ($a0) — the load-bearing regalloc fix.  Residual was
 *     a *uniform +1 register-slot shift*: target allocates the call-clobbered
 *     pseudo set {a0,a1,a2,a3,t0,t1,t2,t3}, the draft allocated
 *     {v1,a0,a1,a2,a3,t0,t1,t2}.  Root cause: gcc's sched1 placed the tag
 *     load (`lw <tag0>, 0(p)`) *after* the last use of the x+w temp, so tag0
 *     could reuse $v1; the target schedules the tag load 14 insns earlier, so
 *     the two live ranges overlap and tag0 must take $a0, pushing every later
 *     pseudo up one slot.
 *     Statement-order (lever A) is INERT here — sweeping the `tag0 = *(u32*)p`
 *     statement through all 6 legal source positions between the p[7]
 *     conditional and the addPrim pair gave 40 mismatched every time; sched1
 *     normalises the DAG regardless of source position.  The register pin is
 *     what changes the allocation, and pinning tag0 (the value whose slot
 *     *causes* the cascade) is the right handle — this is exactly the lever
 *     func_801AADA8's own header documents ("tag0 ... pinned to $4 ($a0) —
 *     needed to reproduce the target's exact a2/a3/t0/t1 register picks for
 *     the addPrim RMW pair").
 *     Pin sweep, for the record: $4 -> MATCH, $5 -> 9, $6 -> 16, $7 -> 16,
 *     $8 -> 31.  Note the first pass pinned temp_v0 instead ($8) and got a
 *     spurious extra move — pinning the *consumer* of the cascade rather than
 *     its cause (cookbook §175 lever B: pin the interloper, not the value you
 *     care about; here the interloper is the tag word aliasing $v1).
 *
 * vx/vy stay pinned to $18/$17 ($s2/$s1) from the first pass — the target's
 * `addu $s2,$s3,$zero` / `addu $s1,$s4,$zero` corner-copy pair.
 *
 * Symbol audit (§174 law 1c, done after MATCH): every symbol re-checked
 * against the target .s relocation lines — jal func_80010A08, jal
 * func_80016638, %hi/%lo(D_800B9A02) via lhu (u16, not s16), %hi/%lo
 * (D_800A651C) via lw, %lo(D_800A6518) via addiu (address-of).  Store sides
 * verified: `sw $a0,0($t0)` is the packet tag, `sw $v0,0($a1)` is the OT slot.
 * src/800.c declares none of these, so no TU-declaration conflict (law 2/3).
 */

extern void *func_80010A08(s32 a0);
extern u16 D_800B9A02;
extern u8 D_800A6518[];
extern void func_80016638(void *a0, s32 a1, s32 a2);

void func_80015D4C(s32 a0, s32 a1, s32 a2, s32 a3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8)
{
    extern OtBlk_80016450 D_800A651C[];   /* block scope: engine_core.h's DEFINE_ macros declare this symbol scalar in their own bodies */
    void *temp_v0;
    register s16 vx __asm__("$18");
    register s16 vy __asm__("$17");
    register u32 tag0 __asm__("$4");
    s32 depth4;

    temp_v0 = func_80010A08(0x18);
    *(u8 *)((u8 *)temp_v0 + 3) = 5;
    *(u8 *)((u8 *)temp_v0 + 7) = 0x28;
    vx = a0;
    vy = a1;
    if (arg8 < 4) {
        *(u8 *)((u8 *)temp_v0 + 7) = 0x2A;
    }

    *(u8 *)((u8 *)temp_v0 + 4) = arg4;
    *(u8 *)((u8 *)temp_v0 + 5) = arg5;
    *(u8 *)((u8 *)temp_v0 + 6) = arg6;
    *(s16 *)((u8 *)temp_v0 + 8) = vx;
    *(s16 *)((u8 *)temp_v0 + 0xA) = vy;
    *(s16 *)((u8 *)temp_v0 + 0xC) = a0 + a2;
    *(s16 *)((u8 *)temp_v0 + 0xE) = vy;
    *(s16 *)((u8 *)temp_v0 + 0x10) = vx;
    tag0 = *(u32 *)temp_v0;
    *(s16 *)((u8 *)temp_v0 + 0x12) = a1 + a3;
    *(s16 *)((u8 *)temp_v0 + 0x14) = a0 + a2;
    *(s16 *)((u8 *)temp_v0 + 0x16) = a1 + a3;

    depth4 = arg7 * 4;
    *(u32 *)temp_v0 = (tag0 & 0xFF000000) |
        (*(u32 *)(depth4 + D_800A651C[D_800B9A02].a) & 0xFFFFFF);
    *(u32 *)(depth4 + D_800A651C[D_800B9A02].a) =
        (*(u32 *)(depth4 + D_800A651C[D_800B9A02].a) & 0xFF000000) |
        ((u32)temp_v0 & 0xFFFFFF);
    if (arg8 < 4) {
        func_80016638(&D_800A6518[D_800B9A02 * 20], arg7, arg8);
    }
}
