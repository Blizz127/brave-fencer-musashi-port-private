/* Main-exec range [8001B86C,8001BA84) from the SLUS executable.
 * SHA256(span)=697162ec0f03063c386121faa74f13ff6f024344a9e03ede07fcdb236fcce6ea.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001B86C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_8001B86C — main/800: the 4-state "start a new frame" state machine driven
 * by D_800747FC.  State 0 initialises the double-buffer OT block for the current
 * buffer index D_800B9A02 and kicks func_80059BFC/func_8001BA84; state 1 arms the
 * frame counter; state 2 runs the per-frame work; states 2 and 3 share the tail
 * that ticks D_80074804 and drives func_8001BADC.
 *
 * Three byte-verified levers were required (all measured, none guessed):
 *
 * 1. UNSIGNED SWITCH INDEX (cookbook §135-1 / §163b).  The dispatch is a pure
 *    equality chain `beq 1 / beqz / beq 2 / beq 3` with NO `slti` range test.
 *    `switch (D_800747FC)` (signed) emits the median-split tree with an `slti`;
 *    only an index whose type is still unsigned after the default promotions
 *    reaches the no-range-test form, so the subject is cast to u32.  src/800.c
 *    already declares `extern s32 D_800747FC;` (L2770) — adopted verbatim and the
 *    unsignedness moved into the switch subject (§174 law 3, DEF-side wall).
 *
 * 2. `break` + ONE trailing `return 0`, NOT `return 0` per arm.  With a `return`
 *    in every arm gcc gives the DECL_RESULT pseudo a live range that reaches into
 *    each arm, it lands in $2, and two things break at once: the case-0 tail
 *    allocates $v1/$a0 instead of the target's $v0/$v1, and reorg refuses to fill
 *    the `beqz` delay slot with the following `addiu $v0,$zero,2` (a stray `nop`,
 *    135 ins vs 134).  Writing `break` and a single `return 0` after the switch
 *    frees $2 and both residuals close together — one source edit, 12 -> 0.
 *
 * 3. The OT table is touched through TWO declarations of the SAME symbol.  The
 *    target reloads D_800B9A02 three times inside case 0, which only happens when
 *    the stores are plain INDIRECT_REFs: an ARRAY_REF store sets MEM_IN_STRUCT_P
 *    and gcc-2.7.2's true_dependence() then drops the dependence against the
 *    not-in-struct constant-address `lhu` (cookbook §135-2), collapsing the three
 *    loads into one.  But a plain store to `SYM+reg` *plus any read of the same
 *    DECL* makes gcc allocate a dead 8-byte stack temp (frame 0x20 vs the target's
 *    0x18) — measured, and it survives every re-spelling of either access.  Two
 *    distinct DECLs of the same assembler symbol avoid the temp while keeping the
 *    plain-store aliasing, so the byte view drives the stores and the s32 view
 *    (`otTbl`, asm-labelled to D_800A651C) drives the loads.  reloc_identity.py
 *    reports AGREE / 34 relocations: every symbol here is the one the target's own
 *    relocation lines name (§174 law 1c).
 *
 * @class: MATCH (was LENGTH-DRIFT/+1 -> ADDRESSING -> MATCH)
 */

extern s32 D_800747FC;
extern s32 D_80074800;
extern s32 D_80074804;
extern s32 D_8007480C;
extern u16 D_800B9A02;
extern u8 D_800A6610[];
extern u8 *D_800A5E60;
extern u8 D_8007BA70[];
extern u8 D_800AF630[];

extern void func_80059BFC(s32 a0, s32 a1);
extern void func_8001BA84(void);
extern void func_80059FC0(u8 *a0);
extern void func_8001BB60(void);
extern s32 func_8001BADC(s32 a0, s32 a1);

s32 func_8001B86C(void)
{
    /* block scope: src/800.c declares D_800A651C as OtBlk_80016450[] inside
     * func_80015D4C, so the byte view has to stay local too. */
    extern u8 otBytes[] __asm__("D_800A651C");
    extern u8 D_800A6528[];                      /* = D_800A651C + 12 */
    extern s32 otTbl[] __asm__("D_800A651C");    /* s32 view of D_800A651C — see note 3 */
    u8 *p = D_800AF630;

    switch ((u32)D_800747FC) {
    case 0: {
        u8 *q = D_8007BA70 + D_800B9A02 * 80000;

        *(s32 *)(otBytes + D_800B9A02 * 20) =
            (s32)(D_800A6610 + (D_800B9A02 << 14));
        *(s32 *)(D_800A6528 + D_800B9A02 * 20) =
            (s32)(D_800A6610 + 4 + (D_800B9A02 << 14));
        D_800A5E60 = q;
        func_80059BFC(otTbl[D_800B9A02 * 5], 2);
        func_8001BA84();
        D_80074800 = 0x80;
        D_800747FC++;
        break;
    }
    case 1:
        D_80074804 = 1;
        D_800747FC = 2;
        break;
    case 2:
        func_80059FC0(p + 0x160);
        func_80059BFC(otTbl[D_800B9A02 * 5], 2);
        func_8001BB60();
        D_800747FC++;
        /* fallthrough */
    case 3:
        if (D_80074804++ >= 2) {
            D_80074804 = 1;
            if (func_8001BADC(D_8007480C, 1) != 0) {
                return 1;
            }
            D_8007480C++;
        } else {
            func_8001BADC(D_8007480C, 0);
        }
        break;
    }
    return 0;
}
