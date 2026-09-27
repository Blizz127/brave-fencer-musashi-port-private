/* Overlay range [800CF148,800CF1CC) from MAIN.CD member 0007.
 * SHA256(span)=ed7355e9a7dce7e7967103ecca969f5df96644072ffc8e17a46db5affae7156a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800167B8();                                 /* extern */
extern s32 D_800D1368;
extern s32 D_800D1374;
s32 func_800CF3B0();                                /* static */
void func_800CF408(s32, s32);                            /* static */

void func_800CF148(void) {
    s32 temp_v0;

    if (func_800CF3B0() == 0) {
        func_800CF408(0, D_800D1368);
        temp_v0 = D_800D1368 - 1;
        D_800D1368 = temp_v0;
        if (temp_v0 < -0x10F) {
            func_800167B8(4);
            D_800D1368 = -0x110;
            D_800D1374 = (s32) (D_800D1374 + 1);
        }
    }
}
