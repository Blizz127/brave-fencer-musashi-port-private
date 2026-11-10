/* sc03_0098: func_80183CE0 - dispatch, then probe 64 units below; set a world flag and release on a hit.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern void (*D_801A1A88[])(void *);
extern u16 D_80126B96;
extern s32 func_8012D624();
extern void func_8012C218();
typedef struct { u16 act; u16 kind; u8 pad4[6]; u16 y; } Obj;
void func_80183CE0(Obj *p) {
    D_801A1A88[p->kind](p);
    if (p->act != 0) {
        p->y = p->y - 64;
        if (func_8012D624(p, 16, 22) == 1) {
            u16 *fp = &D_80126B96;
            *fp |= 0x200;
            func_8012C218(p);
        } else {
            p->y = p->y + 64;
        }
    }
}
