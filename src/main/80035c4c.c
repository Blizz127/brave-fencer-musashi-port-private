/* Main-exec range [80035C4C,8003602C) from the SLUS executable.
 * SHA256(span)=4650693379b42fe7d19748b1a913437b52643c4aae0e494fe705cf40eb3f5b83.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80035C4C - byte-exact against retail at -O2 (tools/register_match.py). */
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



extern u8  D_8006AEEC;
extern s32 D_80076108;
extern s32 D_8007610C;
extern u8  D_8007620C;
extern u8  D_80076214;
extern s32 D_80078F10;
extern s16 D_800A4EF8;
extern s32 D_800A5BC8;
extern u8  D_800A63E4;
extern s32 D_800A63E8;
extern s32 D_800C6D28;
extern s32 D_800C7D30[];

extern void func_8003D650(int a0, int a1, int a2);
extern s32  func_8003EDE8(s32, s32, s32);
extern void func_80036130(s32, u8 *);
extern void func_800361CC();
extern void func_8003621C(void);
extern s32  func_80043410(void);
extern s32  func_80043420(void);
extern int  func_800435CC(s32, void *, void *);
extern s32  func_8004355C(s32 mode, u8 *result);
extern s32  func_80043704(u8 com, u8 *param);

s32 func_80035C4C(s32 arg0) {
    u8 result[8];
    u8 cmd[8];
    s32 trk;
    s32 st;
    s32 sync;
    u32 vol;

    if (*(u8 *)(arg0 + 7) != 0) {
        trk = *(s32 *)(arg0 + 0xC);
        D_8007620C = 0;
        *(u8 *)(arg0 + 7) = 0;
        *(u8 *)(arg0 + 3) = 0;
        if (D_800A5BC8 < trk) {
            return 1;
        }
        if (trk != 0) {
            if ((func_80043420() & 0x80) == 0) {
                *(u8 *)(arg0 + 3) = 1;
            }
            D_80076108 = 0;
            cmd[0] = 5;
            func_800435CC(0xE, cmd, 0);
            D_800A63E8 = *(s32 *)(arg0 + 0xC);
        } else {
            if (D_800C6D28 == 0) {
                return 1;
            }
            D_800A63E8 = D_800C6D28;
            func_80043704(3, 0);
            D_800C6D28 = 0;
            *(u8 *)(arg0 + 3) = 2;
        }
    }

    switch (*(u8 *)(arg0 + 3)) {
    case 0:
        if (++D_80076108 < 3) {
            return 0;
        }
        *(u8 *)(arg0 + 3) += 1;
        /* fall through */
    case 1:
        vol = ((u32)D_800A4EF8 * 97) >> 7;
        D_80076108 = 0;
        D_8006AEEC = vol;
        func_8003EDE8(0, vol & 0xFF, vol & 0xFF);
        func_8003D650(0, 1, 0);
        func_80043704(3, (u8 *)&D_800C7D30[*(s32 *)(arg0 + 0xC)]);
        func_800361CC(func_80036130);
        *(u8 *)(arg0 + 3) += 1;
        /* fall through */
    case 2:
        if (func_80043410() & 0x40) {
            if (D_80076108++ >= 0x12D) {
                D_80076214 = 1;
                return 1;
            }
            return 0;
        }
        sync = func_8004355C(1, result);
        if (sync == 2) {
            *(u8 *)(arg0 + 3) += 1;
            break;
        }
        if (sync != 5) {
            return 0;
        }
        if (result[0] & 0x10) {
            D_80076214 = 1;
            return 1;
        }
        return 1;
    case 3:
        st = func_80043410();
        if ((st & 0x80) == 0) {
            if (st & 0x10) {
                D_80076214 = 1;
                return 1;
            }
            return 0;
        }
        D_800A63E4 = 0xC;
        D_8007610C = 0;
        D_8007620C |= 0x80;
        *(u8 *)(arg0 + 3) += 1;
        break;
    case 4:
        if (D_800A63E4 == 0xD) {
            func_8003621C();
            func_8003EDE8(0, 0, 0);
            func_80043704(9, 0);
            D_8007620C = 0;
            D_80078F10 = 0;
        } else {
            if (D_8007610C == 0) {
                return 0;
            }
            st = func_80043410();
            if (st & 0x80) {
                return 0;
            }
            if (st & 0x10) {
                D_80076214 = 1;
            }
            func_8003621C();
            func_8003EDE8(0, 0, 0);
            D_8007620C = 0;
            D_80078F10 = 0;
            if (D_80076214 != 0) {
                return 1;
            }
            func_80043704(9, 0);
        }
        *(u8 *)(arg0 + 3) += 1;
        return 0;
    case 5:
        sync = func_8004355C(1, result);
        if (sync == 0) {
            return 0;
        }
        if (sync != 5) {
            return 1;
        }
        if (result[0] & 0x10) {
            D_80076214 = 1;
        }
        return 1;
    }
    return 0;
}
