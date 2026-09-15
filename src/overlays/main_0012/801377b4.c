/* Overlay range [801377B4,80137840) from MAIN.CD member 0012.
 * SHA256(span)=a9fcbd0f2b8157531d1510d659f1d3da7f0f0ba1552bd9f14db3a040fd213e57.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80137840(void *);                      /* static */
extern void *D_80127524;
extern void *D_80127528;

void func_801377B4(s32 arg0, s16 arg1, void *arg2) {
    func_80137840(arg2);
    M2C_FIELD(arg2, s16 *, 4) = 1;
    M2C_FIELD(arg2, s32 *, 0) = arg0;
    M2C_FIELD(arg2, s32 *, 8) = (s32) arg1;
    if (!(arg1 & 0x2000)) {
        if (D_80127524 != 0) {
            D_80127528 = D_80127524;
            M2C_FIELD(D_80127524, s16 *, 0x1A) = 2;
        }
        D_80127524 = arg2;
    }
}
