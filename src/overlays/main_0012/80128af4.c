/* Overlay range [80128AF4,80128C14) from MAIN.CD member 0012.
 * SHA256(span)=c1e4d951e65138b64a458d2bfc71a0ab5e64c57d98e1e6f51dbdf76d8073322c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80010DE0();                                  /* extern */
void func_80011B7C();                                 /* extern */
void func_80011C10();                                  /* extern */
void func_8002AEF8();                                  /* extern */
s32 func_8002AF08();                                /* extern */
void func_800CFBBC();                                  /* extern */
s32 func_800CFBE8();                                /* extern */
void D_8017E360();                                     /* static */
void D_8017E364();                                     /* static */
extern s32 D_801840B0;
extern u16 D_800B99F6;

void func_80128AF4(void) {
    switch (D_800B99F6) {                           /* irregular */
    case 0:
        D_801840B0 = func_8002AF08();
        func_80011C10();
        return;
    case 1:
        D_8017E360();
        func_80011C10();
        return;
    case 2:
        if ((D_8017E364() << 0x10) != 0) {
            if (D_801840B0 == 1) {
                if (func_800CFBE8() != 0) {
                    func_800CFBBC();
                    func_80011B7C(0x13);
                } else {
                    func_80011B7C(4);
                }
            } else {
                func_80010DE0();
            }
            func_8002AEF8();
        }
        return;
    }
}
