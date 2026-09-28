/* Complete SC02 retail span [80183DC0,80183FEC).
 * Live STOP 83AC8 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183DC0 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro sqr sf\n"
    "    cop2op 0x0A, 0x28, sf = \\sf, lm = 1\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
extern void func_8012A568(void (*a0)(void));
extern void func_8012931C(struct vec *a0);
extern void func_801292C8(u8 *a0);
extern void func_8012EFB8(s32 a0);
extern s32  func_8005C49C(void);

void func_80183DC0(void *a0) {
    u16 in3[3];   /* 0x10 */
    s16 out2[2];  /* 0x18 */
    struct { s32 vx, vy, vz, pad; } d;   /* 0x20 — same body as the TU's LVec1CDC,
                                           * left ANONYMOUS so banking cannot collide
                                           * with engine_types.h's typedef (§183.1/law 8) */
    s32 v;
    void *tgt = *(void **)((s32)a0 + 0x2C);

    d.vx = *(s16 *)((s32)a0 + 0x6) - *(s16 *)((s32)tgt + 0x6);
    d.vy = 0;
    d.vz = *(s16 *)((s32)a0 + 0xE) - *(s16 *)((s32)tgt + 0xE);
    /* The target INLINES the GTE square (lwc2 IR1..IR3 / sqr 0 / swc2 MAC1..MAC3)
     * off ONE base register instead of calling func_80049324 — same idiom already used
     * in src/ov_SC03_099/ov_SC03_099_jr_8012ACE0.c:2737. */
    {
        s32 *p = &d.vx;
        __asm__ __volatile__(
            "lwc2 $9, 0(%0)\n"
            "lwc2 $10, 4(%0)\n"
            "lwc2 $11, 8(%0)\n"
            "nop\n"
            "nop\n"
            "sqr 0\n"
            : : "r"(p) : "$9", "$10", "$11", "memory");
        __asm__ __volatile__(
            "swc2 $25, 0(%0)\n"
            "swc2 $26, 4(%0)\n"
            "swc2 $27, 8(%0)\n"
            : : "r"(p) : "memory");
    }

    if (*(s16 *)((s32)a0 + 0x36) == 0) {
        /* the pointer is re-loaded per statement: each `sh` kills the CSE
         * of `*(s32 *)(a0+0x20)` (§193-E), which is why the target has three
         * `lw $a0,0x20($s0)`. */
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x10) += *(u16 *)((s32)a0 + 0x30);
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) += *(u16 *)((s32)a0 + 0x32);
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x14) += *(u16 *)((s32)a0 + 0x34);

        if (d.vx + d.vz > 0x9000) {
            *(s32 *)((s32)a0 + 0x14) = 0x18000;
            *(s32 *)((s32)a0 + 0x18) = 0;
            *(s32 *)((s32)a0 + 0x10) = 0;
            *(u16 *)((s32)a0 + 0x36) += 1;
        }
    } else {
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x10) += 0x80;
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x14) += 0x80;

        if (d.vx + d.vz < 0x4001) {
            /* its OWN pseudo: sharing `v` with the abs() block below gives the
             * merged pseudo a whole-function live range, and global_alloc then
             * seats it in $a0 instead of $v0 (§186c). */
            s32 t = func_8005C49C();
            *(s16 *)((s32)a0 + 0x36) = 0;
            *(s32 *)((s32)a0 + 0x14) = -0x100000 - ((t % 9) << 16);
        }
    }

    func_8012931C((struct vec *)a0);

    in3[0] = *(u16 *)((s32)a0 + 0x6);
    in3[1] = *(u16 *)((s32)a0 + 0xA);
    in3[2] = *(u16 *)((s32)a0 + 0xE);
    ((void (*)(u16 *, s16 *))func_8012EFB8)(in3, out2);

    /* CALL unless (|out2[0]| < 0xB5 && |out2[1]| < 0x8D && obj->y < 0x10).
     * Written as a nested if with an early `return` so the call is emitted
     * ONCE (a duplicated tail would need cross_jump to refund it, §193-C). */
    v = out2[0];
    if (v < 0) {
        v = -v;
    }
    if (v < 0xB5) {
        v = out2[1];
        if (v < 0) {
            v = -v;
        }
        if (v < 0x8D) {
            if (*(s16 *)((s32)a0 + 0xA) < 0x10) {
                return;
            }
        }
    }
    func_801292C8((u8 *)a0);
}
