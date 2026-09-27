/* Overlay range [8015A2D8,8015A3C8) from MAIN.CD member 0012.
 * SHA256(span)=56a36af8e5635d5495c8ace7b247856135bbde3829c2cb3e3c159f6a6966f681.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180990;
void func_80146CA0(void *);                      /* static */
void func_80146DB8(s32 (*)());               /* static */
void func_8014C010(void *, s32);             /* static */
void func_80154150(void *, s32);             /* static */
void func_80154A74(void *, s32);             /* static */
void func_801553A8(void *);                      /* static */
void func_80172608(void *);                      /* static */

void func_8015A2D8(void *arg0) {
    s32 var_a1;
    u8 temp_v1;

    func_80146DB8(D_80180990);
    if (M2C_FIELD(arg0, s32 *, 0x44) & 0x200) {
        func_80154150(arg0, 0xA);
        func_80154A74(arg0, 0x1C);
        M2C_FIELD(arg0, s32 *, 0x2C) = 0xFFFC0000;
        goto block_11;
    }
    temp_v1 = M2C_FIELD(arg0, u8 *, 0xA9);
    if (temp_v1 != 0x53) {
        if ((s32) temp_v1 < 0x54) {
            if (temp_v1 != 0x41) {
                M2C_FIELD(arg0, s32 *, 0x23C) = 0;
            } else {
                var_a1 = 7;
                goto block_10;
            }
        } else if (temp_v1 != 0x73) {
            M2C_FIELD(arg0, s32 *, 0x23C) = 0;
        } else {
            goto block_9;
        }
    } else {
block_9:
        var_a1 = 6;
block_10:
        func_80154150(arg0, var_a1);
        func_80154A74(arg0, 0x21);
block_11:
        M2C_FIELD(arg0, s32 *, 0x23C) = 0;
    }
    func_8014C010(arg0, 2);
    func_801553A8(arg0);
    func_80172608(arg0);
    func_80146CA0(arg0);
}
