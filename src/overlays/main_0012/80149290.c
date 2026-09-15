/* Overlay range [80149290,80149350) from MAIN.CD member 0012.
 * SHA256(span)=c562ab0f22769c290b08dfa7d85d1293ece3f76b7406bd7b047d03cef1e299ad.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80149350();                            /* static */

void func_80149290(void *arg0) {
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;

    temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x48);
    sp10 = temp_v0;
    temp_v0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x4C);
    sp14 = temp_v0_2;
    temp_v0_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x4C);
    sp18 = temp_v0_3;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x48) = (s32) M2C_FIELD(arg0, s16 *, 6);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x4C) = (s32) M2C_FIELD(arg0, s16 *, 0xA);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x50) = (s32) M2C_FIELD(arg0, s16 *, 0xE);
    func_80149350();
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x48) = temp_v0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x4C) = temp_v0_2;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x50) = temp_v0_3;
}
