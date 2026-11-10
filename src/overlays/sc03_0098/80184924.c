/* sc03_0098: func_80184924 - leave the object in state 4, or restart it in state 3 once the shared test fails.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801AEAC4[];
extern s32 func_80153BD8();
extern void func_8012A828();
typedef struct { u16 act; u16 kind; u8 pad4[0xF8]; u16 hfc; } Obj;
void func_80184924(Obj *p) {
    if (func_80153BD8(p) == 0) {
        func_8012A828(p, D_801AEAC4);
        p->kind = 3;
        p->hfc = 0;
    } else {
        p->kind = 4;
    }
}
