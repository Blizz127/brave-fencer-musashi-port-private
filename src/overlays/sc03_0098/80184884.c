/* sc03_0098: func_80184884 - trigger poll: on a hit start the cutscene hand-off, otherwise fall back to state 3.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801A1854[], D_801A185C[], D_801AE344[], D_801AEAC4[];
extern u16 D_80126B96, D_80126B98;
extern void *D_80127078;
extern s32 func_8012DEB8();
extern void func_8012A828();
typedef struct { u16 act; u16 kind; u8 pad4[0xF8]; u16 hfc; u16 hfe; } Obj;
void func_80184884(Obj *p) {
    if (func_8012DEB8(p, D_801A1854, D_801A185C) == 1) {
        D_80126B96 = 0x400F;
        D_80126B98 = 0;
        D_80127078 = p;
        p->kind = 16;
        func_8012A828(p, D_801AE344);
    } else {
        func_8012A828(p, D_801AEAC4);
        p->kind = 3;
        p->hfc = 0;
        p->hfe = 1;
    }
}
