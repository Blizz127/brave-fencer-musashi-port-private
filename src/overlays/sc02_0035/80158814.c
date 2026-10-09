/* SC02.CD member35 [80158814,80158880): twin of main_0012 80158814 (src/overlays/main_0012/80158814.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_801BD770;
extern s32 D_801BD77C;
extern s32 D_801BD780;
void func_80147084();
void func_80147098();
void func_801470AC();
void func_80147078();
void func_80158880();
typedef struct { u8 pad[0xA8]; u8 fA8; } T;
void func_80158814(T *p) {
    D_801BD770 = 0;
    D_801BD77C = 1;
    D_801BD780 = 0;
    p->fA8 = 0;
    func_80147084(p);
    func_80147098(p);
    func_801470AC(p);
    func_80147078(p, 0x1A);
    func_80158880(p);
}
