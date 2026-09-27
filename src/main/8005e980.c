/* Main-exec range [8005E980,8005E9D4) from the SLUS executable.
 * SHA256(span)=5723444f8ed9550770b865e0f14a8f5d25947300c939487a3347148402333e53.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005E980(void *arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x46);
    switch (temp_v1) {                              /* irregular */
    case 2:
        M2C_FIELD(arg0, s8 *, 0x36) = 0x44;
        M2C_FIELD(arg0, void **, 0x2C) = (void *) (arg0 + 0x51);
        M2C_FIELD(arg0, u8 *, 0x35) = temp_v1;
        return;
    case 3:
        M2C_FIELD(arg0, s8 *, 0x36) = 0x4D;
        M2C_FIELD(arg0, void **, 0x2C) = (void *) (arg0 + 0x5D);
        M2C_FIELD(arg0, u8 *, 0x35) = 6U;
        return;
    }
}
