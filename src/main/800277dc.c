/* Main-exec range [800277DC,800279AC) from the SLUS executable.
 * SHA256(span)=c9862cc4cbbc849c9ee3d00a0f4141cf4fbdc6c6f7a6081d8fc15cf3750f7f45.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800277DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif
/* GTE instruction macros (vendor/bfm-decomp/include/gte_macros.inc) for GNU as. */
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro rtpt\n"
    "    cop2op 0x02, 0x30\n"
    ".endm\n"
    ".macro nclip\n"
    "    cop2op 0x14, 0x06, sf = 0\n"
    ".endm\n"
    ".macro avsz3\n"
    "    cop2op 0x15, 0x2D\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

#define gte_ldv3(r0, r1, r2) __asm__ volatile (  \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 );"                          \
    "lwc2 $2, 0( %1 );"                          \
    "lwc2 $3, 4( %1 );"                          \
    "lwc2 $4, 0( %2 );"                          \
    "lwc2 $5, 4( %2 )"                           \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_rtpt() __asm__ volatile ("nop;nop;rtpt")
#define gte_nclip() __asm__ volatile ("nop;nop;nclip")
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
#define gte_stopz(r0) __asm__ volatile (         \
    "swc2 $24, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsxy3_g3(r0) __asm__ volatile (    \
    "swc2 $12, 8( %0 );"                         \
    "swc2 $13, 16( %0 );"                        \
    "swc2 $14, 24( %0 )"                         \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsz3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $17, 0( %0 );"                         \
    "swc2 $18, 0( %1 );"                         \
    "swc2 $19, 0( %2 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )            \
    : "memory" )
#define gte_avsz3() __asm__ volatile ("nop;nop;avsz3")
#define gte_stotz(r0) __asm__ volatile (         \
    "swc2 $7, 0( %0 )"                           \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
extern s32 D_80078D88[];
typedef struct { s16 vx, vy, vz, pad; } SVECTOR800277DC;

void *func_800277DC(void *a0, SVECTOR800277DC *a1, void *a2, u8 *a3,
                     s32 count, s32 shift, s32 *ot)
{
    /* The five GTE scratch slots MUST be ONE array, not five scalars.  gcc-2.7.2 assigns a
     * stack slot at the point each addressable local's address is first taken, NOT in
     * declaration order; hoisting &otz/&sz0/&sz1 into pre-loop pointer temps (needed to put
     * their three `addiu $sp` ahead of the mask/t0/t1 setup, see below) therefore stole slot 0
     * from `flag` and shifted the whole frame.  One array pins the layout:
     *   st[0]=flag @sp+0   st[1]=otz @sp+4   st[2]=sz0 @sp+8   st[3]=sz1 @sp+0xC  st[4]=sz2 @sp+0x10
     * &st[0] folds to plain $sp, which is why `flag` is touched as 0($sp) with no address reg. */
    s32 st[5];
    /* t0/t1 pins ARE load-bearing (unpinning them re-drifts to 124 ins): they reproduce the
     * hand-budgeted src/dst induction-variable allocation so every field offset stays a direct
     * displacement off $t0 / $t1.  cnt/mask/shiftAmt/otp need no pin -- gcc lands them on
     * $t2/$t3/$t9/$t8 on its own, and pinning `otp` to $24 actively BREAKS the match (below). */
    register u8 *t0 __asm__("$8");
    register u8 *t1 __asm__("$9");
    s32 cnt;
    s32 mask;
    s32 shiftAmt;
    s32 *otp;
    s32 *potz, *psz0, *psz1;
    s32 idx0, idx1, idx2;
    s32 idx;
    s32 m;

    cnt = count;
    shiftAmt = shift;
    otp = ot;

    if (cnt == 0) {
        return a3;
    }

    /* Explicit pre-loop pointer temps, ordered ahead of mask/t0/t1: loop-invariant motion
     * APPENDS hoisted insns after the preheader's own statements, so leaving these implicit
     * emitted them last (`lui/ori, addiu t0, addiu t1, addiu sp+4/8/0xC`) -- the target is the
     * reverse order. */
    potz = &st[1];
    psz0 = &st[2];
    psz1 = &st[3];
    mask = 0xFFFFFF;
    t0 = (u8 *)a0 + 3;
    t1 = a3 + 4;

    do {
        idx0 = *(u16 *)(t0 + 0x11);
        idx1 = *(u16 *)(t0 + 0x13);
        idx2 = *(u16 *)(t0 + 0x15);

        gte_ldv3(&a1[idx0], &a1[idx1], &a1[idx2]);
        gte_rtpt();

        *(u32 *)(t1 + 8)    = *(u32 *)(t0 + 1);
        *(u32 *)(t1 + 0x10) = *(u32 *)(t0 + 5);
        *(u32 *)(t1 + 0x18) = *(u32 *)(t0 + 9);

        gte_stflg(&st[0]);
        if (!(st[0] & ~0x1000)) {
            gte_nclip();
            gte_stopz(potz);
            if (st[1] > 0) {
                gte_stsxy3_g3(a3);

                if (D_80078D88[0] & 0x8000) {
                    gte_stsz3(psz0, psz1, &st[4]);
                    /* `m` must NOT be the address-taken otz slot: assigning otz in each arm
                     * makes gcc spill to sp+4 three times.  The target keeps the running max
                     * in $v1 and stores ONCE, so the max needs a plain (non-addressable) temp.
                     * `st[2] > st[3]` (not `st[3] < st[2]`) is what loads sz0 first and emits
                     * `slt $v0, $v1, $a2`. */
                    if (st[2] > st[3]) {
                        m = st[2];
                        if (m < st[4]) m = st[4];
                    } else {
                        m = st[3];
                        if (m < st[4]) m = st[4];
                    }
                    st[1] = m >> 2;
                } else {
                    gte_avsz3();
                    gte_stotz(potz);
                }

                *(u32 *)t1 = (*(u32 *)(t0 + 0xD) & mask) | ((u32)t0[0] << 24);
                t1 += 0x20;

                idx = st[1] >> shiftAmt;
                {
                    u32 old = (u32)a3 & mask;
                    /* `s32 *p = otp + idx;` -- writing `otp[idx]` inline emits the address
                     * plus with the SCALED INDEX first (`addu $a0,$a0,$t8`); an explicit
                     * pointer temp emits it base-first (`addu $a0,$t8,$a0`) like the target.
                     * The second half of that fix is that `otp` must be an ordinary pseudo:
                     * with `register s32 *otp __asm__("$24")` local-alloc will not tie the
                     * dying index register to the address destination and the chain lands in
                     * $v0 instead of $a0.  Base-first + unpinned base = the last instruction. */
                    s32 *p = otp + idx;
                    *(u32 *)a3 = (*p & mask) | 0x7000000;
                    a3 += 0x20;
                    *p = old;
                }
            }
        }

        t0 += 0x1C;
    } while (--cnt);

    return a3;
}
