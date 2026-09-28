/* Main-exec range [8001751C,800176F0) from the SLUS executable.
 * SHA256(span)=8dc817d9ff35f6ac17c46cbd34a1a2565ceff180a4432f15de453f57a4a8c56f.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: GetClut, GetTPage, SetPolyGT3. */
#include "psx_types.h"

/* func_8001751C - byte-exact against retail at -O2 (tools/register_match.py). */

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

/* func_8001751C (POLY_GT3 builder) -- splat tags the target "Handwritten
 * function": hand-placed cop2 nops and delay-slot fills no -O2 C emits.
 * The GTE ops are written as single-statement inline asm (NO backslash-
 * continued macros, NO typedefs, externs block-scoped with the canonical
 * def-sigs) so the body is self-contained and liftable to any splice point
 * (cookbook recover_giant shape).
 *
 * Recovered semantics: alloc 0x28 POLY_GT3 via func_80010A08; copy the three
 * colour words; SetPolyGT3; if arg1: func_80017E8C + rtpt over the three
 * vertices (sxy -> p+8/0x14/0x20, IR0 -> sz, FLAG -> flag, SZ3>>2 -> otz),
 * else copy the xy words through, otz = (s16)v0.vz, sz = 0; split the three
 * uv words into u/v bytes; tpage/clut via GetTPage/GetClut; finally
 * if ((sz & ~0x1000) == 0) func_80018194(p, otz, attr).
 */
void func_8001751C(s32 *arg0, s32 arg1)
{
    extern void *func_80010A08(s32);
    extern void func_80058DAC();
    extern void func_80017E8C(s32);
    extern s32 func_80058B40(s32, s32, s32, s32);
    extern s32 func_80058B7C(s32, s32);
    extern void func_80018194(void *, s32, u32);

    u8 *p;
    s32 *va1, *va2;
    u8 *d0, *d1, *d2;
    s32 sz, flag, otz;
    u32 t, c;

    p = (u8 *)func_80010A08(0x28);
    *(u32 *)(p + 4) = *(u32 *)(arg0 + 9);
    *(u32 *)(p + 16) = *(u32 *)(arg0 + 10);
    *(u32 *)(p + 28) = *(u32 *)(arg0 + 11);
    func_80058DAC(p);

    if (arg1 != 0) {
        func_80017E8C(arg1);
        va1 = arg0 + 2;
        va2 = arg0 + 4;
        __asm__ volatile (
            "lwc2 $0, 0( %0 );"
            "lwc2 $1, 4( %0 );"
            "lwc2 $2, 0( %1 );"
            "lwc2 $3, 4( %1 );"
            "lwc2 $4, 0( %2 );"
            "lwc2 $5, 4( %2 )"
            : : "r"(arg0), "r"(va1), "r"(va2));
        __asm__ volatile ("nop;nop;rtpt");
        d0 = p + 8;
        d1 = p + 20;
        d2 = p + 32;
        __asm__ volatile (
            "swc2 $12, 0( %0 );"
            "swc2 $13, 0( %1 );"
            "swc2 $14, 0( %2 )"
            : : "r"(d0), "r"(d1), "r"(d2) : "memory");
        __asm__ volatile ("swc2 $8, 0( %0 )" : : "r"(&sz) : "memory");
        __asm__ volatile (
            "cfc2 $12, $31;nop;sw $12, 0( %0 )"
            : : "r"(&flag) : "$12", "memory");
        __asm__ volatile (
            "mfc2 $12, $19;nop;sra $12, $12, 2;sw $12, 0( %0 )"
            : : "r"(&otz) : "$12", "memory");
    } else {
        *(u32 *)(p + 8) = *(u32 *)(arg0 + 0);
        *(u32 *)(p + 20) = *(u32 *)(arg0 + 2);
        *(u32 *)(p + 32) = *(u32 *)(arg0 + 4);
        otz = *(s16 *)((s8 *)arg0 + 4);
        sz = 0;
    }

    t = *(u32 *)(arg0 + 6);
    *(p + 12) = t;
    *(p + 13) = t >> 16;
    t = *(u32 *)(arg0 + 7);
    *(p + 24) = t;
    *(p + 25) = t >> 16;
    t = *(u32 *)(arg0 + 8);
    *(p + 36) = t;
    *(p + 37) = t >> 16;

    *(u16 *)(p + 26) = func_80058B40(((*(u32 *)(arg0 + 12)) >> 24) & 3,
                                ((*(u32 *)(arg0 + 12)) >> 28) & 3,
                                ((*(u16 *)((s8 *)arg0 + 24)) >> 2) & 0x3FC0,
                                *(u16 *)((s8 *)arg0 + 26) & 0xFF00);

    c = *((u8 *)arg0 + 52);
    *(u16 *)(p + 14) = func_80058B7C(c < 0xE0 ? 0x160 : 0x100, c | 0x100);

    if ((sz & ~0x1000) == 0) {
        func_80018194((void *)p, otz, *(u32 *)(arg0 + 12));
    }
}
