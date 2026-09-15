/* Main-exec range [800462E0,8004637C) from the SLUS executable.
 * SHA256(span)=0d298e08ba10c4ceaa17f4f3f1b1a9771ca2d086dd1574023140e6f48bde7cfd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CFB4;
extern s32 D_8006CFC4;
extern s32 D_8006CFC8;
extern s32 D_8006CFCC;
extern s32 D_8006CFD0;
void func_8004359C(s32);                               /* static */
void func_800435B4(s32);                               /* static */
void func_80043704(s32, s32);                              /* static */
void func_800439D4(s32);                               /* static */
void func_800439F8();                                 /* static */

void func_800462E0(void) {
    if (D_8006CFD0 & 1) {
        func_800439F8(0);
    }
    D_8006CFB4 = 0;
    func_8004359C(D_8006CFC4);
    func_800435B4(D_8006CFC8);
    if (D_8006CFD0 & 1) {
        func_800439D4(D_8006CFCC);
    }
    func_80043704(9, 0);
}
