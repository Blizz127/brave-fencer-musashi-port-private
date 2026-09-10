/* Exact retail word export for [80010ED4,80010F80); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80072C70;
void func_80010AE0();                                 /* static */
void func_800116E0();                                  /* static */
void func_80011778();                                  /* static */
void func_80014338();                                  /* static */
s32 func_80019A24(void *, s32, s32, s32 *);              /* static */
void func_8002D4C8(s32, s32);                              /* static */
extern s32 *D_800A2E20;
extern s32 *D_800AE848;
extern s16 D_800B99DA;
extern s32 D_800C7C60;
extern void *D_800C7C64;

void func_80010ED4(void) {
    D_800C7C60 = 0x57;
    D_800C7C64 = &D_800A2E20;
    if (func_80019A24(&D_800AE848, D_80072C70, 0, &D_800C7C60) != 0) {
        func_8002D4C8(2, 0);
        func_80010AE0(0x3E0);
        func_80014338();
        func_800116E0();
        D_800B99DA = 0;
        func_80011778();
    }
}
