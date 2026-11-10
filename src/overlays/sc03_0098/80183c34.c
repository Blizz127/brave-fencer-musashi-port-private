/* sc03_0098: func_80183C34 - dispatch, then probe 64 units below; release the object on a hit.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern void (*D_801A1928[])(void *);
extern s32 func_8012D624();
extern void func_8012C218();
extern void func_8012B370();
typedef struct { u8 pad[0x18]; u16 h18; } Eff;
typedef struct { u16 act; u16 kind; u8 pad4[6]; u16 y; u8 padc[0x12]; Eff *p20; } Obj;
void func_80183C34(Obj *p) {
    D_801A1928[p->kind](p);
    if (p->act != 0) {
        p->y = p->y - 64;
        if (func_8012D624(p, (s16)p->p20->h18 >> 8, 20) == 1) {
            func_8012C218(p);
        } else {
            p->y = p->y + 64;
            func_8012B370(p);
        }
    }
}
