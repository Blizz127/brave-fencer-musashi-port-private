/* Overlay range [801504D8,80150528) from MAIN.CD member 0012.
 * SHA256(span)=3930fd192312a23f6c11860eb0c25c0b88c33d7383177b7fdc3a350af1d1e289.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80150528(u16 *, u16 *);                /* static */

void func_801504D8(void *arg0) {
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
    sp1A = temp_v0_2 + 1;
    sp1C = temp_v1;
    sp14 = temp_v1;
    func_80150528(&sp10, &sp18);
}
