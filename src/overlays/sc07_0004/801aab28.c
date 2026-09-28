/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AAB28 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
    ".macro op0\n"
    "    op          0\n"
    ".endm\n"
);

typedef struct {
    u16 x;      /* +0x0 */
    u16 y;      /* +0x2 */
    u16 num;    /* +0x4 */
    u16 count;  /* +0x6 */
} SV4_801AAB28;
extern int func_8005C49C(void);
extern void func_801AACD4(void *a0, void *a1, u32 a2, s32 a3);

void func_801AAB28(SV4_801AAB28 *a0, SV4_801AAB28 *a1, s32 a2)
{
    SV4_801AAB28 local1;    /* sp+0x10 : block copy of *a0 (unaligned lwl/lwr) */
    SV4_801AAB28 local2;    /* sp+0x18 : block copy of *a1, x/y then randomised */
    SV4_801AAB28 prev;      /* sp+0x20 : previous emitted x/y (only .x/.y used) */
    SV4_801AAB28 spare;     /* sp+0x28 : never referenced, but the target frame
                               reserves it (var_size 0x20, not 0x18).  A declared
                               aggregate always gets its slot in gcc-2.7.2, so the
                               original had a fourth record here (cookbook 193-I). */
    u32 count;
    u16 num;
    u16 quotient;
    u16 accum;
    s32 n;
    s32 last;
    s32 i;
    s32 r;
    u16 offY;

    count = a1->count;
    num = a1->num;
    /* The `& 0xFFFF` is load-bearing, not cosmetic.  `count` is a u32 fed by an
       `lhu`, so combine folds the mask away for free -- but at cse time the
       compare operand is an AND rather than a bare REG, so record_jump_cond
       (cse.c:5839, "GET_CODE (op0) != REG => return") records NOTHING.  Written
       as a plain `count == 0` cse remembers count != 0 on the fall-through and
       then deletes the loop-entry guard below, costing an instruction and
       shifting the whole preheader. */
    if ((count & 0xFFFF) == 0) {
        return;
    }
    if (num < count) {
        return;
    }
    accum = 0;
    quotient = num / count;

    local1 = *a0;
    local2 = *a1;

    i = 0;
    /* Guard OUTSIDE the loop so `n`/`last` land in the preheader (after the
       branch), which is where the target computes them. */
    if (count != 0) {
        n = count;
        last = n - 1;
        do {
            if (i != 0) {
                r = func_8005C49C();
                local2.x = prev.x + (r & 0x7FF) - 0x400;
                r = func_8005C49C();
                offY = prev.y + (r & 0x7FF) - 0x400;
            } else {
                r = func_8005C49C();
                local2.x = a1->x + (r & 0x1FF) - 0x100;
                r = func_8005C49C();
                offY = a1->y + (r & 0x1FF) - 0x100;
            }
            local2.y = offY;
            if (i != last) {
                func_801AACD4(&local1, &local2, quotient, a2);
                prev.x = local2.x;
                prev.y = local2.y;
            } else {
                /* narrowed in u16 first: convert_to_integer distributes the
                   truncation into the MINUS, giving `subu` then `andi` (the
                   target shape) instead of widening both operands. */
                func_801AACD4(&local1, &local2, (u16)(num - accum), a2);
            }
            i++;
            accum += quotient;
        } while (i < n);
    }
}
