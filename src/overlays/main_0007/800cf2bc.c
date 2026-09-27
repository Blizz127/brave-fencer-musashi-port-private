/* Overlay range [800CF2BC,800CF33C) from MAIN.CD member 0007.
 * SHA256(span)=783b14a284cb294f775eaa5be2ce3cad998ba28dd9e2fb78173325e9e91dce82.
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
extern s32 D_800D136C;
extern s32 D_800D1374;
s32 func_800CF3B0();                                /* static */
void func_800CF6D0(s32, s32);                            /* static */

void func_800CF2BC(void) {
    s32 temp_a0;

    if (func_800CF3B0() == 0) {
        temp_a0 = D_800D136C;
        D_800D136C = (s32) (temp_a0 + 1);
        func_800CF6D0(temp_a0, 0);
        if (D_800D136C >= 0x141) {
            func_800167B8(4);
            D_800D1374 = (s32) (D_800D1374 + 1);
        }
    }
}
