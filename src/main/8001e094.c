/* Main-exec range [8001E094,8001E378) from the SLUS executable.
 * SHA256(span)=394ba0d330a1043d3b2419a6331c1837ea624cf9226362708435b7a4f0ddf29c.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8001E094 - byte-exact against retail at -O2 (tools/register_match.py). */

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

extern u8 D_800AF648;

void func_8001E094(s32 arg0)
{
    s16 sc[16];
    s16 res[16];
    s32 g;
    s32 t;

    sc[0] = *(u16 *)(arg0 + 0x18);
    sc[1] = 0;
    sc[2] = 0;
    sc[3] = 0;
    sc[4] = *(u16 *)(arg0 + 0x1A);
    sc[5] = 0;
    sc[6] = 0;
    sc[7] = 0;
    sc[8] = *(u16 *)(arg0 + 0x1C);

    g = (s32)&D_800AF648;

    /* gte_SetRotMatrix(obj->mat) */
    __asm__ __volatile__(
        "lw $12, 0(%0)\n" "lw $13, 4(%0)\n"
        "ctc2 $12, $0\n" "ctc2 $13, $1\n"
        "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n"
        "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n"
        : : "r"(*(s32 *)(arg0 + 0x34)) : "$12", "$13", "$14", "memory");

    /* res = obj->mat * sc, column by column */
    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"((s32)sc) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
        "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
        : : "r"((s32)res) : "$12", "$13", "$14", "memory");

    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"((s32)sc + 2) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
        "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
        : : "r"((s32)res + 2) : "$12", "$13", "$14", "memory");

    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"((s32)sc + 4) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
        "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
        : : "r"((s32)res + 4) : "$12", "$13", "$14", "memory");

    *(s32 *)((u8 *)res + 0x14) = *(s32 *)(*(s32 *)(arg0 + 0x34) + 0x14);
    *(s32 *)((u8 *)res + 0x18) = *(s32 *)(*(s32 *)(arg0 + 0x34) + 0x18);
    *(s32 *)((u8 *)res + 0x1C) = *(s32 *)(*(s32 *)(arg0 + 0x34) + 0x1C);

    /* gte_SetRotMatrix(&D_800AF648) */
    __asm__ __volatile__(
        "lw $12, 0(%0)\n" "lw $13, 4(%0)\n"
        "ctc2 $12, $0\n" "ctc2 $13, $1\n"
        "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n"
        "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n"
        : : "r"(g) : "$12", "$13", "$14", "memory");

    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"((s32)res) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
        "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
        : : "r"((s32)res) : "$12", "$13", "$14", "memory");

    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"((s32)res + 2) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
        "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
        : : "r"((s32)res + 2) : "$12", "$13", "$14", "memory");

    __asm__ __volatile__(
        "lhu $12, 0(%0)\n" "lhu $13, 6(%0)\n" "lhu $14, 12(%0)\n"
        "mtc2 $12, $9\n" "mtc2 $13, $10\n" "mtc2 $14, $11\n"
        "nop\n" "nop\n" "mvmva 1, 0, 3, 3, 0\n"
        : : "r"((s32)res + 4) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n"
        "sh $12, 0(%0)\n" "sh $13, 6(%0)\n" "sh $14, 12(%0)\n"
        : : "r"((s32)res + 4) : "$12", "$13", "$14", "memory");

    /* gte_SetTransMatrix(&D_800AF648) */
    __asm__ __volatile__(
        "lw $12, 20(%0)\n" "lw $13, 24(%0)\n"
        "ctc2 $12, $5\n" "lw $14, 28(%0)\n"
        "ctc2 $13, $6\n" "ctc2 $14, $7\n"
        : : "r"(g) : "$12", "$13", "$14", "memory");

    t = (s32)res + 0x14;
    __asm__ __volatile__(
        "lhu $13, 4(%0)\n" "lhu $12, 0(%0)\n"
        "sll $13, $13, 16\n" "or $12, $12, $13\n"
        "mtc2 $12, $0\n" "lwc2 $1, 8(%0)\n"
        "nop\n" "nop\n" "mvmva 1, 0, 0, 0, 0\n"
        : : "r"(t) : "$12", "$13", "memory");
    __asm__ __volatile__(
        "swc2 $25, 0(%0)\n" "swc2 $26, 4(%0)\n" "swc2 $27, 8(%0)\n"
        : : "r"(t) : "memory");

    /* gte_SetRotMatrix(res) ; gte_SetTransMatrix(res) */
    __asm__ __volatile__(
        "lw $12, 0(%0)\n" "lw $13, 4(%0)\n"
        "ctc2 $12, $0\n" "ctc2 $13, $1\n"
        "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n"
        "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n"
        : : "r"((s32)res) : "$12", "$13", "$14", "memory");
    __asm__ __volatile__(
        "lw $12, 20(%0)\n" "lw $13, 24(%0)\n"
        "ctc2 $12, $5\n" "lw $14, 28(%0)\n"
        "ctc2 $13, $6\n" "ctc2 $14, $7\n"
        : : "r"((s32)res) : "$12", "$13", "$14", "memory");
}
