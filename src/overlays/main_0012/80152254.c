/* Overlay range [80152254,801522CC) from MAIN.CD member 0012.
 * SHA256(span)=07cfd91a9d29c342bf4edd8cfd65a66287a43da7523be882f64737f95a2b18fc.
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
void func_801522CC(void *);                      /* static */
s32 func_80153800(void *);                          /* static */
void func_80159B3C(void *);                      /* static */
void func_80165718(void *);                      /* static */

void func_80152254(void *arg0) {
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
        func_801522CC(arg0);
        func_80159B3C(arg0);
        func_80165718(arg0);
    }
}
