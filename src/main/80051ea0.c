/* Main-exec range [80051EA0,80051F34) from the SLUS executable.
 * SHA256(span)=fdcacf17c597e431cae303eca3e553505630e594d5573e7151075b794143be89.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80073AF8;
void func_8005C604(s32 (*)(), s32);          /* static */

s32 func_80051EA0(void *arg0, void *arg1, s32 arg2, s8 arg3) {
    s32 temp_a2;
    s32 temp_s1;
    void *temp_v1;

    temp_a2 = arg2 & 0xFFFF;
    temp_s1 = temp_a2 - M2C_FIELD(arg1, s32 *, 8);
    if (temp_s1 < 0) {
        func_8005C604(D_80073AF8, temp_a2);
    }
    temp_v1 = M2C_FIELD(arg1, s32 *, 4) + (temp_s1 * 4);
    M2C_FIELD(arg0, void **, 0) = (void *) M2C_FIELD(temp_v1, void **, 0);
    M2C_FIELD(arg0, s8 *, 3) = arg3;
    M2C_FIELD(temp_v1, void **, 0) = arg0;
    M2C_FIELD(temp_v1, s8 *, 3) = 0;
    return arg0 + (((arg3 & 0xFF) * 4) + 4);
}
