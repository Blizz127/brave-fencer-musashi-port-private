/* Main-exec range [80016110,80016224) from the SLUS executable.
 * SHA256(span)=e988dd4bc46b414166e20ec88b715e71e3e4a35bceb462d756c253e6f96e948d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80016110 - byte-exact against retail at -O2 (tools/register_match.py). */

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

/* Same shapes as the matched sibling func_80016450 (src/800.c) — a fixed
 * 0x18-byte POLY_F4 quad allocator + a single addPrim() into D_800A651C's OT
 * slot, then func_80016638. This one has no parameters: r0=g0=b0=0 (black),
 * code is always 0x2A (no branch), and the addPrim/func_80016638 call use
 * D_800A651C/D_800A6518 directly (matching the sibling's "else" arm shape,
 * but against D_800A651C instead of D_800AE7BC, and args (0,0) not (0,1)).
 * Field writes go through raw pointer arithmetic (not p->member) — a
 * struct-member store is MEM_IN_STRUCT_P and gcc-2.7.2's alias code treats
 * it as non-conflicting with the *(u32*)p full-word read, letting the
 * scheduler hoist that read arbitrarily early; plain casts keep everything
 * on the same alias footing so the load stays where source order puts it. */


extern void *func_80010A08(s32 a0);
extern void func_80016638(void *a0, s32 a1, s32 a2);
extern u16 D_800B9A02;
extern u8 D_800A6518[];

void func_80016110(void)
{
    extern OtBlk_80016450 D_800A651C[];   /* block scope: engine_core.h's DEFINE_ macros declare this symbol scalar in their own bodies */
    void *p;
    u32 *ot;
    register u32 m24 __asm__("$6");
    register u32 pv __asm__("$4");

    p = func_80010A08(0x18);
    m24 = 0x00FFFFFF;

    *(u8 *)((u8 *)p + 3) = 5;
    *(u8 *)((u8 *)p + 7) = 0x2A;
    *(s16 *)((u8 *)p + 8) = *(s16 *)((u8 *)p + 0x10) = -160;
    *(s16 *)((u8 *)p + 0xC) = *(s16 *)((u8 *)p + 0x14) = 160;
    *(s16 *)((u8 *)p + 0xA) = *(s16 *)((u8 *)p + 0xE) = -120;
    *(u8 *)((u8 *)p + 4) = *(u8 *)((u8 *)p + 5) = *(u8 *)((u8 *)p + 6) = 0;
    *(s16 *)((u8 *)p + 0x12) = *(s16 *)((u8 *)p + 0x16) = 120;

    pv = *(u32 *)p;
    *(u32 *)p = (pv & 0xFF000000) | (*(u32 *)D_800A651C[D_800B9A02].a & m24);
    __asm__ __volatile__("" : "=r"(pv));   /* zero-byte 2nd SET: kills the sched1 birthing boost */
    ot = (u32 *)D_800A651C[D_800B9A02].a;
    *ot = (*ot & 0xFF000000) | ((u32)p & m24);
    func_80016638(&D_800A6518[D_800B9A02 * 20], 0, 0);
}
