/* Overlay range [80153B58,80153BD8) from MAIN.CD member 0012.
 * SHA256(span)=82714c7896e6dc43f6104ae65d339383104dbbe820aefeae5d08adb20f755a4a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_8016DA04();                            /* static */
extern u16 D_800B99DA;

void func_80153B58(void *arg0) {
    if (!(D_800B99DA & 3)) {
        func_8016DA04();
    }
    if (!(D_800B99DA & 1)) {
        func_80146A6C(3, arg0, M2C_FIELD(arg0, s16 *, 6), M2C_FIELD(arg0, s16 *, 0xA), (s32) M2C_FIELD(arg0, s16 *, 0xE), 0x08880000, 0x18009000);
    }
}
