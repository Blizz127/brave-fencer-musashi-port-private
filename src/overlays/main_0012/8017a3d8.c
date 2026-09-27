/* Overlay range [8017A3D8,8017A460) from MAIN.CD member 0012.
 * SHA256(span)=6cbecb50f3f8d25714fb18fdeca6c16855fc15964d38c1e54961679b22250c72.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001AAA0(s16);                               /* extern */
void func_800D0CA0();                                 /* extern */
void func_800D0CE0(s16);                               /* extern */
void func_8017A49C();                                  /* extern */
extern s32 D_80185380;
extern s32 D_80185384;
void func_8017A460();                                  /* static */

void func_8017A3D8(void) {
    if (D_80185384 != 0) {
        if (D_80185384 != 0x64) {
            func_8017A460();
            return;
        }
        if (D_80185380 != -1) {
            func_8001AAA0(D_80185380);
            func_8017A49C();
            return;
        }
        func_800D0CE0(D_80185380);
        func_8017A49C();
        return;
    }
    func_800D0CA0(1);
    D_80185384 = (s16) ((u16) D_80185384 + 1);
    func_8017A49C();
}
