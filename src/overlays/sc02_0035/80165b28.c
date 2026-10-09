/* SC02.CD member35 [80165B28,80165B6C): twin of main_0012 80165B28 (src/overlays/main_0012/80165b28.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801873A4[];
typedef struct { u8 pad[0x44]; u32 flags; u8 pad2[0x197-0x48]; u8 idx; } T;
void func_80165B28(T *p) {
    p->flags |= 8;
    D_801873A4[p->idx]();
}
