/* Main-exec range [8003B170,8003B1EC) from the SLUS executable.
 * SHA256(span)=969a81da35a3865226be9e7620a276e7def4006ee40a4158782b9e4dffaa3ed8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0E0;
extern s32 D_8006B548;
extern s32 D_8006B584;
extern s32 D_8006B588;
void func_8003B14C();                                 /* static */
void func_8005CE88(s32);                               /* static */
void func_8005CEC8(s32);                               /* static */
void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */

void func_8003B170(void) {
    if (D_8006B548 == 1) {
        D_8006B548 = 0;
        func_8005CF08();
        D_8006B584 = 0;
        D_8006B588 = 0;
        func_8003B14C(0);
        func_8005CE88(D_8006B0E0);
        func_8005CEC8(D_8006B0E0);
        func_8005CF18();
    }
}
