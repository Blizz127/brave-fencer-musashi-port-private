/* Overlay range [80171E08,80171EC8) from MAIN.CD member 0012.
 * SHA256(span)=8a98ddece7588ac0b407a78ed6732d833627e4b6ddb65b2ccd5bf9d27e124ac3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012DBC(s16, s16, s16, s32);          /* extern */
s32 func_8004CFEC(s32, s32);                        /* extern */
void func_80146D90(void *);                      /* static */
void func_80171EC8(void *, s16);                 /* static */
s32 func_8017248C();                                /* static */

s32 func_80171E08(void *arg0, void *arg1, s16 arg2) {
    s16 var_a1;
    s32 temp_v0;

    temp_v0 = func_8017248C();
    if (temp_v0 != 0) {
        func_80146D90(arg0);
        return temp_v0;
    }
    var_a1 = (func_8004CFEC(M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg0, s16 *, 0xE)) + 0x800) & 0xFFF;
    if (arg2 != 0) {
        var_a1 = func_80012DBC(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12), var_a1, arg2, 1);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12) = var_a1;
    func_80171EC8(arg0, var_a1);
    return 0;
}
