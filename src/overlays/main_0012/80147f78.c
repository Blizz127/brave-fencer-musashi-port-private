/* Overlay range [80147F78,80148038) from MAIN.CD member 0012.
 * SHA256(span)=6006beb0943c37dab180cb63be57c1fb4f9416a4234623307aca4c9095bb553f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80147928();                            /* static */
void func_8014799C(void *, s32);             /* static */
void func_80147A10(void *, s32);             /* static */
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147F78(void *arg0, s32 arg2, s32 arg3) {
    func_80147928();
    func_8014799C(arg0, arg2);
    func_80147A10(arg0, arg3);
    D_80127090 = M2C_FIELD(arg0, s32 *, 0x24);
    D_80127094 = M2C_FIELD(arg0, s32 *, 0x28);
    D_80127098 = M2C_FIELD(arg0, s32 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_80127090;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) D_80127094;
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
