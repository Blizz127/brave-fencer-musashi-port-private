/* Overlay range [80151B98,80151C54) from MAIN.CD member 0012.
 * SHA256(span)=72ed76d592a22ec8701dc38705e37d1e24803d640fb4bcf9db5e6b8442afb19f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80149020();                            /* static */
void func_8014C010(void *, s32);             /* static */
void func_80151C54(void *);                      /* static */
s32 func_801535F4(void *);                          /* static */
void func_80159B3C(void *);                      /* static */
void func_8015BF48(void *);                      /* static */
void func_80165718(void *);                      /* static */

void func_80151B98(void *arg0) {
    s32 temp_v0;

    func_80149020();
    if (M2C_FIELD(arg0, u16 *, 0xB8) == 0x8000) {
        func_80151C54(arg0);
        func_80159B3C(arg0);
        goto block_9;
    }
    temp_v0 = func_801535F4(arg0);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_80151C54(arg0);
        func_80159B3C(arg0);
block_8:
        func_8014C010(arg0, 1);
block_9:
        func_80165718(arg0);
        return;
    case 2:
        func_80151C54(arg0);
        func_8015BF48(arg0);
        goto block_8;
    }
}
