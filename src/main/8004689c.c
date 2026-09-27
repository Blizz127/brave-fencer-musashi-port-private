/* Exact retail word export [8004689C,800468FC); verified against pinned EXE and asm. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80046BFC(s32, s32);                            /* static */
extern s32 D_80078E38;
extern s16 D_800A2B94;
extern s32 D_800A5F1C;
extern s32 D_800AE644;
extern s32 D_800C6D38;
extern s32 D_800C6D3C;
extern s32 D_800C6D40;
extern s32 D_800C7F00;

void func_8004689C(void) {
    D_800C6D40 = 0;
    D_800C6D3C = 0;
    D_800C6D38 = 0;
    D_800AE644 = 0;
    func_80046BFC(0, D_800C7F00);
    D_800A5F1C = 0;
    D_800A2B94 = 0;
    D_80078E38 = 0;
}

