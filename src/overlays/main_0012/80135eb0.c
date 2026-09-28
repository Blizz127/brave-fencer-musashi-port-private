/* Overlay range [80135EB0,80136334) from MAIN.CD member 0012.
 * SHA256(span)=45181f81cacbf7519a72994d030f1e3192232f24dc7190aaa003ec475e79542b.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80135EB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define VectorNormalSS func_80047E98

/* File-scope declarations from the vendor translation unit. */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

// @class: struct
// @stuck: none — MATCH (289 ins). symcheck: only the cosmetic jtbl_801D81B8 floor (§8 carve).
//
// func_80135EB0 — h_seq family exemplar (x138 across the overlay fleet). Levers that made it:
//  1. m2 (the y-axis mask) MUST be the if/else form, NOT `m2=0x10; if (a8<=t3) m2=...`.
//     Both emit the same compact `bnez; li $s2,0x10` pair, but the pre-init form lets CSE carry
//     the D_8017E910 pointer load into the (m1|m2)==0 block; the if/else form ends the CSE
//     extended-BB so the block reloads `lui/lw D_8017E910` (target does). Worth 2 ins + the whole
//     big-block register assignment.
//  2. Zero-byte `__asm__ __volatile__("")` fences in case 1 and case 2 (DIFFERENT templates, "" vs " ")
//     block gcc-2.7.2 cross_jump from folding those two bodies into case 6's second-call tail
//     (they are byte-identical to it; the target keeps all three copies). Worth 10 ins.
//  3. Zero-byte fences between the three big-block coordinate groups stop sched2 hoisting the next
//     group's `lhu` into the previous group's load-delay nop (restores 2 nops).
//  4. `D_801152AA = 0;` AFTER the h0 statement: it shortens the [6]-field temp's local-alloc live
//     range so c0 wins $v1 and the field temps take $v0/$a0 (target), not $v1/$v0.
//  5. case 4 reaches case 8's tail through a shared `L288` label using `w = x << 16` / `w >> 16`
//     so the shared block is exactly `sra $a1,$a1,16` — that is target's .L80136288. `w` pinned to
//     $a1 ($5); it never spans a jal so §74 does not apply.
//  6. arg1 copied into a $s3-pinned local — without it global-alloc gives arg1 $s2 and m2 $s3
//     (arg1 has more refs; target's priority order is arg0, sext-temp, m2, arg1).
//  7. `ret0:` sits between case 8 and case 10 and `done:`/`case 0:` after case 10 — that is the
//     target's basic-block order; reorg then produces the inline `move $v0,$zero` delay slots.

extern u8 D_8017E910;
extern u8 D_8017E914;
extern s16 *D_8017E918;
extern u8 D_8017E91C;
extern s32 D_801150D8;
extern u8 D_80126720[];

extern s32 VectorNormalSS(void *a0, void *a1);
extern s32 func_801365B8(void *arg0, s32 arg1, s32 arg2);
extern s32 func_80136334(void *arg0, s32 arg1, s32 arg2);
extern s32 func_80136824(s32, s32, s32);

s32 func_80135EB0(void *arg0, s32 arg1_) {
    extern u8 D_801152A8[];
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    extern s16 D_80126722;
    extern s16 D_80126724;
    register s32 arg1 __asm__("$19") = arg1_;
    s32 t1;
    s32 t2;
    s32 t3;
    s32 m1;
    s32 m2;
    s32 t4;
    s32 t5;
    s32 t6;
    s32 n1;
    s32 n2;
    s32 r;
    s32 sv;
    register s32 w __asm__("$5");
    void *q;

    t1 = (*(s16 **)&D_8017E910)[0];
    if (t1 < M2C_FIELD(arg0, s16 *, 4)) {
        m1 = 1;
    } else {
        m1 = (M2C_FIELD(arg0, s16 *, 6) < t1) << 1;
    }
    t2 = (*(s16 **)&D_8017E910)[2];
    if (t2 < M2C_FIELD(arg0, s16 *, 0xC)) {
        m1 |= 4;
    } else if (M2C_FIELD(arg0, s16 *, 0xE) < t2) {
        m1 |= 8;
    }
    t3 = (*(s16 **)&D_8017E910)[1];
    if (t3 < M2C_FIELD(arg0, s16 *, 8)) {
        m2 = 0x10;
    } else {
        m2 = (M2C_FIELD(arg0, s16 *, 0xA) < t3) << 5;
    }
    if ((m1 | m2) == 0) {
        u16 *ac;
        s16 *b4;
        s32 c0;
        s32 c1;
        s32 h0;
        s32 h1;

        ac = *(u16 **)&D_8017E910;
        b4 = D_8017E918;
        c0 = ac[0];
        b4[0] = c0;
        h0 = (M2C_FIELD(arg0, s16 *, 4) + M2C_FIELD(arg0, s16 *, 6)) >> 1;
        D_801152AA = 0;
        (*(s16 *)D_80126720) = h0;
        (*(s16 *)D_801152A8) = c0 - h0;
        __asm__ __volatile__("");
        c1 = ac[2];
        b4[2] = c1;
        h1 = (M2C_FIELD(arg0, s16 *, 0xC) + M2C_FIELD(arg0, s16 *, 0xE)) >> 1;
        D_80126724 = h1;
        D_801152AC = c1 - h1;
        __asm__ __volatile__("");
        b4[1] = ac[1];
        D_80126722 = (M2C_FIELD(arg0, s16 *, 8) + M2C_FIELD(arg0, s16 *, 0xA)) >> 1;
        VectorNormalSS(D_801152A8, D_801152A8);
        D_801150D8 |= 1;
        return 1;
    }

    t4 = (*(s16 **)&D_8017E914)[0];
    if (t4 < M2C_FIELD(arg0, s16 *, 4)) {
        n1 = 1;
    } else {
        n1 = (M2C_FIELD(arg0, s16 *, 6) < t4) << 1;
    }
    t5 = (*(s16 **)&D_8017E914)[2];
    if (t5 < M2C_FIELD(arg0, s16 *, 0xC)) {
        n1 |= 4;
    } else if (M2C_FIELD(arg0, s16 *, 0xE) < t5) {
        n1 |= 8;
    }
    t6 = (*(s16 **)&D_8017E914)[1];
    if (t6 < M2C_FIELD(arg0, s16 *, 8)) {
        n2 = 0x10;
    } else {
        n2 = (M2C_FIELD(arg0, s16 *, 0xA) < t6) << 5;
    }
    if (((m1 | m2) & (n1 | n2)) != 0) {
        goto ret0;
    }
    {
        u16 *b0 = *(u16 **)&D_8017E914;
        u16 *ac = *(u16 **)&D_8017E910;
        s16 *b8 = *(s16 **)&D_8017E91C;

        b8[0] = b0[0] - ac[0];
        b8[1] = b0[1] - ac[1];
        b8[2] = b0[2] - ac[2];
    }

    switch (m1) {
    case 4:
        q = arg0;
        sv = M2C_FIELD(arg0, s16 *, 0xC);
        w = arg1 << 16;
        goto L288;
    case 1:
        r = func_801365B8(arg0, (s16) arg1, M2C_FIELD(arg0, s16 *, 4));
        __asm__ __volatile__("");
        goto done;
    case 2:
        r = func_801365B8(arg0, (s16) (arg1 | 1), M2C_FIELD(arg0, s16 *, 6));
        __asm__ __volatile__(" ");
        goto done;
    case 5:
        if (func_80136334(arg0, (s16) arg1, M2C_FIELD(arg0, s16 *, 0xC)) != 0) {
            return 1;
        }
        r = func_801365B8(arg0, (s16) arg1, M2C_FIELD(arg0, s16 *, 4));
        goto done;
    case 6:
        if (func_80136334(arg0, (s16) arg1, M2C_FIELD(arg0, s16 *, 0xC)) != 0) {
            return 1;
        }
        r = func_801365B8(arg0, (s16) (arg1 | 1), M2C_FIELD(arg0, s16 *, 6));
        goto done;
    case 9:
        if (func_801365B8(arg0, (s16) arg1, M2C_FIELD(arg0, s16 *, 4)) != 0) {
            return 1;
        }
        /* fallthrough */
    case 8:
        q = arg0;
        sv = M2C_FIELD(arg0, s16 *, 0xE);
        w = (arg1 | 1) << 16;
    L288:
        r = func_80136334(q, w >> 16, sv);
        goto done;
    ret0:
        return 0;
    case 10:
        if (func_801365B8(arg0, (s16) (arg1 | 1), M2C_FIELD(arg0, s16 *, 6)) != 0) {
            return 1;
        }
        r = func_80136334(arg0, (s16) (arg1 | 1), M2C_FIELD(arg0, s16 *, 0xE));
    done:
        if (r != 0) {
            return 1;
        }
    case 0:
        if (m2 == 0) {
            goto ret0;
        }
        if (m2 == 0x10) {
            if (((s32 (*)(void *, s32, s32))func_80136824)(arg0, (s16) arg1, M2C_FIELD(arg0, s16 *, 8)) == 0) {
                goto ret0;
            }
        } else {
            if (((s32 (*)(void *, s32, s32))func_80136824)(arg0, (s16) (arg1 | 1), M2C_FIELD(arg0, s16 *, 0xA)) == 0) {
                goto ret0;
            }
        }
    default:
        return 1;
    }
}
