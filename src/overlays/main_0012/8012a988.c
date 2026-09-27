/* Overlay range [8012A988,8012AAAC) from MAIN.CD member 0012.
 * SHA256(span)=a6f2d6f81233bea8cdd901da4d85aa89796b04e49c89a63c7fd8077f3d948f25.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Verified byte-exact against retail by tools/match_function.py
 * (73/73 words at 0x8012A988). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"
#include "m2c_macros.h"

void func_8012AAAC(void *);                      /* static */
s32 func_8012ACE0(void *);                          /* static */

void func_8012A988(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_v0;
    u16 temp_v1;

    M2C_FIELD(arg0, u16 *, 0x72) = (u16) (M2C_FIELD(arg0, u16 *, 0x72) & 0x9FFF);
    if ((M2C_FIELD(arg0, u16 *, 0) != 0) && (M2C_FIELD(arg0, u8 *, 0xC1) != 0x11) && (temp_v0 = M2C_FIELD(arg0, s16 *, 0x98), (temp_v0 != 0)) && (temp_v0_2 = temp_v0 - 1, M2C_FIELD(arg0, s16 *, 0x98) = temp_v0_2, ((temp_v0_2 << 0x10) <= 0)) && (M2C_FIELD(arg0, s32 *, 0x90) != 0)) {
        temp_v1 = M2C_FIELD(arg0, u16 *, 0x72);
        if (temp_v1 & 0x400) {
            temp_v0_3 = M2C_FIELD(arg0, s32 *, 0x94) - 1;
            M2C_FIELD(arg0, s32 *, 0x94) = temp_v0_3;
            if (temp_v0_3 < 0) {
                M2C_FIELD(arg0, s32 *, 0x94) = 1;
                M2C_FIELD(arg0, u16 *, 0x72) = (u16) (M2C_FIELD(arg0, u16 *, 0x72) & 0xFBFF);
            }
            goto block_14;
        }
        if (temp_v1 & 0x200) {
            temp_v0_4 = M2C_FIELD(arg0, s32 *, 0x94) - 1;
            M2C_FIELD(arg0, s32 *, 0x94) = temp_v0_4;
            if (temp_v0_4 < 0) {
                temp_v0_5 = func_8012ACE0(arg0);
                if (M2C_FIELD(((temp_v0_5 * 8) + M2C_FIELD(arg0, s32 *, 0x90)), s16 *, 4) != -1) {
                    M2C_FIELD(arg0, s32 *, 0x94) = 0;
                    M2C_FIELD(arg0, s16 *, 0x98) = 0;
                    return;
                }
                var_v0 = temp_v0_5 - 1;
                goto block_13;
            }
            goto block_14;
        }
        var_v0 = M2C_FIELD(arg0, s32 *, 0x94) + 1;
block_13:
        M2C_FIELD(arg0, s32 *, 0x94) = var_v0;
block_14:
        func_8012AAAC(arg0);
    }
}
