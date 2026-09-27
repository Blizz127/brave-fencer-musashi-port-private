/* Overlay range [8017209C,80172170) from MAIN.CD member 0012.
 * SHA256(span)=95cd3f4570a4e6ac5d74e40b5d83ece2ceae9c69835ee975cef25f871fdf3480.
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
void func_80172170(void *, s32);                 /* static */
s32 func_8017248C();                                /* static */

s32 func_8017209C(void *arg0, void *arg1, s32 arg2, s16 arg3) {
    s16 var_v1;
    s32 temp_v0;

    temp_v0 = func_8017248C();
    if (temp_v0 != 0) {
        func_80146D90(arg0);
        return temp_v0;
    }
    var_v1 = (func_8004CFEC(M2C_FIELD(arg1, s16 *, 0) - M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg1, s16 *, 4) - M2C_FIELD(arg0, s16 *, 0xE)) + 0x800) & 0xFFF;
    if (arg3 != 0) {
        var_v1 = func_80012DBC(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12), var_v1, arg3, 1);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12) = var_v1;
    func_80172170(arg0, arg2 & 0xFF);
    return 0;
}
