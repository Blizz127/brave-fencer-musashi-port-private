/* Overlay range [8017D730,8017DC48) from MAIN.CD member 0012.
 * SHA256(span)=8a60c33857dcc99b19302090423afe3eafca0a9160c255919d81122979d6e009.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D730 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define strcpy func_8005C540

/* File-scope declarations from the vendor translation unit. */
#define NULL ((void *)0)
void func_8012A568(void (*a0)(void));
extern void func_8012A568(void (*a0)(void));

/* func_8017D730 @ 0x8017D730 -- ov_MAIN_012 (326 ins, mid-function jr / 7-entry jtbl_80184094).
 *
 * Per-player HUD refresh.  D_80185AF0[k] is the slot's player-status pointer (NULL == slot
 * unused); D_80182614[k] is that slot's array of 7 HUD primitive pointers.  For a live slot each
 * of the 7 fields is re-labelled (strcpy from D_8018251C[i]) and then re-filled by a switch on
 * the field index; for a dead slot the fields get the blank-out treatment instead -- an
 * if/else-if chain over i, NOT a switch (the compare order is a linear 0,1,4; gcc's balanced
 * case tree would have tested 1 first, and a jump-table form costs 8 instructions).
 *
 * ---- codegen notes (five separate idioms; each one alone reads as a wall) ----
 *
 * 1. `case 0` HAS A REAL BODY, so the jump table's minval is already 0 and gcc emits
 *    `sltiu $s0,$s0,7` with no `addiu -1` (cookbook 161a, same family of tell).
 *
 * 2. THE CLAMP TEMPORARIES `a`/`b`/`r` ARE ONE SET OF FUNCTION-SCOPE LOCALS shared by every case
 *    arm (C89 style), not per-case locals.  Two separate effects:
 *      - it pins b->$s1 and r->$s0.  Case 6 has no second call, yet the target still copies the
 *        return into $s0 -- only a shared pseudo whose live range spans cases 3/4 explains that.
 *      - it is why `andi $a0,$a0,0xFFFF` survives.  `a` is also assigned from the 32-bit `lw` in
 *        case 5, so combine's reg_nonzero_bits for that pseudo is unknown and it cannot fold the
 *        `(u16)` truncation away.  With per-case locals every set is provably <=16 bits, combine
 *        deletes the andi, and six instructions vanish.
 *
 * 3. gcc-2.7.2's fold SWAPS which operand of a chained `|` carries the constant, so each call
 *    pair is written as the MIRROR IMAGE of the target's tree:
 *      `(f(a) | 0xB00000) | f(b)`  ->  emits  f(a) | (f(b) | 0xB00000)
 *      `r | (f(b) | 0xC0000)`      ->  emits  (r | 0xC0000) | f(b)
 *    The call pairs are also single EXPRESSIONS, not statements: as statements the save of the
 *    first return value is emitted before the second call's argument setup, and reorg then fills
 *    the second jal's delay slot with `addiu $a1,$zero,0xC` instead of `addu $s0,$v0,$zero`.
 *
 * 4. THE ELSE BRANCH INDEXES UNIFORMLY WITH `i`, NOT WITH THE LITERAL 1 / 4.  cse's
 *    record_jump_equiv folds `i` to the branch constant, so the emitted offsets are still
 *    0x4/0x10 -- but before cse the address is `symbol + i*4`, and THAT is what makes loop.c
 *    hoist `&D_8018251C` into a callee-saved register at all.  Writing `D_8018251C[1]` gives a
 *    constant address, no hoist, the strcpy source falls back to the 3-instruction `lw sym(idx)`
 *    gas macro, and the loop-invariant constant 4 takes $s6 instead.  It also fixes the ORDER of
 *    the two hoists: this one originates in the ELSE loop, i.e. later in the k-loop body than the
 *    LICM'd `&D_801827A8` (which comes from the j-loop inside case 0), so the preheader gets
 *    $s7=D_801827A8 first and $s6=D_8018251C second, exactly as the target does.
 *
 * 5. D_80183F30 is a 3-byte align-1 blob copied by mips.c block_move_sequence
 *    (lb,lb,lb,sb,sb,sb) -- it must be a char[3] struct assignment, never three byte stores
 *    (cookbook 160a).
 */

typedef struct {
    char c[3];
} Blk3_8017D730;

extern char *strcpy(char *, const char *);
extern u32 func_8017DC48(s32 a0, s32 a1);
extern void func_8017DCB0(s32 a0, s32 a1, void *a2, s32 a3);

extern void *D_80185AF0[]; /* status ptr per slot */
extern void *D_80182614[]; /* HUD prim ptr array per slot */
extern char *D_8018251C[]; /* label strings */
extern s32 D_801827A8[];   /* level thresholds */
extern u16 *D_80182580[];  /* icon tables */
extern char *D_8018253C;
extern Blk3_8017D730 D_80183F30;

void func_8017D730(void) {
    s16 k;
    s16 i;
    s16 j;
    u8 *p;
    void **arr;
    u32 a;
    u32 b;
    s32 r;
    s32 n;
    u16 *ico;

    for (k = 0; k < 4; k++) {
        p = (u8 *)D_80185AF0[k];
        arr = (void **)D_80182614[k];
        if (p != NULL) {
            for (i = 0; i < 7; i++) {
                strcpy((char *)arr[i], D_8018251C[i]);
                switch (i) {
                case 0:
                    for (j = 0; j < 5; j++) {
                        if (*(s16 *)(p + 8) < D_801827A8[j]) {
                            break;
                        }
                    }
                    if (p[0x4E] != 0) {
                        j = (*(s32 *)p == 0) ? 0x1A : 0x1C;
                    }
                    *(s32 *)arr = j + 4;
                    break;
                case 1:
                    a = p[7];
                    if (a >= 100) {
                        a = 99;
                    }
                    b = p[6];
                    if (b >= 60) {
                        b = 59;
                    }
                    func_8017DCB0((func_8017DC48((u16)a, 0x18) | 0xB00000) |
                                      func_8017DC48(b, 0xC),
                                  5, (u8 *)arr[1] + 0x12, 0);
                    break;
                case 2:
                    a = *(u16 *)(p + 0x34);
                    if (a >= 1000) {
                        a = 999;
                    }
                    func_8017DCB0(func_8017DC48((u16)a, 0x14), 3, (u8 *)arr[2] + 8, 1);
                    n = p[0x42];
                    if (n >= 7) {
                        n = 6;
                    }
                    ico = D_80182580[n];
                    *(u16 *)((u8 *)arr[2] + 0x10) = *ico++;
                    *(u16 *)((u8 *)arr[2] + 0x12) = ico[0];
                    *(u16 *)((u8 *)arr[2] + 0x14) = ico[1];
                    a = p[0x39];
                    if (a >= 0x18) {
                        a = 0x17;
                    }
                    b = p[0x38];
                    if (b >= 0x3C) {
                        b = 0x3B;
                    }
                    func_8017DCB0((func_8017DC48((u16)a, 0x18) | 0xB00000) |
                                      func_8017DC48(b, 0xC),
                                  5, (u8 *)arr[2] + 0x18, 0);
                    break;
                case 3:
                    a = *(u16 *)(p + 0x3C);
                    if (a >= 1000) {
                        a = 999;
                    }
                    b = *(u16 *)(p + 0x3A);
                    if (b >= 1000) {
                        b = 999;
                    }
                    r = func_8017DC48((u16)a, 0x14);
                    if (r == 0) {
                        r = 0xD00000;
                    }
                    func_8017DCB0(r | (func_8017DC48(b, 4) | 0xC0000), 7, (u8 *)arr[3] + 6, 1);
                    break;
                case 4:
                    a = *(u16 *)(p + 0x40);
                    if (a >= 1000) {
                        a = 999;
                    }
                    b = *(u16 *)(p + 0x3E);
                    if (b >= 1000) {
                        b = 999;
                    }
                    r = func_8017DC48((u16)a, 0x14);
                    if (r == 0) {
                        r = 0xD00000;
                    }
                    func_8017DCB0(r | (func_8017DC48(b, 4) | 0xC0000), 7, (u8 *)arr[4] + 6, 1);
                    break;
                case 5:
                    a = *(u32 *)(p + 0x14);
                    if (a > 99999) {
                        a = 99999;
                    }
                    func_8017DCB0(func_8017DC48(a, 0xC), 5, (u8 *)arr[5] + 2, 1);
                    break;
                case 6:
                    a = *(u16 *)(p + 0xC);
                    if (a >= 0x24) {
                        a = 0x23;
                    }
                    r = func_8017DC48((u16)a, 0x18);
                    if (r == 0) {
                        r = 0xD000000;
                    }
                    func_8017DCB0(r, 2, (u8 *)arr[6] + 0x10, 1);
                    break;
                }
            }
        } else {
            for (i = 0; i < 7; i++) {
                if (i == 0) {
                    *(s32 *)arr = 4;
                } else if (i == 1) {
                    strcpy((char *)arr[i], D_8018251C[i]);
                } else if (i == 4) {
                    strcpy((char *)arr[i], D_8018253C);
                } else {
                    *(Blk3_8017D730 *)arr[i] = D_80183F30;
                }
            }
        }
    }
}
