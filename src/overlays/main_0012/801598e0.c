/* Overlay range [801598E0,80159968) from MAIN.CD member 0012.
 * SHA256(span)=9031141dc03b482eeff66352b00c3c70dca672541ce0623d2579a1f2d19f7f05.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80159968();                            /* static */

void func_801598E0(void *arg0) {
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0xA9);
    switch (temp_v1) {                              /* irregular */
    case 0x41:
        M2C_FIELD(arg0, u16 *, 0xAA) = (u16) (M2C_FIELD(arg0, u16 *, 0xAA) & 0xAFFF);
        M2C_FIELD(arg0, u16 *, 0xAC) = (u16) (M2C_FIELD(arg0, u16 *, 0xAC) & 0xAFFF);
        break;
    case 0x53:
    case 0x73:
        M2C_FIELD(arg0, u8 *, 0xAE) = (s16) (M2C_FIELD(arg0, u8 *, 0xAE) | 0x8000);
        break;
    }
    func_80159968();
}
