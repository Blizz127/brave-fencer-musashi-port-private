/* Main-exec range [80017778,800178C8) from the SLUS executable.
 * SHA256(span)=86449607c3a465df6de3b15c857e41fa4385aa7c23c715daf72292c085cca77d.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: RotTransPers4, SetPolyG4. */
#include "psx_types.h"

/* func_80017778 - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* func_80017778 — src/800.c (main, -O2).
 *
 * Builds one POLY_G4 (0x24 bytes) from a "vector-quad" descriptor (arg0):
 *   0x00..0x1F  four SVECTORs (v0..v3)
 *   0x20..0x2F  four packed rgb+code words
 *   0x30        a flags-ish word forwarded verbatim to the submit call
 * arg1 != 0 -> run RotTransPers4 on v0..v3 (perspective project into the
 *              packet's xy0..xy3), func_80017E8C(arg1) primes the matrix;
 * arg1 == 0 -> copy the already-projected xy words straight through and use
 *              v0.vz as otz.
 * Then, unless the RotTransPers4 clip flag (bit 0x1000 masked off) is set,
 * hand the packet to func_80017F14 (arg2 != 0) or func_80018094 (arg2 == 0).
 *
 * Mirrors the already-matched sibling func_80017930 (same file) which builds
 * a POLY_GT4 the same way; here there is no uv/tpage/clut section and the GTE
 * work goes through the SDK helper RotTransPers4 instead of raw gte_* macros.
 */

extern void *func_80010A08(s32);
extern void func_80058DE8(void *);
extern void func_80017E8C(s32);
extern s32 func_8004961C(void *, void *, void *, void *,
                          s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
extern void func_80017F14(void *, s32, s32);
extern void func_80018094(void *, s32, u32);

typedef struct {
    s16 vx, vy, vz, pad;
} SV_80017778;

typedef struct {
    SV_80017778 v[4]; /* 0x00 */
    u32 rgb[4];        /* 0x20 */
    u32 flags;          /* 0x30 */
} Src_80017778;

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 r1, g1, b1, pad1;
    s16 x1, y1;
    u8 r2, g2, b2, pad2;
    s16 x2, y2;
    u8 r3, g3, b3, pad3;
    s16 x3, y3;
} G4_80017778;

void func_80017778(Src_80017778 *arg0, s32 arg1, s32 arg2)
{
    G4_80017778 *p;
    s32 otz;
    s32 opz;
    s32 flag;

    p = (G4_80017778 *)func_80010A08(0x24);
    *(u32 *)&p->r0 = arg0->rgb[0];
    *(u32 *)&p->r1 = arg0->rgb[1];
    *(u32 *)&p->r2 = arg0->rgb[2];
    *(u32 *)&p->r3 = arg0->rgb[3];
    func_80058DE8(p);

    if (arg1 != 0) {
        func_80017E8C(arg1);
        otz = func_8004961C(&arg0->v[0], &arg0->v[1], &arg0->v[2], &arg0->v[3],
                             (s32 *)&p->x0, (s32 *)&p->x1, (s32 *)&p->x2, (s32 *)&p->x3,
                             &opz, &flag);
    } else {
        *(u32 *)&p->x0 = *(u32 *)&arg0->v[0];
        *(u32 *)&p->x1 = *(u32 *)&arg0->v[1];
        *(u32 *)&p->x2 = *(u32 *)&arg0->v[2];
        *(u32 *)&p->x3 = *(u32 *)&arg0->v[3];
        otz = arg0->v[0].vz;
        flag = 0;
    }

    if ((flag & ~0x1000) == 0) {
        if (arg2 != 0) {
            func_80017F14(p, otz, arg0->flags);
        } else {
            func_80018094(p, otz, arg0->flags);
        }
    }
}
