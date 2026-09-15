/* Overlay range [8014CD80,8014CF04) from MAIN.CD member 0012.
 * SHA256(span)=273daaef7cca41d2a7cfc1ab885851dd05f83958abc15d4ff7234d0303bda392.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135888(s32, s32, void *, void *);        /* static */
s32 func_80135A4C(s32, s32, void *, void *);        /* static */
s32 func_8014C918(void *, u8);                      /* static */

s32 func_8014CD80(void *arg0, void *arg1, void *arg2) {
    s32 var_v1;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x174);
    if (M2C_FIELD(temp_s1, u16 *, 0) != 0) {
        if (!(M2C_FIELD(temp_s1, u16 *, 0x5C) & 0x400) || (M2C_FIELD(temp_s1, s32 *, 0x58) == 0) || (M2C_FIELD(temp_s1, s16 *, 0xA) < M2C_FIELD(arg0, s16 *, 0xA))) {
            if (M2C_FIELD(temp_s1, u16 *, 0) != 0) {
                M2C_FIELD(temp_s1, s8 *, 0x74) = 0;
            }
            goto block_6;
        }
        M2C_FIELD(arg1, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x98);
        M2C_FIELD(arg1, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 0x9A) - 3);
        M2C_FIELD(arg1, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x9C);
        if (M2C_FIELD(temp_s1, u16 *, 0x5C) & 8) {
            M2C_FIELD(arg2, u16 *, 2) = (u16) (M2C_FIELD(arg1, u16 *, 2) + 0xC);
            var_v1 = func_80135A4C(M2C_FIELD(temp_s1, s32 *, 0x20), M2C_FIELD(temp_s1, s32 *, 0x58), arg1, arg2);
            if (var_v1 != 0) {
                temp_v0 = M2C_FIELD(arg2, u16 *, 0);
                M2C_FIELD(arg0, u16 *, 0x78) = temp_v0;
                M2C_FIELD(arg0, u16 *, 6) = temp_v0;
                temp_v0_2 = M2C_FIELD(arg2, u16 *, 2);
                M2C_FIELD(arg0, u16 *, 0x7A) = temp_v0_2;
                M2C_FIELD(arg0, s16 *, 0xA) = (s16) temp_v0_2;
                temp_v0_3 = M2C_FIELD(arg2, u16 *, 4);
                M2C_FIELD(arg0, u16 *, 0x7C) = temp_v0_3;
                M2C_FIELD(arg0, u16 *, 0xE) = temp_v0_3;
                goto block_11;
            }
            goto block_12;
        }
        var_v1 = func_80135888(M2C_FIELD(temp_s1, s32 *, 0x20), M2C_FIELD(temp_s1, s32 *, 0x58), arg1, arg2);
block_11:
        if (var_v1 == 0) {
block_12:
            M2C_FIELD(temp_s1, s8 *, 0x74) = 0;
            M2C_FIELD(arg0, void **, 0x174) = 0;
            return 0;
        }
        M2C_FIELD(arg0, s16 *, 0x16E) = (s16) (func_8014C918(arg0, M2C_FIELD(temp_s1, u8 *, 0x75)) & 0xFF);
        return 1;
    }
block_6:
    M2C_FIELD(arg0, void **, 0x174) = 0;
    return 0;
}
