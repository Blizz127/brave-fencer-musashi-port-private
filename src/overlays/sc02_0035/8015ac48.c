/* SC02.CD member35 [8015AC48,8015AC90): twin of main_0012 8015AC48 (src/overlays/main_0012/8015ac48.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_80186B00;
void func_80154150();
void func_80146DB8();
void func_80161CD0();
typedef struct { u8 pad_0[366]; u16 f16E; } T;
void func_8015AC48(T *p) {
    func_80154150(p, 9);
    func_80146DB8(p, &D_80186B00);
    func_80161CD0(p, p->f16E);
}
