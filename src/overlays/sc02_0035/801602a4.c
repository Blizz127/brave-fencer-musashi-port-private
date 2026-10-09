/* SC02.CD member35 [801602A4,8016032C): twin of main_0012 801602A4 (src/overlays/main_0012/801602a4.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186B6C[];
void func_80154A74();
void func_80147078();
void func_80159B70();
s32 func_80161208();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8; } T;
void func_801602A4(T *p) {
    if (p->b8 == 0x8000) {
        D_80186B6C[p->idx](p);
        func_80154A74(p, 0x11);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        func_80161208(p);
    }
}
