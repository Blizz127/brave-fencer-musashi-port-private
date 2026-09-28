/* Main-exec range [800391D4,80039300) from the SLUS executable.
 * SHA256(span)=9e6eecc7e97ebe88b9f07da51a1dc2762c5c2496d31911efa7d4e4c105af2af9.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800391D4 - byte-exact against retail at -O2 (tools/register_match.py). */
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



/* func_800391D4 (main / src/800_c.c, 75 ins) -- MATCH in match_one AND rtu_match (real TU), Fable T5x 2026-09-05.
 * Levers, all measured (see .run/P32/t5x/reports/func_800391D4.md):
 *  - `register s32 i __asm__("$7")`: a hard reg is not a biv (loop.c:3572), so D_80073140[i] is never a giv ->
 *    the target's per-iteration sll/lui/addu/lw stays (S79).
 *  - `extern s32 D_80073140[][1]` + `[i][0]`: load-bearing spelling of the table access (S79; the TU now carries it).
 *  - `a1v = arg1;` BEFORE `off = 0;`: the s16 parameter's sign-extend becomes preheader SOURCE code emitted before
 *    off's init. Left implicit, the extend is an in-loop invariant that move_movables splices in front of
 *    NOTE_INSN_LOOP_BEG, i.e. AFTER `off = 0` (loop.c:1652/1708) -- the S79 closeness-3 residual.
 *  - NINE `__asm__("")` pads: insn_count knife-edge. move_movables hoists the D_800C6DD0 address iff
 *    threshold(58) * savings(1) * lifetime(1) >= insn_count (loop.c:1631). The target does NOT hoist it, so the
 *    loop must count >= 59 real insns; moving the extend out of the body cost 2, so 7 pads -> 9.
 */
void func_800391D4(s32 arg0, s16 arg1, s16 arg2) {
    extern u8 D_800C6DD0[];
    extern u8 D_800C6DD4[];
    extern s32 D_80073140[][1];
    extern s32 D_800C7D20;
    extern s32 D_800A2B98;
    extern u8 *D_800762B0;
    extern u8 D_800762B4[];

    u8 *base;
    u8 *entry;
    register s32 i __asm__("$7");
    s32 off;
    s32 mask;
    s32 a1v;

    i = 0;
    base = arg0 + arg2 * 0x1A;
    a1v = arg1;
    off = 0;
    do {
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        __asm__("");
        if (*(base + i + 0x23) != 0 && *(s16 *)&D_800C6DD4[off] == a1v) {
            entry = &D_800C6DD0[(s16)i * 0x60];
            if (entry[0x5A] != 0) {
                s32 off2;
                u8 *base2;
                off2 = *(s16 *)(entry + 6) * 0x1A;
                base2 = *(s32 *)(entry + 0x50);
                *(base2 + off2 + (s16)i + 0x23) = 0;
                entry[0x5A] = 0;
            }
            mask = D_80073140[i][0];
            D_800C7D20 &= ~mask;
            D_800A2B98 |= mask;
            D_800762B0[i] = 2;
            D_800762B4[i] = 0;
        }
        i++;
        off += 0x60;
    } while (i < 0x10);
}
