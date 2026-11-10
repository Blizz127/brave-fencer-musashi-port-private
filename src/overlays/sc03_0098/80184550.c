/* sc03_0098: func_80184550 - object tick: trigger cue 415/423 on script 23, return to idle when flagged.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern u8 D_801ADA9C[];
extern void func_8002D4C8();
extern void func_8012C588();
extern void func_8012A828();
typedef struct {
    u16 act; u16 kind; u8 pad4[0x30]; u16 h34; u8 pad36[0x3A]; s16 sel; u16 h72; u8 pad74[0x1E];
    s32 w94; u8 pad98[0x64]; u16 hfc; u16 hfe;
} Obj;
void func_80184550(Obj *p) {
    if (p->w94 == 23) {
        if (p->sel == 2) {
            func_8012C588(423, p);
        } else {
            func_8002D4C8(3251, 0);
            func_8012C588(415, p);
        }
    }
    if ((p->h72 & 0x4000) != 0) {
        func_8012A828(p, D_801ADA9C);
        p->kind = 3;
        p->hfc = 0;
        p->hfe = 0;
    }
}
