/* Main-exec range [80042BDC,80042C64) from the SLUS executable.
 * SHA256(span)=310f4fbfe05d64f7e76756377d194aee4b880c1a5574cc7b6748e8403bf74874.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006BB2E;
extern s32 D_8006BB30;
extern s32 D_8006CB8C;
extern s32 *D_8006CB90;
void func_8005CEF8(u16 *);                             /* static */
void func_8005CF18(u16 *);                             /* static */
extern u16 D_8006BAFC;

u16 *func_80042BDC(void) {
    if (D_8006BAFC == 0) {
        func_8005CEF8(&D_8006BAFC + 0x38);
        D_8006BAFC = 1;
        *D_8006CB8C = D_8006BB2E;
        *D_8006CB90 = D_8006BB30;
        func_8005CF18(D_8006CB8C);
        return &D_8006BAFC;
    }
    return 0;
}
