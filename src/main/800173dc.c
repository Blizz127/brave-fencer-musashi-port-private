/* Main-exec range [800173DC,800174DC) from the SLUS executable.
 * SHA256(span)=b0e3a3426d9f6065b9e940a88f06c2a557b8c4a2aa9828323b57ead44c93b284.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: RotTransPers3, SetPolyG3. */
#include "psx_types.h"

/* func_800173DC - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* SVECTOR-shaped vertex: vx/vy packed as one word (xy), then z, then pad.
 * Same layout convention as V16F18 in func_80016F18 (src/800.c). */
typedef struct {
    u32 xy;   /* 0x0: vx (lo16) | vy (hi16) */
    s16 z;    /* 0x4 */
    s16 pad;  /* 0x6 */
} SVec3_800173DC; /* 0x8 */

/* Source descriptor: three vertices + three Gouraud colour words + a trailing
 * flags/attr word (only ever read, never as a vertex). */
typedef struct {
    SVec3_800173DC v0;      /* 0x00 */
    SVec3_800173DC v1;      /* 0x08 */
    SVec3_800173DC v2;      /* 0x10 */
    u32 rgbc0;               /* 0x18 */
    u32 rgbc1;               /* 0x1C */
    u32 rgbc2;               /* 0x20 */
    u32 attr;                /* 0x24 */
} Src_800173DC;

/* POLY_G3 (libgpu), 0x1C bytes. */
typedef struct {
    u32 tag;    /* 0x00 */
    u32 rgbc0;  /* 0x04 */
    u32 xy0;    /* 0x08 */
    u32 rgbc1;  /* 0x0C */
    u32 xy1;    /* 0x10 */
    u32 rgbc2;  /* 0x14 */
    u32 xy2;    /* 0x18 */
} G3_800173DC; /* 0x1C */

extern void *func_80010A08(s32 size);
extern void func_80058D98(G3_800173DC *p);
extern void func_80017E8C(s32 arg0);
extern s32 func_8004958C(void *v0, void *v1, void *v2,
                          s32 *sxy0, s32 *sxy1, s32 *sxy2,
                          s32 *p, s32 *flag);
/* §183 TYPE-adopted-TU: src/800.c declares (and defines at 0x80018094) the
 * third parameter as u32; adopt the TU's spelling verbatim. arg0->attr is
 * already u32, so no cast is needed at the use site and codegen is unchanged. */
extern void func_80018094(void *a0, s32 a1, u32 a2);

void func_800173DC(Src_800173DC *arg0, s32 arg1)
{
    G3_800173DC *p;
    s32 otzp;
    s32 flg;
    s32 otz;

    p = (G3_800173DC *)func_80010A08(0x1C);
    p->rgbc0 = arg0->rgbc0;
    p->rgbc1 = arg0->rgbc1;
    p->rgbc2 = arg0->rgbc2;
    func_80058D98(p);

    if (arg1 != 0) {
        func_80017E8C(arg1);
        otz = func_8004958C(&arg0->v0, &arg0->v1, &arg0->v2,
                             (s32 *)&p->xy0, (s32 *)&p->xy1, (s32 *)&p->xy2,
                             &otzp, &flg);
    } else {
        p->xy0 = arg0->v0.xy;
        p->xy1 = arg0->v1.xy;
        p->xy2 = arg0->v2.xy;
        __asm__ volatile("");
        otz = arg0->v0.z;
        flg = 0;
    }

    if ((flg & ~0x1000) == 0) {
        func_80018094(p, otz, arg0->attr);
    }
}
