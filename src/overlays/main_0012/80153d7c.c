/* Overlay range [80153D7C,80153E00) from MAIN.CD member 0012.
 * SHA256(span)=d49b0bb3fec8430c141ae5115de7359a36774e284e36b283c14e517b20aa588b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180180;
void func_80146CA0(void *);                      /* static */
void func_80147324();                     /* static */
void func_80149020(void *);                      /* static */
void func_80154274(void *, s32 (*)());       /* static */
extern s16 D_800B9A08;

void func_80153D7C(void *arg0) {
    s8 var_v0;

    func_80147324(0x451);
    func_80154274(arg0, D_80180180);
    func_80149020(arg0);
    M2C_FIELD(arg0, u16 *, 0x244) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg0, u16 *, 0x246) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    M2C_FIELD(arg0, u16 *, 0x248) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
    var_v0 = 0xA;
    if (D_800B9A08 == 0x3075) {
        var_v0 = 0x14;
    }
    M2C_FIELD(arg0, s8 *, 0xDE) = var_v0;
    M2C_FIELD(arg0, s8 *, 0xDF) = 0;
    func_80146CA0(arg0);
}
