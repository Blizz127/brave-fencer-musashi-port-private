/* Overlay range [80164F44,80165024) from MAIN.CD member 0012.
 * SHA256(span)=f3217cdd0e7fa247bf06b76ea7d1849f8c7795c5b74cce533efa0ea32351160a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80146E90();                     /* static */
void func_80165124(void *);                      /* static */
void func_80165140(void *);                      /* static */
void func_801651B8(void *);                      /* static */

void func_80164F44(void *arg0) {
    s16 temp_v0;
    s32 var_v1;
    u16 temp_v1;
    u16 var_v0;

    M2C_FIELD(arg0, u16 *, 0x62) = (u16) (M2C_FIELD(arg0, u16 *, 0x62) + 4);
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x60) + 0x40;
    M2C_FIELD(arg0, u16 *, 0x60) = temp_v1;
    temp_v0 = M2C_FIELD(arg0, u16 *, 0x2E) - temp_v1;
    M2C_FIELD(arg0, u16 *, 0x2E) = (u16) temp_v0;
    M2C_FIELD(arg0, s16 *, 0x2C) = temp_v0;
    if (temp_v0 < 0x1000) {
        M2C_FIELD(arg0, u16 *, 0x2E) = 0x1000U;
        M2C_FIELD(arg0, s16 *, 0x2C) = 0x1000;
        M2C_FIELD(arg0, u16 *, 0x60) = 0x80U;
        func_80146E90(0xE);
        func_80146CA0(arg0);
    }
    func_80165124(arg0);
    var_v1 = 2;
    if (M2C_FIELD(arg0, s16 *, 0x2C) < 0x2800) {
        var_v0 = M2C_FIELD(arg0, u16 *, 0x66) + 1;
    } else {
        var_v1 = 3;
        var_v0 = M2C_FIELD(arg0, u16 *, 0x66) + 1;
    }
    M2C_FIELD(arg0, u16 *, 0x66) = var_v0;
    if ((s16) var_v0 == var_v1) {
        func_80165140(arg0);
        M2C_FIELD(arg0, u16 *, 0x66) = 0U;
    }
    func_801651B8(arg0);
}
