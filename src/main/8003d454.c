/* Main-exec range [8003D454,8003D518) from the SLUS executable.
 * SHA256(span)=494244cab1921cb0ac2a0271bc3d099b56d5a16226ceb0236f1d0674230fc30a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B8E8;
extern s32 D_8006B8F0;
extern s32 D_8006B8F5;
extern s32 D_8006B8F6;
void func_800425B0(s32, s32);                            /* static */
void func_80042610();                                 /* static */
void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */
extern u8 D_8006B8F4;

void func_8003D454(void) {
    if (D_8006B8E8 == 0) {
        D_8006B8F5 = 0;
        if (D_8006B8F6 != 0x7F) {
            func_8005CF08();
            if (D_8006B8F4 != 0) {
                func_80042610(0);
                D_8006B8F4 = 0;
            } else if (D_8006B8F6 == 0) {
                func_800425B0(0, D_8006B8F0);
                D_8006B8F0 = 0;
            } else {
                func_800425B0(6, 0);
            }
            func_8005CF18();
            D_8006B8F6 = 0x7FU;
        }
    }
}
