/* SC02.CD member35 [80178840,801788B8): twin of main_0012 80178840 (src/overlays/main_0012/80178840.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80019064();
void func_80131E00();
extern s32 D_80187D14;
extern s32 D_80187D20[];
typedef struct { u8 pad[0x5C]; u16 u5C; u8 u5E; } T;
void func_80178840(T *p) {
    u8 n;
    if ((p->u5C & 1) == 0) {
        return;
    }
    n = p->u5E;
    if (n == 0xC) {
        func_80019064(&D_80187D14);
    }
    func_80131E00(p, D_80187D20[n]);
}
