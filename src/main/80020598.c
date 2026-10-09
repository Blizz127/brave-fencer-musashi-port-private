/* Main-exec range [80020598,80020A28) from the SLUS executable.
 * SHA256(span)=3a54b8a48a5b35976567ec8c6f2266f8c9182311aa8020af5636272359fb1af7.
 * Word export for the native seam; the C body below keeps its
 * own oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80020598 - byte-exact against retail at -O2 (tools/register_match.py). */

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

/* vendor TU-level declarations this function needs */
typedef struct {
    /* 0x00 */ s16 m[3][3];
    /* 0x14 */ s32 t[3];
} MTX_80020248; /* 0x20 */

/* func_80020598 — per-object rotation/translation matrix builder, sibling of
 * func_80020248 (same TU, same libgte inline-asm block set).  Walks a
 * NULL-terminated s32 list; for each entry it builds a local MATRIX from a
 * packed 12-bit rotation triple, then writes the concatenated matrix into
 * D_80074818[i] (via a2) and D_80074818[i + 0x40] == D_80075018[i] (via a3),
 * plus the RotTrans'd translation vector.
 *
 * Index 0 and 1 take their rotation from entry[3] (a1[3]) and their translation
 * from entry[0]'s first / second byte triple; index >= 2 takes both from the
 * entry the walking pointer is on.  Indices 0x19 / 0x16 / 8 get an extra
 * uniform ScaleMatrix by D_80126C4E / D_80126D10 / D_80126D12.
 *
 * Levers this one needed (all byte-measured against asm/nonmatchings/800):
 *  - §168/§194-E  the SAME-TU neighbour func_80020248 supplies the eight
 *                 gte_* macro bodies verbatim; nothing else reproduces them.
 *  - the 3-way index dispatch is a `switch`, NOT `if / else if`: the target
 *    branches to all three arms (beqz / beq / j) instead of falling through
 *    into arm 0.  That alone was 30+ rows.
 *  - only ONE pointer variable (a1) is written; `p = a1 + 5` is loop.c's own
 *    combined address giv ($s0, preheader `addiu $s0,$a1,0x5`).  Writing that
 *    second pointer in C costs 8 instructions and a whole different regalloc.
 *  - §3-T2 statement order: `i = 0;` must precede `rm = D_80074818;` or the
 *    lui/addiu pair schedules ahead of the `lw $v0,0($s5)` guard and leaves a
 *    load-delay nop (LENGTH-DRIFT +1, and it swaps the $s1/$s2 save order).
 *  - §333/§334 frame arithmetic: .frame is 0x88 with only 0x28 of live locals.
 *    The a2/a3 homes are 8-byte-aligned/8-byte-rounded slots at 0x38/0x40 and
 *    24 further bytes sit ABOVE them at 0x48-0x5F.  A trailing dead aggregate
 *    alone cannot reproduce that (declared locals are slotted BEFORE the
 *    reload spills, so it pushes 0x38/0x40 to 0x50/0x58); modelling the two
 *    pointer homes as declared 8-byte aggregates and putting the dead 24 bytes
 *    after them lands every offset exactly.
 *  - §17 register pin: the a3 home must be read once into $t0 and survive the
 *    "memory"-clobbering RTIR/STCLMV blocks so STM can reuse it.  Unpinned,
 *    gcc picks $v1 (9 rows); `register ... __asm__("$8")` on one variable that
 *    carries BOTH homes in turn closes them all.
 *
 *  - the last instruction (default arm `lbu $v1,0x1($s3)` — biv-based while
 *    arm 0's identical byte is giv-based) is NOT a combine_givs split: it is a
 *    pass-ordering fact.  Spell the byte as `(w >> 8) & 0xFF` off the bare word
 *    load (the same-TU func_80020A28 precedent), NOT as a byte deref.  A byte
 *    deref is a DEST_ADDR giv that loop.c unconditionally folds onto the
 *    reduced register; the shift-mask defers the load's BIRTH to the post-loop
 *    combine pass, which narrows it into `lbu 1(base)` off the ORIGINAL base.
 *    (Temp-pointer spellings cannot reach it: cse1's find_best_addr folds any
 *    same-ebb temp back into (plus base k) before loop — the equal-ADDRESS_COST
 *    tie-break prefers the complex address to free a register.)  The narrowed
 *    spelling shifts spill demand: pad[6] -> pad[4] keeps the frame at 0x88.
 *
 * MATCH: 292/292, closeness 0 (S69e1 fable escalation).  Relocs walked: 3x
 * func_80020DA4, func_80012558, func_80020F34 (cross-jumped shared tail),
 * D_80074818, D_80126C4E/D10/D12 — all verified against the target's own lines.
 */







 /* 0x20 */

typedef struct { MTX_80020248 *p; s32 unused; } MH;

typedef struct {
    /* 0x0 */ u8  b0;
    /* 0x1 */ u8  b1;
    /* 0x2 */ u8  b2;
    /* 0x3 */ s8  t[3];
    /* 0x6 */ u16 h;
} OBJ598; /* 0x8 */

extern MTX_80020248 D_80074818[];

extern u16 D_80126C4E;
extern u16 D_80126D10;
extern u16 D_80126D12;

extern void func_80020DA4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_80020F34(s32 a0, s32 a1);

/* PsyQ inline_c.h names (same asm), so the strict lane maps them to its
 * native GTE helpers (musashi_lane_gte_inline.h). */
#define gte_SetRotMatrix(r0) __asm__ volatile (              \
    "lw $12, 0( %0 );"                                   \
    "lw $13, 4( %0 );"                                   \
    "ctc2 $12, $0;"                                      \
    "ctc2 $13, $1;"                                      \
    "lw $12, 8( %0 );"                                   \
    "lw $13, 12( %0 );"                                  \
    "lw $14, 16( %0 );"                                  \
    "ctc2 $12, $2;"                                      \
    "ctc2 $13, $3;"                                      \
    "ctc2 $14, $4"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define gte_SetTransMatrix(r0) __asm__ volatile (              \
    "lw $12, 20( %0 );"                                  \
    "lw $13, 24( %0 );"                                  \
    "ctc2 $12, $5;"                                      \
    "lw $14, 28( %0 );"                                  \
    "ctc2 $13, $6;"                                      \
    "ctc2 $14, $7"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define gte_ldclmv(r0) __asm__ volatile (           \
    "lhu $12, 0( %0 );"                                  \
    "lhu $13, 6( %0 );"                                  \
    "lhu $14, 12( %0 );"                                 \
    "mtc2 $12, $9;"                                      \
    "mtc2 $13, $10;"                                     \
    "mtc2 $14, $11"                                      \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define gte_rtir() __asm__ volatile (               \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 3, 3, 0"                                \
    : : : "memory" )

#define gte_stclmv(r0) __asm__ volatile (           \
    "mfc2 $12, $9;"                                      \
    "mfc2 $13, $10;"                                     \
    "mfc2 $14, $11;"                                     \
    "sh $12, 0( %0 );"                                   \
    "sh $13, 6( %0 );"                                   \
    "sh $14, 12( %0 )"                                   \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14", "memory" )

#define gte_ldlv0(r0) __asm__ volatile (            \
    "lhu $13, 4( %0 );"                                  \
    "lhu $12, 0( %0 );"                                  \
    "sll $13, $13, 16;"                                  \
    "or $12, $12, $13;"                                  \
    "mtc2 $12, $0;"                                      \
    "lwc2 $1, 8( %0 )"                                   \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13" )

#define gte_rt() __asm__ volatile (                 \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 0, 0, 0"                                \
    : : : "memory" )

#define gte_stlvnl(r0) __asm__ volatile (           \
    "swc2 $25, 0( %0 );"                                 \
    "swc2 $26, 4( %0 );"                                 \
    "swc2 $27, 8( %0 )"                                  \
    :                                                    \
    : "r"( r0 )                                          \
    : "memory" )

void func_80020598(s32 *a0, OBJ598 *a1, MTX_80020248 *a2, MTX_80020248 *a3)
{
    MTX_80020248 lm;
    s16 local[3];
    MTX_80020248 *rm;
    s32 i;
    u32 w;
    s16 v;
    MH h2;
    MH h3;
    register MTX_80020248 *m3 __asm__("$8");
    s32 pad[4];

    h2.p = a2;
    h3.p = a3;
    i = 0;
    rm = D_80074818;
    while (*a0 != 0) {
        switch (i) {
        case 0:
            local[0] = a1[3].h;
            w = *(u32 *)&a1[3];
            local[1] = a1[3].b1 | ((w & 0xF) << 8);
            local[2] = ((w >> 16) & 0xFF) | ((w & 0xF0) << 4);
            func_80020DA4((s32)local, (s32)&lm);
            func_80012558((s32)&lm, 0x800);
            lm.t[0] = (s8)a1->b0;
            lm.t[1] = (s8)a1->b1;
            lm.t[2] = (s8)a1->b2;
            break;
        case 1:
            local[0] = a1[3].h;
            w = *(u32 *)&a1[3];
            local[1] = a1[3].b1 | ((w & 0xF) << 8);
            local[2] = ((w >> 16) & 0xFF) | ((w & 0xF0) << 4);
            func_80020DA4((s32)local, (s32)&lm);
            lm.t[0] = a1->t[0];
            lm.t[1] = a1->t[1];
            lm.t[2] = a1->t[2];
            a1++;
            break;
        default:
            local[0] = a1->h;
            w = *(u32 *)a1;
            local[1] = ((w >> 8) & 0xFF) | ((w & 0xF) << 8);
            local[2] = ((w >> 16) & 0xFF) | ((w & 0xF0) << 4);
            func_80020DA4((s32)local, (s32)&lm);
            lm.t[0] = a1->t[0];
            lm.t[1] = a1->t[1];
            lm.t[2] = a1->t[2];
            a1++;
            if (i == 0x19) {
                v = D_80126C4E;
                local[2] = v;
                local[1] = v;
                local[0] = v;
                func_80020F34((s32)&lm, (s32)local);
            } else if (i == 0x16) {
                v = D_80126D10;
                local[2] = v;
                local[1] = v;
                local[0] = v;
                func_80020F34((s32)&lm, (s32)local);
            } else if (i == 8) {
                v = D_80126D12;
                local[2] = v;
                local[1] = v;
                local[0] = v;
                func_80020F34((s32)&lm, (s32)local);
            }
            break;
        }
        m3 = h2.p;
        gte_SetRotMatrix(m3);
        gte_ldclmv(&lm.m[0][0]);
        gte_rtir();
        gte_stclmv(&rm->m[0][0]);
        gte_ldclmv(&lm.m[0][1]);
        gte_rtir();
        gte_stclmv(&rm->m[0][1]);
        gte_ldclmv(&lm.m[0][2]);
        gte_rtir();
        gte_stclmv(&rm->m[0][2]);
        m3 = h3.p;
        gte_SetRotMatrix(m3);
        gte_ldclmv(&lm.m[0][0]);
        gte_rtir();
        gte_stclmv(&rm[0x40].m[0][0]);
        gte_ldclmv(&lm.m[0][1]);
        gte_rtir();
        gte_stclmv(&rm[0x40].m[0][1]);
        gte_ldclmv(&lm.m[0][2]);
        gte_rtir();
        gte_stclmv(&rm[0x40].m[0][2]);
        gte_SetTransMatrix(m3);
        gte_ldlv0(&lm.t[0]);
        gte_rt();
        gte_stlvnl(&rm[0x40].t[0]);
        rm++;
        a0++;
        i++;
    }
}
