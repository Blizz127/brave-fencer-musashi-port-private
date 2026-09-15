/* Overlay range [8014CD0C,8014CD80) from MAIN.CD member 0012.
 * SHA256(span)=299c24a99d7b7d992331e14595c2594662ec8fac414724d07d98ceb85f4140b1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8014CD80(u16 *, u16 *);                /* static */
void func_8014CF04(u16 *, u16 *);                /* static */

void func_8014CD0C(void *arg0) {
    u16 sp1C;
    s16 sp1A;
    u16 sp18;
    u16 sp14;
    s16 sp12;
    u16 sp10;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v1;

    temp_v0 = M2C_FIELD(arg0, u16 *, 6);
    sp18 = temp_v0;
    sp10 = temp_v0;
    temp_v0_2 = M2C_FIELD(arg0, u16 *, 0xA);
    sp12 = temp_v0_2 - 3;
    temp_v1 = M2C_FIELD(arg0, u16 *, 0xE);
    sp1A = temp_v0_2 + 5;
    sp1C = temp_v1;
    sp14 = temp_v1;
    if (M2C_FIELD(arg0, s32 *, 0x174) == 0) {
        func_8014CF04(&sp10, &sp18);
        return;
    }
    func_8014CD80(&sp10, &sp18);
}
