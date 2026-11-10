/* sc03_0098: func_801821C8 - object state step (countdown, then release).
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_800D3918[];
extern s32 func_80182574();
extern void func_801292C8();
typedef struct { u8 pad[0x30]; s32 w30; } Peer;
typedef struct { u8 pad[0x27]; u8 b27; } Eff;
typedef struct {
    u16 act; u16 kind; u8 pad4[0x10]; s32 w14; u8 pad18[4]; s32 w1c; Eff *p20; u8 pad24[8]; Peer *w2c;
} Obj;
void func_801821C8(Obj *p) {
    s32 r;
    Peer *q;
    r = func_80182574(p, D_800D3918, 17);
    if ((r & 0xFF) == 0) {
        if (r & 0x2000) {
            if (p->w2c == 0) {
                goto done;
            }
            p->w1c = 30;
            p->kind = 4;
            return;
        }
        if (p->w1c < 35) {
            p->w14 += 0x10000;
            if (p->w2c != 0) {
                p->p20->b27 = 98;
            }
        }
        if (--p->w1c != 0) {
            return;
        }
    }
    q = p->w2c;
    if (q != 0 && q != (Peer *)-1) {
        q->w30 = q->w30 - 1;
    }
done:
    func_801292C8(p);
}
