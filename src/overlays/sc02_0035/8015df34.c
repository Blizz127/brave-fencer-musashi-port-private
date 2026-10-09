/* SC02.CD member35 [8015DF34,8015DFE4): twin of main_0012 8015DF34 (src/overlays/main_0012/8015df34.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186B6C[];
void func_8015E0D4();
void func_80147078();
void func_80159B70();
void func_8015E018();
void func_80161208();
typedef struct {
    u16 idx;
    u8 pad2[0xB6]; u16 b8;
    u8 padBA[0xBE]; void *u178;
} T;
void func_8015DF34(T *p) {
    if (p->b8 & 0x4000) {
        func_8015E0D4(p);
    }
    if (p->b8 == 0x8000) {
        D_80186B6C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        if (p->u178) {
            func_8015E018(p);
        }
        func_80161208(p);
    }
}
