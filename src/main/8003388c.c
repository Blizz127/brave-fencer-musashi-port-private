/* Exact retail word export for [8003388C,800342E8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003388C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
/* Types from vendor/bfm-decomp/src/800_shared.h. */
typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
} B12; /* 0x0C */
typedef struct {
    /* 0x00 */ u8  pad00[4];
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  pad05[11];
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u8  pad14[2];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8  pad18[8];
} C24; /* 0x20 */
typedef struct {
    /* 0x00 */ u16 cur;
    /* 0x02 */ u16 step;
    /* 0x04 */ u16 tgt;
    /* 0x06 */ u8  act;
    /* 0x07 */ u8  pad07;
} Ramp388C; /* 0x08 */

typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ u8  unk08;
    /* 0x09 */ u8  unk09;
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
    /* 0x0C */ u8  unk0C;
    /* 0x0D */ u8  unk0D;
    /* 0x0E */ u8  pad0E[2];
    /* 0x10 */ s32 unk10;
} Cmd388C; /* 0x14 */

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ u8  pad02[6];
    /* 0x08 */ u16 unk08;
    /* 0x0A */ u8  pad0A[2];
    /* 0x0C */ u32 *unk0C;
    /* 0x10 */ u8  *unk10;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u8  unk16;
    /* 0x17 */ u8  unk17;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ Ramp388C unk1C[3];
    /* 0x34 */ u16 unk34;
    /* 0x36 */ u8  unk36;
    /* 0x37 */ u8  pad37[1];
    /* 0x38 */ u8  unk38;
    /* 0x39 */ u8  unk39;
    /* 0x3A */ u8  unk3A[8];
    /* 0x42 */ u8  pad42[2];
    /* 0x44 */ u32 *unk44;
    /* 0x48 */ u8  unk48;
    /* 0x49 */ u8  pad49[1];
    /* 0x4A */ u16 unk4A;
    /* 0x4C */ u8  unk4C;
    /* 0x4D */ u8  unk4D;
    /* 0x4E */ u8  unk4E;
    /* 0x4F */ u8  unk4F;
    /* 0x50 */ u16 unk50;
    /* 0x52 */ s16 unk52;
} Ent388C;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u16 unk08;
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8  pad18[0x0C];
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8  pad28[0x0C];
    /* 0x34 */ u8  unk34;
    /* 0x35 */ u8  unk35;
    /* 0x36 */ u8  unk36;
    /* 0x37 */ u8  pad37[9];
    /* 0x40 */ void (*unk40)(u8 *, s32);
    /* 0x44 */ s32 unk44;
    /* 0x48 */ u16 unk48;
    /* 0x4A */ u16 unk4A;
    /* 0x4C */ u8  unk4C;
    /* 0x4D */ u8  unk4D;
    /* 0x4E */ u8  unk4E;
    /* 0x4F */ u8  unk4F;
    /* 0x50 */ u8  pad50[2];
    /* 0x52 */ u8  unk52;
    /* 0x53 */ u8  unk53;
} Chan388C; /* 0x54 */

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ u8  pad10[4];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8  pad16[2];
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u8  pad1A[2];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8  pad20[0x1A];
    /* 0x3A */ s16 unk3A;
    /* 0x3C */ s16 unk3C;
    /* 0x3E */ u8  pad3E[2];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8  unk44;
    /* 0x45 */ u8  unk45;
    /* 0x46 */ u8  pad46[2];
} Voice388C; /* 0x48 */

extern s16 D_800A4EF0;
extern s16 D_800C5328[];
extern s16 D_800A46A2;
extern u8  D_800A4988[];
extern B12 *D_8006A970[];
extern s32 D_80073140[];
extern u16 D_8006AB30[];
extern u16 D_8006AB32[];
extern u8  D_800A4F1E;
extern u16 D_8006AA30[];
extern s16 D_800A4EFA;
extern u8  D_800A4F19;
extern const u16 D_8007319E[];
extern const u16 D_800731A0[];
extern u16 D_8007321E;
extern s16 D_800A4EF6;

extern void func_80034650(u8 *, s32);
extern void func_800336A8();
extern s32  func_80030CA4(u16);
extern s16  func_8003F144(s32, s32, s32, C24 *);
extern s32  func_8003F380(s32, s32);
extern void func_800316F8(s32);
extern void func_8002F064(s32, s32);
extern void func_8002EFF8(s32, s32);
extern void func_800342E8(u8 *, s32);

void func_8003388C(Ent388C *arg, s32 arg1)
{
    Cmd388C rec;
    C24 sp28;
    s32 pad[4];
    Ent388C *e;
    Cmd388C *cmd;
    Chan388C *ch;
    Voice388C *vo;
    Ramp388C *r;
    B12 *b;
    u32 *p;
    s32 op;
    register s32 c0 __asm__("$2");
    register s32 c1 __asm__("$3");
    register s32 c2 __asm__("$2");
    register s32 c3 __asm__("$4");
    s32 mask;
    s32 vi;
    s32 bank;
    s32 lvl;
    register s32 res __asm__("$3");
    register s32 base __asm__("$2");
    register s32 sum __asm__("$3");
    s32 t24;
    s32 tmp9;
    u32 t, t18, d, amt, res2;
    register u32 v __asm__("$2");
    register u32 m __asm__("$3");
    register u32 q __asm__("$2");
    u16 h;
    u32 b04;
    u16 h2;
    s32 n84;
    u32 n86;
    register u32 x86 __asm__("$2");
    u8 flag;
    s32 called;
    s32 lv;
    register u32 tv __asm__("$2");
    register u32 pr1 __asm__("$5");
    register u32 pr2 __asm__("$3");
    register u32 pr3 __asm__("$3");
    u32 i;

    e = arg;
    if (e->unk34 != 0 && e->unk34 != D_800A4EF0) {
        func_80034650((u8 *)e, 0);
        return;
    }
    if (e->unk08 != 0) {
        e->unk08 = e->unk08 - 1;
    }

    r = e->unk1C;
    flag = 0;
    for (i = 0; i < 3; i++, r++) {
        if (r->act != 0) {
            flag = 1;
            h = r->cur;
            t = h;
            if (t == r->tgt) {
                r->act = 0;
            } else if (t < r->tgt) {
                r->cur = h + r->step;
                if (r->cur >= 0x4000) {
                    r->cur = 0x3FFF;
                }
                if (r->tgt < r->cur) {
                    r->cur = r->tgt;
                }
            } else {
                if (t >= r->step) {
                    r->cur = h - r->step;
                } else {
                    r->cur = 0;
                }
                if (r->cur < r->tgt) {
                    r->cur = r->tgt;
                }
            }
        }
    }

    called = 0;
    if (e->unk16 != 0) {
        if (e->unk18 > e->unk1A) {
            e->unk18 = e->unk18 - e->unk1A;
            func_800336A8((void *)e);
            called = 1;
        } else {
            func_80034650((u8 *)e, 1);
            return;
        }
    } else if (flag != 0) {
        func_800336A8((void *)e);
        called = 1;
    }

    if (e->unk39 != e->unk38) {
        if (called == 0) {
            func_800336A8((void *)e);
        }
        e->unk39 = e->unk38;
    }

    if (e->unk36 != 0) {
        for (i = 0; i < 8; i++) {
            if (e->unk3A[i] != 0) {
                return;
            }
        }
        e->unk00 = 0;
        return;
    }

    e->unk14 = e->unk14 - 1;
    if (e->unk14 != 0) {
        return;
    }

    if (e->unk48 != 0) {
        p = e->unk0C;
        for (;;) {
            op = *p;
            switch ((u32)op >> 24) {
            case 0x80:
                p++;
                rec.unk06 = op;
                rec.unk08 = op >> 16;
                op = *p;
                p++;
                rec.unk02 = op;
                rec.unk00 = op >> 16;
                op = *p;
                p++;
                c0 = op;
                op >>= 8;
                c1 = op;
                op >>= 8;
                c3 = (u32)op >> 8;
                rec.unk0C = c0;
                e->unk4F = c0;
                c2 = op;
                rec.unk0B = c1;
                e->unk4E = c1;
                rec.unk0A = c2;
                e->unk4D = c2;
                rec.unk09 = c3;
                e->unk4C = c3;
                h2 = *(u16 *)p;
                p++;
                rec.unk04 = h2;
                e->unk4A = h2;
                op = *p;
                p++;
                rec.unk0D = 0;
                rec.unk10 = op;
                goto done;
            case 0x81:
                p++;
                rec.unk06 = op;
                rec.unk08 = op >> 16;
                op = *p;
                rec.unk02 = op;
                rec.unk00 = op >> 16;
                rec.unk0C = e->unk4F;
                rec.unk0B = e->unk4E;
                rec.unk0A = e->unk4D;
                rec.unk09 = e->unk4C;
                rec.unk04 = e->unk4A;
                p++;
                rec.unk10 = 0;
                rec.unk0D = 0;
                goto done;
            case 0x82:
                p++;
                e->unk17 = op;
                e->unk44 = p;
                continue;
            case 0x83:
                if (e->unk17 != 0) {
                    e->unk17 = e->unk17 - 1;
                    if (e->unk17 == 0) {
                        p++;
                        continue;
                    }
                }
                if ((op & 0xFFFFFF) != 0) {
                    goto pend83;
                }
                p = e->unk44;
                continue;
            case 0x85:
                if (e->unk17 != 0) {
                    e->unk17 = e->unk17 - 1;
                    if (e->unk17 == 0) {
                        p++;
                        e->unk50 = 0;
                        e->unk52 = 0;
                        continue;
                    }
                }
                e->unk52 = e->unk52 + (s8)op * 16;
                e->unk50 = e->unk50 + (s8)(op >> 8);
                mask = op & 0xFF0000;
                if (mask != 0) {
                    goto pend85;
                }
                p = e->unk44;
                continue;
            case 0x84:
                p++;
                e->unk1C[0].act = 1;
                e->unk1C[0].step = op >> 8;
                n84 = op & 0x7F;
                e->unk1C[0].tgt = (n84 * 16383) >> 7;
                continue;
            case 0x86:
                n86 = op & 0x7F;
                x86 = (n86 * 16383) >> 7;
                p++;
                e->unk1C[0].act = 0;
                e->unk1C[0].tgt = x86;
                e->unk1C[0].cur = x86;
                continue;
            case 0x87:
                for (i = 0; i < 8; i++) {
                    if (e->unk3A[i] != 0) {
                        goto set36;
                    }
                }
                e->unk00 = 0;
                return;
            }
        }
    done:
        e->unk0C = p;
        cmd = &rec;
    } else {
        cmd = (Cmd388C *)e->unk0C;
    }

    if (cmd->unk06 == 0) {
        goto after;
    }
    vi = func_80030CA4(cmd->unk04);
    if (vi == 0) {
        goto after;
    }
    lvl = cmd->unk0A;
    vi = vi - 1;
    if ((lvl & 0x80) == 0) {
        bank = D_800C5328[lvl * 2];
    } else {
        bank = 4;
    }
    if (bank < 0) {
        goto after;
    }
    ch = (Chan388C *)(D_800A4988 + vi * 0x54);
    vo = (Voice388C *)(D_800A4988 + 0x2A0 + vi * 0x48);
    if ((lvl & 0x80) == 0) {
        b = &D_8006A970[bank][cmd->unk0B];
        vo->unk1C = b->unk00;
        vo->unk18 = b->unk04;
        vo->unk3A = b->unk06;
        vo->unk3C = b->unk08;
    } else {
        if (func_8003F144(D_800A46A2, lvl & 0x7F, cmd->unk0B, &sp28) != 0) {
            goto after;
        }
        res = func_8003F380(D_800A46A2, sp28.unk16);
        if (res < 0) {
            goto after;
        }
        b04 = sp28.unk04;
        vo->unk1C = res;
        vo->unk18 = b04 << 8;
        vo->unk3A = sp28.unk10;
        vo->unk3C = sp28.unk12;
    }

    vo->unk44 = 1;
    vo->unk40 = ch->unk0A;
    vo->unk45 = 0;
    ch->unk4C = 0;
    ch->unk4A = 0x7FFF;
    ch->unk4D = 0;
    ch->unk00 = 0;
    ch->unk04 = 0;
    ch->unk08 = cmd->unk04;
    ch->unk0C = cmd->unk0B;
    ch->unk0E = lvl;
    ch->unk36 = 0;
    ch->unk10 = bank;
    ch->unk14 = cmd->unk10;
    tmp9 = cmd->unk09;
    __asm__ __volatile__("" : "=r"(tmp9) : "0"(tmp9));
    lvl = tmp9;
    ch->unk35 = lvl;
    ch->unk52 = lvl;
    if (e->unk38 != 0 && lvl != 0) {
        sum = lvl + e->unk38;
        if ((u8)sum < 0x42) {
            lvl = 1;
        } else {
            lvl = sum - 0x40;
            if ((u8)lvl >= 0x80) {
                lvl = 0x7F;
            }
        }
    }

    t24 = cmd->unk06 + e->unk52;
    ch->unk40 = func_800342E8;
    ch->unk44 = arg1;
    ch->unk4E = 0x85;
    ch->unk53 = 0;
    ch->unk24 = t24;
    ch->unk12 = cmd->unk02;
    ch->unk4F = 0;
    ch->unk48 = 0;
    arg->unk3A[vi] = 1;
    func_800316F8((s32)ch);

    vo->unk00 = D_80073140[ch->unk0A];
    t18 = vo->unk18;
    base = (t18 & 0xFF00) + ((s8)t18 * 2);
    base -= 0x3C00;
    d = ch->unk24;
    d -= base;
    if (d >= 0x5300) {
        res2 = 0x3FFF;
    } else {
        q = D_8006AB30[d >> 8];
        q = q * (0x100 - (d & 0xFF));
        pr3 = D_8006AB32[d >> 8] * (d & 0xFF);
        res2 = (q + pr3) >> 8;
    }
    vo->unk14 = res2;

    amt = cmd->unk08;
    if (e->unk50 < amt) {
        amt = amt - e->unk50;
    } else {
        amt = 0;
    }
    if (D_800A4F1E != 0) {
        amt = amt * 112;
        amt = amt >> 7;
    }
    ch->unk34 = amt;
    m = D_8006AA30[amt];
    m = m * D_800A4EFA;
    m = m >> 7;
    if (e->unk16 != 0) {
        m = m * e->unk18;
        m = m >> 15;
    }
    r = e->unk1C;
    for (i = 0; i < 3; i++, r++) {
        m = m * r->cur;
        m = m >> 14;
    }
    lv = lvl & 0xFF;
    if (lv != 0) {
        if (D_800A4F19 != 0) {
            tv = D_8007319E[lv];
            pr1 = m * tv;
            v = pr1 >> 14;
            vo->unk0A = v;
            pr2 = m * D_800731A0[0x7F - lv];
            v = pr2 >> 14;
            vo->unk08 = v;
        } else {
            v = (m * D_8007321E) >> 14;
            vo->unk0A = v;
            vo->unk08 = v;
        }
    } else {
        v = m;
        vo->unk08 = v;
        vo->unk0A = v;
    }
    vo->unk0C = 0;
    vo->unk0E = 0;
    vo->unk04 = 0x6009F;
    __asm__ __volatile__("");
    if (D_800A4EF6 > cmd->unk0C) {
        func_8002F064(1, vo->unk00);
    } else {
        func_8002F064(0, vo->unk00);
    }
    func_8002EFF8(1, vo->unk00);

after:
    if (cmd->unk00 == 0) {
        for (i = 0; i < 8; i++) {
            if (e->unk3A[i] != 0) {
                goto set36;
            }
        }
        e->unk00 = 0;
        return;
    }
    e->unk14 = cmd->unk00;
    if (e->unk48 != 0) {
        return;
    }
    if (cmd->unk0D == 0) {
        goto advance;
    }
    if (e->unk17 != 0) {
        e->unk17 = e->unk17 - 1;
        if (e->unk17 == 0) {
            goto advance;
        }
    }
    e->unk0C = (u32 *)((u8 *)arg->unk10 + (cmd->unk0D * 20 - 20));
    return;
pend83:
    e->unk14 = op;
    e->unk0C = e->unk44;
    return;
pend85:
    e->unk14 = mask >> 16;
    e->unk0C = e->unk44;
    return;
set36:
    e->unk36 = 1;
    return;
advance:
    cmd++;
    e->unk0C = (u32 *)cmd;
}
