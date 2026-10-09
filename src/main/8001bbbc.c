/* Main-exec range [8001BBBC,8001BC6C) from the SLUS executable.
 * SHA256(span)=3c72d6dc7239a27a2b5f81b0b3390f54bba424801d0e247e8de211b24ee6dd82.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001BBBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_8001BBBC — main/800: build the 0x14-byte "scanline band" primitive at the
 * head of the current prim buffer (D_800A5E60) — a GPU draw-mode word (0xE1000040)
 * followed by a TILE (code 0x62, 0x140x8 at (a0-160, a1-120), colour a2) — then
 * PSY-Q addPrim() it onto OT entry 1 of the current buffer's table
 * (D_800A6610 + (D_800B9A02 << 14)) and bump D_800A5E60 past it.
 *
 * @class: MATCH (was SCHEDULE-REORDER/2)
 *
 * THE RESIDUAL AND ITS MECHANISM (the only non-obvious thing here; cookbook
 * material — sched.md S1/S2 + §37's 2-instruction-constant note):
 *
 *   The target materialises the 24-bit mask as `lui $t1,0xff / addiu $v0,4 /
 *   ori $t1,$t1,0xffff` — the independent `li 4` sits BETWEEN the two halves of
 *   the mask.  Written as one constant (`mFF = 0xFFFFFF`) that is UNREACHABLE:
 *   mips.md:3208's `large_int` define_split fires inside sched1's try_split
 *   (sched.c:4830), so the lui/ori get CONSECUTIVE LUIDs, and rank_for_schedule's
 *   only tie-break among the priority-1 constants is exactly that LUID
 *   (sched.c:2428).  No statement order can put a third insn between two
 *   consecutive LUIDs — a 63-variant statement-order sweep confirmed it (every
 *   one scored the same 2).  So the target's two halves are NOT a split pair:
 *   they are two insns from expand.  Two edits reproduce that:
 *
 *   1. Build the mask in two steps with a zero-byte re-tie between them
 *      (`__asm__("" : "=r"(mFF) : "0"(mFF))`, the §30-#3 idiom already used by
 *      func_80016110/func_80016450 in this file) so cse cannot fold
 *      `0xFF0000 | 0xFFFF` back into one CONST_INT.  Now the `ori` carries its
 *      own LUID, taken at the point the `|=` is written.
 *   2. Route the len byte's 4 through the already-multi-set `tmp` ($2) instead of
 *      an anonymous temp.  An anonymous temp is single-set, so birthing_insn_p
 *      (sched.c:2469) boosts it to LAUNCH_PRIORITY and it sinks BELOW the mask's
 *      low half; a hard-reg pseudo with reg_n_sets>1 gets no boost and floats up
 *      with the other priority-1 constants in plain ascending-LUID order — which,
 *      with the `|=` written after the store, lands it exactly between the halves.
 *
 *   Both are required: the split alone still scores 2, the boost-kill alone
 *   moves the `li 4` one slot too far (ahead of the `lui`).
 *
 * Symbols hand-checked against asm/nonmatchings/800/func_8001BBBC.s (§174 law 1c):
 * D_800A5E60 (lw %lo + sw %lo), D_800B9A02 (lhu %lo), D_800A6610 (addiu %lo);
 * no calls.  All three externs are copied verbatim from src/800.c L4489-4491
 * (the same file-scope spellings func_8001B86C and func_8001D3FC already use).
 */

extern u16 D_800B9A02;
extern u8 D_800A6610[];
extern u8 *D_800A5E60;

void func_8001BBBC(s32 a0, s32 a1, u8 a2)
{
    register u8 *p __asm__("$7");
    register u32 tblAddr __asm__("$8");
    register u32 tmp __asm__("$2");
    register u32 val __asm__("$3");
    register u32 mFF __asm__("$9");
    register u32 m24 __asm__("$4");
    register u32 tag0 __asm__("$10");
    u32 *tbl;

    tag0 = 0xE1000040;
    mFF = 0xFF0000;
    __asm__("" : "=r"(mFF) : "0"(mFF));   /* zero-byte re-tie: keeps the mask's two
                                           * halves as two expand insns (see header) */
    a0 -= 0xA0;

    p = D_800A5E60;
    tblAddr = D_800B9A02;
    a1 -= 0x78;

    tmp = 4;
    *(u8 *)(p + 3) = tmp;
    mFF |= 0xFFFF;

    *(u8 *)(p + 11) = 0x62;
    *(u16 *)(p + 16) = 0x140;
    *(u16 *)(p + 18) = 8;

    val = *(u32 *)p;
    tbl = (u32 *)(D_800A6610 + (tblAddr << 14));

    *(u16 *)(p + 12) = (u16)a0;
    *(u32 *)(p + 4) = tag0;
    *(u8 *)(p + 10) = a2;
    *(u8 *)(p + 9) = a2;
    *(u8 *)(p + 8) = a2;
    *(u16 *)(p + 14) = (u16)a1;
    tmp = tbl[1];
    m24 = 0xFF000000;
    val = (val & m24) | (tmp & mFF);
    *(u32 *)p = val;

    val = (u32)(p + 0x14);
    D_800A5E60 = (u8 *)val;
    tmp = tbl[1];
    tmp = (tmp & m24) | ((u32)p & mFF);
    tbl[1] = tmp;
}
