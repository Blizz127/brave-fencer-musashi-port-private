/* sc03_0098: func_801822AC - object wait step: run the shared tick, switch state when its counter is zero.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern void func_801827A0();
typedef struct { u16 act; u16 kind; u8 pad4[0x18]; s32 w1c; u8 pad20[0x10]; s32 w30; } Obj;
void func_801822AC(Obj *p) {
    func_801827A0(p);
    if (p->w30 == 0) {
        p->kind = 6;
        p->w1c = 0;
    } else {
        p->w1c = p->w1c + 1;
    }
}
