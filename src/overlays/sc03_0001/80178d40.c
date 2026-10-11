/* Overlay range [80178D40,80179B28) from MAIN.CD member 0012.
 * SHA256(span)=29d3c72b380c97fb8c98bd70ae120dec8ab1251ef7c7ab1e2dab96de13b33d5b.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178D40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; } Blk_80178D40;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct { u8 pad0[0x12]; u16 unk12; } Obj20_80178D40;
typedef struct Actor_80178D40 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    s16 unk8;
    u16 unkA;
    s16 unkC;
    u16 unkE;
    u8 pad10[0x20 - 0x10];
    Obj20_80178D40 *unk20;
    u8 pad24[0x34 - 0x24];
    s16 unk34;
    u8 pad36[0xD4 - 0x36];
    struct Actor_80178D40 *unkD4;
    s32 unkD8;
    s32 unkDC[7];
    s32 unkF8;
    u8 padFC[0x10A - 0xFC];
    s16 unk10A;
} Actor_80178D40;
typedef struct { s16 vx, vy, vz, pad; } SV3_80178D40;
typedef s32 M2C_UNK;
void func_8012A568(void (*a0)(void));
extern void func_8012A568(void (*a0)(void));

extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_80175414(s32 _arg0);
extern void func_80175454(void);

/* func_80178D40 - 890 ins, 94-case jr switch (jtbl_801D8E24).
 * STATUS: **MATCH** -- 890/890 ins, byte-exact (masked). PIN-FREE (this body is
 * templated across 134 overlays; a pinned body would crash the sibling TUs).
 *   python3 tools/match_one.py func_80178D40 --c .run/phase26-cracks/func_80178D40.c \
 *       --asm-subdir asm/ov_SC01_077/nonmatchings/ov_SC01_077_jr_801734BC
 *   => MATCH (890 ins)
 * Jump table VERIFIED: 94 entries (= the sltiu 0x5E bound, no trailing zero pad),
 * 93 unique blocks, cases 0xF/0x3F share one block; my case->block sequence is
 * identical to jtbl_801D8E24's.
 *
 * Byte-derived structure (the levers that cracked it):
 *  1. NO status variable. Every case stores `(*(s16*)&D_801EF464) = K` DIRECTLY. The shared
 *     `sh $v0, (*(s16*)&D_801EF464)` at .L80179AEC is a jump2 CROSS-JUMP merge of those stores:
 *     find_cross_jump's FIRST call (minimum=1, vs the code before the target label)
 *     matches that 1 insn, and because it succeeds the jump_chain loop (minimum=2) is
 *     SKIPPED -- which is what BLOCKS the deeper, wrong 3-insn merges of the identical
 *     func_80137614 tails (cases 0/0x45/0x32). reorg then steals the `li K` back into
 *     each `j` delay slot, so it looks un-merged. A `status` pseudo instead of direct
 *     stores loses that block and costs 6 insns.
 *  2. after-switch = `D_801EE1C8 += 8;` (.L80179AF4) -> the out-of-range default lands
 *     there with NO explicit `default:` label.
 *  3. arg0/arg1/pv are STRUCT pointers. gcc-2.7.2 sched alias (sched.c true_dependence)
 *     only lets a MEM_IN_STRUCT varying-address load hoist above a non-MEM_IN_STRUCT
 *     fixed-address store (the (*(s16*)&D_801EF464) store). Raw `*(T *)(int + off)` casts get
 *     MEM_IN_STRUCT_P = 0 and block that hoist -> stray nops.
 *  4. g = &D_801EF3A8 stays a plain `s16 *` (NOT a struct ptr) so its varying,
 *     non-in-struct stores keep their order w.r.t. the loads.
 *  5. Statement order inside the D_801EF3A8 cases is load-bearing (sched LUID/priority):
 *     g[0],g[2],g[1] in 0x25/0x48/0x26; g[7],g[8],g[1],g[3] in 0x4F/0x28.
 *  6. Cases 0x5B/0x5C: the loops "found" bodies are emitted BEFORE the case label ->
 *     source-level labels placed between cases + `goto`.
 *  7. Per-case temporaries are BLOCK-LOCAL (local-alloc), not function-scope.
 *  8. stack locals declared in slot order (0x10,0x18,0x20,0x28,0x30,0x38,0x40,0x48,
 *     0x50,0x58,0x60) -> frame 0x78.
 *
 * Case 0x5C -- the last 39 residuals. Four levers, all generalizable:
 *
 *  9. NO-PEEL: a `break` out of a do-while whose target COINCIDES with the loop's own
 *     natural fall-through exit makes NOTE_INSN_LOOP_BEG be followed by an
 *     unconditional jump -> jump.c `duplicate_loop_exit_test` (jump.c:599/2131) rotates
 *     the loop and peels iteration 1 (here `i` was provably 0, so the peeled `i++`
 *     const-folded to `li $a2,1` and dragged an extra lui/addiu/lw address block with
 *     it). Writing `goto L5D;` instead of `break;` -- SAME destination, different
 *     construct -- keeps the loop a plain do-while and the peel disappears.
 *     RULE: never let a loop's `break` land on the loop's own fall-through label.
 *
 * 10. SURVIVING REG-REG COPY (residual #1, `addu $v1,$v0,$zero`). A source-level
 *     `fp = q;` copy ALWAYS dies: cse.c `canon_reg` rewrites every later use of `fp`
 *     to `q` (qty_first_reg keeps the older reg) and flow deletes the now-dead set.
 *     To make a copy SURVIVE, its def and its uses must sit in different extended basic
 *     blocks -- cse resets its hash table at a label with >1 predecessor (a loop top).
 *     So: TEST THE MEM DIRECTLY, then assign the variable inside the branch body:
 *         if (arg1->a.w != 0) { fp5c = arg1->a.w; ... do { ... fp5c ... } while (); }
 *     cse folds the redundant 2nd load into `fp5c = <load temp>` (a copy) in the guard
 *     block, but CANNOT propagate it into the loop body -> the copy is emitted.
 *     (Assigning `fp5c` BEFORE the test gives one pseudo and no copy -- what we had.)
 *
 * 11. CROSS-JUMP-MERGED `(*(s16*)&D_801EF464) = 3` (residual #2). `if (i != 10) { (*(s16*)&D_801EF464) = 3;
 *     break; }` lets jump2 tail-merge the `lui/sh` into the shared .L80179AEC tail and
 *     reorg steal the `li 3` into the `bne` delay slot. Storing it unconditionally
 *     BEFORE the `if` blocks the merge and costs 3 inline insns.
 *
 * 12. THE UN-COALESCED LOOP COPY (residual #3, `addu $v1,$a0,$zero` + `addiu $a0,$v1,4`).
 *     This is loop.c's NON-REPLACEABLE DEST_REG GIV, not a source-level copy (see #10:
 *     those always die). Recipe -- BOTH halves are needed:
 *       a) make the pointer an INDEX GIV: `p5c = &D_801EE624[i5c];`  (a DEST_REG giv)
 *       b) make it NON-replaceable so loop.c emits `emit_insn_after(move dest,new_reg)`
 *          (loop.c:3945): record_giv (loop.c:4437) needs the giv used OUTSIDE the loop
 *          -- so the "found" body goes AFTER the loop and stores through `p5c`.
 *       c) put the BIV increment (`i5c++`) LAST in the body. loop.c inserts the reduced
 *          giv's `addiu` immediately BEFORE the biv's increment insn, so `i5c++` at the
 *          bottom puts `addiu $a0,$v1,4` in the loop-back delay slot. With `i5c++` at
 *          the TOP the giv-add lands at the top, nothing is left to fill the delay slot,
 *          and reorg STEALS the loop-top `move` into it (duplicating it: +1 insn).
 *
 * 13. Loop3 needs its OWN pointer pseudo (`r5c`, not `q5c`). `q5c` is loop1's pointer,
 *     and in loop1 $v1 is held by `fp5c` -> q5c is forced to $a0, and loop3 inherits it.
 *     Both "found" bodies then read $a0, become identical, and jump2 CROSS-JUMPS them
 *     into one block (-2 insns). A distinct pseudo frees loop3 into $v1, so found3
 *     (`sw $zero,0($v1)`) differs from found2 (`sw $zero,0($a0)`) and they stay separate.
 *     RULE: two structurally identical loops must differ in REGISTER, or cross_jump
 *     merges their tails.
 */






M2C_UNK func_80178D40(s32 arg0, s32 arg1)
{

    extern s32 D_80126B58;
    extern s32 D_801EE1C8;
    extern short D_801EF464;
    extern void func_80179B28(s32);
    extern void func_80137614(s32, s32, s32);
    extern void func_8012F214(s32, s32, s32);
    extern s32 *func_8012F40C(s32*, s32);
    extern void func_80179D30(u16*);
    extern void func_80179D78(u16*);
    extern void func_80179EA0(u16*);
    extern void func_80179DCC(short);
    extern void func_80179DF8(void);
    extern void func_80179E1C(short);
    extern void func_80179E48(s16);
    extern void func_80179E74(s16);
    extern void func_80179EE8(short);
    extern void func_80179F14(s16, s16);
    extern void func_80179F44(void);
    extern void func_80179F6C(short);
    extern void func_80179F98(u16*);
    extern void func_80179FEC(u16*);
    extern void func_8017A040(u16*);
    extern void func_8017A094(s32);
    extern void func_8017A0C4(s32);
    extern void func_8017A0F4(void);
    extern void func_8017A11C(void);
    extern void func_8017A144(s32);
    extern void func_8017A180(void);
    extern void func_8017A1A8(void);
    extern void func_8017A1D0(void);
    extern void func_8017A1F8(void);
    extern void func_8017A220(void);
    extern void func_8017A248(void);
    extern void func_8017A270(void);
    extern void func_8017A298(void);
    extern void func_8017A2C0(void);
    extern void func_8017A2E8(void);
    extern void func_8017A310(void);
    extern void func_8017A338(void);
    extern void func_8017A360(void);
    extern void func_8017A388(void);
    extern s32 func_8017A3B0(void);
    extern int func_8017A3D8(void);
    extern s32 func_8017AD0C(s32);
    extern s32 func_8017B238(s32, s32);
    extern s32 func_8017B614(s32, s32);
    extern void func_8017B7A8(void *);
    extern void func_8017B824(void);
    extern void func_8017B880(void);
    extern void func_8017B940(void *);
    extern void func_8017BA3C(s32, s32);
    extern s32 func_8017BB34(s32, s32);
    extern void func_8012A828(s32, void*);
    extern s32 func_8012B8A4(s16*);
    extern void func_8012E88C(u8*);
    extern void func_8012E8A8(u8*);
    extern void func_8001AAD0(s32, s32);
    extern s32 D_801EE1CC;
    extern s32 D_801EE5E0;
    extern s16 D_801EE5E4;
    extern s16 D_801EE5E8;
    extern s16 D_801EE5EC;
    extern s16 D_801EE5F0;
    extern s32 D_801EE5F8;
    extern s32 D_801EE5FC;
    extern s32 D_801EE60C;
    extern s16 D_801EE610;
    extern s16 D_801EE614;
    extern s32 D_801EE618;
    extern s32 D_801EE620;
    extern s32 D_801EE624[10];
    extern s32 D_801EF2D8;
    extern s16 D_801EF3A8;
    extern s32 D_801EF3EC;


    SV3_80178D40 v10, v18, v20, v28, v30, v38, v40, v48;
    s32 out50[2];
    SV3_80178D40 v58, v60;
    Actor_80178D40 *pv = &(*(Actor_80178D40*)&D_80126B58);
    s32 i5b, i5c, fp5b, fp5c;
    s32 *q5b, *q5c, *p5c, *r5c;
    s16 *g = &D_801EF3A8;

    switch (((Cmd_80178D40 *)arg1)->op) {
    case 1:
        func_80179B28(D_801EE5E0);
        D_801EE5E0 = ((s32 (*)(s32, s32, s32))func_80137614)(((Cmd_80178D40 *)arg1)->a.w, D_801EE5EC, D_801EE5F0 ? 0x48 : 0x40);
        (*(s16*)&D_801EF464) = 2;
        break;
    case 0:
        func_80179B28(D_801EE5E0);
        D_801EE5E0 = ((s32 (*)(s32, s32, s32))func_80137614)(((Cmd_80178D40 *)arg1)->a.w, D_801EE5E4, D_801EE5E8 ? 0x48 : 0x40);
        (*(s16*)&D_801EF464) = 1;
        break;
    case 0x45:
        ((void (*)(s32))((Cmd_80178D40 *)arg1)->a.w)(((Actor_80178D40 *)arg0));
        if (D_801EF2D8 != 0) {
            func_80179B28(D_801EE5E0);
            D_801EE5E0 = ((s32 (*)(s32, s32, s32))func_80137614)(((Actor_80178D40 *)arg0)->unkDC[1], D_801EE5E4, D_801EE5E8 ? 0x48 : 0x40);
            (*(s16*)&D_801EF464) = 1;
        } else {
            (*(s16*)&D_801EF464) = 3;
        }
        break;
    case 0x32:
        func_80179B28(D_801EE5E0);
        D_801EE5E0 = ((s32 (*)(s32, s32, s32))func_80137614)(((Actor_80178D40 *)arg0)->unkDC[((Cmd_80178D40 *)arg1)->a.w], D_801EE5E4,
                                   D_801EE5E8 ? 0x48 : 0x40);
        (*(s16*)&D_801EF464) = 1;
        break;
    case 2:
        func_80179B28(D_801EE5E0);
        if (D_801EE5F8 != 0) {
            D_801EE1C8 = D_801EE5F8;
            D_801EE5F8 = 0;
            (*(s16*)&D_801EF464) = 3;
            return;
        }
        (*(s16*)&D_801EF464) = 6;
        break;
    case 6:
        func_80179DF8();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 3:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *))func_80179D30)(&v10);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 4:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v10, &v18);
        ((void (*)(void *))func_80179D30)(&v18);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x4C:
        ((void (*)(void *))func_80179D78)((void *)((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x4D:
        v10.vx = ((Blk_80178D40 *)((Cmd_80178D40 *)arg1)->a.p)->f0;
        v10.vy = 0;
        v10.vz = ((Blk_80178D40 *)((Cmd_80178D40 *)arg1)->a.p)->f4;
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v10, &v18);
        v18.pad = ((Blk_80178D40 *)((Cmd_80178D40 *)arg1)->a.p)->f6;
        ((void (*)(void *))func_80179D78)(&v18);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x15:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0)->unkD4, &v10, &v18);
        ((void (*)(void *))func_80179D30)(&v18);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 5:
        ((void (*)(s32))func_80179DCC)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 7:
        ((void (*)(s32))func_80179E1C)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 8:
        ((void (*)(s32))func_80179E74)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 9:
        v10.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v10.vy = 0;
        v10.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *))func_80179EA0)(&v10);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0xA:
        v10.vx = ((Actor_80178D40 *)arg0)->unk6;
        v10.vy = ((Actor_80178D40 *)arg0)->unkA;
        v10.vz = ((Actor_80178D40 *)arg0)->unkE;
        ((void (*)(void *))func_80179EA0)(&v10);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x16: {
        Actor_80178D40 *p = ((Actor_80178D40 *)arg0)->unkD4;
        v10.vx = p->unk6;
        v10.vy = p->unkA;
        v10.vz = p->unkE;
        ((void (*)(void *))func_80179EA0)(&v10);
        (*(s16*)&D_801EF464) = 3;
        break;
    }
    case 0xB:
        func_8017A0F4();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0xC:
        func_8017A11C();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0xD:
        func_8017A180();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0xE:
        func_8017A1A8();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x10:
        func_8017A1D0();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x46:
        func_8017A1F8();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x59:
        func_8017A220();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x5A:
        func_8017A248();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x49:
        func_8017A144(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x47:
        func_8017A270();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x17:
        ((void (*)(s32))func_80179EE8)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x18:
        ((void (*)(s32, s32))func_80179F14)(((Cmd_80178D40 *)arg1)->a.h[0], ((Cmd_80178D40 *)arg1)->a.h[1]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x19:
        ((void (*)(s32))func_80179F6C)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x1A:
        ((void (*)(s32))func_80179F98)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x51:
        ((void (*)(s32))func_8017A040)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x1B:
        D_801EE618 = ((Cmd_80178D40 *)arg1)->a.w;
        func_80179F44();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x1C:
        func_8017A338();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x52:
        func_8017A360();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x1D:
        func_8017A388();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x3B:
        func_8017A094(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x3C:
        func_8017A0C4(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0xF:
    case 0x3F:
        (*(s16*)&D_801EF464) = 4;
        D_801EE1CC = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x3E:
        (*(s16*)&D_801EF464) = 5;
        D_801EE60C = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x40:
        D_801EE60C = (s32)func_8017A3B0;
        (*(s16*)&D_801EF464) = 5;
        break;
    case 0x23:
        ((void (*)(void *, s32))func_8012A828)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x31:
        ((void (*)(void *, s32))func_8012A828)(((Actor_80178D40 *)arg0), ((Actor_80178D40 *)arg0)->unkDC[((Cmd_80178D40 *)arg1)->a.w]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x24:
        (*(s16*)&D_801EF464) = 3;
        ((Actor_80178D40 *)arg0)->unk20->unk12 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x25:
        g[0] = 1;
        g[2] = ((Actor_80178D40 *)arg0)->unk20->unk12 + ((Cmd_80178D40 *)arg1)->a.uh[0];
        g[1] = 0x1E;
        (*(s16*)&D_801EF464) = 3;
        g[3] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x48:
        g[0] = 1;
        g[2] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        g[1] = 0x1E;
        (*(s16*)&D_801EF464) = 3;
        g[3] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x26:
        g[0] = 1;
        g[2] = ((s32 (*)(void *))func_8012B8A4)(((Actor_80178D40 *)arg0));
        g[1] = 0x1E;
        (*(s16*)&D_801EF464) = 3;
        g[3] = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x3D:
        ((void(*)(void *, s32))func_8012E8E0)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x27:
        g[0] = 2;
        g[4] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        (*(s16*)&D_801EF464) = 3;
        g[1] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x4F:
        g[5] = 1;
        g[0] = 3;
        g[6] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        (*(s16*)&D_801EF464) = 3;
        g[7] = ((Actor_80178D40 *)arg0)->unkA;
        g[8] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        g[1] = 0x10;
        g[3] = 4;
        /* fallthrough */
    case 0x28:
        g[5] = 0;
        g[0] = 3;
        g[6] = ((Cmd_80178D40 *)arg1)->a.uh[0];
        (*(s16*)&D_801EF464) = 3;
        g[7] = ((Actor_80178D40 *)arg0)->unkA;
        g[8] = ((Cmd_80178D40 *)arg1)->a.uh[1];
        g[1] = 0x10;
        g[3] = 4;
        break;
    case 0x29:
        v20.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v20.vy = ((Actor_80178D40 *)arg0)->unkA;
        v20.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v20, &v28);
        g[5] = 0;
        g[0] = 3;
        *(SV3_80178D40 *)(g + 6) = v28;
        g[1] = 0x10;
        g[3] = 4;
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x50:
        v30.vx = ((Cmd_80178D40 *)arg1)->a.uh[0];
        v30.vy = ((Actor_80178D40 *)arg0)->unkA;
        v30.vz = ((Cmd_80178D40 *)arg1)->a.uh[1];
        ((void (*)(void *, void *, void *))func_8012F214)(((Actor_80178D40 *)arg0), &v30, &v38);
        g[5] = 1;
        g[0] = 3;
        *(SV3_80178D40 *)(g + 6) = v38;
        g[1] = 0x10;
        g[3] = 4;
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x2A:
        g[0] = 4;
        (*(s16*)&D_801EF464) = 3;
        g[1] = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x1E:
        ((void (*)(void *, s32))func_8017B238)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x21:
        ((void (*)(void *, s32))func_8017BA3C)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        ((void (*)(void *, s32))func_8017B238)(((Actor_80178D40 *)arg0), (s32)&D_801EE5FC);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x54:
        ((void (*)(void *, s32))func_8017BB34)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        ((void (*)(void *, s32))func_8017B238)(((Actor_80178D40 *)arg0), (s32)&D_801EE5FC);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x1F:
        ((void (*)(void *, s32))func_8017B614)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x22:
        ((void (*)(void *, s32))func_8017BA3C)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        ((void (*)(void *, s32))func_8017B614)(((Actor_80178D40 *)arg0), (s32)&D_801EE5FC);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x55:
        ((void (*)(void *, s32))func_8017BB34)(((Actor_80178D40 *)arg0), ((Cmd_80178D40 *)arg1)->a.w);
        ((void (*)(void *, s32))func_8017B614)(((Actor_80178D40 *)arg0), (s32)&D_801EE5FC);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x20:
        func_8017B7A8(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x4E:
        D_801EE620 = ((Cmd_80178D40 *)arg1)->a.w;
        func_8017B940(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x57:
        func_8017B824();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x58:
        func_8017B880();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x2B:
        (*(s16*)&D_801EF464) = 3;
        ((Actor_80178D40 *)arg0)->unk2 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2C:
        (*(s16*)&D_801EF464) = 3;
        ((Actor_80178D40 *)arg0)->unk34 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2D:
        (*(s16*)&D_801EF464) = 3;
        ((Actor_80178D40 *)arg0)->unkD8 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2F:
        (*(s16*)&D_801EF464) = 3;
        ((Actor_80178D40 *)arg0)->unk10A = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x2E:
        (*(s16*)&D_801EF464) = 3;
        ((Actor_80178D40 *)arg0)->unkF8 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x11:
        func_8017A298();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x12:
        func_8017A2C0();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x13:
        func_8017A2E8();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x14:
        func_8017A310();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x33: {
        void (*f)(Actor_80178D40 *) = (void (*)(Actor_80178D40 *))((Cmd_80178D40 *)arg1)->a.w;
        D_801EF3EC = (s32)&((Cmd_80178D40 *)arg1)[1];
        f(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801EF464) = 3;
        break;
    }
    case 0x30:
        if (((Cmd_80178D40 *)arg1)->a.w == 0) {
            ((void (*)(void *))func_8012E8A8)(((Actor_80178D40 *)arg0));
            (*(s16*)&D_801EF464) = 3;
        } else {
            ((void (*)(void *))func_8012E88C)(((Actor_80178D40 *)arg0));
            (*(s16*)&D_801EF464) = 3;
        }
        break;
    case 0x4A:
        ((void(*)())func_80175414)();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x4B:
        func_80175454();
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x34:
        (*(s16*)&D_801EF464) = 3;
        D_801EE1C8 = ((Cmd_80178D40 *)arg1)->a.w;
        return;
    case 0x35:
        D_801EE5F8 = (s32)&((Cmd_80178D40 *)arg1)[1];
        (*(s16*)&D_801EF464) = 3;
        D_801EE1C8 = ((Cmd_80178D40 *)arg1)->a.w;
        return;
    case 0x36:
        (*(s16*)&D_801EF464) = 3;
        D_801EE1C8 += 8;
        if (((s32 (*)(s32))((Cmd_80178D40 *)arg1)->a.w)(((Actor_80178D40 *)arg0)) == 0) {
            break;
        }
        D_801EE1C8 = *(s32 *)(D_801EE1C8 + 4);
        return;
    case 0x37:
        (*(s16*)&D_801EF464) = 3;
        D_801EE5E4 = ((Cmd_80178D40 *)arg1)->a.uh[0];
        D_801EE5E8 = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x38:
        (*(s16*)&D_801EF464) = 3;
        D_801EE5EC = ((Cmd_80178D40 *)arg1)->a.uh[0];
        D_801EE5F0 = ((Cmd_80178D40 *)arg1)->a.uh[1];
        break;
    case 0x39: {
        s32 w1, w2;
        v40.vx = ((Actor_80178D40 *)arg0)->unk6;
        v40.vy = ((Actor_80178D40 *)arg0)->unkA;
        v40.vz = ((Actor_80178D40 *)arg0)->unkE;
        v48.vx = pv->unk6;
        v48.vy = pv->unkA;
        v48.vz = pv->unkE;
        ((void (*)(void *, void *))func_8012F40C)(out50, &v40);
        w1 = out50[0];
        ((void (*)(void *, void *))func_8012F40C)(out50, &v48);
        w2 = out50[0];
        (*(s16*)&D_801EF464) = 3;
        D_801EE5E4 = w1;
        D_801EE5E8 = (s16)w1 >= (s16)w2;
        break;
    }
    case 0x3A: {
        s32 w1, w2;
        v58.vx = ((Actor_80178D40 *)arg0)->unk6;
        v58.vy = ((Actor_80178D40 *)arg0)->unkA;
        v58.vz = ((Actor_80178D40 *)arg0)->unkE;
        v60.vx = pv->unk6;
        v60.vy = pv->unkA;
        v60.vz = pv->unkE;
        ((void (*)(void *, void *))func_8012F40C)(out50, &v58);
        w1 = out50[0];
        ((void (*)(void *, void *))func_8012F40C)(out50, &v60);
        w2 = out50[0];
        (*(s16*)&D_801EF464) = 3;
        D_801EE5EC = w2;
        D_801EE5F0 = (s16)w1 < (s16)w2;
        break;
    }
    case 0x41:
        ((void(*)(s32, s32))func_8002D4C8)(((Cmd_80178D40 *)arg1)->a.uh[0], ((Cmd_80178D40 *)arg1)->a.uh[1]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x42:
        ((void (*)(s32))func_8017AD0C)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x43:
        D_801EE60C = (s32)func_8017A3D8;
        D_801EE614 = 0;
        (*(s16*)&D_801EF464) = 5;
        D_801EE610 = ((Cmd_80178D40 *)arg1)->a.w;
        break;
    case 0x44:
        func_8001AAD0(((Cmd_80178D40 *)arg1)->a.h[0], ((Cmd_80178D40 *)arg1)->a.h[1]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x53:
        ((void (*)(s32))func_80179E48)(((Cmd_80178D40 *)arg1)->a.h[0]);
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x56:
        ((void (*)(s32))func_80179FEC)(((Cmd_80178D40 *)arg1)->a.w);
        (*(s16*)&D_801EF464) = 3;
        break;
    L5B_found:
        fp5b = ((Cmd_80178D40 *)arg1)->a.w;
        *q5b = fp5b;
        ((void (*)(Actor_80178D40 *))fp5b)(((Actor_80178D40 *)arg0));
        (*(s16*)&D_801EF464) = 3;
        break;
    case 0x5B:
        i5b = 0;
        q5b = D_801EE624;
        do {
            i5b++;
            if (*q5b == 0) {
                goto L5B_found;
            }
            q5b++;
        } while (i5b < 10);
        (*(s16*)&D_801EF464) = 3;
        break;
    L5C_found1:
        *q5c = 0;
        goto L5C_join;
    case 0x5C:
        i5c = 0;
        if (((Cmd_80178D40 *)arg1)->a.w != 0) {
            fp5c = ((Cmd_80178D40 *)arg1)->a.w;
            q5c = D_801EE624;
            do {
                if (*q5c == fp5c) {
                    goto L5C_found1;
                }
                i5c++;
                q5c++;
            } while (i5c < 10);
        L5C_join:
            if (i5c != 10) {
                (*(s16*)&D_801EF464) = 3;
                break;
            }
            i5c = 0;
            do {
                p5c = &D_801EE624[i5c];
                if (*p5c != 0) {
                    goto L5C_found2;
                }
                i5c++;
            } while (i5c < 10);
            (*(s16*)&D_801EF464) = 3;
            break;
        L5C_found2:
            *p5c = 0;
            goto L5D;
        }
        r5c = D_801EE624;
        do {
            i5c++;
            if (*r5c != 0) {
                *r5c = 0;
                goto L5D;
            }
            r5c++;
        } while (i5c < 10);
        /* fallthrough */
    case 0x5D:
    L5D:
        (*(s16*)&D_801EF464) = 3;
        break;
    default:
        break;
    }
Lend:
    D_801EE1C8 += 8;
}
