/* Overlay range [80156ECC,80156FA8) from MAIN.CD member 0012.
 * SHA256(span)=fdb4f31bc82bb5fe8e69e832e4b83286d396d71decdfaa2a5bcd80954216f881.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80147478(s32);                         /* static */
void func_80149350(s32, void *, void *);         /* static */
void func_80156FA8(void *, void *, void *);      /* static */

void func_80156ECC(s32 arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    u16 temp_s0;
    u16 temp_s0_2;
    u16 temp_s0_3;

    func_80156FA8(arg2, arg3, arg4);
    func_80147478(arg0);
    func_80149350(arg0, arg1, arg1);
    temp_s0 = (u16) M2C_FIELD(arg2, s16 *, 6);
    if (M2C_FIELD(arg2, s16 *, 6) == 0) {
        func_80149350(arg0, arg2, arg2);
        M2C_FIELD(arg2, s16 *, 6) = (s16) temp_s0;
    }
    temp_s0_2 = (u16) M2C_FIELD(arg3, s16 *, 6);
    if (M2C_FIELD(arg3, s16 *, 6) == 0) {
        func_80149350(arg0, arg3, arg3);
        M2C_FIELD(arg3, s16 *, 6) = (s16) temp_s0_2;
    }
    temp_s0_3 = (u16) M2C_FIELD(arg4, s16 *, 6);
    if (M2C_FIELD(arg4, s16 *, 6) == 0) {
        func_80149350(arg0, arg4, arg4);
        M2C_FIELD(arg4, s16 *, 6) = (s16) temp_s0_3;
    }
}
