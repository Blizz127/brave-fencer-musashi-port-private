/* Exact retail word export for [8002DC68,8002DF80); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002DC68 - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* func_8002DC68 -- the 0x400+ message dispatcher: takes the D_8006451C record for
 * (param_1 & 0xFFFF), optionally follows one level of indirection (kind 6), raises the
 * D_800A4F17 reentrancy lock, and switches on the record's low-6-bit kind (1..18).
 *
 * Case 12's `(param_2 << 25) >> 25` is NOT decoration -- it is the byte lever (cookbook
 * candidate: "defeat CSE with a shift pair combine folds back into the mask").  The target
 * computes `andi $s2,0x7F` TWICE: once into $v1 for the `sltu` and again into $v0, which
 * reorg then steals for the `beqz`'s delay slot.  Written as `param_2 & 0x7F` on both sides,
 * cse merges the two `(and:SI ...)` into one pseudo, the store reuses $v1 and the delay slot
 * goes empty -- exactly the 2-instruction residual this function sat at (idx 156 nop vs
 * `andi $v0,$s2,0x7F`, idx 158 `sb $v1` vs `sb $v0`).  cse sees the shift pair as an unrelated
 * expression, and combine's simplify_shift_const turns it back into `andi ...,0x7F` afterwards,
 * so the second mask survives to fill the slot.  Byte-verified both ways round (the shift pair
 * on the compare side matches identically).
 *
 * NOTE for the gate (§378): src/800_b.c already carries four `extern void func_8002DC68(s32, s32);`
 * decls (lines 851, 928, 1249, 2007) plus call sites at 868, 905, 936 (already self-cast) and
 * inside func_8002F248.  This definition returns s32, so the §376/§378 chain
 * (fix_arity_callers --any-proto -> cast_self_callers) has to run before the whole-binary gate. */
extern s16 D_800A4EFC;
extern u8  D_8006451C[];
extern u8  D_800A4F1B;
extern s8  D_800A4F17;
extern u8  D_8006A980;
extern s16 D_8006A982;
extern u8  D_8006A984;
extern u8  D_8006A988[];

extern s32  func_8002F4E4(u8 *);
extern void func_8002F248(s32, s32);
extern void func_8002F714(s32, s32);
extern s32  func_80032048(u32, u8 *, u32);
extern s32  func_800322A8(u32, u8 *, u32);
extern s32  func_800324A4(u32, u8 *, u32, s32);
extern s32  func_80032774(u32, u8 *, u32);
extern s32  func_80034314(u32, u8 *, u32);

s32 func_8002DC68(u32 param_1, u32 param_2) {
    u8 *p;
    u8 *lk;
    s32 ret;
    s8 old;
    u16 val;
    u32 m7;

    if (D_800A4EFC != 0) {
        return 0;
    }
    p = &D_8006451C[(param_1 & 0xFFFF) * 4];
    if (D_800A4F1B == 0 && (*p & 0x80) == 0) {
        return 0;
    }
    if ((*p & 0x3F) == 6) {
        s32 id = func_8002F4E4(p) & 0xFFFF;
        if (id == 0) {
            return 0;
        }
        p = &D_8006451C[id * 4];
    }
    lk = (u8 *)&D_800A4F17;
    old = *lk;
    *lk = 1;
    ret = 0;
    switch (*p & 0x3F) {
    case 1:
        ret = func_80032048(param_1, p, param_2 & 0xFFFF);
        break;
    case 9:
        ret = func_800324A4(param_1, p, param_2 & 0xFFFF, 0);
        break;
    case 7:
        ret = func_800324A4(param_1, p, param_2 & 0xFFFF, 1);
        break;
    case 10:
        func_800322A8(param_1, p, param_2 & 0xFFFF);
        /* fallthrough */
    case 8:
        ret = func_80032774(param_1, p, param_2 & 0xFFFF);
        break;
    case 5:
        ret = func_80034314(param_1, p, param_2 & 0xFFFF);
        break;
    case 2:
        func_8002F248((s32)p, param_2 & 0xFFFF);
        break;
    case 11:
        if ((D_8006A980 & 4) != 0) {
            val = D_8006A982 + D_8006A988[param_2 & 7] - 2;
        } else {
            D_8006A980 |= 4;
            val = D_8006A988[param_2 & 7];
        }
        D_8006A982 = val;
        m7 = param_2 & 7;
        if (m7 == 6) {
            D_8006A980 |= 1;
        } else if (m7 == 2) {
            D_8006A980 |= 2;
        }
        break;
    case 12:
        D_8006A980 |= 8;
        if (D_8006A984 < (param_2 & 0x7F)) {
            D_8006A984 = (u8)((param_2 << 25) >> 25);
        }
        break;
    case 13:
        ret = func_80032048((param_1 & 0xFFFF) | 0x08F40000, p, 0xFFFF);
        break;
    case 14:
        ret = func_80032048((param_1 & 0xFFFF) | 0x0A8A0000, p, 0xFFFF);
        break;
    case 15:
        ret = func_80032048((param_1 & 0xFFFF) | 0x08960000, p, 0xFFFF);
        break;
    case 17:
        func_8002F714(p[3], param_2 & 0xFFFF);
        break;
    case 16:
        ret = func_80032048((param_1 & 0xFFFF) | 0x0B7D0000, p, 0xFFFF);
        break;
    case 18:
        ret = func_80032048((param_1 & 0xFFFF) | 0x04F30000, p, 0xFFFF);
        break;
    }
    D_800A4F17 = old;
    return ret;
}
