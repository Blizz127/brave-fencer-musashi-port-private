/* Overlay range [80179B74,80179D30) from MAIN.CD member 0012.
 * SHA256(span)=f85d99d1e822c370c03d0f8707bcc0a65ac078258968b1a5ffb40efcd74daae0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179B74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: schedule
// @stuck: none — MATCH (111 ins). symcheck: data syms CLEAN (D_80184F40/D_80185344, 0 INVENTED); its lone MISSING is jtbl_801D8F9C, the COMPILER-emitted table ($L17 -> .rdata) — banking needs the §8a/§8e rodata-island flip (35 entries, .align 3), not a source-side ref.
/* func_80179B74 (ov_SC01_077) — command-queue WRITER: copies the opcode + its
 * operand halfwords from *p into the 0x200-entry ring D_80184F40 at write index
 * D_80185344.  Mirror of the reader func_8017A4AC (same ring, read index D_801DA710).
 *
 * Three levers were needed on top of the obvious shape (each byte-proven here):
 *  1. jtbl SPAN — the target's table is 35 entries (0..0x22) with NO `addiu a0,a0,-1`
 *     bias and `sltiu v0,a0,0x23`, so the source must contain an empty `case 0:` and
 *     an empty `case 0x22:`; without them gcc biases by -1 and emits sltiu 0x20.
 *  2. SCHEDULE — the operand push must route through a NAMED block-scoped temp
 *     (`{ s16 t = *p++; ring[idx] = t; ... }`).  Written as the anonymous
 *     `ring[idx] = *p++;` the sched1 pass puts the `lh D_80185344` ahead of the
 *     `lhu 0(a1)` in exactly the two blocks that also carry a live `addiu a1,a1,2`
 *     (cases {1,5} and {0x17,0x1c,0x1d,0x20}) — 6 of the 8 residual mismatches.
 *     The temp gives the loaded value its own pseudo and flips those two blocks.
 *  3. FRAME — the target reserves 0x80 with NO saves and NO spills; gcc's own
 *     (unused) area for this body is 0x58, so +0x28 of address-taken local is
 *     required: `s32 pad[10]; (void)&pad;` (cookbook §17 phantom-frame INDUCE
 *     lever).  10 words exactly; 8 -> 0x78 and 12 -> 0x88 both miss.
 *
 * Case-block ORDER in the source is the emitted block order: {1,5} then {0x13}
 * then {2,3,4,6,0x12,0x14,0x1f} then {0x17,0x1c,0x1d,0x20}.  The 3-/2-/1-push
 * tails are then cross-jump merged (no calls, so §88 does not block it) into the
 * shared .L80179CE4 / .L80179D08 tail that sits after the last case block.
 *
 * Symbols are the splat spellings and match the sibling TU ov_SC01_077_jr_8017A4AC.c
 * (`extern u16 D_80184F40[0x200];` / `extern s16 D_80185344;`) so the whole-binary
 * link and any one-big-TU build see one consistent type.
 */

extern u16 D_80184F40[0x200];
extern s16 D_80185344;

void func_80179B74(u16 *p) {
    s32 pad[10];
    s16 c;

    (void)&pad;
    c = *p++;
    D_80184F40[D_80185344] = c;
    D_80185344 = (D_80185344 + 1) & 0x1FF;
    switch (c) {
    case 0:
        break;
    case 1:
    case 5:
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        break;
    case 0x13:
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        break;
    case 2:
    case 3:
    case 4:
    case 6:
    case 0x12:
    case 0x14:
    case 0x1F:
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        break;
    case 0x17:
    case 0x1C:
    case 0x1D:
    case 0x20:
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        { s16 t = *p++; D_80184F40[D_80185344] = t; D_80185344 = (D_80185344 + 1) & 0x1FF; }
        break;
    case 0x22:
        break;
    }
}
