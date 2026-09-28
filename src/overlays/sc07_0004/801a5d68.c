/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5D68 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 v;                                  /* 0x0 */
    u16 pad;                                /* 0x2 */
} Pair4_801B02DC;
typedef struct {
    u16 f0;                                 /* 0x0 */
    u16 f2;                                 /* 0x2 */
    u16 f4;                                 /* 0x4 */
    u16 f6;                                 /* 0x6 */
} Entry8_801A5D68;
extern u8 D_801B0328[];
extern u8 D_801B0330[];
extern u8 D_801B030C[];
extern u16 D_801F885C;
extern Pair4_801B02DC D_801B02DC[];
extern Pair4_801B02DC D_801B02DE[];
extern void func_801A6184(u8 *, s32, s32);
extern void func_801A5E60();

void func_801A5D68(void *arg) {
    Entry8_801A5D68 buf[4];
    u8 *p;
    s32 i;
    u16 val;

    func_801A6184((u8 *)arg, (s32)D_801B0328, (s32)D_801B0330);
    p = D_801B030C;
    /* Plain `while` (NOT if + do-while): the front end emits LOOP_BEG followed
       by a simplejump to the bottom test, which is exactly the precondition for
       jump.c:2131 duplicate_loop_exit_test to COPY the 0xFF test to the top.
       That reproduces the target's two textually-identical guard/back-edge test
       blocks.  Writing `if (...) do { } while (...)` instead makes jump.c
       cross-jump the two inverse conditional blocks back together into the
       `j <bottom test>` shape (38-instruction residual, first-pass draft). */
    while (*p != 0xFF) {
        /* Indexing by `i` (not a walking `Entry8 *`) keeps ONE address giv:
           loop.c reduces &buf[i] to a single pointer stepped by 8 and reaches
           every field through 0x0/0x2/0x4 displacements.  A walking pointer
           splits into TWO givs (base+0 and base+4) and costs 2 extra insns.
           Preheader strata (cookbook 190-A) then fall out exactly: biv init
           `i = 0`, hoisted invariant `D_801F885C`, giv init `$a0 = $s2`. */
        for (i = 0; i < 4; i++) {
            buf[i].f0 = D_801B02DC[*p].v;
            /* f2 is cleared AFTER f0 in source order so sched1 sinks the
               `sh $zero, 0x2($a0)` into the `lhu`'s load-delay slot; written
               first it emits at the block top and leaves a `nop` behind
               (+1 instruction). */
            buf[i].f2 = 0;
            val = D_801B02DE[*p].v;
            buf[i].f4 = val;
            if (*p >= 6) {
                buf[i].f4 = val + D_801F885C;
            }
            p++;
        }
        func_801A5E60(arg, buf);
    }
}
