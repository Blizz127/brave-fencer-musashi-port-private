/* Overlay range [8015FDCC,8015FE70) from MAIN.CD member 0012.
 * SHA256(span)=f7cff06810cdf6171f132fde610aa1242474ddb005d841bb7e1cbf1273e62d6d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80028DE0();                                /* extern */
void func_80139914(s32);                         /* static */
s32 func_801399F0(s32);                             /* static */
void func_801466F0(s32, void *, s32, s32, s32, s32, s32, s32); /* static */
void func_80146CA0(void *);                      /* static */
void func_80147324();                     /* static */
s32 func_80165700(void *, u8);                      /* static */

void func_8015FDCC(void *arg0) {
    if (func_801399F0(M2C_FIELD(arg0, s32 *, 0x198)) != 0) {
        func_80147324(0x19);
        func_80139914(M2C_FIELD(arg0, s32 *, 0x198));
        M2C_FIELD(arg0, s32 *, 0x198) = 0;
        if ((func_80028DE0() == 0) && (func_80165700(arg0, M2C_FIELD(arg0, u8 *, 0x1A0)) & 0xFF)) {
            func_801466F0(0x24, arg0, 0, 0, 0, 0, 0, 0);
            func_80147324(0x989);
        }
        func_80146CA0(arg0);
    }
}
