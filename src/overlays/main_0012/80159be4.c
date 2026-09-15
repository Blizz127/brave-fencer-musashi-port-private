/* Overlay range [80159BE4,80159C84) from MAIN.CD member 0012.
 * SHA256(span)=f2834037efda4168a719e4287fe156d38bba04d41f604eb0ae0fbb64ea17f81d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180980;
void func_80146CA0(void *);                      /* static */
void func_80146DB8(s32 (*)());               /* static */
void func_80154150(void *, s32);             /* static */
void func_80154A74(void *, s32);             /* static */
void func_801553A8(void *);                      /* static */
void func_801553C0(void *);                      /* static */
void func_80172590(void *);                      /* static */

void func_80159BE4(void *arg0) {
    s32 var_a1;
    func_80146DB8(D_80180980);
    if (M2C_FIELD(arg0, s32 *, 0x44) & 0x200) {
        func_80154150(arg0, 5);
        var_a1 = 0x1C;
    } else {
        func_80154150(arg0, 4);
        var_a1 = 0x11;
    }
    func_80154A74(arg0, var_a1);
    M2C_FIELD(arg0, s32 *, 0x234) = 0;
    M2C_FIELD(arg0, s32 *, 0x238) = 0;
    func_801553C0(arg0);
    func_801553A8(arg0);
    func_80172590(arg0);
    func_80146CA0(arg0);
}
