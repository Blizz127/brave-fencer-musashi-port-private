/* sc03_0098: func_80183040 - orbiting object step: spin, probe the ground at 48 units out, react to distance.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801AE8BC[], D_801AE23C[], D_801AEAC4[];
extern void func_8012B1B4();
extern s32 func_8012B8E4();
extern s32 func_8012CBA4();
extern s32 func_8004787C();
extern s32 func_80047948();
extern s32 func_80133784();
extern s32 func_8012BCCC();
extern s32 func_8012BDBC();
extern s32 func_8005C49C();
extern void func_8012A828();
typedef struct { u8 pad[0x12]; u16 h12; } Eff;
typedef struct {
    u16 act; u16 kind; s32 w4, w8, wc; u8 p10[0x10]; Eff *p20; u8 pad24[0x14];
    s32 w38, w3c, w40; u8 pad44[0xB8]; u16 fc; u16 fe;
} Obj;
void func_80183040(Obj *p) {
    s32 v[3];
    s32 pad[4];
    s16 a[4];
    s16 b[4];
    s32 d;
    s32 r;
    p->fc = p->fc + 1;
    v[0] = 0;
    v[1] = 0;
    v[2] = -((s16)p->fc << 17) / 36;
    func_8012B1B4(p, v);
    p->p20->h12 = p->p20->h12 + func_8012B8E4(p, 16);
    p->p20->h12 = p->p20->h12 & 0xFFF;
    if ((func_8012CBA4(p) & 0x6000) == 0) {
        p->w4 = p->w38;
        p->w8 = p->w3c;
        p->wc = p->w40;
    }
    r = 48;
    a[0] = ((u16 *)p)[3] - ((func_8004787C(p->p20->h12 & 0xFFF) * r) >> 12);
    a[1] = ((u16 *)p)[5] - 32;
    a[2] = ((u16 *)p)[7] - ((func_80047948(p->p20->h12 & 0xFFF) * r) >> 12);
    b[0] = a[0];
    b[1] = a[1] + 96;
    b[2] = a[2];
    if ((func_80133784(1, a, b) & 0x6000) == 0) {
        p->w4 = p->w38;
        p->wc = p->w40;
    }
    d = func_8012BCCC(p);
    if (d <= 4096) {
        if (func_8012BDBC(p, 512) == 1) {
            if ((func_8005C49C() & 3) == 0) {
                func_8012A828(p, D_801AE8BC);
                p->kind = 5;
            } else {
                func_8012A828(p, D_801AE23C);
                p->kind = 15;
            }
        }
    }
    if (d > 0x40000) {
        func_8012A828(p, D_801AEAC4);
        p->kind = 1;
        p->fc = 0;
        p->fe = 1;
    }
    if ((s16)p->fc == 36) {
        p->fc = 0;
    }
}
