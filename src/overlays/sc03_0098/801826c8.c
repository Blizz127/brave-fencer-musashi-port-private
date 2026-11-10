/* sc03_0098: func_801826C8 - orient a rotation matrix toward the peer and transform an offset vector.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
typedef struct { s32 w[8]; } M;
extern M D_800AE620;
extern s32 func_8012B6D4();
extern void func_8004A0DC();
extern void func_800484EC();
typedef struct { u16 act; } Peer;
typedef struct { u8 pad[0x10]; u8 v10[1]; u8 pad11[0x1B]; Peer *w2c; } Obj;
s32 func_801826C8(Obj *p, s32 a1) {
    s32 c[4];
    M m;
    s32 v[3];
    Peer *q = p->w2c;
    if (q->act == 0) {
        return 0;
    }
    m = D_800AE620;
    func_8004A0DC(func_8012B6D4((u8 *)p + 4, (u8 *)q + 4), &m);
    v[1] = 0;
    v[0] = 0;
    v[2] = a1;
    func_800484EC(&m, v, p->v10);
    return 1;
}
