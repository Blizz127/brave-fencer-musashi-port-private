/* Exact retail word export for [800324A4,80032774); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_800324A4 - byte-exact against retail at -O2 (tools/register_match.py). */

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
extern s32  func_800324A4(u32, u8 *, u32, s32);
s32 aF800301A4(void) __asm__("func_800301A4");
extern void func_800301A4(void);
extern Rec14 *D_80068304[];
extern Owner4EE8 *D_800A4EE8;
extern s16 D_800A4EF0;
extern u16 D_800A46E8[];
extern s8 D_800A4F17;
#define LOCKBYTE (*(u8 *)&D_800A4F17)
#define SLOTBASE ((u8 *)&D_800A4F17 - 0x82F)
extern s32 func_8003310C(s32);
extern void func_8003324C(s32);
extern void func_80032A74(Slot54 *, s32, Rec14 *, s32);

s32 func_800324A4(u32 arg0, u8 *p, u32 flags, s32 arg3) {
    Rec14 *rec;
    Slot54 *e;
    u8 *q;
    s32 i;
    s32 idx;
    s32 ret;
    s32 count;
    s32 minp;
    s32 maxp;
    s32 pr;
    u32 x;
    



    register u32 t __asm__("$4");
    u16 y;
    s32 v;
    u8 old;
    u8 b0;
    u8 b1;
    u8 b2;
    


    u32 b3;

    t = arg0;
    x = arg0;
    b2 = p[2];
    b1 = p[1];
    b3 = p[3];
    

    maxp = 0;
    y = t >> 16;

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

    ret = 0;
    idx = 0;
    count = 0;

    old = LOCKBYTE;
    LOCKBYTE = 1;

    v = rec->unk00;

    q = SLOTBASE;
    minp = 0x80;
    for (i = 0; i < 8; i++, q += 0x54) {
        if ((*(u16 *)q & 0x3F) == 1 && *(u16 *)(q + 4) == (u16)x) {
            pr = q[0xB] & 0x7F;
            if (pr < minp) {
                idx = i + 1;
                minp = pr;
            }
            if (pr >= maxp) {
                maxp = pr;
            }
            count++;
        }
    }

    if (count <= arg3) {
        idx = 0;
    } else if ((s32)(flags & 0x7F) < minp) {
        goto done;
    }

    if (idx == 0) {
        if (flags & 0x4000) {
            if ((flags & 0x3000) == 0) {
                goto done;
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
        idx--;
        e = (Slot54 *)((u8 *)D_800A46E8 + idx * 0x54);
        if (e->unk08 != 0) {
            goto done;
        }
        ret = idx + 1;
        func_8003324C((u16)idx);
    }

    if (flags & 0x1000) {
        ((u8 *)e)[0xB] = flags & 0x7F;
        if ((s32)(flags & 0x7F) < maxp) {
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
    func_80032A74(e, idx, rec, (u16)flags);

done:
    LOCKBYTE = old;
    return ret;
}
