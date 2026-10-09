/* SC02.CD member35 [8015E344,8015E40C): twin of main_0012 8015E344 (src/overlays/main_0012/8015e344.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186B6C[];
void func_8015E40C();
s32 func_80161B18();
s32 func_80161B84();
s32 func_80161208();
void func_8015E5B0();
void func_80147078();
void func_80159BE4();
typedef struct {
    u16 idx;
    u8 pad2[0xB6]; u16 b8;
    u8 padBA[0x17A]; s32 u234;
} T;
void func_8015E344(T *p) {
    func_8015E40C(p);
    if (func_80161B18(p)) {
        return;
    }
    if (func_80161B84(p)) {
        return;
    }
    if (func_80161208(p)) {
        return;
    }
    if (p->b8 & 0x4000) {
        func_8015E5B0(p);
        p->u234 = 1;
    }
    if (p->b8 & 0x8000) {
        D_80186B6C[p->idx](p);
        func_80147078(p, 0);
        func_80159BE4(p);
    }
}
