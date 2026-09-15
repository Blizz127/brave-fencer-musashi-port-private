/* Overlay range [80160C28,80160CB4) from MAIN.CD member 0012.
 * SHA256(span)=f41b1d53f4890ffc068b5f8ddc22eedbc1bf095f1f0f14d7a9bb1a939fc56256.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
s32 func_80161208();                                /* static */

void func_80160C28(void *arg0) {
    void *temp_a0;
    void *temp_v1;

    if (func_80161208() == 0) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x20);
        M2C_FIELD(arg0, s32 *, 0x238) = (s32) (M2C_FIELD(arg0, s32 *, 0x238) + 0x1C000);
        M2C_FIELD(temp_a0, u16 *, 0x10) = (u16) ((M2C_FIELD(temp_a0, u16 *, 0x10) - M2C_FIELD(arg0, u16 *, 0x23A)) & 0xFFF);
        temp_v1 = M2C_FIELD(arg0, void **, 0x20);
        if ((s16) M2C_FIELD(temp_v1, u16 *, 0x10) < 0xC00) {
            M2C_FIELD(temp_v1, u16 *, 0x10) = 0xC00U;
            M2C_FIELD(arg0, s16 *, 0xB8) = 1;
            func_80146CA0(arg0);
        }
    }
}
