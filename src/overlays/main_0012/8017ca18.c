/* Overlay range [8017CA18,8017CBC8) from MAIN.CD member 0012.
 * SHA256(span)=847e66ea1f2719cc922ddacf66cc8bbfacb5a4e5f3da7f27380d42b77ca79015.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017CA18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_8017CA18 (ov_MAIN_012 / jr_801789AC) — 108 ins, jump-table (jtbl_8018400C, 13 entries).
 *
 * STEP-0 SIBLING (cookbook §160g): the callee set + globals are fixed by TWO already-banked
 * functions:
 *   - func_8017DD28's own signature (src/ov_MAIN_012/ov_MAIN_012_jr_8017CF3C.c:4282):
 *     s32 *func_8017DD28(s32 *out);  and D_800AE7BC's element shape { u32 *ot; u32 pad[4]; }
 *     (0x14 stride) — from that function's own `Env_8017DD28` block-scope typedef.
 *   - func_8017CBC8's signature is fixed by its OWN definition later in this exact TU
 *     (src/ov_MAIN_012/ov_MAIN_012_jr_801789AC.c:5879): s32 func_8017CBC8(s32 ot, u8 *s, s16 c);
 *   - the TAIL's addPrim idiom (raw pointer-cast, no `volatile`/no PTag bitfield struct, each
 *     `D_800AE7BC[idx].ot[2]` full expression repeated inline) matches the ALREADY-MATCHED sibling
 *     src/ov_SC03_099/ov_SC03_099_jr_8013F350.c:1330 func_8013FAF8 (312/312) byte-for-byte in
 *     shape — NOT func_8017DD28's fancier `volatile u16*` + PTag-bitfield-cast + `register`-pinned
 *     idiom, which compiles to the SAME instructions here but in the WRONG order (see below).
 *
 * SWITCH RECONSTRUCTION (jtbl_8018400C, dispatch on D_8011512C, range [0,12] — neither edge is
 * the function's own epilogue, so no §161a/§162a1 empty-case padding is needed):
 *   entry 0,5,8,9   -> n=1;          break                (target 8017CA90 -> falls to CAC0)
 *   entry 1,2       -> n=5;          break                (target 8017CA98 -> falls to CAC0)
 *   entry 3,4,10,11 -> n=5; goto CALL                      (target 8017CAA0 -> jumps to CAAC)
 *   entry 6,7,12    -> n=1; CALL: ot=func_8017CBC8(...);   (target 8017CAA8 -> falls straight
 *                                                            into CAAC with NO jump instruction)
 * The fall-through (case 6/7/12, no jump) vs explicit-jump (case 3/4/10/11) distinction is what
 * fixes the case-group ORDER in source: gcc-2.7.2 emits switch arms in source order, so the
 * n=1-then-call group must be the textually LAST arm, immediately before the shared CALL: label.
 * `n` is never given a default value — the fall-off-the-end-of-switch path (D_8011512C outside
 * [0,12]) genuinely leaves it holding whatever was on the stack, matching the target's `s3` being
 * unset on that path.
 *
 * THE LAST-7-INSTRUCTION SCHED1 TRAP (new lever, feed to cookbook §30 family): the trailing
 * `D_801151D0 = ot;` (after `ot += 0x28;`) kept getting hoisted by sched1 to IMMEDIATELY after the
 * `addiu` that computes it, ahead of the SECOND addPrim RMW's `lw/and/or/sw` finish (which the
 * target keeps LAST) — same 7 instructions, wrong order, reproducible across EVERY C rephrasing
 * of the RMW side (bitfield-cast vs raw-pointer, block-scoped temp vs inline, `volatile`/register
 * pins, memory-clobber barriers — all no-ops). gdb-on-cc1 (`priority`/`rank_for_schedule`,
 * `tools/reference/gcc-2.7.2/sched.c`) showed the bare `D_801151D0 = ot;` a plain SET to a
 * fixed-symbol MEM — is what floats early; the fix is on the STORE side, not the load side:
 * `((struct { s32 f; } *)&D_801151D0)->f = ot;` (an anonymous-struct COMPONENT_REF store, the §30
 * `/s` grant, applied to a STORE for the first time — every prior citation was load-side).
 */

typedef struct { u32 *ot; u32 pad[4]; } Env_8017CA18;      /* 0x14 stride, per func_8017DD28 */

extern s32 D_801151D0;
extern s16 D_8011512C;
extern u8 *D_80115134;
extern s16 D_800B9A02;
extern Env_8017CA18 D_800AE7BC[];

extern s32 *func_8017DD28(s32 *out);
extern s32 func_8017CBC8(s32 ot, u8 *s, s16 c);
extern s32 func_8005A600(s32, s32, s32, s32, s32);

void func_8017CA18(void) {
    s32 ot;
    u8 *s2;
    s16 n;
    s16 i;

    ot = D_801151D0;
    s2 = D_80115134;

    if (D_8011512C == 1 || D_8011512C == 2) {
        ot = (s32)func_8017DD28((s32 *)ot);
    }

    switch (D_8011512C) {
    case 0:
    case 5:
    case 8:
    case 9:
        n = 1;
        break;
    case 1:
    case 2:
        n = 5;
        break;
    case 3:
    case 4:
    case 10:
    case 11:
        n = 5;
        goto CALL;
    case 6:
    case 7:
    case 12:
        n = 1;
    CALL:
        ot = func_8017CBC8(ot, s2 + 0xA0, 0);
        break;
    }

    for (i = 0; i < n; i++) {
        ot = func_8017CBC8(ot, s2, i);
        s2 += 0x20;
    }

    func_8005A600(ot, 0, 0, 0x15, 0);

    *(s32 *)ot = 0x02000000;
    *(s32 *)ot = (D_800AE7BC[*(u16 *)&D_800B9A02].ot[2] & 0xFFFFFF) | 0x02000000;
    D_800AE7BC[*(u16 *)&D_800B9A02].ot[2] =
        (D_800AE7BC[*(u16 *)&D_800B9A02].ot[2] & 0xFF000000) | ((u32)ot & 0xFFFFFF);

    ot += 0x28;
    ((struct { s32 f; } *)&D_801151D0)->f = ot;
}
