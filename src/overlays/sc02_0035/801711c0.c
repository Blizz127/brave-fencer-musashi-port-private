/* SC02.CD member35 [801711C0,801711FC): twin of main_0012 801711C0 (src/overlays/main_0012/801711c0.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187A30[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801711C0(T *p) {
    D_80187A30[p->idx](p);
}
