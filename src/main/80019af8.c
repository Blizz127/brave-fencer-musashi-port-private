/* Exact retail word export for [80019AF8,8001A0FC); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: CdPosToInt, CdReadSectorReadyCB, CdReadStateMachine, CdReadyCallback, cdReq_cdResult, cdReq_cdlFile, cdReq_curSector, cdReq_dest, cdReq_drainPhase, cdReq_posInt, cdReq_result, cdReq_retry, cdReq_savedReadyCB, cdReq_sink, cdReq_size, cdReq_state, cdReq_timeout, cdReq_wordsRemaining. */
#include "psx_types.h"

/* func_80019AF8 - byte-exact against retail at -O2 (tools/register_match.py). */

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

extern s32   func_800435CC(s32 mode, void *buf, void *param);  /* CdControl        */
extern s32   func_8004355C(s32 mode, u8 *result);             /* CdSync           */
extern void *func_800435B4(void *func);                       /* CdReadyCallback  */
extern void  func_800434BC(void);                             /* CdFlush          */
extern void func_8001A338(u8);   /* §376: def takes u8; only ever passed BY ADDRESS */
extern s32   func_8002FD14(s32, s32);
extern void  func_8001A0FC(void);
extern s32   func_8001A114(void);

extern s32   D_800AE6F0;
extern s32   D_800AE750;
extern s32   D_800AE7B0;
extern u8    D_800AE738;
extern void *D_800AE7A4;
extern s32   D_800AE7AC;
extern s32   D_800AE754;
extern s32   D_800AE7A8;
extern void *D_800AE72C;
extern s32   D_800AE728;
extern s32   D_800AE748;
extern s32   D_800AE74C;
extern void *D_800AE734;
extern s32   D_800AE708;
extern s32   D_800AE6E8;
extern s32   D_800AE6F8;
extern s32   D_800AE6FC;
extern s32   D_800AE700;
extern s32   D_800AE70C;
extern s32   D_800AE71C;
extern s32   D_800AE724;
extern u8    D_800AE798;
extern u8    D_800AE799;

/* Hand-rolled polled async CD reader: one state step per call, switch(cdReq_state) over 11 states.
 * Sequence: CdlSetmode(0xA0) -> CdlSeekL(+CdPosToInt) -> CdlReadN (+CdReadSectorReadyCB sector
 * drain) -> CdlPause/Flush, with a recovery arm (states 9/10) driving func_8001A0FC/func_8001A114.
 * Progress is returned via cdReq_result (0 busy / 1 done); pauseAfterSeek != 0 stops after the seek.
 *
 * MATCHING NOTES (byte-proven 385/385):
 *  - the cdReq_ block members reached at a NEGATIVE displacement from a held base
 *    (D_800AE740 = retry[-0x10], cdReq_cdResult = retry[-0x18] / cdlFile[-0x6C] /
 *    savedReadyCB[+4] / drainPhase[-0x14]) must be spelled through a pointer VARIABLE, and the
 *    byte store needs its OWN variable (`q`): `*(p - 0x10) = 0xA0` folds back to
 *    `lui $at,%hi(sym-0x10)` and costs +1 instruction, `q = p - 0x10; *q = 0xA0` does not.
 *  - EVERY held pointer gets a DISTINCT local. A local assigned in two arms stops being a
 *    single-set pseudo, so alias.c can no longer canonicalise `(mem (reg))` to its symbol and the
 *    scheduler refuses to hoist an unrelated global load past it (a stray load-delay `nop`, +1).
 *  - `s32 pad[2]` is the §333 frame dial: the target's 0x28 frame needs 8 bytes of declared-but-
 *    unused locals. Without it the frame is 0x20 and every $sp displacement shifts.
 *  - `setStateNine:` / `resetState:` are real labels, not cross-jump artefacts: they pin the
 *    merged tails to case 0 and case 10 respectively (gcc's own merge picks the other end).
 *  - case 10 assigns the callee's result straight to D_800AE6E8; a temp there buys a dead
 *    `addu $v1,$v0,$zero` (the other three CdSync arms DO need the temp, since $v0 is reused for
 *    the comparison constants).
 * Provenance: full byte-match against asm/nonmatchings/800/CdReadStateMachine.s (S72). */
void func_80019AF8(s32 pauseAfterSeek) {
    s32 *rp;
    s32 *dp;
    s32 *sp7;
    s32 *sp9;
    u8 *p;
    u8 *q;
    u8 *p2;
    u8 *p3;
    u8 *p8;
    void **fpp;
    s32 r;
    s32 st;
    s32 n;
    s32 i;
    s32 off;
    s32 pad[2];

    switch (D_800AE6F0) {
    case 0:
        p = (u8 *)&D_800AE750;
        *(s32 *)p = 0;
        D_800AE71C = 0;
        D_800AE70C = 0;
        q = p - 0x10;
        *q = 0xA0;
        func_800435CC(0xE, q, p - 0x18);
        if ((p[-0x18] & 0x10) != 0) {
        setStateNine:
            D_800AE6F0 = 9;
            break;
        }
        D_800AE6F0++;
        /* fallthrough */
    case 1:
        r = func_8004355C(1, &D_800AE738);
        D_800AE6E8 = r;
        if (r == 0) {
            break;
        }
        if (r == 5) {
            goto resetState;
        }
        if (r != 2) {
            break;
        }
        D_800AE750 = 0;
        D_800AE6F0++;
        /* fallthrough */
    case 2:
        rp = &D_800AE750;
        *rp = *rp + 1;
        if (*rp < 3) {
            break;
        }
        *rp = 0;
        D_800AE6F0++;
        break;
    case 3:
        fpp = &D_800AE7A4;
        func_800435CC(0x15, (u8 *)*fpp, (u8 *)fpp - 0x6C);
        if ((*((u8 *)fpp - 0x6C) & 0x10) != 0) {
            goto setStateNine;
        }
        D_800AE754 = 0;
        D_800AE7AC = func_80043B1C((CdlLOC *)*fpp);
        D_800AE6F0++;
        /* fallthrough */
    case 4:
        p2 = &D_800AE738;
        r = func_8004355C(1, p2);
        D_800AE6E8 = r;
        if (r == 5) {
            D_800AE750++;
        flushRetry:
            func_800434BC();
            D_800AE6F0 = 3;
            break;
        }
        if (r == 0) {
            break;
        }
        if (r != 2) {
            D_800AE7B0 = 0;
            D_800AE754++;
            if (D_800AE754 < 0xB5) {
                return;
            }
            goto flushRetry;
        }
        if (pauseAfterSeek != 0) {
            func_800435CC(9, 0, p2);
            if ((*p2 & 0x10) != 0) {
                goto setStateNine;
            }
            D_800AE6F0 = 8;
            D_800AE70C = *(s32 *)D_800AE7A4;
            break;
        }
        D_800AE6F0++;
        /* fallthrough */
    case 5:
        D_800AE74C = 0;
        if (D_800AE7A8 < 1) {
            D_800AE6F8 = 0;
        } else {
            D_800AE6F8 = 3;
            D_800AE748 = (D_800AE7A8 + 3) / 4;
            D_800AE798 = 1;
            D_800AE728 = (s32)D_800AE72C;
        }
        p3 = (u8 *)&D_800AE734;
        *(void **)p3 = func_800435B4(func_8001A338);
        func_800435CC(6, 0, p3 + 4);
        if ((p3[4] & 0x10) != 0) {
            goto setStateNine;
        }
        D_800AE750 = 0;
        D_800AE6F0++;
        /* fallthrough */
    case 6:
        dp = &D_800AE74C;
        if (*dp == 1) {
            func_800435B4(D_800AE734);
            func_800435CC(9, 0, (u8 *)dp - 0x14);
            if ((*((u8 *)dp - 0x14) & 0x10) != 0) {
                goto setStateNine;
            }
            st = D_800AE6F0;
            n = D_800AE71C;
            D_800AE6F0 = st + 1;
            if (n == 0) {
                D_800AE6F0 = st + 2;
            }
            break;
        }
        if (*dp == 2) {
            func_800435B4(D_800AE734);
            goto resetState;
        }
        D_800AE750++;
        if (D_800AE750 < 0x12C) {
            break;
        }
        func_800435B4(D_800AE734);
        D_800AE6F0 = 0;
        func_800434BC();
        break;
    case 7:
        i = 0;
        if (D_800AE71C > 0) {
            do {
                off = i * 8;
                do {
                    r = func_8002FD14(*(s32 *)(off + D_800AE724), *(s32 *)(off + D_800AE724 + 4));
                } while (r == 0);
                i++;
            } while (i < D_800AE71C);
        }
        sp7 = &D_800AE6F0;
        *sp7 = *sp7 + 1;
        break;
    case 8:
        p8 = &D_800AE738;
        r = func_8004355C(1, p8);
        D_800AE6E8 = r;
        if (r == 2) {
            D_800AE728 = 0x80010000;
            D_800AE6F0 = 0;
            D_800AE6F8 = 0;
            D_800AE6FC = 0;
            D_800AE700 = 0;
            D_800AE748 = 1;
            D_800AE74C = 0;
            D_800AE798 = 0;
            D_800AE799 = 0;
            D_800AE70C = 0;
            D_800AE7B0 = 1;
            D_800AE708 = 0;
            return;
        }
        if (r != 5) {
            break;
        }
        func_800434BC();
        func_800435CC(9, 0, p8);
        if ((*p8 & 0x10) == 0) {
            break;
        }
        goto setStateNine;
    case 9:
        func_8001A0FC();
        sp9 = &D_800AE6F0;
        *sp9 = *sp9 + 1;
        /* fallthrough */
    case 10:
        D_800AE6E8 = func_8001A114();
        if (D_800AE6E8 == 0) {
            break;
        }
    resetState:
        D_800AE6F0 = 0;
        break;
    }
    D_800AE7B0 = 0;
}
