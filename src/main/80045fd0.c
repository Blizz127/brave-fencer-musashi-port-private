/* Main-exec range [80045FD0,800460CC) from the SLUS executable.
 * SHA256(span)=c26d03bf8638b6852079a21c881d02e2b09a8faf91f2866c001225fcbfc19e2e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8006CF9C();                                     /* static */
extern s32 D_8006CFA8;
extern s32 D_8006CFB0;
extern s32 D_8006CFB4;
extern s32 D_8006CFC0;
extern s32 D_8006CFC4;
extern s32 D_8006CFC8;
extern s32 D_8006CFCC;
extern s32 D_8006CFD0;
extern s32 D_8006CFD4;
void func_8004359C(s32);                               /* static */
void func_800435B4(s32);                               /* static */
void func_80043704(s32, s32);                              /* static */
void func_800439D4(s32);                               /* static */

void func_80045FD0(void) {
    D_8006CFA8 = (s32) (D_8006CFA8 + (D_8006CFB0 * 4));
    D_8006CFB4 = (s32) (D_8006CFB4 - 1);
    D_8006CFC0 = (s32) (D_8006CFC0 + 1);
    if (D_8006CFB4 == 0) {
        func_8004359C(D_8006CFC4);
        func_800435B4(D_8006CFC8);
        if (D_8006CFD0 & 1) {
            func_800439D4(D_8006CFCC);
        }
        func_80043704(9, 0);
        if (D_8006CF9C != 0) {
            D_8006CF9C(2, D_8006CFD4);
        }
    }
}
