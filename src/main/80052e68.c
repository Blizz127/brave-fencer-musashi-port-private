/* Main-exec range [80052E68,80052F04) from the SLUS executable.
 * SHA256(span)=c3c6f1d1cc4856e3104968241a85eb6eec78de061693c24a033afa71d2a5050a.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004867C(s32, void *);              /* static */
void func_8004871C();                            /* static */
void func_80048D9C(s32 *, s32);                  /* static */
void func_8004917C(s32 *);                       /* static */
extern s32 *D_800A63F0;

void func_80052E68(s32 arg0) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;

    sp10 = M2C_FIELD(&D_800A63F0, s32 *, 0);
    sp14 = M2C_FIELD(&D_800A63F0, s32 *, 4);
    sp18 = M2C_FIELD(&D_800A63F0, s32 *, 8);
    sp1C = M2C_FIELD(&D_800A63F0, s32 *, 0xC);
    sp20 = M2C_FIELD(&D_800A63F0, s32 *, 0x10);
    sp24 = M2C_FIELD(&D_800A63F0, s32 *, 0x14);
    sp28 = M2C_FIELD(&D_800A63F0, s32 *, 0x18);
    sp2C = M2C_FIELD(&D_800A63F0, s32 *, 0x1C);
    func_8004867C(M2C_FIELD(&D_800A63F0, s32 *, 0x14), &D_800A63F0);
    func_80048D9C(&sp10, arg0);
    func_8004871C();
    func_8004917C(&sp10);
}
