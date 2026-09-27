/* Main-exec range [8002D6D8,8002D7F4) from the SLUS executable.
 * SHA256(span)=b05bb0a251c524a88b3ac4787938140c2736c85ffbe9e5c0df2331d942d1a41b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006451C;
void func_8002D320();                            /* static */
u32 func_8002F4E4(u8 *, u32);                       /* static */
void func_80030F80();                            /* static */
void func_80031BE0();                            /* static */
void func_8003324C(s32, u32);                    /* static */
extern s16 D_800A4EFC;
extern u8 D_800A4F17;
extern u8 D_800A4F18;

void func_8002D6D8(u32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    u32 temp_v1;
    u32 var_a1;
    u8 *temp_a0;

    var_a1 = arg0 >> 0x10;
    temp_v1 = var_a1 & 0xFFFF;
    D_800A4F17 = 1;
    temp_s0 = arg0 & 0xFFFF;
    if ((temp_v1 >= 0x100U) && ((temp_a0 = (temp_v1 * 4) + D_8006451C, ((*temp_a0 & 0x7F) != 6)) || (var_a1 = func_8002F4E4(temp_a0, var_a1), ((var_a1 & 0xFFFF) != 0)))) {
        temp_s0_2 = temp_s0 - 1;
        if (temp_s0 != 0) {
            if (M2C_FIELD((&D_800A4F17 + (temp_s0_2 * 0x54)), u16 *, -0x82B) == (var_a1 & 0xFFFF)) {
                func_8003324C(temp_s0_2 & 0xFFFF, var_a1);
            }
            D_800A4F17 = D_800A4F18;
            if (D_800A4F18 != 0) {
                if (D_800A4EFC != 0) {
                    D_800A4EFC -= 1;
                }
                func_80030F80();
                func_8002D320();
                func_80031BE0();
                D_800A4F18 = 0;
                D_800A4F17 = 0;
            }
        }
    }
}
