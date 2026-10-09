/* SC02.CD member35 [80156A1C,80156A88): twin of main_0012 80156A1C (src/overlays/main_0012/80156a1c.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147324();
extern u8 D_8011520C[];
extern u16 D_801867A4[];
typedef struct { u8 pad[0xDA]; u8 uDA; } T;
void func_80156A1C(T *p, s32 a1) {
    if (p->uDA) {
        return;
    }
    func_80147324(D_801867A4[D_8011520C[a1]]);
    p->uDA++;
}
