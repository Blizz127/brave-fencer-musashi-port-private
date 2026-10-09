/* SC02.CD member35 [801705F8,80170634): twin of main_0012 801705F8 (src/overlays/main_0012/801705f8.c); only the
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
extern CB D_801879C8[];
typedef struct { u8 pad[534]; u8 idx; } T;
void func_801705F8(T *p) {
    D_801879C8[p->idx](p);
}
