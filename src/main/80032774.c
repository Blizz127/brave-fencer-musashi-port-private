/* Exact retail word export for [80032774,80032A74); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80032774 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct Rec14 {
     u16 unk00;
     u16 unk02;
     u32 unk04;
     u32 unk08;
     u16 unk0C;
     u16 unk0E;
     u32 unk10;
} Rec14;
typedef struct Owner4EE8 {
     u8 pad00[0x14];
     Rec14 **unk14;
} Owner4EE8;
typedef struct Slot54 {
     s16 unk00;
     s16 unk02;
     s16 unk04;
     s16 unk06;
     u16 unk08;
     s8  unk0A;
} Slot54;
extern s32  func_80032774(u32, u8 *, u32);
typedef struct Slot54View {
     u16 unk00;
     s16 unk02;
     u16 unk04;
     u16 unk06;
     u16 unk08;
     s8  unk0A;
     u8  unk0B;
     u8  pad0C[0x48];
} Slot54View;
extern Rec14 *D_80068304[];
extern Owner4EE8 *D_800A4EE8;
extern s16 D_800A4EF0;
extern u16 D_800A46E8[];
#define SLOTS ((Slot54View *)D_800A46E8)
#define PFLAG ((s8 *)((u8 *)D_800A46E8 + 0x82F))
extern s32 func_8003310C(s32);
extern void func_800335B8(s32, s32);
extern void func_8003324C(s32);
extern void func_80032A74(Slot54 *, s32, Rec14 *, s32);

s32 func_80032774(u32 arg0, u8 *p, u32 flags)
{
    Rec14 *rec;
    Slot54View *e;
    Slot54View *q;
    s32 ret;
    s32 best;
    s32 cnt;
    s32 i;
    s32 mn;
    s32 mx;
    s32 t;
    s32 yy;
    s32 f4000;
    u32 x;
    u16 y;
    u16 v;
    u8 old;
    u8 b0;
    u8 b1;
    u8 b2;
    s32 b3;

    b2 = p[2];
    b1 = p[1];
    b3 = p[3];
    mx = 0;
    y = arg0 >> 16;
    x = arg0;

    if (b1 == 0) {
        rec = &D_80068304[b2][b3];
    } else {
        if (D_800A4EF0 != b1) {
            return 0;
        }
        if (D_800A4EE8 == 0) {
            return 0;
        }
        rec = D_800A4EE8->unk14[b2];
        rec += b3;
    }

    yy = y;
    ret = 0;
    best = 0;
    cnt = 0;
    old = *PFLAG;
    *PFLAG = 1;
    q = SLOTS;
    mn = 0x80;
    v = rec->unk00;
    for (i = 0, f4000 = flags & 0x4000; i < 8; i++, q++) {
        if ((q->unk00 & 0x3F) == 1 && q->unk04 == (u16)x) {
            if (yy == 0 || q->unk06 == yy) {
                if (f4000) {
                    func_800335B8(i, (u16)flags);
                }
                goto done;
            }
            t = q->unk0B & 0x7F;
            if (t < mn) {
                best = i + 1;
                mn = t;
            }
            if (mx <= t) {
                mx = t;
            }
            cnt++;
        }
    }

    if (cnt < 2) {
        best = 0;
    } else if ((s32)(flags & 0x7F) < mn) {
        goto done;
    }

    if (best == 0) {
        if (flags & 0x4000) {
            if ((flags & 0x3000) == 0) {
                goto done;
            }
        }
        best = func_8003310C(v);
        if (best == 0) {
            goto done;
        }
        ret = best;
        best = ret - 1;
        e = &SLOTS[best];
    } else {
        ret = best;
        best = ret - 1;
        e = &SLOTS[best];
        if (e->unk08 != 0) {
            goto done;
        }
        func_8003324C((u16)best);
    }

    if (flags & 0x1000) {
        e->unk0B = flags & 0x7F;
        if ((s32)(flags & 0x7F) < mx) {
            flags |= 0x8000;
        }
    }

    b0 = p[0];
    e->unk04 = x;
    e->unk06 = y;
    e->unk02 = v;
    e->unk00 = (b0 & 0xC0) | 1;
    e->unk08 = rec->unk0C;
    e->unk0A = 5;
    func_80032A74((Slot54 *)e, best, rec, (u16)flags);

done:
    *PFLAG = old;
    return ret;
}
