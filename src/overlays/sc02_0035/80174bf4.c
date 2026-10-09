/* SC02.CD member35 [80174BF4,80174C60): twin of main_0012 80174BF4 (src/overlays/main_0012/80174bf4.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80187B48[];
typedef struct {
    u8 pad[4];
    u8 idx;
    u8 pad5[7];
    s32 unkC;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[8];
    s16 unk20, unk22, unk24;
    u8 pad26[8];
    s16 unk2E, unk30, unk32;
    u8 pad34[0x20];
    s32 unk54;
} T;
void func_80174BF4(T *p) {
    p->unkC = 0x12C;
    p->unk14 = 0x12C;
    p->unk20 = 0x155;
    p->unk22 = 0x800;
    p->unk24 = 0;
    p->unk2E = 0;
    p->unk30 = -0x28;
    p->unk32 = 0;
    p->unk54 = 0;
    D_80187B48[p->idx]();
}
