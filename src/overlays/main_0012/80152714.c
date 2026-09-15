/* Overlay range [80152714,80152790) from MAIN.CD member 0012.
 * SHA256(span)=ae764fa85e6c6f862242212aa5ca2a8de40cd2a6b9fb23898e4f7a111e1b1771.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80019064(void *);                   /* extern */
void func_80151204(void *, s16);                 /* static */
void func_80152790(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
void func_80165718(void *);                      /* static */
extern s32 *D_80062BF4;
extern u8 D_80078EC1;

void func_80152714(void *arg0) {
    func_80019064(&D_80062BF4);
    func_80151204(arg0, M2C_FIELD(arg0, s16 *, 0xF2));
    if (D_80078EC1 != 2) {
        M2C_FIELD(arg0, s32 *, 0x1AC) = 0x3C0000;
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 0x100);
    }
    func_80152790(arg0);
    func_80159B3C(arg0);
    func_80165718(arg0);
}
