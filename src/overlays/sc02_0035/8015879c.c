/* SC02.CD member35 [8015879C,80158814): twin of main_0012 8015879C (src/overlays/main_0012/8015879c.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8015879C (main_0012.s): NOT verified
 * against retail. C89-gated only; promotion requires an oracle MATCH.
 * m2c shape: arg0->unkA8 on a void*. The disassembly stores it as a
 * BYTE (sb $zero, 0xA8), so the model declares one u8 at +0xA8 — a
 * word member would miscompile. The three globals are word stores
 * (sw %lo(...)); D_801BD770 was missing from the draft's declarations
 * and is added per the repo pipeline convention. Body is m2c's
 * verbatim. */

struct data_8015879C {
    u8 pad[0xA8];
    u8 unkA8;
};

extern s32 D_801BD770;
extern s32 D_801BD77C;
extern s32 D_801BD780;
void func_80146C98(void *, s32);
void func_80147078(void *, s32);
void func_80147084();
void func_80147098(void *);
void func_801470AC(void *);
void func_80158880(void *);

void func_8015879C(struct data_8015879C *arg0) {
    D_801BD770 = 0;
    D_801BD77C = 1;
    D_801BD780 = 0;
    arg0->unkA8 = 0;
    func_80147084();
    func_80147098(arg0);
    func_801470AC(arg0);
    func_80147078(arg0, 0x1A);
    func_80146C98(arg0, 1);
    func_80158880(arg0);
}
