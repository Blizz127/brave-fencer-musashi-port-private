/* sc03_0098: func_80182300 - object chase step toward its peer, hit test at distance 64.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_800D3918[];
extern s32 func_801826C8();
extern void func_801292C8();
extern void func_801827A0();
extern s32 func_80182574();
extern s32 func_800132BC();
typedef struct { u8 pad[6]; u16 x; u8 p8[6]; u16 z; u8 p10[0x20]; s32 w30; } Peer;
typedef struct {
    u16 act; u16 kind; u8 pad4[2]; u16 x; u8 p8[6]; u16 z; u8 p10[4]; s32 w14; u8 pad18[4]; s32 w1c;
    u8 pad20[0xC]; Peer *w2c;
} Obj;
void func_80182300(Obj *p) {
    Peer *q;
    s16 a[4];
    s16 b[4];
    s16 c[8];
    if (func_801826C8(p, -98304) == 0) {
        func_801292C8(p);
        return;
    }
    q = p->w2c;
    p->w14 = 0x18000;
    if (p->w1c >= 336) {
        q->w30 = q->w30 - 1;
        func_801292C8(p);
        return;
    }
    func_801827A0(p);
    func_80182574(p, D_800D3918, 0);
    a[0] = p->x;
    a[1] = 0;
    a[2] = p->z;
    b[0] = q->x;
    b[1] = 0;
    b[2] = q->z;
    if (func_800132BC(a, b) < 65) {
        q->w30 = q->w30 - 1;
        p->kind = 5;
    }
    p->w1c = p->w1c + 1;
}
