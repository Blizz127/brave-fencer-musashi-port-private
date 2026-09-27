/* Overlay range [80165240,8016533C) from MAIN.CD member 0012.
 * SHA256(span)=08a0b072ab4dc8636ef76aa57b90290f8a2be04e6b67ca396560f1801bd47ead.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016ED4(void *, s32, s32, s32);    /* extern */
void func_80017DC4(s32, void *);          /* extern */
void func_80048FBC(void *, s32 (*)(), void *); /* extern */
extern s32 D_80180FB4;
extern s32 D_80180FD4;
extern s32 D_80180FD8;
extern s32 D_80180FDC;
extern s32 D_80180FE0;

void func_80165240(s32 arg1, void *arg2) {
    s32 sp50;
    s8 sp48;
    s32 sp44;
    s32 sp43;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp28;
    s32 sp20;
    s32 sp18;
    s16 sp14;
    s32 sp10;
    func_80017DC4(arg1, &sp50);
    func_80048FBC(&sp50, D_80180FB4, &sp10);
    func_80048FBC(&sp50, D_80180FB4 + 8, &sp18);
    func_80048FBC(&sp50, D_80180FB4 + 0x10, &sp20);
    func_80048FBC(&sp50, D_80180FB4 + 0x18, &sp28);
    sp14 = 3;
    sp48 = 0x2C;
    sp30 = D_80180FDC;
    sp34 = D_80180FD4;
    sp38 = D_80180FE0;
    sp3C = D_80180FD8;
    sp43 = M2C_UNALIGNED32(M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */));
    sp44 = 0x50000000;
    func_80016ED4(&sp10, D_80180FD4, D_80180FE0, D_80180FD8);
}
