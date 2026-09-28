/* Main-exec range [800221A8,800226C0) from the SLUS executable.
 * SHA256(span)=5eb7774640069bcc7919d11fd7d3203f02a0d3bd1cbedaa3a9fa22b9144b144e.
 * Word export for the native seam; the body below keeps its
 * own oracle match claim (registry-verified, untouched). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_800221A8 - byte-exact against retail at -O2 (tools/register_match.py). */

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

/* func_800221A8 (src/800.c, main, 326 ins) -- byte-proven MATCH.
 *
 * Projects a 12-point silhouette for the object at arg0 and hands the screen-XY
 * array to func_800226C0 with the OT slot picked by the projected depth.
 * GsCOORDINATE2 at sp+0x88 (super is at +0x48, so `rotate` must be declared),
 * MATRIX out at sp+0xD8 -> $s0, the u16 game-state word is read off the
 * D_800AF630 base at +0xA3D2 (the house idiom, cf. func_80015144 in this TU).
 *
 * LEVERS THAT MATTERED (all four were needed; each was worth 3-160 instructions):
 *  1. FRAME LAYOUT = declaration order of the AGGREGATES.  expand_decl slots every
 *     BLKmode local with align 0 -> BIGGEST_ALIGNMENT (8), so each aggregate starts
 *     8-byte aligned in declaration order: sv0/sv1/sv2 @0x10/0x18/0x20, sxy[13]
 *     @0x28 (ends 0x5B -> rounds to 0x60), the 4-byte AGGREGATE sxy2 @0x60 (a
 *     scalar there would sit at 0x5C and pull m2 to 0x64), m2 @0x68, cd @0x88,
 *     m @0xD8, vv @0xF8.  The address-taken SCALARS follow in declaration order
 *     at 0x108/0x10C/0x110, giving frame 0x130.  (§333/§358 family.)
 *  2. NO STRENGTH REDUCTION.  The target recomputes every index with sll; a
 *     `i += 3;` placed BEFORE the last sxy[i] pair let loop.c combine_givs merge
 *     the address givs and reduce them into 4 extra induction registers (-8 ins,
 *     closeness 166).  Writing `sxy[i + 3]` first and `i += 3;` LAST keeps every
 *     giv bare (benefit 2 - 2*biv_count = 0 => "not worth while", loop.md §L0),
 *     and cse then rewrites `i += 3` as a COPY of the already-computed i+3
 *     (`addu $t0,$a1,$zero`).  §344's counter pin also kills LSR, but a hard-reg
 *     counter lets local-alloc coalesce i+3 back in place -- it plateaus at 41.
 *  3. `i = 0;` goes AFTER the `if (o->unk74)` block, not before: dbr fills the
 *     beqz slot with a copy of the join head, so the insn appears TWICE.
 *  4. `o->unk2E & 0xFFF` INLINE in both arms, not via a `d` local -- the cse temp
 *     takes $v0 (the dead 0xC000 constant's register); a named local takes $v1.
 */

typedef struct { s16 vx, vy, vz, pad; } SV221A8;
typedef struct { s16 m[3][3]; s32 t[3]; } MX221A8;          /* 0x20 */
typedef struct { s32 vx, vy, vz, pad; } VC221A8;            /* 0x10 */
typedef struct { u16 x, y; } XY221A8;                       /* 0x04 */

typedef struct {
    /* 0x00 */ s32 flg;
    /* 0x04 */ MX221A8 coord;
    /* 0x24 */ MX221A8 workm;
    /* 0x44 */ void *rotate;
    /* 0x48 */ void *super;
    /* 0x4C */ void *sub;
} CD221A8; /* 0x50 */

typedef struct {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ XY221A8 pt[1];
} Src221A8;

typedef struct {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ u8 pad0E[2];
    /* 0x10 */ s16 unk10[4];
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ Src221A8 *unk20;
    /* 0x24 */ u8 pad24[4];
    /* 0x28 */ s32 unk28;
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E;
    /* 0x30 */ u8 pad30[4];
    /* 0x34 */ MX221A8 unk34;
    /* 0x54 */ MX221A8 unk54;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ void *unk78;
} Obj221A8;

#define SRM221A8(r0) __asm__ volatile (                  \
    "lw $12, 0( %0 );"  "lw $13, 4( %0 );"               \
    "ctc2 $12, $0;"     "ctc2 $13, $1;"                  \
    "lw $12, 8( %0 );"  "lw $13, 12( %0 );"              \
    "lw $14, 16( %0 );"                                  \
    "ctc2 $12, $2;"     "ctc2 $13, $3;" "ctc2 $14, $4"   \
    : : "r"( r0 ) : "$12", "$13", "$14" )

#define STM221A8(r0) __asm__ volatile (                  \
    "lw $12, 20( %0 );" "lw $13, 24( %0 );"              \
    "ctc2 $12, $5;"     "lw $14, 28( %0 );"              \
    "ctc2 $13, $6;"     "ctc2 $14, $7"                   \
    : : "r"( r0 ) : "$12", "$13", "$14" )

#define LDV0221A8(r0) __asm__ volatile (                 \
    "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"( r0 ) )

#define LDV3221A8(r0, r1, r2) __asm__ volatile (         \
    "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );"              \
    "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );"              \
    "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )"               \
    : : "r"( r0 ), "r"( r1 ), "r"( r2 ) )

#define RTPS221A8() __asm__ volatile ("nop;nop;rtps")
#define RTPT221A8() __asm__ volatile ("nop;nop;rtpt")

#define STSXY221A8(r0) __asm__ volatile (                \
    "swc2 $14, 0( %0 )" : : "r"( r0 ) : "memory" )

#define STSXY3221A8(r0, r1, r2) __asm__ volatile (       \
    "swc2 $12, 0( %0 );" "swc2 $13, 0( %1 );"            \
    "swc2 $14, 0( %2 )"                                  \
    : : "r"( r0 ), "r"( r1 ), "r"( r2 ) : "memory" )

#define STFLG221A8(r0) __asm__ volatile (                \
    "cfc2 $12, $31;nop;sw $12, 0( %0 )"                  \
    : : "r"( r0 ) : "$12", "memory" )

#define STSZOTZ221A8(r0) __asm__ volatile (              \
    "mfc2 $12, $19;nop;sra $12, $12, 2;sw $12, 0( %0 )"  \
    : : "r"( r0 ) : "$12", "memory" )

#define STSZ221A8(r0) __asm__ volatile (                 \
    "swc2 $19, 0( %0 )" : : "r"( r0 ) : "memory" )

extern u8 D_800AF630[];
extern u8 D_800A6610[];
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8004901C(void *a0, void *a1);
extern void func_800547D8(s32 a0, void *a1);
extern s32 func_80021174(s32 a0, s32 a1);
extern void func_800226C0();

void func_800221A8(Obj221A8 *o) {
    SV221A8 sv0;
    SV221A8 sv1;
    SV221A8 sv2;
    XY221A8 sxy[13];
    XY221A8 sxy2[1];
    MX221A8 m2;
    CD221A8 cd;
    MX221A8 m;
    VC221A8 vv;
    s32 flag;
    s32 otz;
    s32 sz;
    u8 *p;
    u8 *ot;
    Src221A8 *s;
    MX221A8 *mp;
    u32 z;
    s32 i;

    cd.super = o->unk78;
    cd.flg = 0;
    p = D_800AF630;

    if (o->unk2C & 1) {
        o->unk2C &= 0xFFFE;
        cd.coord = o->unk34;
    } else {
        func_80049CAC((s32)o->unk10, (s32)&cd.coord);
        cd.coord.t[0] = o->unk08;
        cd.coord.t[1] = o->unk0A;
        cd.coord.t[2] = o->unk0C;
    }

    vv.vx = o->unk18;
    vv.vy = o->unk1A;
    vv.vz = 0x1000;
    func_8004901C(&cd.coord, &vv);

    mp = &m;
    func_800547D8((s32)&cd, mp);

    o->unk34 = cd.coord;
    o->unk54 = cd.workm;

    s = o->unk20;
    if (s != 0 && func_80021174(o->unk28, (s32)cd.workm.t) != 0) {
        ot = (u8 *)((*(u16 *)(p + 0xA3D2) << 14) + (u32)D_800A6610);
        SRM221A8(mp);
        STM221A8(mp);
        sv0.vz = 0;
        sv0.vy = 0;
        sv0.vx = 0;
        LDV0221A8(&sv0);
        RTPS221A8();
        STSXY221A8(&sxy[0]);
        STFLG221A8(&flag);
        STSZOTZ221A8(&otz);
        if ((flag & ~0x1000) == 0) {
            STSZ221A8(&sz);
            z = otz + 1;
            if (o->unk2E & 0xC000) {
                if ((o->unk2E & 0xC000) == 0xC000) {
                    z -= (o->unk2E & 0xFFF);
                    if ((s32)z < 0) {
                        z = 0;
                    }
                } else {
                    z += (o->unk2E & 0xFFF);
                }
            }
            if (z < 0x1000) {
                m2.m[0][0] = o->unk18;
                m2.m[0][1] = 0;
                m2.m[0][2] = 0;
                m2.m[1][0] = 0;
                m2.m[1][1] = o->unk1A;
                m2.m[1][2] = 0;
                m2.m[2][0] = 0;
                m2.m[2][1] = 0;
                m2.m[2][2] = 0x1000;
                m2.t[2] = 0;
                m2.t[1] = 0;
                m2.t[0] = 0;
                SRM221A8(&m2);
                STM221A8(&m2);
                if (o->unk74 != 0) {
                    sv0.vx = *(u16 *)&o->unk74;
                    sv0.vy = *((u16 *)&o->unk74 + 1);
                    sv0.vz = sz;
                    LDV0221A8(&sv0);
                    RTPS221A8();
                    STSXY221A8(&sxy2[0]);
                    sxy[0].x += sxy2[0].x;
                    sxy[0].y += sxy2[0].y;
                }
                i = 0;
                do {
                    sv0.vx = s->pt[i].x;
                    sv0.vy = s->pt[i].y;
                    sv0.vz = sz;
                    sv1.vx = s->pt[i + 1].x;
                    sv1.vy = s->pt[i + 1].y;
                    sv1.vz = sz;
                    sv2.vx = s->pt[i + 2].x;
                    sv2.vy = s->pt[i + 2].y;
                    sv2.vz = sz;
                    LDV3221A8(&sv0, &sv1, &sv2);
                    RTPT221A8();
                    STSXY3221A8(&sxy[i + 1], &sxy[i + 2], &sxy[i + 3]);
                    sxy[i + 1].x += sxy[0].x;
                    sxy[i + 1].y += sxy[0].y;
                    sxy[i + 2].x += sxy[0].x;
                    sxy[i + 2].y += sxy[0].y;
                    sxy[i + 3].x += sxy[0].x;
                    sxy[i + 3].y += sxy[0].y;
                    i += 3;
                } while (i < 0xC);
                func_800226C0((s32)o, (s32)s, (s32)&sxy[0], (s32)(ot + z * 4));
            }
        }
    }
}
