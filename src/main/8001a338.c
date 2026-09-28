/* Exact retail word export for [8001A338,8001A9D8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: CdPosToInt, CdReadSectorReadyCB, LzssDecodeSector, cdReq_drainPhase, cdReq_posInt, cdReq_sectorHdrBuf, cdReq_state, lzss_sectorStagingBuf. */
#include "psx_types.h"

/* func_8001A338 - byte-exact against retail at -O2 (tools/register_match.py). */

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


/* libcd types (vendor include/psyq/libcd.h) */
/* CD logical location — minute/second/sector are BCD. 4 bytes. (/LIBCD.H) */
typedef struct {
    u8 minute; /* +0x00 */
    u8 second; /* +0x01 */
    u8 sector; /* +0x02 */
    u8 track;  /* +0x03 */
} CdlLOC;

/* CD file descriptor (CdSearchFile result / directory entry). 24 bytes. (/LIBCD.H) */
typedef struct {
    CdlLOC pos;      /* +0x00  file start location */
    u32    size;     /* +0x04  file size in bytes   */
    char   name[16]; /* +0x08  file name            */
} CdlFILE;

typedef struct XRECT {
/* 0x00 */ u16 x;
/* 0x02 */ u16 y;
/* 0x04 */ u16 w;
/* 0x06 */ u16 h;
} XRECT;

typedef struct CdReq {
/* 0x00 */ s32   state;
/* 0x04 */ s32   unk04;
/* 0x08 */ s32   phase;
/* 0x0C */ s32   unk0C;
/* 0x10 */ s32   unk10;
/* 0x14 */ s32   texIdx;
/* 0x18 */ s32   unk18;
/* 0x1C */ s32   unk1C;
/* 0x20 */ XRECT rect;
/* 0x28 */ XRECT *rectp;
/* 0x2C */ s32   count;
/* 0x30 */ s32   busy;
/* 0x34 */ s32   list;
/* 0x38 */ s32   sink;
/* 0x3C */ s32   dest;
/* 0x40 */ s32   unk40[6];
/* 0x58 */ s32   words;
/* 0x5C */ s32   drain;
/* 0x60 */ s32   unk60[2];
/* 0x68 */ u8    mask[0x40];
/* 0xA8 */ u8    flags;
/* 0xA9 */ u8    unkA9;
/* 0xAA */ u8    bit;
/* 0xAB */ u8    byteIdx;
/* 0xAC */ s32   unkAC[3];
/* 0xB8 */ s32   size;
/* 0xBC */ s32   posInt;
} CdReq;

extern s32   D_800AE6F0;
extern s32   D_800AE7AC;
extern s32   D_800AE74C;
extern s32   D_800AE6F8;
extern u8    D_80078E40[];
extern u32   D_80079A70[];
extern u8    D_80079A74;
extern u8    D_80079A75;
extern s32   D_80079A78;
extern s32   D_80079A7C;
extern u32   D_8007A280[];
extern void *D_80072C80;

extern s32  func_80043994(void *buf, s32 n);
/* func_800599B8 is declared by the TU at src/800.c:5480 (SpadRect_800184F0 *), ABOVE this
 * insertion point, so the draft must not redeclare it with a void* first parameter. */
extern s32  func_8002FB08(s32 a0);
extern s32  func_8002FC64(s32 a0, u32 *a1);
extern void func_8002FDC8(void);
extern void func_80018714(void *);
extern s32  func_80018730(u8 *src);

void func_8001A338(u8 reason) {
    CdReq *p = (CdReq *)&D_800AE6F0;
    XRECT dead;
    u32 *q;
    XRECT *r;
    register s32 i __asm__("$18");
    s32 n, pos, res, b;
    s32 tmp;
    s32 k80;
    s32 one;
    s32 dst;
    s32 cnt;
    s32 dst4;

    if (reason != 1) goto endReason;

    func_80043994(D_80078E40, 3);
    pos = func_80043B1C((CdlLOC *)D_80078E40);
    if (pos != D_800AE7AC) {
        if (D_800AE6F8 == 4) func_8002FDC8();
        D_800AE74C = 2;
        return;
    }
    D_800AE7AC = pos + 1;
    switch (D_800AE6F8) {
    case 0:
        func_80043994(D_80079A70, 4);
        if (D_80079A70[0] != 0x434150) goto abortDrain;
        p->flags = D_80079A75;
        switch (D_80079A74) {
        case 6:
            func_80043994(D_8007A280, 0x1FC);
            q = &D_8007A280[0x24];
            n = D_80079A78;
            i = 0;
            p->rectp = (XRECT *)D_8007A280;
            if (n > 0) {
                do {
                    func_800599B8(p->rectp, q);
                    i++;
                    r = p->rectp;
                    q += (s16)r->w / 2;
                    p->rectp = r + 1;
                } while (i < n);
            }
            goto sectorDone;
        setTwo:
            p->phase = 2;
            goto tilePhase;
        case 0:
        case 5:
            p->texIdx = 0;
            func_80043994(p->mask, 0x10);
            p->rect.h = 0x20;
            p->rect.w = 0x20;
            p->rect.y = 0;
            p->rect.x = 0;
            p->bit = 1;
            p->byteIdx = 0;
            for (;;) {
                if (p->byteIdx >= 0x40) {
                    if (p->flags != 0) goto setTwo;
                    p->phase = 0;
                    goto tilePhase;
                }
                if ((p->mask[p->byteIdx] & p->bit) != 0) goto tilePhase;
                if (p->bit == 0x80) {
                    p->bit = 1;
                    p->byteIdx++;
                } else {
                    p->bit <<= 1;
                }
                p->rect.x += 0x20;
                if ((s16)p->rect.x > 0x3FF) {
                    p->rect.x = 0;
                    p->rect.y += 0x20;
                }
            }
        tilePhase:
            p->phase++;
            break;
        case 7:
            if (p->size < 0) goto phaseDone;
            p->phase = 3;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            p->sink = (s32)D_80072C80;
            break;
        case 1:
            p->phase = 3;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            p->sink = p->dest;
            break;
        case 8:
            p->phase = 6;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            break;
        case 2:
            if (p->busy != 0) goto phaseDone;
            p->phase = 3;
            dst = *(s32 *)(p->count * 8 + p->list + 4);
            tmp = D_80079A7C - 0x7FD;
            p->words = (u32)tmp >> 2;
            p->sink = dst;
            break;
        case 3:
            if (p->busy != 0) goto phaseDone;
            do {
                res = func_8002FB08(*(s32 *)(p->count * 8 + p->list));
            } while (res == 0);
            p->phase = 4;
            p->words = D_80079A7C - 0x800;
            break;
        case 4:
            p->phase = 5;
            p->words = (u32)(D_80079A7C - 0x7FD) >> 2;
            dst4 = p->dest;
            p->sink = dst4;
            func_80018714((void *)dst4);
            break;
        }
        break;
    case 1:
        q = &D_80079A70[p->texIdx * 0x200];
        func_80043994(q, 0x200);
        func_800599B8(&p->rect, q);
        p->texIdx = (p->texIdx + 1) & 3;
        k80 = 0x80;
        one = 1;
        do {
            b = p->bit;
            if (b == k80) {
                p->bit = one;
                p->byteIdx++;
            } else {
                p->bit = b << 1;
            }
            if (p->byteIdx < 0x40) goto cont1;
        sectorDone:
            if (p->flags != 0) goto phaseDone;
            p->phase = 0;
            goto post;
        cont1:
            p->rect.x += 0x20;
            if ((s16)p->rect.x > 0x3FF) {
                p->rect.x = 0;
                p->rect.y += 0x20;
            }
        } while ((p->mask[p->byteIdx] & p->bit) == 0);
        break;
    case 3:
        if (p->words < 0x201) {
            func_80043994((void *)p->sink, p->words);
            goto sectorDone;
        }
        func_80043994((void *)p->sink, 0x200);
        p->sink += 0x800;
        p->words -= 0x200;
        break;
    case 4:
        if (p->words < 0x801) {
            cnt = (p->words + 3) / 4;
            func_80043994(D_80079A70, cnt);
            if (func_8002FC64(p->words, D_80079A70) == 0) goto stageFail;
            p->count++;
            if (p->flags != 0) goto phaseDone;
            p->phase = 0;
            break;
        }
        func_80043994(D_80079A70, 0x200);
        res = func_8002FC64(0x800, D_80079A70);
        p->sink += 0x800;
        p->words -= 0x800;
        if (res != 0) break;
    stageFail:
        func_8002FDC8();
        p->phase = 7;
        break;
    case 5:
        func_80043994(D_80079A70, 0x200);
        if (func_80018730((u8 *)D_80079A70) == 0) goto sectorDone;
        break;
    case 6:
        p->words -= 0x200;
        if (p->words > 0) break;
        if (p->flags == 0) goto setZero;
    phaseDone:
        p->phase = 2;
        break;
    setZero:
        p->phase = 0;
        break;
    }
post:
    if (p->phase == 2) {
        p->drain = 1;
    } else if (p->phase == 7) {
        p->drain = 2;
    }
endReason:
    if (reason == 5) {
        if (p->phase == 4) func_8002FDC8();
    abortDrain:
        p->drain = 2;
    }
}
