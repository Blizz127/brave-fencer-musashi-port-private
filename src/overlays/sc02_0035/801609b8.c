/* SC02.CD member35 [801609B8,80160A28): twin of main_0012 801609B8 (src/overlays/main_0012/801609b8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186B6C[];
s32 func_801487F4();
void func_80160A74();
void func_80161208();
typedef struct { u16 idx; } T;
void func_801609B8(T *p) {
    if ((func_801487F4(p) & 8) == 0) {
        D_80186B6C[p->idx](p);
        func_80160A74(p);
    } else {
        func_80161208(p);
    }
}
