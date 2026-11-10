/* sc03_0098: func_801845E4 - object tick (variant): switch state when the shared test fails; on script 23 poll a trigger and play a cue.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801AE7B4[];
extern u8 D_801A1854[], D_801A185C[];
extern s32 func_80153BD8();
extern void func_80153BF0();
extern void func_8012A828();
extern s32 func_8012DEB8();
extern void func_8002D4C8();
extern void func_80153C74();
typedef struct {
    u16 act; u16 kind; u8 pad4[0x18]; s32 w1c; u8 pad20[0x14]; u16 h34; u8 pad36[0x3A]; u16 sel; u8 pad72[0x22];
    s32 w94;
} Obj;
void func_801845E4(Obj *p) {
    if (func_80153BD8(p) == 0) {
        func_80153BF0(p);
        func_8012A828(p, D_801AE7B4);
        p->h34 = 7;
        p->kind = 19;
        p->w1c = 30;
    }
    if (p->w94 == 23) {
        if (func_8012DEB8(p, D_801A1854, D_801A185C) == 1) {
            func_8002D4C8(3250, 0);
            if ((u32)(p->sel - 2) < 2) {
                func_80153C74(3, 24);
            } else {
                func_80153C74(1, 20);
            }
        }
    }
}
