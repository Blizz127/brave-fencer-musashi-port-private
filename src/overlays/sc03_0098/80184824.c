/* sc03_0098: func_80184824 - countdown, then release into state 1 when the shared check reports a hit.
 * Hand-recovered from the retail words (gcc-2.7.2 -O2). */
#include "psx_types.h"
extern s32 func_8012CBCC();
typedef struct { u16 act; u16 kind; u8 pad4[0xF8]; s16 hfc; } Obj;
void func_80184824(Obj *p) {
    if (p->hfc != 0) {
        p->hfc = p->hfc - 1;
    } else if ((func_8012CBCC(p) & 0x6000) != 0) {
        p->kind = 1;
    }
}
