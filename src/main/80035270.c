/* Main-exec range [80035270,800359B0) from the SLUS executable.
 * SHA256(span)=6cfb45d7f4fde0da4653497520c5e1b3ff7cffbfe7e24ba4a5ac937c7f609f1f.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80035270 - byte-exact against retail at -O2 (tools/register_match.py). */
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



/* P31 S72 — split out of src/800.c at the jtbl-span TU boundary (vram 0x80035270-0x8003A444).
 * This TU owns .rodata span C (0x800732A0-0x8007344C); see config/splat.us.exe.yaml and cookbook §426.
 * Declarations shared with the sibling TUs live in src/800_shared.h. */

/* func_80035270 — CD stream state machine (main, src/800_c.c, jtbl_800732A0 span C).
 *
 * Levers that made this byte-exact (all verified against asm/nonmatchings/800_c/func_80035270.s):
 *  - `+ zr` ($0 register variable, the src/800_c.c func_80036AF8 house idiom) forces the
 *    `addu $sN,$aN,$zero` copies that split `n`/`idx` and `drv`/`hi` into two pseudos.
 *  - HARD-REGISTER PINS, not declaration/statement order, fix gcc-2.7.2's global-alloc here:
 *    pinning ONLY `hi`->$s4 and `n`->$a0 rotates idx->$s2, h->$s3, drv->$a1 into place.
 *    (A full sweep of all 720 declaration orders and all 6 prologue statement orders moved
 *    nothing; the pins took the residual from 26 instructions to 6.)  `sync` reuses $a0 for
 *    its two disjoint live ranges in cases 2 and 9; case 5 keeps its own `sync5` ($v1).
 *  - The shared tails are written as explicit `goto Lret0/Lret1/Lflush/Lsetflag` with the
 *    labels placed where the .s puts the merged blocks.  gcc's cross_jump keeps the LAST
 *    duplicate; the target keeps the copy that sits with case 5's `f03 = 4; return 0`, so
 *    `default:` is co-located there (legal C89 — a case label may sit in a nested block).
 *  - `rec2 = ((s32)h << 6) + (s32)rec;` (fresh variable, h-first) puts the sum in the h64
 *    register -> `addu $v0,$v0,$v1`; the self-assignment `rec = rec + ...` used by cases 4
 *    and 6 reuses rec's register -> `addu $v1,$v1,$v0`.  Both forms are load-bearing.
 *  - `func_8003EDE8(0, vol + zr, vol + zr)` is what emits `addu $a1,$s0,$zero` /
 *    `addu $a2,$a1,$zero`; a plain `(0, vol, vol)` emits `move $a2,$s0` (cse canonicalises
 *    the second copy back to the pseudo's own hard reg).
 *  - `if (++D_800760F8 < 10)` gives lhu/addiu/sh/sll16/sra16/slti; a plain post-increment
 *    then a reload would emit `lh`.  `slti $v0,$v0,0x12D` is `<= 300`, not `< 300`.
 *  - Locals take sp offsets in DECLARATION order upward: result@0x10, param@0x18, loc@0x20.
 *
 * BANKING NOTE (§376): src/800_c.c:461 currently declares `extern void func_80035270(void);`
 * (address-taken at `req.f08 = (s32)func_80035270;`).  That conflicts with this definition;
 * the decl must become `extern s32 func_80035270(s32);` (or the use be cast) before the TU
 * will compile.
 */

extern s32 D_8006A69C;
extern u8  D_8006A6A0;
extern s32 D_8006AEE8;
extern u8  D_8006AEEC;
extern s32 D_80078F10;
extern s16 D_800760F8;
extern s32 D_80076100;
extern u8  D_800760FC;
extern u8  D_800760FD;
extern s16 D_80076208;
extern u8  D_8007620C;
extern u8  D_80076210;
extern u8  D_80076214;
extern s32 D_800A4638;
extern s16 D_800A4688;
extern u8  D_800A4698;
extern s16 D_800A4EF6;
extern s16 D_800A4EFA;

extern void func_800434BC(void);
extern s32  func_8004355C(s32 mode, u8 *result);
extern int  func_800435CC(s32, void *, void *);
extern int  func_80043830(int com, u8 *param, u8 *result);
extern int  func_80043410(void);
extern int  func_80043420(void);
extern s32  func_8003EDE8(s32, s32, s32);
extern void func_8003D650(int a0, int a1, int a2);

s32 func_80035270(s32 arg0) {
    register s32 zr __asm__("$0");
    u8 result[8];
    u8 param[8];
    CdlLOC loc;
    s32 flags;
    register s32 n __asm__("$4");
    s32 idx;
    s32 lo;
    s16 h;
    s32 drv;
    register s32 hi __asm__("$20");
    u8 *rec;
    u8 *rec2;
    u8 b;
    s32 i;
    s32 cnt;
    s32 count;
    s32 *p;
    s32 *src;
    s32 *dst;
    s32 target;
    s32 cmp;
    u8 *q;
    CdlLOC *lp;
    register s32 sync __asm__("$4");
    s32 sync5;
    s32 tmp;
    s32 inc;
    u8 ctr;
    s32 st;
    s32 t;
    s32 val;
    s32 vol;

    flags = *(s32 *)(arg0 + 0x10);
    lo = flags >> 4;
    h = lo & 0x1F;
    n = flags & 0xF;
    idx = n + zr;
    drv = (flags >> 9) & 0x1F;
    hi = drv + zr;
    if (lo & 1) {
        if (*(u8 *)((u8 *)&D_8006A6A0 + drv * 0x48) != 0) {
            idx = n + 4;
        } else {
            idx = n + 8;
        }
    }
    h = h >> 1;

    if (*(u8 *)(arg0 + 7) != 0) {
        *(u8 *)(arg0 + 7) = 0;
        *(u8 *)(arg0 + 3) = 0x11;
        if (*(s32 *)(arg0 + 0xC) == 0) {
            goto Lret1;
        }
        p = &D_80078F10;
        target = *(s32 *)(arg0 + 0x2C) + 1;
        if (target != p[0]) {
            i = 1;
            cmp = target + zr;
            for (; i < 5; i++) {
                if (p[i] == cmp) {
                    break;
                }
            }
            if (i == 5) {
                goto Lret1;
            }
            cnt = D_8006AEE8;
            if (i < cnt) {
                count = 0;
                dst = &D_80078F10;
                src = &D_80078F10 + i;
                do {
                    *dst = *src;
                    src++;
                    i++;
                    count++;
                    dst++;
                } while (i < cnt);
                D_8006AEE8 = count;
            }
        }
        *(s32 *)(arg0 + 0x14) = 0xF;
        D_800760F8 = 0;
        D_80076100 = func_80043420();
    }

    switch (*(u8 *)(arg0 + 3)) {
    case 0x11:
        q = &D_800760FC;
        *q = 1;
        D_800760FD = idx;
        if (func_80043830(0xD, q, result) == 0) {
            D_800760F8++;
            goto Lcheck;
        }
        *(u8 *)(arg0 + 3) = 0x12;
        func_8003EDE8(0, 0, 0);
        D_800760F8 = 0;
        /* fall through */
    case 0x12:
        param[0] = 200;
        if (func_80043830(0xE, param, result) == 0) {
            D_800760F8++;
            goto Lcheck;
        }
        if ((*(s32 *)(arg0 + 0x10) == 0x4486 || *(s32 *)(arg0 + 0x10) == 0x4364) &&
            D_800A4698 == 0 && D_800A4688 == 0x2B) {
            goto Lvol;
        }
        rec = (u8 *)*(s32 *)((u8 *)&D_8006A69C + hi * 0x48);
        rec2 = (u8 *)(((s32)h << 6) + (s32)rec);
        b = *(u8 *)(rec2 + (idx << 2) + 1);
        if ((b & 0x20) == 0) {
            goto Lzero;
        }
        if ((b & 0x40) == 0) {
            goto Lone;
        }
    Lvol:
        if (D_800A4EF6 >= 2) {
            func_8003D650(0, 1, 1);
        } else {
            func_8003D650(0, 1, 0);
        }
        goto Lcont;
    Lone:
        func_8003D650(0, 1, 1);
        goto Lcont;
    Lzero:
        func_8003D650(0, 1, 0);
    Lcont:
        D_800760F8 = 0;
        if (D_80076100 & 0x80) {
            *(u8 *)(arg0 + 3) = 1;
            goto Lcase1;
        }
        *(u8 *)(arg0 + 3) = 0;
        /* fall through */
    case 0:
        if (*(s32 *)(arg0 + 0x14) != 0) {
            *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) - 1;
        }
        if (++D_800760F8 < 10) {
            goto Lret0;
        }
        *(u8 *)(arg0 + 3) = 1;
        D_800760F8 = 0;
        /* fall through */
    case 1:
    Lcase1:
        if (*(s32 *)(arg0 + 0x14) != 0) {
            *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) - 1;
        }
        lp = &loc;
        CdIntToPos(*(s32 *)(arg0 + 0xC), lp);
        D_800760F8++;
        if (func_80043830(2, (u8 *)lp, 0) == 0) {
            goto Lcheck;
        }
        if (func_800435CC(0x15, lp, 0) == 0) {
            goto Lcheck;
        }
        D_800760F8 = 0;
        *(u8 *)(arg0 + 3) = 2;
        /* fall through */
    case 2:
        if (*(s32 *)(arg0 + 0x14) != 0) {
            *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) - 1;
        }
        sync = func_8004355C(1, result);
        if (sync == 0) {
            D_800760F8++;
            goto Lcheck;
        }
        if (sync == 5) {
            if (func_800435CC(1, param, result) != 0) {
                *(u8 *)(arg0 + 3) = 1;
                goto Lret0;
            }
            if (result[0] & 0x10) {
                goto Lsetflag;
            }
            *(u8 *)(arg0 + 3) = 1;
            goto Lret0;
        }
        D_80076208 = *(s32 *)(arg0 + 0x14);
        *(u8 *)(arg0 + 3) = 3;
        /* fall through */
    case 3:
        if (*(s32 *)(arg0 + 0x14) != 0) {
            *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x14) - 1;
            goto Lret0;
        }
        D_800760F8 = 0;
        *(u8 *)(arg0 + 3) = 4;
        /* fall through */
    case 4:
        CdIntToPos(*(s32 *)(arg0 + 0xC), &loc);
        if (func_800435CC(0x1B, &loc, 0) == 0) {
            D_800760F8++;
            goto Lcheck;
        }
        rec = (u8 *)*(s32 *)((u8 *)&D_8006A69C + hi * 0x48);
        rec = rec + ((s32)h << 6);
        D_80076210 = 0;
        D_800760F8 = 0;
        vol = (*(u8 *)(rec + (idx << 2)) * D_800A4EFA >> 7) & 0x7F;
        func_8003EDE8(0, vol + zr, vol + zr);
        D_8006AEEC = vol;
        *(u8 *)(arg0 + 3) = 5;
        /* fall through */
    case 5:
        sync5 = func_8004355C(1, result);
        if (sync5 == 2) {
            goto Lstate6;
        }
        if (sync5 == 5) {
            if (result[0] & 0x10) {
                goto Lflush;
            }
            func_800434BC();
            *(u8 *)(arg0 + 3) = 4;
    default:
    Lret0:
            return 0;
        }
        D_800760F8++;
        goto Lcheck;
    Lstate6:
        *(u8 *)(arg0 + 3) = 6;
        /* fall through */
    case 6:
        func_800435CC(1, 0, 0);
        st = func_80043410();
        D_8007620C = st;
        if ((st & 0x20) == 0) {
            goto Lret0;
        }
        rec = (u8 *)*(s32 *)((u8 *)&D_8006A69C + hi * 0x48);
        rec = rec + ((s32)h << 6);
        t = D_800A4638;
        *(s32 *)(arg0 + 0x18) = t;
        val = *(s16 *)(rec + (idx << 2) + 2) + t;
        *(s32 *)(arg0 + 0x14) = val;
        if ((u32)val < (u32)t) {
            *(u8 *)(arg0 + 6) = 1;
        } else {
            *(u8 *)(arg0 + 6) = 0;
        }
        *(u8 *)(arg0 + 3) = 7;
        /* fall through */
    case 7:
        ctr = D_80076210;
        inc = ctr + 1;
        tmp = ctr & 3;
        D_80076210 = inc;
        if (tmp == 0) {
            func_800435CC(1, 0, 0);
            st = func_80043410();
            D_8007620C = st;
            if (st & 0x10) {
                goto Lflush;
            }
        }
        t = D_800A4638;
        if ((u32)t < (u32)*(s32 *)(arg0 + 0x14)) {
            goto Lret0;
        }
        if (*(u8 *)(arg0 + 6) != 0) {
            if ((u32)t >= (u32)*(s32 *)(arg0 + 0x18)) {
                goto Lret0;
            }
        }
        *(u8 *)(arg0 + 3) = 8;
        /* fall through */
    case 8:
        func_8003EDE8(0, 0, 0);
        if (func_800435CC(9, 0, 0) == 0) {
            goto Lret0;
        }
        D_8007620C = 0;
        *(u8 *)(arg0 + 3) = 9;
        /* fall through */
    case 9:
        sync = func_8004355C(1, result);
        if (sync == 0) {
            goto Lret0;
        }
        if (sync != 5) {
            goto Lret1;
        }
        if ((result[0] & 0x10) == 0) {
            goto Lret1;
        }
        goto Lsetflag;
    }

Lcheck:
    if (D_800760F8 <= 300) {
        goto Lret0;
    }
Lflush:
    func_800434BC();
Lsetflag:
    D_80076214 = 1;
Lret1:
    return 1;
}
