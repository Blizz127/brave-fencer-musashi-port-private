/* Exact retail word export [80046ABC,80046B44); verified against pinned EXE and asm. */
/* Verified byte-exact against retail by tools/match_function.py
 * (34/34 words at 0x80046ABC). The two unused middle parameters are
 * load-bearing: the live values arrive in $a3 and on the stack, so the
 * signature must declare (and ignore) the $a1/$a2 slots. Types and
 * signatures are otherwise whatever reproduces the bytes; they are not
 * evidence of the original declaration. */
#include "psx_types.h"

void func_80046CFC();                                 /* static */
extern s32 D_80078E38;
extern s16 D_800A2B94;
extern s32 D_800A2B9C;
extern s32 D_800A5E80;
extern s32 D_800A5E84;
extern s32 D_800A6424;
extern s32 D_800A6608;
extern s32 D_800C7C78;

void func_80046ABC(s32 arg0, s32 unused1, s32 unused2, s32 arg3, s32 arg4) {
    func_80046CFC(1);
    D_800C7C78 = 0;
    D_800A5E80 = arg3;
    D_800A2B9C = arg0 & 1;
    D_800A6608 = 0;
    D_800A6424 = 0;
    D_800A2B94 = 0;
    D_80078E38 = 0;
    D_800A5E84 = arg4;
}
