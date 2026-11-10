/* sc03_0098: func_80182864 - advance an object's timed script table.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern void func_800183E0();
typedef struct { u8 pad[204]; s32 *w204; s32 *w208; u8 pad212[0xC]; s32 w224; } Obj;
void func_80182864(Obj *p) {
    s32 *v;
    s32 f;
    if (p->w224 == 0) {
        return;
    }
    p->w224 = p->w224 - 1;
    if (p->w224 > 0) {
        return;
    }
    v = p->w208;
    v += 2;
    f = *v;
    if (f & 0x40000000) {
        v = p->w204;
    } else if (f < 0) {
        p->w224 = 0;
        return;
    }
    p->w224 = v[0];
    p->w208 = v;
    func_800183E0(v[1]);
}
