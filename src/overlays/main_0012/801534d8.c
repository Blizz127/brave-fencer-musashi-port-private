/* Overlay range [801534D8,80153550) from MAIN.CD member 0012.
 * SHA256(span)=c88971cee32bb8dbd5b7314b5a96cbeb36dd367758d76edb9caf6ea3872f976a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146D90(void *, u16);                 /* static */
void func_80149020();                            /* static */
void func_80153550(void *);                      /* static */
s32 func_80153800(void *);                          /* static */
void func_80159B3C(void *);                      /* static */
void func_80165718(void *);                      /* static */

void func_801534D8(void *arg0) {
    u16 temp_a1;

    func_80149020();
    if (func_80153800(arg0) == 0) {
        temp_a1 = M2C_FIELD(arg0, u16 *, 0x8C);
        M2C_FIELD(arg0, s16 *, 4) = 0;
        M2C_FIELD(arg0, s16 *, 8) = 0;
        M2C_FIELD(arg0, s16 *, 0xC) = 0;
        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg0, u16 *, 0x88);
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(arg0, u16 *, 0x8A);
        M2C_FIELD(arg0, u16 *, 0xE) = temp_a1;
        func_80146D90(arg0, temp_a1);
        func_80153550(arg0);
        func_80159B3C(arg0);
        func_80165718(arg0);
    }
}
