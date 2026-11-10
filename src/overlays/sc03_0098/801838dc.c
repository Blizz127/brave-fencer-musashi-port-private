/* sc03_0098: func_801838DC - object step: steer toward the player on the ground plane, hold a vertical band.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern s32 D_80126B5C;
extern s32 D_80126B64;
extern s16 D_80126B62;
extern s32 func_8012B8E4();
extern void func_8012B1B4();
extern void func_8012CBCC();
typedef struct { u8 pad[0x12]; u16 h12; } Eff;
typedef struct {
    u16 act; u16 kind; s32 w4; u8 pad8[2]; s16 y; s32 wc; u8 pad10[0x10]; Eff *p20; u8 pad24[0x70];
    s32 w94; u16 h98;
} Obj;
void func_801838DC(Obj *p) {
    s32 v[4];
    s32 k = 10;
    s32 d;
    if (p->w94 == k) {
        p->h98 = 0;
    }
    p->p20->h12 = p->p20->h12 + func_8012B8E4(p, 4);
    p->p20->h12 = p->p20->h12 & 0xFFF;
    v[0] = 0;
    v[1] = 0;
    d = p->w4 - D_80126B5C;
    v[2] = d;
    if (d > 0) {
        v[2] = -d;
    }
    d = p->wc - D_80126B64;
    v[3] = d;
    if (d > 0) {
        v[3] = -d;
    }
    v[2] = (v[2] + v[3]) >> 4;
    func_8012B1B4(p, v);
    if (p->y <= D_80126B62 - 10) {
        p->y = p->y + 8;
    } else if (p->y >= D_80126B62) {
        p->y = p->y - 8;
    } else if (p->w94 == k) {
        p->kind = 11;
        p->h98 = 1;
    }
    func_8012CBCC(p);
}
