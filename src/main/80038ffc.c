/* Main-exec range [80038FFC,8003916C) from the SLUS executable.
 * SHA256(span)=01991d7380c3f5089d94f150c393d63029693647db8948d74df20cc4c75ab096.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80038FFC - byte-exact against retail at -O2 (tools/register_match.py). */
#define CdIntToPos func_80043A18
#define CdPosToInt func_80043B1C
#define CdSearchFile func_80045374
typedef struct {
    u8 minute;
    u8 second;
    u8 sector;
    u8 track;
} CdlLOC;
typedef struct {
    CdlLOC pos;
    u32    size;
    char   name[16];
} CdlFILE;
extern CdlFILE *CdSearchFile(CdlFILE *fp, char *name);
extern int      CdPosToInt(CdlLOC *p);
extern CdlLOC  *CdIntToPos(int i, CdlLOC *p);

/* P31 S72 — the declarations that CROSS the src/800.c -> 800_b.c -> 800_c.c split.
 *
 * Measured, not guessed: of 1,247 names declared across the three regions, only 57 are used
 * outside the region that declares them, and 19 of those are typedefs. Every one had exactly
 * ONE definition and zero shape conflicts, so this is a partition of the old file, not a
 * rewrite — each typedef was MOVED here, never copied (a duplicate typedef is a C89 error).
 * The set was derived from the compiler's own errors, not from a regex model of C (R33).
 * See cookbook §426 and config/splat.us.exe.yaml for why the split exists at all. */

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



s32 func_80038FFC(s32 *param_1) {
    extern void func_80039B20(s32 *, s32);
    extern void func_80039308(s32 *, s32);
    extern void func_80039C5C(s32 *, s32);
    extern void func_80039F50(s32 *, s32);
    extern void func_8003A098(s32 *, s32);
    extern void func_8003A0D0(s32 *, s32);
    extern void func_8003A0E4(s32 *, s32);
    extern void func_8003A234(s32 *);

    u8 *np;
    u8 byte;
    s32 acc;

    acc = *(u8 *)*param_1;
    if (acc & 0x80) {
        *param_1 = (s32)((u8 *)*param_1 + 1);
        *((u8 *)param_1 + 0x1F7) = (u8)acc;
    } else {
        acc = *((u8 *)param_1 + 0x1F7);
    }

    switch ((u32)acc >> 4) {
    case 8:
        func_80039B20(param_1, acc & 0xF);
        break;
    case 9:
        func_80039308(param_1, acc & 0xF);
        break;
    case 10:
        func_80039C5C(param_1, acc & 0xF);
        break;
    case 11:
        func_80039F50(param_1, acc & 0xF);
        break;
    case 12:
        func_8003A098(param_1, acc & 0xF);
        break;
    case 13:
        func_8003A0D0(param_1, acc & 0xF);
        break;
    case 14:
        func_8003A0E4(param_1, acc & 0xF);
        break;
    case 15:
        acc &= 0xF;
        if (acc == 7) {
            goto set_zero;
        }
        if (acc < 8) {
            if (acc == 0) {
                goto set_zero;
            }
            return 0;
        }
        if (acc == 15) {
            goto call_234;
        }
        return 0;
    set_zero:
        acc = 0;
    loop_start:
        while (1) {
            byte = *(u8 *)*param_1;
            np = (u8 *)*param_1 + 1;
            *param_1 = (s32)np;
            acc += byte & 0x7F;
            if (!(byte & 0x80)) {
                break;
            }
            acc <<= 7;
        }
        *param_1 = (s32)np + (s16)acc;
        break;
    call_234:
        func_8003A234(param_1);
        break;
    }
    return 0;
}
