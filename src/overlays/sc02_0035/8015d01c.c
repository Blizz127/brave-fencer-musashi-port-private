/* SC02.CD member35 [8015D01C,8015D104): twin of main_0012 8015D01C (src/overlays/main_0012/8015d01c.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80154274();
s32 func_80012A60();
void func_801725F4();
void func_80146CA0();
extern s32 D_800D550C;
extern s32 D_80186D30;
typedef struct Inner { u8 pad[0x10]; s16 u10; u16 u12; } Inner;
typedef struct Q { u8 pad[0x20]; Inner *inner; } Q;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x14]; s32 u38;
    u8 pad3C[0x144]; Q *u180;
} T;
void func_8015D01C(T *p) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
    func_80154274(p, &D_800D550C);
    p->inner->u10 = 0;
    a = p->inner->u12;
    b = p->u180->inner->u12;
    c = (b + 0x800) & 0xFFF;
    d = func_80012A60(a, b);
    e = func_80012A60(a, c);
    if ((s16)d < (s16)e) {
        p->inner->u12 = b;
    } else {
        p->inner->u12 = c;
    }
    p->u38 = (s32)&D_80186D30 | 0x40000000;
    func_801725F4(p);
    func_80146CA0(p);
}
