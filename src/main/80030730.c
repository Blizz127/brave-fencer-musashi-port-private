/* Exact retail word export for [80030730,80030A14); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80030730 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    s32 unk14;
} Rsc24;
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
extern s32  func_80030730(void);
typedef struct {
    u8  unk00[4];
    u8  unk04;
    u8  unk05[11];
    u16 unk10;
    u16 unk12;
    u8  unk14[2];
    s16 unk16;
    u8  unk18[8];
} Blk28;
extern u8    D_8006AEF4;
extern s16   D_800A46CC;
extern s16   D_800A46CE[];
extern s16   D_800A46D2[];
extern Rsc24 D_800A4640[];
extern A12   D_80064D44[];
extern s32   D_80065504[];
extern B12 *D_8006A970[];
extern s32   D_800760F0;
extern s32   D_800760F4;
extern s16   D_800C5328[];
extern s16   D_800C532A[];
extern s16  func_80042374(s32);
extern void func_80037D74(void);
extern s16  func_8003F144(s32, s32, s32, C24 *);
extern s32  func_8003F380(s32, s32);

s32 func_80030730(void) {
    Blk28 sp10;
    A12 *e;
    B12 *p;
    u8 *q;
    s16 *pd;
    s16 *pcc;
    s32 n;
    s32 n0;
    s32 k;
    s32 i;
    s32 res;

    if (func_80042374(0) == 0) {
        return 0;
    }
    D_8006AEF4 &= 0xFC;
    func_80037D74();

    k = D_800A46CE[0] * 24;
    D_800760F0 = 0;
    e = &D_80064D44[D_800A46CE[1]];
    n0 = e->pad04[0];
    D_800760F4 = n0;
    if (n0 == 0) {
        *(u8 *)((u8 *)D_800A4640 + k + 0x10) = 0;
        D_800A46CC = 0;
        return 1;
    }
    q = e->unk00;
    if (D_80065504[D_800A46CE[0]] < n0) {
        D_800760F4 = D_80065504[D_800A46CE[0]];
    }
    p = D_8006A970[D_800A46CE[0]];
    n = 10;
    if (D_800760F4 < 11) {
        if (e->unk06 != 0) {
            *(s16 *)((u8 *)D_800A4640 + k + 0x06) = e->unk07;
            D_800A4640[D_800A46CE[0]].unk04 = e->unk06;
            D_800A4640[D_800A46CE[0]].unk08 = e->unk08;
            D_800C532A[e->unk08 * 2] = D_800A46CE[0];
        }
        n = D_800760F4;
        D_800760F4 = 0;
        D_800C5328[D_800A46CE[1] * 2] = D_800A46CE[0];
    } else {
        D_800760F4 -= 10;
    }

    for (i = 0; i < n; i++, q += 2, p++) {
        pd = D_800A46D2;
        if (func_8003F144(*pd, q[0], q[1], (C24 *)&sp10) == 0) {
            res = func_8003F380(*pd, sp10.unk16);
            if (res >= 0) {
                p->unk0A = 1;
                p->unk04 = sp10.unk04 << 8;
                p->unk00 = res;
                p->unk06 = sp10.unk10;
                p->unk08 = sp10.unk12;
            }
        }
    }

    if (D_800760F4 == 0) {
        D_800A4640[D_800A46CE[0]].unk10 = 0;
        D_800A46CC = 0;
        return 1;
    }
    pcc = &D_800A46CC;
    D_800760F0 = D_800760F0 + 10;
    (*pcc)++;
    return 0;
}
