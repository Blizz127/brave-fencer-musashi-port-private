/* sc03_0098: func_80182A68 - scene object init, switch on its variant (0..5).
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
typedef struct { u8 b[52]; } E52;
extern E52 D_801A15DC[];
extern u8 D_801A1714[], D_801A17B4[], D_801A17FC[];
extern u8 D_801ADFBC[], D_801AD884[], D_801AEF34[], D_801AEDB4[];
extern s32 func_8012C354();
extern void func_8012CAE4();
extern void func_80143970();
extern void func_8012A828();
extern void func_8012B23C();
extern void func_8012B2CC();
extern s32 func_8005C49C();
extern void func_8012C658();
typedef struct {
    u16 act; u16 kind; u8 pad4[0x1C]; struct { u8 pad[0x12]; s16 h12; } *p20; u8 pad24[0x4C];
    s16 sel; u8 pad72[0x42]; s32 b4; u8 padb8[4]; u8 *bc; u8 c0; u8 padc1[0x3B];
    u16 fc; u16 fe; u16 f100;
} Obj;
void func_80182A68(Obj *p) {
    if (func_8012C354(p, &D_801A15DC[p->sel]) == 0) {
        func_8012CAE4(p);
        return;
    }
    p->c0 = 1;
    p->b4 = -1025;
    func_80143970(p);
    switch (p->sel) {
    case 0:
        func_8012A828(p, D_801ADFBC);
        p->kind = 1;
        func_8012B23C(p);
        {
            u16 t = p->fc;
            p->bc = D_801A1714;
            p->fc = 0;
            p->f100 = t;
        }
        break;
    case 2:
        {
            u16 t;
            func_8012A828(p, D_801AD884);
            t = p->fc;
            p->kind = 9;
            p->bc = D_801A17B4;
            p->f100 = t;
        }
        break;
    case 1:
    case 3:
        func_8012A828(p, D_801AEF34);
        p->kind = 6;
        p->bc = D_801A17FC;
        break;
    case 4:
        func_8012A828(p, D_801ADFBC);
        p->kind = 13;
        func_8012B23C(p);
        p->bc = D_801A1714;
        p->fc = 30;
        break;
    case 5:
        if (*(s16 *)&p->fc != 0) {
            func_8012A828(p, D_801AEDB4);
            p->kind = 14;
            p->p20->h12 = func_8005C49C() & 0xFFF;
        } else {
            func_8012A828(p, D_801ADFBC);
            p->kind = 1;
        }
        func_8012B23C(p);
        p->bc = D_801A1714;
        p->fe = 1;
        do {
            func_8012C658(303, 5, p);
            p->fe++;
        } while ((s16)p->fe < 6);
        p->fe = 0;
        break;
    }
    func_8012B2CC(p);
}
