/* Exact retail word export for [8002F248,8002F4E4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_8002F248 - byte-exact against retail at -O2 (tools/register_match.py). */

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


typedef struct F1ccRec {
    u8 pad[0x0E];
    u8 flg[8];
    u8 tail[0x3E];
} F1ccRec;

typedef struct F1ccSlot {
    u8 pad[0x20];
    u32 u20;
    u32 u24;
    u32 u28;
    u32 u2C;
    u16 u30;
    u8 mid[5];
    u8 u37;
    u8 u38;
    u8 tail[0x1B];
} F1ccSlot;

void func_8002F248(s32 arg0, s32 arg1) {
    extern s32 D_800A4EEC;
    extern u8 D_8006A9F8[];
    extern u8 D_800A4694[];
    extern s32 func_8002DC68();    /* §376: def returns s32 and takes (u32, u32) */
    extern s32 func_800331D4(s32);
    s32 i;
    s32 idx;
    F1ccRec *rec;
    F1ccSlot *slots;

    switch (*(u8 *)(arg0 + 3)) {
    case 0:
        D_800A4EEC = D_800A4EEC * 0x41C64E6D + 0x3039;
        switch (((u32)D_800A4EEC >> 16) & 0x7) {
        case 0:
        case 3:
            func_8002DC68(0x67C, 0);
            break;
        case 1:
        case 2:
            func_8002DC68(0x689, 0);
            break;
        case 4:
        case 5:
            func_8002DC68(0x67B, 0);
            break;
        }
        break;
    case 1:
        func_8002DC68((u16)arg1, 0);
        break;
    case 2:
        idx = func_800331D4(0x95C);
        if (idx) {
            rec = (F1ccRec *)D_800A4694 + idx;
            slots = (F1ccSlot *)(D_800A4694 + 0x2F4);
            for (i = 0; i < 8; i++) {
                if (rec->flg[i]) {
                    slots[i].u30 = 0;
                    slots[i].u38 = 0;
                    slots[i].u2C = -0x18;
                    slots[i].u28 = slots[i].u20 - 0x100;
                    slots[i].u37 |= 1;
                }
            }
        }
        break;
    case 3:
        idx = func_800331D4(0x95C);
        if (idx) {
            rec = (F1ccRec *)D_800A4694 + idx;
            slots = (F1ccSlot *)(D_800A4694 + 0x2F4);
            for (i = 0; i < 8; i++) {
                if (rec->flg[i]) {
                    slots[i].u30 = 0;
                    slots[i].u38 = 0;
                    slots[i].u2C = 0x18;
                    slots[i].u28 = slots[i].u20 + 0x100;
                    slots[i].u37 |= 1;
                }
            }
        }
        break;
    case 4:
        D_800A4EEC = D_800A4EEC * 0x41C64E6D + 0x3039;
        switch (((u32)D_800A4EEC >> 16) & 0x7) {
        case 0:
        case 3:
            func_8002DC68(0xAFD, 0);
            break;
        case 1:
        case 2:
        case 5:
            func_8002DC68(0xAFF, 0);
            break;
        case 4:
            func_8002DC68(0xAFE, 0);
            break;
        }
        break;
    case 5:
        func_8002DC68(0xB06, 0);
        func_8002DC68(0xB07, 0);
        break;
    case 6:
        func_8002DC68(0xB06, 0);
        func_8002DC68(0xC60, 0);
        break;
    case 7:
        D_800A4EEC = D_800A4EEC * 0x41C64E6D + 0x3039;
        func_8002DC68(*(u16 *)(D_8006A9F8 + (((u32)D_800A4EEC >> 15) & 0x1E)), 0);
        break;
    }
}
