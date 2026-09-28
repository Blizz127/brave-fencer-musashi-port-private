/* Exact retail word export for [800363CC,80036AF8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800363CC - byte-exact against retail at -O2 (tools/register_match.py). */
#define CdIntToPos func_80043A18
#define CdPosToInt func_80043B1C
#define CdReadyCallback func_800435B4
#define CdSearchFile func_80045374
#define streamLoad_cbActive D_80076110
#define streamLoad_savedReadyCB D_8006AEF0
#define streamLoad_state D_8006AF00
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



extern void func_80037334(void);
extern void func_800434BC(void);
extern void *CdReadyCallback(void *);                /* CdReadyCallback; §376: keep the TU's void spelling */
extern int  func_800435CC(s32, void *, void *);   /* CdControl  */
extern s32  func_8004355C(s32 mode, u8 *result);  /* CdSync     */

extern u8   D_8006AEF4;
extern u16  D_800A4E8E;
extern int  streamLoad_state;
extern void *streamLoad_savedReadyCB;
extern u8   streamLoad_cbActive;
extern int  D_800A6544;

extern int  func_80036260(void);   /* sub-handler passed to func_80037CD8; the definition returns int */

extern s32  func_80043420(void);   /* CdMode */
extern void func_8002EC10(void);
extern void func_80037358(int posInt);
extern void func_80037144(s32 idx);
extern int  func_80037CD8(void *arg);
extern s32  func_8003750C(void);
extern int  func_800374CC(int *out);
extern int  func_8003775C(void);
extern void func_80037D74(void);
extern void *func_80037368(int *out);
extern void func_800377D8(u8);     /* this loader's CdlReadN ready-callback (defined below) */

extern int  D_800A4F28;            /* tick / timeout counter                       */
extern int  D_800A4F2C;            /* CdMode-derived settle budget                 */
extern int  D_800A4F30;            /* remaining sub-stream repeat count (from n)   */
extern int  D_800A4F34;            /* last sector position (stall detection)       */
extern int  D_800A4F38;   /* §376: TU spelling (src/800_c.c:890); reached as a byte below */
extern u8   D_80068B60[];          /* per-resource descriptor table (0x10 stride)  */

/* Second CD loader, DISTINCT from CdReadStateMachine: an 18-state machine (streamLoad_state) with
 * its OWN ready-callback (func_800377D8). Runs SetMode(0xA0)/SeekL/ReadN with retry + CdMode
 * handling, looping n (D_800A4F30) times over sub-streams. Returns 0 = busy, 1 = done,
 * 2 = error/abort. Driven by ResourceLoadStateMachine.
 *
 * Matching notes (P31 S73):
 *  - `idx` MUST be its own local: written inline, `(arg0 - 0x100) * 0x10` folds at tree level into
 *    `arg0*0x10 - 0x1000` and the -4096 disappears into the `lh` displacement (2 insns, wrong).
 *  - `sVar1` is `int` (not `short`): a HImode local live across three calls loads with `lhu` and
 *    pays a `sll/sra` sign-extend at the use; the int-typed read sign-extends at the load (`lh`).
 *  - Every held global address is its own single-set pointer local (§429) — that is what turns
 *    `lui/%lo` pairs into the `lui + addiu` base the target uses for D_800A4F28/2C/30/34/38 and
 *    D_800A4E8E.
 *  - `break` vs `return 0` is load-bearing and NOT interchangeable here (both mean "return 0"):
 *    `break` funnels through the single trailing `return 0`, so cross_jump merges the arm's tail
 *    into .L80036AD4/.L80036ADC; `return 0` keeps the `$v0 = 0` hard-reg set inside the arm, which
 *    excludes $v0 from that block's allocation. Case 11 needs `return 0` (its state++ lands in $v1
 *    and stays inline); every other zero-return arm needs `break`. */
int func_800363CC(int arg0, void *loc, int n) {
    u8    cmd[8];
    u8    result[8];
    int   pos;
    int   sync;
    int   resKind;
    u8   *pb;
    int  *p28;
    int  *p2C;
    int  *p30;
    int  *p34;
    u16  *flags;
    int   t;
    int   idx;

    idx = arg0 - 0x100;
    resKind = *(short *)(D_80068B60 + idx * 0x10);
    p28 = &D_800A4F28;
    *p28 += 1;
    switch (streamLoad_state) {
    case 0:
        D_800A4F30 = n;
        *(u8 *)&D_800A4F38 = 0;
        D_800A6544 = 0;
        func_8002EC10();
        flags = &D_800A4E8E;
        *flags &= 0xFFDF;
        streamLoad_state++;
        break;
    case 1:
        func_80037334();
        func_80037358(CdPosToInt((CdlLOC *)loc));
        func_80037144(resKind);
        streamLoad_state++;
        /* fall through */
    case 2:
        sync = func_8004355C(1, result);
        if (sync != 5 && sync != 2) break;
        if ((func_80043420() & 0x80) != 0) {
            D_800A4F2C = 0;
        } else {
            D_800A4F2C = 3;
        }
        streamLoad_state++;
        /* fall through */
    case 3:
        cmd[0] = 0xA0;
        if (func_800435CC(0x0E, cmd, result) == 0) {   /* CdlSetmode */
            if ((result[0] & 0x10) == 0) break;
            func_80037334();
            streamLoad_state = 0;
            return 2;
        }
        D_800A4F28 = 0;
        streamLoad_state++;
        /* fall through */
    case 4:
        sync = func_8004355C(1, result);
        if (sync == 5) {
            streamLoad_state = 3;
            break;
        }
        if (sync != 2) {
            if (D_800A4F28 < 0x3D) break;
            streamLoad_state = 3;
            break;
        }
        streamLoad_state++;
        /* fall through */
    case 5:
        p2C = &D_800A4F2C;
        if (*p2C != 0) {
            *p2C -= 1;
            break;
        }
        streamLoad_state++;
        /* fall through */
    case 6:
        if (func_80037CD8((void *)func_80036260) == 0) break;
        streamLoad_state = 7;
        /* fall through */
    case 7:
        if (func_8003750C() == 0) break;
        streamLoad_state++;
        /* fall through */
    case 8:
        sync = func_8004355C(1, result);
        if (sync != 5 && sync != 2) break;
        streamLoad_state++;
        /* fall through */
    case 9:
        D_800A4F28 = 0;
        if (func_800435CC(0x15, loc, result) == 0) break;   /* CdlSeekL */
        streamLoad_state++;
        /* fall through */
    case 10:
        sync = func_8004355C(1, result);
        if (sync == 5) {
            if (func_800435CC(1, 0, result) == 0) {         /* CdlNop */
                streamLoad_state = 9;
                break;
            }
            if ((result[0] & 0x10) == 0) {
                streamLoad_state = 9;
                break;
            }
            func_80037334();
            D_8006AEF4 &= 0xFD;
            streamLoad_state = 0;
            return 2;
        }
        if (sync != 2) {
            if (D_800A4F28 < 0x12D) break;
            func_800434BC();
            streamLoad_state = 9;
            return 2;
        }
        streamLoad_state++;
        /* fall through */
    case 11:
        D_800A4F28 = 0;
        if (func_800435CC(6, loc, result) == 0) {           /* CdlReadN */
            if ((result[0] & 0x10) == 0) break;
            D_8006AEF4 &= 0xFD;
            func_80037334();
            streamLoad_state = 0;
            return 2;
        }
        if (streamLoad_cbActive == 0) {
            streamLoad_savedReadyCB = ((void *(*)(void *))CdReadyCallback)((void *)func_800377D8);
        } else {
            CdReadyCallback((void *)func_800377D8);
        }
        streamLoad_cbActive = 1;
        streamLoad_state++;
        return 0;   /* NOT `break` -- see the header note */
    case 12:
        if (func_800374CC(&pos) == 0) {
            p34 = &D_800A4F34;
            if (pos != *p34) {
                *p34 = pos;
                D_800A4F28 = 0;
            }
            if (D_800A4F28 < 0x12D) break;
            if (streamLoad_cbActive != 0) {
                CdReadyCallback(streamLoad_savedReadyCB);
                streamLoad_savedReadyCB = 0;
                streamLoad_cbActive = 0;
            }
            streamLoad_state++;
            break;
        }
        if (streamLoad_cbActive != 0) {
            CdReadyCallback(streamLoad_savedReadyCB);
            streamLoad_savedReadyCB = 0;
            streamLoad_cbActive = 0;
        }
        streamLoad_state++;
        /* fall through */
    case 13:
        if (func_8003775C() == 0) break;
        func_80037D74();
        streamLoad_state++;
        break;
    case 14:
        pb = (u8 *)func_80037368(&sync);
        if (sync != 1) {
            streamLoad_state = 0x11;
            break;
        }
        if (*pb == 1) {
            streamLoad_state++;
        } else if (*pb == 2) {
            *(u8 *)&D_800A4F38 = 1;
            streamLoad_state = 0x11;
            break;
        } else {
            p30 = &D_800A4F30;
            t = *p30;
            if (t == 0) {
                streamLoad_state = 1;
                break;
            }
            t -= 1;
            *p30 = t;
            if (t != 0) {
                streamLoad_state = 1;
                break;
            }
            streamLoad_state = 0x11;
            break;
        }
        /* fall through */
    case 15:
        if (func_800435CC(9, 0, result) == 0) {             /* CdlPause */
            if ((result[0] & 0x10) == 0) break;
            streamLoad_state = 0;
            return 1;
        }
        streamLoad_state++;
        break;
    case 16:
        sync = func_8004355C(1, result);
        if (sync != 5 && sync != 2) break;
        pb = (u8 *)&D_800A4F38;
        t = *pb;
        streamLoad_state = 0;
        if (t != 0) {
            *pb = 0;
            return 2;
        }
        return 1;
    case 17:
        if (func_800435CC(9, 0, result) != 0) streamLoad_state = 0x10;
        break;
    }
    return 0;
}
