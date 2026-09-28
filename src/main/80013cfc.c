/* Main-exec range [80013CFC,80013E94) from the SLUS executable.
 * SHA256(span)=9f3a61eab7d82c48b08c197dbc7272f32a811dfca40982712e6a18ad6f610c45.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: ApplyMatrixSV. */
#include "psx_types.h"

/* func_80013CFC - byte-exact against retail at -O2 (tools/register_match.py). */

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

#define gte_SetRotMatrixX(r0) __asm__ __volatile__ ( \
    "lw $12, 0(%0);" \
    "lw $13, 4(%0);" \
    "ctc2 $12, $0;" \
    "ctc2 $13, $1;" \
    "lw $12, 8(%0);" \
    "lw $13, 12(%0);" \
    "lw $14, 16(%0);" \
    "ctc2 $12, $2;" \
    "ctc2 $13, $3;" \
    "ctc2 $14, $4" \
    : : "r"(r0) : "$12", "$13", "$14")

#define gte_ldclmvX(r0) __asm__ __volatile__ ( \
    "lhu $12, 0(%0);" \
    "lhu $13, 6(%0);" \
    "lhu $14, 12(%0);" \
    "mtc2 $12, $9;" \
    "mtc2 $13, $10;" \
    "mtc2 $14, $11" \
    : : "r"(r0) : "$12", "$13", "$14")

#define gte_rtirX() __asm__ __volatile__ ("nop; nop; mvmva 1, 0, 3, 3, 0")

#define gte_stclmvX(r0) __asm__ __volatile__ ( \
    "mfc2 $12, $9;" \
    "mfc2 $13, $10;" \
    "mfc2 $14, $11;" \
    "sh $12, 0(%0);" \
    "sh $13, 6(%0);" \
    "sh $14, 12(%0)" \
    : : "r"(r0) : "$12", "$13", "$14")

void func_80013CFC(short param_1, void *param_2, void *param_3)
{
    s16 matrix[16];
    s16 rot[16];
    s32 sin_val;
    s32 cos_val;
    register s32 v1 __asm__("$3");
    s16 *rotp;
    s16 *matp;

    func_80013F3C(matrix);
    sin_val = func_8004787C(param_1);
    cos_val = func_80047948(param_1);

    v1 = -sin_val;
    __asm__ __volatile__("" ::: "memory");
    *(s16 *)((s32)rot + 0x00) = cos_val;
    *(s16 *)((s32)rot + 0x08) = cos_val;
    *(s16 *)((s32)rot + 0x10) = 0x1000;
    rotp = rot;
    *(s16 *)((s32)rot + 0x06) = sin_val;
    matp = matrix;
    *(s16 *)((s32)rot + 0x02) = v1;
    *(s16 *)((s32)rot + 0x04) = 0;
    *(s16 *)((s32)rot + 0x0A) = 0;
    *(s16 *)((s32)rot + 0x0C) = 0;
    *(s16 *)((s32)rot + 0x0E) = 0;

    gte_SetRotMatrixX(matp);
    gte_ldclmvX(rotp);
    gte_rtirX();
    gte_stclmvX(matp);
    gte_ldclmvX(rotp + 1);
    gte_rtirX();
    gte_stclmvX(matp + 1);
    gte_ldclmvX(rotp + 2);
    gte_rtirX();
    gte_stclmvX(matp + 2);

    func_8001282C(matp);
    func_80048FBC(matp, param_2, param_3);
}
