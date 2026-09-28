/* Exact retail word export for [800314DC,800316F8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800314DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
/* Types from vendor/bfm-decomp/src/800_shared.h. */
typedef struct Slot {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u8 unk08[0xC];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 unk16[2];
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 unk1A[0x26];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 unk45[3];
} Slot;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
} B12; /* 0x0C */


typedef struct Obj {
    /* 0x00 */ u8 unk00[0xA];
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u8 unk12[0x12];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ u16 unk30;
    /* 0x32 */ u8 unk32[0x5];
    /* 0x37 */ u8 unk37;
    /* 0x38 */ u8 unk38;
    /* 0x39 */ u8 unk39;
    /* 0x3A */ s16 unk3A;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ u8 unk3E[0x13];
    /* 0x51 */ u8 unk51;
    /* 0x52 */ u8 unk52[2];
} Obj;


/* 0x0C stride record pointed at by D_8006A970[] -- must match src/800.c's B12
   (same name, same offsets/widths) since the destination TU already declares
   this struct and symbol. */

extern Slot D_800A4C28[];
extern s32 D_80073140[];
extern B12 *D_8006A970[];
extern u16 D_8006AB30[];
extern u16 D_8006AB32[];

void func_800314DC(Obj *p) {
    Slot *e;
    /* dead local: the target frame is `vars= 8` with no $sp reference. */
    s32 pad[2];
    u16 h;
    u32 t;
    /* $2 pin #1 -- `base` is a LOCAL qty in the D_800A4C28 block. Unpinned,
       local-alloc.c:1825 combine_regs TIES its dest into operand 0 of the
       addu (the dying `t & 0xFF00` temp, which lives in $v1), so base lands
       in $v1; the target keeps it in $v0. A hard-reg dest cannot be tied, so
       the pin materialises base in $v0 exactly where the target has it. */
    register s32 base __asm__("$2");
    u32 d;
    u32 res;
    /* $2 pin #2 (disjoint lifetime from `base`) -- see the lerp comment. */
    register u32 q __asm__("$2");

    if (!(p->unk37 & 1)) {
        return;
    }

    if (p->unk30 != 0) {
        p->unk30--;
        return;
    }

    if (p->unk2C < 0) {
        p->unk24 += p->unk2C;
        if (p->unk24 <= p->unk28) {
            p->unk24 = p->unk28;
            p->unk37 &= 0xFE;
        }
    } else {
        p->unk24 += p->unk2C;
        if (p->unk24 >= p->unk28) {
            p->unk24 = p->unk28;
            p->unk37 &= 0xFE;
        }
    }

    if (!(p->unk37 & 1) && p->unk38 != 0) {
        if (p->unk24 != p->unk3C) {
            p->unk28 = p->unk3C;
            if (p->unk3C < p->unk24) {
                p->unk2C = -p->unk3A;
            } else {
                p->unk2C = p->unk3A;
            }
        }
        p->unk38 = 0;
        p->unk37 |= 1;
    }

    e = &D_800A4C28[p->unk51];
    e->unk00 = D_80073140[p->unk0A];
    h = D_8006A970[p->unk10][p->unk0C].unk04;
    /* `t` MUST be a separate SImode local: a HImode `h` used both by the
       0x18 store and by SImode arithmetic is what keeps the otherwise
       redundant `andi $v0,$a0,0xFFFF` alive (folding it away costs an insn). */
    t = h;
    /* splitting the -0x3C00 off keeps the sh scheduled AFTER the andi/sll/sra
       chain: as one expression the store's memory dependence on the 0x24 load
       gives it enough sched1 priority to hoist into the load-delay region. */
    base = (t & 0xFF00) + ((s8)t * 2);
    e->unk18 = h;
    base -= 0x3C00;
    /* in-place update: the target reuses $a1 for both the 0x24 load and the
       difference, and global.c has no coalescing (K8) -- cross-block sharing
       has to be ONE pseudo in the source. */
    d = p->unk24;
    d -= base;
    if (d >= 0x5300) {
        res = 0x3FFF;
    } else {
        /* `q` merges the D_8006AB30 load with the first product into one
           $v0-pinned range. That blocks $v0 across insns 4..11 of this block,
           which is what pushes 0x100 -> $v1, the index -> $a0, the D_8006AB32
           load -> $v1, and (via the global pass) the second mflo -> $v1. */
        q = D_8006AB30[d >> 8];
        q = q * (0x100 - (d & 0xFF));
        res = (q + D_8006AB32[d >> 8] * (d & 0xFF)) >> 8;
    }
    e->unk14 = res;
    e->unk40 = p->unk0A;
    if (e->unk44 != 0) {
        e->unk04 |= 0x10;
    } else {
        e->unk44 = 1;
        e->unk04 = 0x10;
    }
}
