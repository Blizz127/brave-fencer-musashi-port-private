/* Overlay range [8014DF94,8014E048) from MAIN.CD member 0012.
 * SHA256(span)=c9806e7bbcf4d5fc248d6b1b17d9ae1a2b8c5bf7302eedb1f832f9d3bd8d10da.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8014E048(void *, u16 *, u16 *);        /* static */
void func_8014E284(void *, u16 *, u16 *);        /* static */

void func_8014DF94(void *arg0) {
    u16 sp1C;
    s16 sp1A;
    u16 sp18;
    u16 sp14;
    s16 sp12;
    u16 sp10;
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v1;
    u16 temp_v1_2;

    temp_a0 = M2C_FIELD(arg0, u16 *, 0x88);
    sp10 = temp_a0;
    sp12 = M2C_FIELD(arg0, u16 *, 0x8A) - 0x10;
    temp_a1 = M2C_FIELD(arg0, u16 *, 0x8C);
    sp14 = temp_a1;
    temp_v1 = M2C_FIELD(arg0, u16 *, 6);
    sp18 = temp_v1;
    temp_v1_2 = temp_v1 - temp_a0;
    sp1A = M2C_FIELD(arg0, u16 *, 0xA) - 0x10;
    temp_v0 = M2C_FIELD(arg0, u16 *, 0xE);
    sp18 = temp_v1_2;
    sp18 = temp_a0 - temp_v1_2;
    sp1C = temp_v0;
    temp_v0_2 = temp_v0 - temp_a1;
    sp1C = temp_v0_2;
    sp1C = temp_a1 - temp_v0_2;
    if (M2C_FIELD(arg0, s32 *, 0x170) == 0) {
        func_8014E284(arg0, &sp10, &sp18);
        return;
    }
    func_8014E048(arg0, &sp10, &sp18);
}
