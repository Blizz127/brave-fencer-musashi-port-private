/* sc03_0098: func_801828E4 - spawn follow-up actor 300 when the ground probe is clear; chain actor 303 spawns.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801A7970[];
extern u8 D_801AF0B4[];
extern void func_8002AC00();
extern s32 func_8012CEB0();
extern void func_8001C214();
extern void func_8012A828();
extern void *func_8012C658();
extern void func_8012C218();
extern void func_8012B030();
typedef struct { u8 pad[0x12]; u16 h12; } Eff;
typedef struct {
    u16 act; u16 pad2; u8 pad4[2]; u16 x; u8 p8[2]; u16 y; u8 pc[2]; u16 z; u8 p10[0x10]; Eff *p20;
    u8 pad24[0x4C]; s16 sel; u8 pad72[0x8C]; u16 fe; u16 f100;
} Obj;
void func_801828E4(Obj *p) {
    s16 a[4];
    s16 b[4];
    s32 s2;
    Obj *s0;
    func_8002AC00(13);
    if (p->act == 0) {
        return;
    }
    b[0] = a[0] = p->x;
    b[1] = a[1] = p->y;
    b[2] = a[2] = p->z;
    a[1] = a[1] - 8;
    b[1] = b[1] + 8;
    if ((func_8012CEB0(a, b, 0) & 0x1F) != 0) {
        return;
    }
    if (((s16)p->f100 & 0x8000) != 0) {
        return;
    }
    s2 = p->p20->h12;
    func_8001C214(p->p20, D_801A7970);
    func_8012A828(p, D_801AF0B4);
    p->p20->h12 = s2;
    s0 = func_8012C658(300, 1, p);
    if (s0 == 0) {
        return;
    }
    if ((s16)p->y >= 16) {
        func_8012C218(s0);
        return;
    }
    s0->p20->h12 = s2;
    func_8012B030(s0);
    if (p->sel == 5) {
        u16 t = p->f100;
        s0->sel = 6;
        s0->fe = 1;
        s0->f100 = t;
        do {
            func_8012C658(303, 5, s0);
            s0->fe += 3;
        } while ((s16)s0->fe < 16);
        s0->fe = 0;
    }
}
