/* sc03_0098: func_80183E78 - ground probe at the object; choose the next state from the current script.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801AD404[], D_801AD1FC[], D_801ADFBC[], D_801AEAC4[];
extern s32 func_8012CEB0();
extern void func_80131E00();
extern void func_8012A828();
typedef struct {
    u16 act; u16 kind; u8 pad4[2]; u16 x; u8 p8[2]; u16 y; u8 pc[2]; u16 z; u8 p10[0x24];
    u16 h34; u8 pad36[0x26]; u16 h5c; u8 pad5e[0x32]; u8 *w90; u8 pad94[0x38]; u8 *wcc; u8 padd0[0x2C];
    u16 hfc; s16 hfe; u16 f100;
} Obj;
void func_80183E78(Obj *p) {
    s16 a[4];
    s16 b[4];
    b[0] = a[0] = p->x;
    b[1] = a[1] = p->y;
    b[2] = a[2] = p->z;
    a[1] = a[1] - 8;
    b[1] = b[1] + 8;
    if ((func_8012CEB0(a, b, 0) & 0x1F) != 0) {
        p->f100 |= 0x8000;
        func_80131E00(p, 6);
        return;
    }
    if (p->w90 == D_801AD404) {
        func_8012A828(p, D_801AD1FC);
        p->kind = 20;
        p->h34 = 1;
        p->hfe = 0;
        p->wcc = D_801ADFBC;
    } else {
        if (p->hfe != 0) {
            func_8012A828(p, D_801AEAC4);
        } else {
            func_8012A828(p, D_801ADFBC);
        }
        p->kind = 1;
    }
    p->hfc = 0;
    p->h5c = 0xAA10;
}
