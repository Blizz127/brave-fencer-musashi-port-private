/* Main-exec range [80029ED4,80029FD4) from the SLUS executable.
 * SHA256(span)=3c28d8f5f2e8afbaafdfb13f9e43efbce4baec1a25a7c02da4416b34c395dfb2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029504();                                /* static */
void func_8002A2D4(s32, u32, s32, s32);      /* static */
extern u32 D_80078F04;
extern u32 D_80078F08;
extern u32 D_80078F0C;

void func_80029ED4(s32 arg0) {
    s32 temp_a0_2;
    u32 temp_a0;
    u32 temp_a1;

    if (func_80029504() >= 0xA) {
        temp_a1 = D_80078F04 + arg0;
        D_80078F04 = temp_a1;
        if (temp_a1 >= 0x66U) {
            temp_a0 = D_80078F08 + 1;
            D_80078F08 = temp_a0;
            D_80078F04 = (D_80078F04 + arg0) % 102;
            if (temp_a0 > 0x98967FU) {
                D_80078F08 = 0x98967F;
            }
            temp_a0_2 = D_80078F08 - D_80078F0C;
            if (temp_a0_2 >= 0xA) {
                D_80078F0C = D_80078F08;
                func_8002A2D4((D_80078F08 - D_80078F0C) / 10, temp_a1, 0x98967F, MULT_HI(temp_a0_2, 0x66666667));
            }
        }
    }
}
