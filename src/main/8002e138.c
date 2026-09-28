/* Exact retail word export for [8002E138,8002E5BC); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002E138 - byte-exact against retail at -O2 (tools/register_match.py). */

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


extern s16 D_8006A982;
extern u8  D_8006A96E;
extern u8  D_8006A980;
extern u8  D_8006A984;
extern s16 D_8006A990;
extern u8  D_8006A994[];
extern s16 D_800A4E86;
extern u16 D_800A4E8C;
extern u16 D_800A4E8E;
extern u16 D_800A4EE0;
extern u8  D_800A4EE6;
extern s16 D_800A4EF6;
extern s16 D_800A4EF8;
extern s16 D_800A4EFA;
extern s16 D_800A4EFC;
extern u8  D_800A4F16;
extern u8  D_800A4F19;
extern u8  D_800A4F1B;
extern u8  D_800A4F1C;
extern u8  D_800A4F1E;
extern u16 D_800A4F20;

extern void func_8002D904(s32);
extern void func_8002E5BC(void);
extern void func_8002E5F8(void);
extern void func_8002E638(s32 a0);
extern void func_8002E700(s32 a0);
extern void func_8002E79C(s32 a0);
extern void func_8002E818(s32 a0);
extern void func_8002E8DC(s32 a0);
extern void func_8002E94C(s32 a0);
extern void func_8002EB10(void);
extern void func_8002EBAC(void);
extern void func_8002EC10(void);
extern void func_8002EDE4(void);
extern void func_8002EE90(void);
extern void func_8002EEB8(void);
extern void func_8002EED8(s32 a0);
extern void func_8002EFD0(void);
extern void func_8002F0D0(void);
extern void func_80031CC8(void);
extern void func_80031DEC(void);
extern void func_80031E94(void);
extern void func_80031F14(void);
extern void func_80031FC8(void);
extern void func_8003491C(s32 arg0);
extern void func_80038668(s32 a0, s32 a1);

void func_8002E138(s32 a0, s32 a1, s32 a2) {
    if ((u16)a0 == 0x7F) {
        return;
    }

    switch ((u16)a0 - 1) {
    case 0:
        func_8002E638(a1 & 0xFFFF);
        break;
    case 7:
        func_8002E700(a1 & 0xFFFF);
        break;
    case 1:
        func_8002F0D0();
        func_8002EDE4();
        D_800A4F1B = 1;
        D_800A4EE0 = 0x4000;
        D_800A4F1C = 0;
        D_8006A96E = 0;
        D_8006A980 = 0;
        D_8006A982 = 0;
        D_8006A984 = 0;
        D_800A4EE6 = 0;
        D_800A4EFC = 0x1E;
        D_800A4F1E = 0;
        break;
    case 2:
        func_8002F0D0();
        func_80031CC8();
        D_800A4EFC = 0;
        break;
    case 3:
        func_8002EED8((a1 & 0xFFFF) | (a2 << 16));
        break;
    case 4:
        func_8002EE90();
        break;
    case 5:
    case 15:
    case 30:
        D_800A4EF6 = 2;
        break;
    case 6:
    case 16:
    case 31:
        D_800A4EF6 = 1;
        break;
    case 10:
        if (D_800A4F19 != 0) {
            func_8002E5BC();
        }
        break;
    case 11:
        if (D_800A4F19 == 0) {
            func_8002E5F8();
        }
        break;
    case 12:
        func_8003491C((a1 & 0xFFFF) | (a2 << 16));
        break;
    case 13:
        func_8002EB10();
        break;
    case 14:
        func_8002EBAC();
        break;
    case 17:
        func_8002E79C(a1 & 0xFFFF);
        break;
    case 18:
        func_8002E8DC(a1 & 0xFFFF);
        break;
    case 19:
        func_80031F14();
        func_8002E818(0);
        break;
    case 20:
        func_80031FC8();
        func_8002E94C(0);
        break;
    case 21:
        func_8002EEB8();
        break;
    case 22:
        func_8002EC10();
        break;
    case 23:
    case 25:
        func_80031DEC();
        break;
    case 24:
    case 26:
        func_80031E94();
        break;
    case 27:
        func_8002EFD0();
        break;
    case 28:
        D_800A4F1B = 0;
        break;
    case 29:
        D_800A4F1B = 1;
        break;
    case 32: {
        s16 t = D_8006A994[a1 & 7];
        D_800A4F16 = 1;
        D_800A4EF8 = t;
        break;
    }
    case 33:
        D_800A4EFA = D_8006A994[a1 & 7];
        break;
    case 34:
        {
            u8 *p = &D_800A4F1C;
            *p |= 1;
            if (D_800A4E8C + 0x100 == 0x134) {
                func_80038668(D_800A4E86, 3);
            }
        }
        break;
    case 35:
        {
            u8 *p = &D_800A4F1C;
            *p |= 2;
            if (D_800A4E8C + 0x100 == 0x134) {
                func_80038668(D_800A4E86, 4);
            }
        }
        break;
    case 36:
        {
            u8 *p = &D_800A4F1C;
            *p |= 4;
            if (D_800A4E8C + 0x100 == 0x134) {
                func_80038668(D_800A4E86, 5);
                func_80038668(D_800A4E86, 6);
                func_80038668(D_800A4E86, 7);
            }
        }
        break;
    case 37:
        {
            u8 *p = &D_800A4F1C;
            *p |= 8;
            if (D_800A4E8C + 0x100 == 0x134) {
                func_80038668(D_800A4E86, 8);
            }
        }
        break;
    case 38:
        if ((D_800A4E8E & 1) != 0) {
            D_8006A990 = 0;
            D_800A4F20 = a1;
        } else {
            func_8002D904(a1 & 0xFFFF);
        }
        break;
    case 41:
        D_800A4F1C = 0;
        break;
    case 39:
        D_800A4F1E = 1;
        break;
    case 40:
        D_800A4F1E = 0;
        func_80031CC8();
        break;
    }
}
