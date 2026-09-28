/* Exact retail word export for [80030A14,80030CA4); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80030A14 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
     u8 *unk00;
     u8  pad04[2];
     u8  unk06;
     u8  unk07;
     u8  unk08;
     u8  pad09[3];
} A12;
typedef struct {
     s32 unk00;
     s16 unk04;
     s16 unk06;
     s16 unk08;
     u8  unk0A;
     u8  unk0B;
} B12;
typedef struct {
     u8  pad00[4];
     u8  unk04;
     u8  pad05[11];
     u16 unk10;
     u16 unk12;
     u8  pad14[2];
     s16 unk16;
     u8  pad18[8];
} C24;
extern s32  func_80030A14(void);
extern s16 D_800A46CC;
extern s16 D_800A46CE[];
extern s16 D_800A46D0;
extern s16 D_800A46D2[];
extern s16 D_800A4644[];
extern s16 D_800A4646[];
extern s16 D_800A4648[];
extern u8  D_800A4650[];
extern s16 D_800C5328[];
extern s16 D_800C532A[];
extern A12  D_80064D44[];
extern B12 *D_8006A970[];
extern s32 D_800760F0;
extern s32 D_800760F4;
extern s16 func_80042374(s32);
extern s16 func_8003F144(s32, s32, s32, C24 *);
extern s32 func_8003F380(s32, s32);

s32 func_80030A14(void) {
    C24 sp10;
    A12 *e;
    u8 *p;
    B12 *q;
    s32 count;
    s32 i;
    s32 r;
    s32 t;

    if (func_80042374(0) == 0) {
        return 0;
    }

    e = &D_80064D44[D_800A46D0];
    p = e->unk00 + D_800760F0 * 2;
    q = &D_8006A970[D_800A46CE[0]][D_800760F0];
    t = D_800A46CE[0] * 24;

    if (D_800760F4 < 11) {
        if (e->unk06 != 0) {
            *(s16 *)((u8 *)D_800A4646 + t) = e->unk07;
            D_800A4644[D_800A46CE[0] * 12] = e->unk06;
            D_800A4648[D_800A46CE[0] * 12] = e->unk08;
            D_800C532A[e->unk08 * 2] = D_800A46CE[0];
        }
        count = D_800760F4;
        D_800760F4 = 0;
        D_800C5328[D_800A46D0 * 2] = D_800A46CE[0];
    } else {
        count = 10;
        D_800760F4 -= 10;
    }

    for (i = 0; i < count; i++, p += 2, q++) {
        if (func_8003F144(D_800A46D2[0], p[0], p[1], &sp10) == 0) {
            r = func_8003F380(D_800A46D2[0], sp10.unk16);
            if (r >= 0) {
                q->unk0A = 1;
                q->unk04 = sp10.unk04 << 8;
                q->unk00 = r;
                q->unk06 = sp10.unk10;
                q->unk08 = sp10.unk12;
            }
        }
    }

    if (D_800760F4 == 0) {
        D_800A4650[D_800A46CE[0] * 24] = 0;
        D_800A46CC = 0;
        return 1;
    }

    D_800760F0 += 10;
    return 0;
}
