/* Exact retail word export for [80030F80,800314DC); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80030F80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

/* func_80030F80 -- MATCH, 343/343 (Fable escalation S69e1; was NEAR closeness 3).
 * All j destinations, jal order, and HI16/LO16 symbol order verified with
 * objdump -r against the .s (law 1c: match_one masks relocs).
 *
 * TU decls already in src/800.c (do NOT duplicate at bank time):
 *   extern u8 D_800A4988[]; extern u8 D_800A4F19; extern s32 D_80073140[];
 *   extern u16 D_8006AA30[]; extern const u16 D_8007319E[]; extern u16 D_8007321E;
 *   extern u8 D_800A4C6D[]; extern s32 D_800C7D2C;
 *   extern void func_8002EFF8(s32 a0, s32 a1);  (file scope, src/800.c:18923)
 *   extern void func_80031988(Ent30D80 *arg0);  (file scope, src/800.c:18924)
 *   `typedef struct Obj {...} Obj;` is defined AFTER this function (src/800.c:18968)
 *   and func_800314DC is defined at :19003 as `void func_800314DC(Obj *p)`, so this
 *   draft forward-declares the TAG at file scope (`struct Obj;`) and prototypes
 *   `func_800314DC(struct Obj *)` -- compatible with the later definition (Sec 376/378).
 *   Same trick for `struct Ent30D80` (complete at src/800.c:11).
 *   NEW to the TU: `extern const u16 D_800731A0[];` (real dlabel, asm/data/6324C.data.s:699).
 *
 * THE LEVERS (each byte-load-bearing; measured 316 -> 3):
 *  1. ONE ANCHOR SYMBOL. Every address in this function is spelled as an offset from
 *     D_800A4988, so cse.c's use_related_value/get_related_value can express each one
 *     as `addiu $reg,$s6,K` off the FIRST materialised address. That is why the target
 *     shows `lui $s6,%hi(D_800A4EFE)` (= D_800A4988+0x576) with $s2/$s7/$s0 derived from
 *     it, but keeps D_80073140 / D_800731A0 / D_8007319E as full lui/addiu pairs:
 *     get_related_value only relates `(const (plus SYMBOL int))` to the SAME symbol, never
 *     two different symbols. Spelling D_800A4EFE / D_800A4EFA / D_800A4C28 / D_800A4F19 as
 *     their own externs costs +1 insn each and loses the whole derived chain.
 *  2. POINTER LOCALS, NOT ARRAY SUBSCRIPTS, for the loop-invariant bases (sv/w/q/r/tbl).
 *     `D_800A4EFE[u]` compiles to the 3-insn split address (lui $at; addu $at,$at,$u;
 *     lbu %lo(sym)($at)); a pointer local puts the base in a pseudo and gives the target's
 *     2-insn `addu $v0,$s6,$a0; lbu $v1,0($v0)`.
 *  3. THE PRE-LOOP STATEMENT ORDER *IS* THE PREHEADER ORDER (sv, p, i=0, tbl, w, q, r):
 *     sched1 keeps ties in LUID order, so this reproduces $s6,$s2,$s5,$s4,$s7,$fp exactly.
 *     `r = D_8007319E` is the 7th and last invariant: global.c runs out of callee-saved
 *     registers, local-alloc's REG_EQUIV note survives, and reload REMATERIALISES it inline
 *     as `lui $t0/addiu $t0` -- exactly the target's un-hoisted pair at 0x80031344.
 *  4. ONE `w` POINTER SERVES THREE THINGS (master volume `*(s16*)w`, the stereo flag
 *     `w[0x1F]`, and the voice-slot base `(s32)w - 0x2D2`), which is what makes it worth a
 *     callee-saved register ($s7) and what produces `addiu $v1,$s7,-0x2D2` in-loop.
 *     `vb` must be s32 (not u8*) so `k + vb` keeps the target's `addu $a0,$s3,$v1`
 *     operand order -- pointer arithmetic gets canonicalised to pointer-first.
 *  5. `i * 0x48` (a GIV), not a `k` biv: a biv's `k = 0` is pre-loop code and lands BEFORE
 *     the address-giv init; as a giv both inits are emitted by strength_reduce and come out
 *     in the target's `addiu $s0,$s6,-0x56C` / `addu $s3,$zero,$zero` order.
 *  6. ONE `p` BIV WITH BYTE OFFSETS. Two source pointers (base and base+0xA) make loop.c
 *     invent a third giv at +0x40; one biv + `p[K]` lets combine_givs settle on the +0xA
 *     group ($s0) while the biv itself ($s2) keeps the offset-0 loads and the call args.
 *  7. `m = (m * X) >> 7;` as ONE expression (not `m = m * X; m = m >> 7;`): the product
 *     needs its own pseudo to get the target's `mflo $t0` / `srl $a1,$t0,7` pair.
 *  8. `mask = tbl[...]; p[0x50] = 0; func_8002EFF8(0, mask);` at 0x80031400 -- with the
 *     store AFTER the loads it can no longer fill the lhu's load-delay slot and dbr takes it
 *     for the jal's. At `case 3` the same rewrite instead lets cse reuse the switch's own
 *     `lhu $a0` (-2 insns), so that site keeps `p[0x50] = 0;` FIRST: the store's varying
 *     address makes cse invalidate_memory and forces the target's reload.
 *  9. The switch is a real `switch` on cases 3 / 0 / 2 IN THAT SOURCE ORDER with 3 falling
 *     through into 0 -- expand_end_case reorder_insns puts the balanced compare tree
 *     (beq 2 / slti 3 / beqz 0 / bne 3) ahead of the bodies, which is the target's layout.
 * 10. `flag = 1;` sits OUTSIDE the inner `if` in the 0x4C and 0x37&2 blocks (its constant
 *     is what `sb $s1,0x46($s0)` and `D_800A4C6D[k] = 1` reuse) but INSIDE the 0x4F one --
 *     that is exactly which branches get the `addiu $s1,$zero,1` delay slot and which a nop.
 * 11. `if ((s16)h <= 0)` on the u16 0x4A field (sll 16 + bgtz), and the 0x1C sign test
 *     written `>= 0` with the ADD arm first, so the target's `bltz` picks the sub arm.
 *
 * 12. THE DISPATCH-BLOCK MEMORY CLOBBER (closed the old case-3 residual, 3 -> 0).
 *     The target needs case 3's u16 index RELOADED (cse invalidation) while the sb
 *     stays AFTER the lw (mask idiom order), and needs case 2 to keep FOLDING the
 *     dispatch-loaded index into its call arg. Ruled out by reading the pinned gcc:
 *      - volatile-cast index load: forces the reload but loop.c:339
 *        init_recog_no_volatile makes every DEST_ADDR giv rewrite of a volatile mem
 *        fail recog -- the address stays biv-based (`lhu 10($s2)`, not `0($s0)`).
 *        A volatile mem can NEVER join a giv group. (find_mem_givs does record it.)
 *      - asm clobber at the case-3 head: reload+giv fine, but reorg.c stop_search_p
 *        halts fill_slots_from_thread at ANY asm insn (asm_noperands>=0), so the
 *        `addu $a0,$zero,$zero` never hoists into the bne's delay slot (+1 len).
 *     THE FIX (all three pieces load-bearing):
 *        idx = *(u16 *)(p + 0xA);          <- named local; case 2 passes idx (the
 *        dsp = sv[idx];                       fold, done by hand; matches the target's
 *        __asm__("" : : : "memory");          $a0 live range).  dsp MUST be s32 (u8
 *        switch (dsp) { ... }                 costs an `andi 0xff`).
 *     The NON-volatile clobber invalidates cse's memory table at zero bytes, sits in
 *     the DISPATCH block (outside every case's delay-slot thread), and goes AFTER the
 *     lbu (between lhu and its first use it would eat the load-delay nop at final).
 *     Case 3 then re-reads memory -> real reload; mask idiom keeps the sb by the jal.
 * 13. THE q/r HOIST FLIP: the two new pseudos flipped the razor-thin global-alloc tie
 *     between the 6th/7th pre-loop invariants -- $fp took r and q rematerialised,
 *     INVISIBLE under match_one (HI16/LO16 masked; shapes shift only at the remat
 *     site, seen as a bogus 7-row 'schedule' diff at the q/r lookups). Caught with
 *     objdump -r. Swapping the init order (r 6th, q 7th) flips it back. Lever 3's
 *     preheader-order law still holds: the emitted preheader shows only the WINNERS.
 */

struct Obj;
struct Ent30D80;

extern u8  D_800A4988[];
extern u8  D_800A4F19;
extern s32 D_80073140[];
extern u16 D_8006AA30[];
extern const u16 D_8007319E[];
extern const u16 D_800731A0[];
extern u16 D_8007321E;
extern u8  D_800A4C6D[];
extern s32 D_800C7D2C;

extern void func_8002EFF8(s32 a0, s32 a1);
extern void func_8003D3B4(s32, s32);
extern void func_800314DC(struct Obj *);
extern void func_800316F8(s32);   /* §376: the definition takes s32; cast at the use site */
extern void func_80031988(struct Ent30D80 *);

typedef struct VoiceF80 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ u8  pad0C[0x34];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8  unk44;
    /* 0x45 */ u8  pad45[3];
} VoiceF80; /* 0x48 */

void func_80030F80(void)
{
    u8 *p;
    u8 *sv;
    u8 *w;
    const u16 *q;
    const u16 *r;
    s32 *tbl;
    s32 vb;
    s32 mask;
    VoiceF80 *e;
    u32 m;
    u32 v;
    s16 n;
    s16 t;
    u8 flag;
    u8 st;
    s32 dsp;
    u16 idx;
    u16 h;
    s32 i;

    sv = D_800A4988 + 0x576;
    p = D_800A4988;
    i = 0;
    tbl = D_80073140;
    w = D_800A4988 + 0x572;
    r = D_8007319E;
    q = D_800731A0;
    for (; i < 8; i++, p += 0x54) {
        flag = 0;
        p[0x4E] &= 0x7F;
        if (p[0x4E] != 0) {
            *(s32 *)(p + 0x4) += 1;
            if (*(s32 *)p != 0) {
                *(s32 *)p -= 1;
                if (*(s32 *)p == 0) {
                    func_8002EFF8(1, tbl[*(u16 *)(p + 0xA)]);
                    func_800316F8((s32)p);
                }
            } else {
                if (p[0x4E] >= 2) {
                    p[0x4E] -= 1;
                } else {
                    idx = *(u16 *)(p + 0xA);
                    dsp = sv[idx];
                    __asm__("" : : : "memory");
                    switch (dsp) {
                    case 3:
                        mask = tbl[*(u16 *)(p + 0xA)];
                        p[0x50] = 0;
                        func_8002EFF8(0, mask);
                        /* fallthrough */
                    case 0:
                        p[0x4E] = 0;
                        if (*(s32 *)(p + 0x40) != 0) {
                            (*(void (**)(s32, s32))(p + 0x40))(p[0x51], *(s32 *)(p + 0x44));
                        }
                        *(s32 *)(p + 0x40) = 0;
                        break;
                    case 2:
                        if (p[0x50] != 0) {
                            func_8003D3B4(idx, 1);
                            p[0x50] = 0;
                        }
                        break;
                    }
                }
                if (p[0x4C] != 0) {
                    h = *(u16 *)(p + 0x4A) - 0x220;
                    *(u16 *)(p + 0x4A) = h;
                    flag = 1;
                    if ((s16)h <= 0) {
                        *(u16 *)(p + 0x4A) = 0;
                        p[0x4C] = 0;
                        p[0x50] = 1;
                        D_800A4C6D[i * 0x48] = 1;
                        func_8002EFF8(0, tbl[*(u16 *)(p + 0xA)]);
                    }
                }
                if (p[0x4F] != 0) {
                    flag = 1;
                    p[0x4F] = 0;
                }
                if (p[0x37] & 2) {
                    if (*(s32 *)(p + 0x1C) >= 0) {
                        *(s32 *)(p + 0x18) += *(u16 *)(p + 0x32);
                        if (*(s32 *)(p + 0x18) >= *(s32 *)(p + 0x1C)) {
                            *(s32 *)(p + 0x18) = *(s32 *)(p + 0x1C);
                            p[0x37] &= 0xFD;
                        }
                    } else {
                        *(s32 *)(p + 0x18) -= *(u16 *)(p + 0x32);
                        if (*(s32 *)(p + 0x18) <= *(s32 *)(p + 0x1C)) {
                            *(s32 *)(p + 0x18) = *(s32 *)(p + 0x1C);
                            p[0x37] &= 0xFD;
                        }
                    }
                    flag = 1;
                }
                if ((D_800A4F19 != 0 && p[0x53] != 0) || flag) {
                    n = p[0x35];
                    if (n != 0) {
                        t = n + (*(s32 *)(p + 0x18) >> 8);
                        n = t;
                        if (p[0x53] != 0) {
                            t = p[0x53] + t;
                            if (t < 0x42) {
                                n = 1;
                            } else {
                                t -= 0x40;
                                n = t;
                                if (t >= 0x80) {
                                    n = 0x7F;
                                }
                            }
                        }
                    }
                    if (flag || n != p[0x52]) {
                        m = D_8006AA30[p[0x34]];
                        m = (m * *(s16 *)w) >> 7;
                        m = (m * *(s16 *)(p + 0x48)) >> 7;
                        if (flag) {
                            m = (m * ((s16)*(u16 *)(p + 0x4A) >> 7)) >> 8;
                        }
                        vb = (s32)w - 0x2D2;
                        e = (VoiceF80 *)(i * 0x48 + vb);
                        e->unk00 = tbl[*(u16 *)(p + 0xA)];
                        if (n != 0) {
                            if (w[0x1F] != 0) {
                                v = (m * q[0x7F - n]) >> 14;
                                e->unk08 = v;
                                v = (m * r[n]) >> 14;
                                e->unk0A = v;
                            } else {
                                v = (m * D_8007321E) >> 14;
                                e->unk0A = v;
                                e->unk08 = v;
                            }
                        } else {
                            v = m;
                            e->unk0A = v;
                            e->unk08 = v;
                        }
                        e->unk40 = *(u16 *)(p + 0xA);
                        if (e->unk44 != 0) {
                            e->unk04 |= 3;
                        } else {
                            e->unk44 = 1;
                            e->unk04 = 3;
                        }
                        p[0x52] = n;
                    }
                }
                func_800314DC((struct Obj *)p);
                h = *(u16 *)(p + 0x12);
                if (h != 0) {
                    h -= 1;
                    *(u16 *)(p + 0x12) = h;
                    if (h == 0) {
                        func_80031988((struct Ent30D80 *)p);
                        mask = tbl[*(u16 *)(p + 0xA)];
                        p[0x50] = 0;
                        func_8002EFF8(0, mask);
                        if (*(s32 *)(p + 0x40) != 0) {
                            (*(void (**)(s32, s32))(p + 0x40))(p[0x51], *(s32 *)(p + 0x44));
                        }
                        *(s32 *)(p + 0x40) = 0;
                    }
                }
            }
        } else {
            st = sv[*(u16 *)(p + 0xA)];
            if (st == 0 || st == 3) {
                D_800C7D2C &= ~tbl[*(u16 *)(p + 0xA)];
            }
        }
    }
}
