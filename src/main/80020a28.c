/* Main-exec range [80020A28,80020DA4) from the SLUS executable.
 * SHA256(span)=a3b7f4bf1a0c92de81cea08e1cb11b321360d518291906be1c759ce1b98e3cfa.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80020A28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* GTE command mnemonics (mvmva, rtpt, ...) come from include/gte_macros.inc. */
__asm__(".include \"gte_macros.inc\"\n");

/* func_80020A28 -- the 12-bit-packed-euler sibling of func_80020248 (same 5-arg shape).
 * Walks a NULL-terminated object list, builds each object's rotation matrix with
 * func_80020DA4 and multiplies it into two output matrix arrays (scratchpad when the
 * list is short, main RAM otherwise).  a4 != 0 skips the a2 (rm) array.
 *
 * LEVERS THAT MADE IT MATCH (cookbook):
 *  - the 5th parameter `a4` is never register-allocated, so every use reloads it from
 *    its incoming stack home -> the in-loop `lw $t0, 0x88($sp)`; do NOT hand-roll that
 *    load with inline asm (the warm start did, and it cost 8 bytes of frame).
 *  - `c` is written INSIDE the loop (`(u8 *)a1 + 3`) so loop.c strength-reduces it into
 *    a giv whose init `addiu $s3,$s4,3` is emitted AFTER move_movables' three hoisted
 *    `addiu $sN,$sp,0x1x` column pointers (loop.md L1 rule 6 / §358 family).  Declaring
 *    it before the loop makes it a BIV, whose init then lands BEFORE the hoists and in
 *    the `beq` delay slot.
 *  - byte 1 of the packed word is `(w >> 8) & 0xFF`, NOT `((u8 *)a1)[1]`.  gcc-2.7.2
 *    narrows the shift+mask back into `lbu $v1, 1($s4)` on its own, while the explicit
 *    byte deref creates a THIRD address giv that combine_givs folds into `c` as
 *    `lbu -2($s3)` -- which also re-ranks the allocnos ($s1/$s2/$s3 permute) and drops
 *    two reload slots (frame -0x70 instead of -0x78).  One spelling, three symptoms.
 */

/* §321 dial 2 -- src/800.c already carries this typedef and these three declarations at
 * FILE scope (lines 10200-10211), immediately above this function's slot.  They are
 * emitted only for the standalone `match_one` probe; SRM_80020248 is defined by the TU
 * just above us, so the real TU sees none of this and there is no `conflicting types`. */
#ifndef SRM_80020248
typedef struct {
    /* 0x00 */ s16 m[3][3];
    /* 0x14 */ s32 t[3];
} MTX_80020248; /* 0x20 */

extern MTX_80020248 D_80074818[];
extern MTX_80020248 D_80075018[];

extern void func_80020DA4(s32 a0, s32 a1);
#endif

typedef struct {
    /* 0x0 */ u32 xy;
    /* 0x4 */ u16 unk4;
    /* 0x6 */ u16 unk6;
} OBJ_80020A28; /* 0x8 */

#define gte_SetRotMatrix(r0) __asm__ volatile (              \
    "lw $12, 0( %0 );"                                   \
    "lw $13, 4( %0 );"                                   \
    "ctc2 $12, $0;"                                      \
    "ctc2 $13, $1;"                                      \
    "lw $12, 8( %0 );"                                   \
    "lw $13, 12( %0 );"                                  \
    "lw $14, 16( %0 );"                                  \
    "ctc2 $12, $2;"                                      \
    "ctc2 $13, $3;"                                      \
    "ctc2 $14, $4"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define gte_SetTransMatrix(r0) __asm__ volatile (              \
    "lw $12, 20( %0 );"                                  \
    "lw $13, 24( %0 );"                                  \
    "ctc2 $12, $5;"                                      \
    "lw $14, 28( %0 );"                                  \
    "ctc2 $13, $6;"                                      \
    "ctc2 $14, $7"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define gte_ldclmv(r0) __asm__ volatile (           \
    "lhu $12, 0( %0 );"                                  \
    "lhu $13, 6( %0 );"                                  \
    "lhu $14, 12( %0 );"                                 \
    "mtc2 $12, $9;"                                      \
    "mtc2 $13, $10;"                                     \
    "mtc2 $14, $11"                                      \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define gte_rtir() __asm__ volatile (               \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 3, 3, 0"                                \
    : : : "memory" )

#define gte_stclmv(r0) __asm__ volatile (           \
    "mfc2 $12, $9;"                                      \
    "mfc2 $13, $10;"                                     \
    "mfc2 $14, $11;"                                     \
    "sh $12, 0( %0 );"                                   \
    "sh $13, 6( %0 );"                                   \
    "sh $14, 12( %0 )"                                   \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14", "memory" )

#define gte_ldlv0b(r0) __asm__ volatile (            \
    "lb $13, 1( %0 );"                                   \
    "lb $12, 0( %0 );"                                   \
    "sll $13, $13, 16;"                                  \
    "sll $12, $12, 16;"                                  \
    "srl $12, $12, 16;"                                  \
    "or $12, $12, $13;"                                  \
    "lb $13, 2( %0 );"                                   \
    "mtc2 $12, $0;"                                      \
    "mtc2 $13, $1"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13" )

#define gte_rt() __asm__ volatile (                 \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 0, 0, 0"                                \
    : : : "memory" )

#define gte_stlvnl(r0) __asm__ volatile (           \
    "swc2 $25, 0( %0 );"                                 \
    "swc2 $26, 4( %0 );"                                 \
    "swc2 $27, 8( %0 )"                                  \
    :                                                    \
    : "r"( r0 )                                          \
    : "memory" )

s32 func_80020A28(s32 *a0, OBJ_80020A28 *a1, MTX_80020248 *a2, MTX_80020248 *a3, s32 a4)
{
    MTX_80020248 lm;            /* sp+0x10 */
    u16 src[3];                 /* sp+0x30 */
    MTX_80020248 *rm;
    MTX_80020248 *om;
    u8 *c;
    u32 w;
    s32 n;
    s32 ret;

    ret = 0;
    n = 0;
    while (*a0++ != 0) {
        n++;
    }

    if (n >= 8) {
        rm = D_80074818;
        om = D_80075018;
    } else {
        rm = (MTX_80020248 *)0x1F800000;
        om = (MTX_80020248 *)0x1F8000E0;
        ret = 1;
    }

    while (--n != -1) {
        src[0] = *(u16 *)((u8 *)a1 + 6);
        w = a1->xy;
        src[1] = ((w >> 8) & 0xFF) | ((w & 0xF) << 8);
        src[2] = ((w >> 16) & 0xFF) | ((w & 0xF0) << 4);
        func_80020DA4((s32)src, (s32)&lm);

        if (a4 == 0) {
            gte_SetRotMatrix(a2);
            gte_ldclmv(&lm.m[0][0]);
            gte_rtir();
            gte_stclmv(&rm->m[0][0]);
            gte_ldclmv(&lm.m[0][1]);
            gte_rtir();
            gte_stclmv(&rm->m[0][1]);
            gte_ldclmv(&lm.m[0][2]);
            gte_rtir();
            gte_stclmv(&rm->m[0][2]);
            rm++;
        }

        gte_SetRotMatrix(a3);
        gte_ldclmv(&lm.m[0][0]);
        gte_rtir();
        gte_stclmv(&om->m[0][0]);
        gte_ldclmv(&lm.m[0][1]);
        gte_rtir();
        gte_stclmv(&om->m[0][1]);
        gte_ldclmv(&lm.m[0][2]);
        gte_rtir();
        gte_stclmv(&om->m[0][2]);

        gte_SetTransMatrix(a3);
        c = (u8 *)a1 + 3;
        gte_ldlv0b(c);
        gte_rt();
        gte_stlvnl(&om->t[0]);

        om++;
        a1++;
    }

    return ret;
}
