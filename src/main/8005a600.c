/* Complete retail export [8005A600,8005A658); existing C independently reverified. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_8005AB00();
s32 func_8005AD34();
typedef struct { u8 pad[3]; u8 unk3; s32 unk4, unk8; } T;
void func_8005A600(T *p, void *a1, void *a2, u16 a3, s32 a4) {
    p->unk3 = 2;
    p->unk4 = func_8005AB00(a1, a2, a3);
    p->unk8 = func_8005AD34(a4);
}
