/* Overlay range [8015C030,8015C08C) from MAIN.CD member 0012.
 * SHA256(span)=f0aaa22cdf388e25ced7e01778f043ec3a353de79b43278db88fa632e5df7ecb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80154150();                     /* static */
void func_801553A8(void *);                      /* static */

void func_8015C030(void *arg0, void *arg1) {
    M2C_FIELD(arg0, s32 *, 0x238) = 0x80000;
    M2C_FIELD(arg0, s32 *, 0x234) = (s32) (M2C_FIELD(arg1, s16 *, 0) << 7);
    M2C_FIELD(arg0, s32 *, 0x23C) = (s32) (M2C_FIELD(arg1, s16 *, 4) << 7);
    func_80154150(0x11);
    func_801553A8(arg0);
    func_80146CA0(arg0);
}
