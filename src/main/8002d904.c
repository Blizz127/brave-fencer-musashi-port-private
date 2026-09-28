/* Exact retail word export for [8002D904,8002DC68); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002D904 - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* func_8002D904 (main, 217 ins) — byte MATCH.  Levers that closed it, in the order they paid:
 *
 * 1. NON-/s TABLE LOADS ARE THE WHOLE SCHEDULE (worth 26 of 41 residuals).  gcc-2.7.2's
 *    expand_expr INDIRECT_REF sets MEM_IN_STRUCT_P whenever "the address was computed by
 *    addition" — so `D_80068B5E[i][0]`, `((u16*)D_80068B5E)[i*8]` and every other indexed
 *    spelling is /s AND varying, which true_dependence/anti_dependence then declare
 *    non-aliasing against the plain fixed-address scalar stores around it (cf. the W16 note
 *    at src/800.c:21942).  The load floats to the top of the block and permutes the whole
 *    tail.  Assigning the address to a POINTER VARIABLE first makes the INDIRECT_REF's
 *    operand a VAR_DECL, not a PLUS_EXPR — MEM_IN_STRUCT_P stays 0, the real store->load
 *    edges come back, and the load sits exactly where the target has it.  combine folds the
 *    pointer back into the MEM, so it costs ZERO instructions.  (b5e / b66 below.)
 * 2. `s16 b = a;` BEFORE the guard, not after (+2 ins, and the $v0/$a1 split).  gcc-2.7.2
 *    collapses `(short)x` on an SImode pseudo to nothing at expand time (convert_modes sees
 *    oldmode == GET_MODE(x) == SImode and returns x), so NO cast at the call site can emit
 *    the target's `sll/sra`.  The extension only survives when a genuinely HImode local is
 *    assigned in one block and consumed in a distant one.  And the copy must sit ABOVE
 *    `if (a < 0)` so `a`'s live range overlaps `b`'s — otherwise they coalesce and the
 *    `addu $a1,$v0,$zero` disappears.
 * 3. `id = arg0 & 0xFFFF;` ABOVE the func_8002EE64 call (worth the last 3 residuals).  That
 *    makes the pseudo cross a call, so global-alloc gives it a CALLEE-SAVED reg ($s1) instead
 *    of $a2; sched1 then sinks the `andi` back below the `jal` on its own.  The 0x134 test
 *    deliberately re-spells `(arg0 & 0xFFFF)` — the target recomputes it from $s2 at 8002DB14
 *    because $s1 has been reused for &D_800A4E86 by then.
 * 4. §333 frame arithmetic: .frame wants vars=8 (0x28 = 16 args + 16 regs + 8), which four
 *    saved regs alone do not explain — an unreferenced trailing aggregate supplies it.
 * 5. Address-of locals (pa2/p86/q86/p8e) are the TU's own house idiom (src/800.c:17641,
 *    17665, 17787): with -G0 gcc emits each global reference as one `lh sym` macro, so there
 *    is no address subexpression for CSE to hoist across blocks — only an explicit pointer
 *    produces the target's `lui/addiu` base registers ($t0, $s1, $s0, $a0).
 * 6. `p86` is assigned AFTER the func_80038210 call so the `lui/addiu $s1` pair lands after
 *    the `jal` rather than being hoisted into the pre-call slot.
 *
 * Declarations follow src/800.c verbatim (§376): D_80068B60 is `u8[]` at 0x10 stride
 * (src/800.c:21368), D_80068B66 is `u16[][8]` (17731), D_80065438 is `H2[]` (21967) — the H2
 * typedef below is the TU's own (src/800.c:226) and harvest_verify strips it on splice —
 * and func_8003834C is (s32, s16) per its definition at src/800.c:22556.
 * Verified: match_one MATCH 217/217; blocker_probe real-cc1 whole-TU MATCH 217 ins, no
 * blockers; reloc_identity AGREE (50 relocs); all four internal `j` targets checked by hand
 * (§195-D: the 26-bit field is masked, so match_one cannot see them) — 0xf4 / 0xf0 / 0x328 /
 * 0x300, identical to the target's .L8002D9F8 / .L8002D9F4 / .L8002DC2C / .L8002DC04.
 */



extern void func_8002EE64(void);
extern s32  func_80038210(s32, s16, s32);
extern void func_8003819C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80038308(s16 a0);
extern void func_8003834C(s32, s16);
extern void func_80038638(s32, s32);

extern s16 D_800A4642[];
extern s16 D_80068B5C[][8];
extern u16 D_80068B5E[][8];
extern u8  D_80068B60[];
extern s16 D_80068B62[][8];
extern u16 D_80068B66[][8];
extern H2  D_80065438[];
extern s32 D_800652F0[];
extern s32 D_800760E0;
extern s32 D_800A4E7C;
extern s16 D_800A4E84;
extern s16 D_800A4E86;
extern u16 D_800A4E8A;
extern u16 D_800A4E8C;
extern u16 D_800A4E8E;
extern s16 D_800A4E9A;
extern u16 D_800A4EA0;
extern u16 D_800A4EA2;
extern u8  D_800A4F1C;
extern u8  D_800A4F1E;

void func_8002D904(s32 arg0) {
    s32 i;
    s32 p;
    s32 a;
    s16 b;
    s32 t;
    s32 id;
    s32 q;
    u16 f;
    u16 *pa2;
    u16 *b5e;
    u16 *b66;
    s32 pad[2];         /* §333: unreferenced — supplies the target's vars=8 */

    id = arg0 & 0xFFFF; /* above the call on purpose: pins `id` to a callee-saved reg */
    func_8002EE64();
    i = id - 0x100;
    a = D_800A4642[D_80068B5C[i][0] * 12];
    b = a;              /* above the guard on purpose: keeps `a` and `b` from coalescing */
    if (a < 0) {
        return;
    }
    if ((D_800A4E8E & 0x20) == 0) {
        return;
    }
    if (D_800A4F1E != 0) {
        return;
    }

    if (id == 0x18E) {
        p = D_800760E0;
    } else if (D_80068B62[i][0] != 0) {
        t = *(s32 *)(D_800A4E7C + D_80068B62[i][0] * 4);
        if (t == 0) {
            return;
        }
        p = D_800A4E7C + t + 4;
    } else {
        p = D_800A4E7C + 0x10;
    }

    pa2 = &D_800A4EA2;
    q = D_800652F0[D_80065438[*(s16 *)(D_80068B60 + i * 0x10)].f0];
    if ((*pa2 & 4) != 0 && D_800A4EA0 == i) {
        D_800A4EA0 = 0;
        D_800A4E8E = *pa2;
        *pa2 = 0;
        D_800A4E8E |= 4;
        D_800A4E8C = i;
        D_800A4E8A = 0;
        D_800A4E86 = D_800A4E9A;
        b5e = (u16 *)((u8 *)D_80068B5E + D_800A4E8C * 0x10);
        D_800A4E84 = *b5e;
        func_8003819C(D_800A4E86, 0, 0x4000, 0x111);
        func_8003834C(D_800A4E86, D_800A4E84);
        func_80038308(D_800A4E86);
    } else {
        s16 *p86;
        s16 *q86;
        s32 r;

        r = func_80038210(p, b, q);
        p86 = &D_800A4E86;      /* after the call: keeps lui/addiu $s1 out of the pre-call slot */
        *p86 = r;
        if (*p86 == -1) {
            return;
        }
        if ((arg0 & 0xFFFF) == 0x134) {   /* re-spelled, not `id`: the target recomputes it */
            if ((D_800A4F1C & 2) == 0) {
                func_80038638(*p86, 4);
            }
            if ((D_800A4F1C & 4) == 0) {
                func_80038638(*p86, 5);
                func_80038638(*p86, 6);
                func_80038638(*p86, 7);
            }
            if ((D_800A4F1C & 8) == 0) {
                func_80038638(*p86, 8);
            }
        }
        {
            u16 *p8e = &D_800A4E8E;

            f = *p8e & 0x20;
            *p8e = f | 4;
            b5e = (u16 *)((u8 *)D_80068B5E + i * 0x10);
            D_800A4E84 = *b5e;
            D_800A4E8C = i;
            b66 = (u16 *)((u8 *)D_80068B66 + i * 0x10);
            if ((*b66 & 1) != 0) {
                *p8e = f | 0x104;
            } else {
                *p8e = f | 4;
            }
        }
        q86 = &D_800A4E86;
        func_8003834C(*q86, D_800A4E84);
        D_800A4E8A = 0;
        func_80038308(*q86);
    }
    D_800A4E8E |= 9;
}
