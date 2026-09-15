/* Overlay range [8014D4C0,8014D610) from MAIN.CD member 0012.
 * SHA256(span)=cdfe634510760069bafb2f72a4f17f580728a1c5a8063c9fa4394e36ef1fd169.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80135A4C(s32, s32, void *, void *);        /* static */
s32 func_8014C918(void *, u8);                      /* static */

s32 func_8014D4C0(void *arg0, void *arg1, void *arg2) {
    void *temp_s0;

    M2C_FIELD(arg1, u16 *, 2) = (u16) (M2C_FIELD(arg1, u16 *, 2) - 3);
    M2C_FIELD(arg2, u16 *, 2) = (u16) (M2C_FIELD(arg2, u16 *, 2) + 8);
    temp_s0 = M2C_FIELD(arg0, void **, 0x174);
    if (M2C_FIELD(temp_s0, u16 *, 0) != 0) {
        if (!(M2C_FIELD(temp_s0, u16 *, 0x5C) & 0x400) || (M2C_FIELD(temp_s0, s32 *, 0x58) == 0) || (M2C_FIELD(temp_s0, s16 *, 0xA) < M2C_FIELD(arg0, s16 *, 0xA))) {
            if (M2C_FIELD(temp_s0, u16 *, 0) != 0) {
                M2C_FIELD(temp_s0, s8 *, 0x74) = 0;
            }
            goto block_6;
        }
        M2C_FIELD(arg1, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0x98);
        M2C_FIELD(arg1, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 0x9A) - 3);
        M2C_FIELD(arg1, u16 *, 4) = (u16) M2C_FIELD(arg0, u16 *, 0x9C);
        if (func_80135A4C(M2C_FIELD(temp_s0, s32 *, 0x20), M2C_FIELD(temp_s0, s32 *, 0x58), arg1, arg2) == 0) {
            M2C_FIELD(temp_s0, s8 *, 0x74) = 0;
            M2C_FIELD(arg0, void **, 0x174) = 0;
            return 0;
        }
        M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg2, u16 *, 0);
        M2C_FIELD(arg0, s16 *, 0xA) = (s16) M2C_FIELD(arg2, u16 *, 2);
        M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg2, u16 *, 4);
        M2C_FIELD(arg0, s16 *, 0x16E) = (s16) (func_8014C918(arg0, M2C_FIELD(temp_s0, u8 *, 0x75)) & 0xFF);
        return 1;
    }
block_6:
    M2C_FIELD(arg0, void **, 0x174) = 0;
    return 0;
}
