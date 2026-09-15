/* Overlay range [801508F8,8015094C) from MAIN.CD member 0012.
 * SHA256(span)=5ebc2ed3db8c594218111f3d6bc1fda68831539b10ffedc7694f33d010a04410.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8015094C(void *);                          /* static */

void func_801508F8(void *arg0) {
    if ((M2C_FIELD(arg0, u8 *, 0x1BF) != 0) && (M2C_FIELD(arg0, u16 *, 0) != 0x1A)) {
        do {

        } while (func_8015094C(arg0) != 0);
    }
}
