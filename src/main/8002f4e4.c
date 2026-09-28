/* Exact retail word export for [8002F4E4,8002F5C8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F4E4 - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* func_8002F4E4 -- 6-level gauntlet lookup into the D_800A4EE8 owner block.
 *
 * TU-placement note (src/800.c): this function's INCLUDE_ASM sits at ~line 9410,
 * BEFORE the file declares `typedef struct Owner4EE8 {...}` (~9756, whose first
 * 0x14 bytes are an opaque pad00 that THIS function is the one to break out into
 * fields) and BEFORE `typedef ... Rsc24` / `extern Rsc24 D_800A4640[];` (~10860/10885).
 * So local equivalents are declared here.
 *
 * The two object externs are declared at BLOCK scope on purpose. A second
 * FILE-scope declaration of D_800A4640 / D_800A4EE8 with a different (local)
 * struct type is a hard error under the pinned cc1 ("conflicting types for
 * `D_800A4640'", rc=33) once the real ones appear later in the TU; the same
 * pair at block scope is only a warning ("type mismatch with previous external
 * decl") and compiles clean. Codegen is identical either way -- verified.
 */

/* D_800A4640 element -- same layout as the TU's own `Rsc24` (src/800.c ~13288,
 * declared later in the file than this function's INCLUDE_ASM slot, so it
 * can't be named directly here). Spelled with the TU's own typedef NAME
 * ("Rsc24", block-scoped -- shadows harmlessly, since the file-scope typedef
 * of the same name/shape doesn't exist yet at this point in the TU) and the
 * TU's own field-list TEXT verbatim, with no inline offset comments: the
 * reconciler's cosmetic-typedef check is a literal body-text comparison
 * against src/800.c's `Rsc24`, and per-field offset comments here (the TU's
 * copy has only one trailing offset tag, after the closing brace, not one
 * per field) made the two bodies textually differ and tripped
 * refuse-DIFFERENT-STRUCT even though the layouts are identical
 * field-for-field. */

/* opaque — matches the TU's `typedef struct Owner4EE8 Owner4EE8;` spelling
 * (src/800.c ~13559) exactly so this local decl is droppable at bank time in
 * favor of the TU's real `typedef struct Owner4EE8 { u8 pad00[0x14]; Rec14
 * **unk14; } Owner4EE8;`. This function only ever touches fields that live
 * inside pad00, so it pointer-casts through the opaque type at each byte
 * offset (same pattern as func_80034314 / func_8002C8F4) rather than naming
 * a same-named struct with a conflicting layout. */

extern s16 D_800A4EF0;

s32 func_8002F4E4(u8 *a0) {
    extern Rsc24 D_800A4640[];
    extern Owner4EE8 *D_800A4EE8;
    Owner4EE8 *a2;
    s32 idx;
    s32 lvl;
    s32 val;
    s32 idx2;
    s32 word;
    s32 rowBytes;
    u16 *row;

    if (D_800A4EF0 == 0) {
        return 0;
    }

    a2 = D_800A4EE8;
    if (a2 == 0) {
        return 0;
    }

    idx = a0[2];
    lvl = D_800A4640[idx].unk00;

    if (lvl < *(s16 *)((u8 *)a2 + 0x04)) {
        return 0;
    }
    lvl -= *(s16 *)((u8 *)a2 + 0x04);

    if (lvl >= *(s16 *)((u8 *)a2 + 0x02)) {
        return 0;
    }

    val = (*(s16 **)((u8 *)a2 + 0x08))[lvl];
    if (val == 0) {
        return 0;
    }

    idx2 = a0[3];
    if (idx2 >= *(s16 *)((u8 *)a2 + 0x0C)) {
        return 0;
    }
    val -= 1;

    /* Row stride is in BYTES and must stay bound to unk0E: writing
     * idx2 * (unk0E * 2) inline lets gcc reassociate it to
     * (idx2 * 2) * unk0E (sll a0 then mult) -- the separate rowBytes
     * local pins mult $a0,$v0 with $v0 = unk0E*2, as the target has.
     * The `row` pointer temp is also load-bearing: it is what keeps val
     * in $a1 and puts val*2 into a fresh $v0. NO register pins -- pinning
     * val to $5 (first-pass attempt) makes the shift go in-place into $a1
     * and reorders the mult delay shadow (sll before lw). Cookbook lever C:
     * the fix was to UNPIN.
     */
    rowBytes = *(s16 *)((u8 *)a2 + 0x0E) * 2;
    row = (u16 *)((u8 *)(*(u16 **)((u8 *)a2 + 0x10)) + idx2 * rowBytes);
    word = row[val];

    if (word != 0x7F) {
        return word;
    }

    return 0;
}
