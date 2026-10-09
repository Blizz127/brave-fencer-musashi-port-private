/* SC02.CD member35 [8015EE7C,8015EEE0): twin of main_0012 8015EE7C (src/overlays/main_0012/8015ee7c.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_800D4C48;
extern s32 D_80186B50;
void func_8014CBF8();
void func_801474EC();
void func_80154274();
void func_80146DB8();
void func_801477E8();
void func_80146CA0();
void func_8015EE7C(void *p) {
    func_8014CBF8(p);
    func_801474EC(p);
    func_80154274(p, &D_800D4C48);
    func_80146DB8(p, &D_80186B50);
    func_801477E8(p, 0xFFF40000);
    func_80146CA0(p);
}
