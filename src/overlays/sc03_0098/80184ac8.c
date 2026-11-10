/* sc03_0098: func_80184AC8 - spawn-init: take an effect slot, copy the owner's heading, nudge the position back along it.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801A18EC[], D_801A1904[], D_801A191C[];
extern void *func_8012C1B8();
extern void func_8012CAE4();
extern void func_8001CA1C();
extern void func_8012A828();
extern void func_8012B23C();
extern void func_8012B2CC();
extern void func_8012B14C();
extern s32 func_8004787C();
extern s32 func_80047948();
typedef struct { u8 pad[0x12]; u16 h12; } Eff;
typedef struct Obj Obj;
struct Obj {
    u16 act; u16 kind; u8 pad4[2]; u16 x; u8 p8[2]; u16 y; u8 pc[2]; u16 z; u8 p10[0x10]; Eff *p20;
    u8 pad24[0x40]; Obj *w64;
};
void func_80184AC8(Obj *p) {
    Eff *e;
    e = func_8012C1B8(p);
    p->p20 = e;
    if (e == 0) {
        func_8012CAE4(p);
        return;
    }
    func_8001CA1C(e, D_801A18EC);
    func_8012A828(p, D_801A1904);
    p->p20->h12 = p->w64->p20->h12;
    func_8012B23C(p);
    func_8012B2CC(p);
    func_8012B14C(p, D_801A191C);
    p->kind = 1;
    p->y = p->y - 144;
    p->x = p->x - (func_8004787C((s16)p->p20->h12) >> 8);
    p->z = p->z - (func_80047948((s16)p->p20->h12) >> 8);
}
