/* sc03_0098: func_80184C38 - spawn-init (variant): also randomise the script index and flag the effect.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801A1934[], D_801A19F4[], D_801A1A7C[];
extern void *func_8012C1B8();
extern void func_8012CAE4();
extern void func_8001CA1C();
extern void func_8012A828();
extern void func_8012B23C();
extern void func_8012B2CC();
extern void func_8012B14C();
extern s32 func_8005C49C();
extern s32 func_8004787C();
extern s32 func_80047948();
typedef struct { u8 pad[0x12]; u16 h12; u8 pad14[0x18]; u16 h2c; } Eff;
typedef struct Obj Obj;
struct Obj {
    u16 act; u16 kind; u8 pad4[2]; u16 x; u8 p8[2]; u16 y; u8 pc[2]; u16 z; u8 p10[0x10]; Eff *p20;
    u8 pad24[0x40]; Obj *w64; u8 pad68[0x2C]; s32 w94;
};
void func_80184C38(Obj *p) {
    Eff *e;
    e = func_8012C1B8(p);
    p->p20 = e;
    if (e == 0) {
        func_8012CAE4(p);
        return;
    }
    func_8001CA1C(e, D_801A1934);
    func_8012A828(p, D_801A19F4);
    p->w94 = func_8005C49C() & 0xF;
    p->p20->h12 = p->w64->p20->h12;
    func_8012B23C(p);
    func_8012B2CC(p);
    func_8012B14C(p, D_801A1A7C);
    p->kind = 1;
    p->p20->h2c |= 0x10;
    p->y = p->y - 144;
    p->x = p->x - (func_8004787C((s16)p->p20->h12) >> 8);
    p->z = p->z - (func_80047948((s16)p->p20->h12) >> 8);
}
