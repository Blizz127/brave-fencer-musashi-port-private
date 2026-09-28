/* Exact retail word export for [80032048,800322A8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80032048 - byte-exact against retail at -O2 (tools/register_match.py). */

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
extern s32  func_80032048(u32, u8 *, u32);
extern Rec14 *D_80068304[];
extern Owner4EE8 *D_800A4EE8;
extern s16 D_800A4EF0;
extern u16 D_800A46E8[];
extern s8 D_800A4F17;
extern s32 func_800331D4(s32);
extern s32 func_8003310C(s32);
extern void func_800335B8(s32, s32);
extern void func_8003324C(s32);
extern void func_80032A74(Slot54 *, s32, Rec14 *, s32);

s32 func_80032048(u32 arg0, u8 *p, u32 flags) {
    Rec14 *rec;
    Slot54 *e;
    s32 idx;
    s32 ret;
    u32 x;
    u32 y;
    u32 v;
    u8 old;
    u8 b1;
    u8 b2;
    u32 b3;
    u32 b0;

    y = arg0 >> 16;
    b1 = p[1];
    b2 = p[2];
    b3 = p[3];

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

    old = *(u8 *)&D_800A4F17;
    *(u8 *)&D_800A4F17 = 1;

    ret = 0;
    v = rec->unk00;
    if ((u16)flags == 0xFFFF) {
        flags = 0;
        x = (u16)y;
        y = 0;
    } else {
        x = arg0;
    }

    idx = func_800331D4(x);
    if (idx == 0) {
        if (flags & 0x4000) {
            if ((flags & 0x3000) == 0) {
                goto done;
            }
        } else if (flags & 0x1000) {
            if ((flags & 0x7F) < 0x30) {
                v >>= 1;
            }
        }
        idx = func_8003310C(v);
        if (idx == 0) {
            goto done;
        }
        ret = idx;
        idx = ret - 1;
        e = (Slot54 *)((u8 *)D_800A46E8 + idx * 0x54);
    } else {
        if (flags & 0x4000) {
            func_800335B8(idx - 1, (u16)flags);
            goto done;
        }
        idx--;
        e = (Slot54 *)((u8 *)D_800A46E8 + idx * 0x54);
        if (e->unk08 != 0) {
            goto done;
        }
        ret = idx + 1;
        func_8003324C((u16)idx);
    }

    b0 = p[0];
    e->unk04 = x;
    e->unk06 = y;
    e->unk02 = v;
    e->unk00 = (b0 & 0xC0) | 1;
    e->unk08 = rec->unk0C;
    e->unk0A = 5;
    func_80032A74(e, idx, rec, (u16)flags);

done:
    *(u8 *)&D_800A4F17 = old;
    return ret;
}
