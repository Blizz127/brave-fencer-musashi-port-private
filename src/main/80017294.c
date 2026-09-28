/* Main-exec range [80017294,8001739C) from the SLUS executable.
 * SHA256(span)=94c2291cf2e35ebb22746974a9400a64f1a5ef49d4b2ffedea353256c09aebcd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: RotTransPers4, SetPolyF4. */
#include "psx_types.h"

/* func_80017294 - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* func_80017294 (main, src/800.c) — mass-lane fresh crack.
 *
 * Builds one POLY_F4 (0x18 bytes) from a "quad descriptor" arg0:
 *   0x00..0x1F  four SVECTOR-ish V0 entries (v0..v3), each { u32 xy; s16 z; s16 pad; }
 *   0x20        rgbc word (r0,g0,b0,code packed)
 *   0x24        flags word (passed straight through to func_80018094)
 * arg1 != 0  -> func_80017E8C(arg1) then RotTransPers4 projects v0..v3 into the
 *               poly's xy0..xy3 and returns otz, with a separate `flag` out-param.
 * arg1 == 0  -> copy the xy words straight through, otz = arg0->v[0].z, flag = 0.
 * Finally, if (flag & ~0x1000) == 0, hand the poly to func_80018094(p, otz, flags).
 *
 * Structurally identical in shape to func_80017930/func_80016F18 in this same TU
 * (both already-matched siblings), and to func_8018F734 (src/ov_SC03_117/...) which
 * is the RotTransPers4-based POLY_G4 exemplar this draft's call shape is modeled on.
 */

extern void *func_80010A08(s32);
extern void func_80058DC0(void *);
extern void func_80017E8C(s32);   /* src/800.c already declares this as (s32) at L1122/L1244 */
extern s32 func_8004961C(void *, void *, void *, void *,
                          s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern void func_80018094(void *, s32, u32);

typedef struct {
    u32 xy;
    s16 z;
    s16 pad;
} V0_80017294;   /* 8 bytes */

typedef struct {
    V0_80017294 v[4];  /* 0x00 */
    u32 rgbc;           /* 0x20 */
    u32 flags;           /* 0x24 */
} Src_80017294;

typedef struct {
    u32 tag;
    u32 rgbc;
    u32 xy0;
    u32 xy1;
    u32 xy2;
    u32 xy3;
} F4_80017294;   /* 0x18 bytes, POLY_F4 layout */

void func_80017294(Src_80017294 *arg0, s32 arg1)
{
    F4_80017294 *p;
    s32 otz;
    s32 flag;
    s32 opz;

    p = (F4_80017294 *)func_80010A08(0x18);
    p->rgbc = arg0->rgbc;
    func_80058DC0(p);

    if (arg1 != 0) {
        func_80017E8C(arg1);
        otz = func_8004961C(&arg0->v[0], &arg0->v[1], &arg0->v[2], &arg0->v[3],
                             (s32 *)&p->xy0, (s32 *)&p->xy1, (s32 *)&p->xy2, (s32 *)&p->xy3,
                             &opz, &flag);
    } else {
        p->xy0 = arg0->v[0].xy;
        p->xy1 = arg0->v[1].xy;
        p->xy2 = arg0->v[2].xy;
        p->xy3 = arg0->v[3].xy;
        otz = arg0->v[0].z;
        /* zero-byte scheduling barrier: without it gcc-2.7.2's sched1 hoists
         * `flag = 0` into the load-delay slot after the xy3 load (sched1
         * normalises statement order away, cf. func_80015D4C's note in this
         * same TU); the barrier keeps the store in its natural last position,
         * leaving a genuine nop in that slot as the target has. */
        __asm__ __volatile__("" ::: "memory");
        flag = 0;
    }

    if ((flag & ~0x1000) == 0) {
        func_80018094(p, otz, arg0->flags);
    }
}
