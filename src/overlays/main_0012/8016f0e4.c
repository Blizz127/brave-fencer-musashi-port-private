/* Overlay range [8016F0E4,8016F14C) from MAIN.CD member 0012.
 * SHA256(span)=3d9cda4c88f1d26aca6651c7fee5bfbf51f735aa6d46cc4adfc6e952bafbd37e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80147060(void *);                      /* static */
void func_80148634(void *);                      /* static */
void func_801511A8(void *);                      /* static */
void func_8017196C(void *, s32);            /* static */
extern u16 D_80078EB4;
extern s8 D_800B9A17;

void func_8016F0E4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x1F8) = 0;
    M2C_FIELD(arg0, s32 *, 0x1FC) = 0;
    func_8017196C(arg0, 0);
    func_80147060(arg0);
    func_801511A8(arg0);
    if (D_80078EB4 != 0) {
        D_800B9A17 = 1;
    }
    func_80148634(arg0);
}
