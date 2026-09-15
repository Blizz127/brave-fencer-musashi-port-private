/* Overlay range [8012C438,8012C51C) from MAIN.CD member 0012.
 * SHA256(span)=ea07a9dcfabda9338ec6a11cb4d4c0061f55f9aeb7be9bdaa173e351f4ade2eb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001C810(s32, s32);                    /* extern */
s32 func_8001CFDC(s32, s32);                /* extern */
void func_8012CAE4(void *);                      /* static */
extern u8 D_80078EAE;

s32 func_8012C438(void *arg0, void *arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v0_2;

    M2C_FIELD(arg0, void **, 0x78) = arg1;
    if (D_80078EAE == 0) {
        var_v0 = M2C_FIELD(arg1, s16 *, 0) * 0x18;
        if (var_v0 < 0) {
            var_v0 += 0xF;
        }
        var_v0_2 = var_v0 >> 4;
    } else {
        var_v0_2 = (s32) (u16) M2C_FIELD(arg1, s16 *, 0);
    }
    M2C_FIELD(arg0, s16 *, 0x76) = (s16) var_v0_2;
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) M2C_FIELD(arg1, u16 *, 2);
    if (M2C_FIELD(arg1, s32 *, 4) != 0) {
        temp_v0 = func_8001CFDC(0x26, 0x85);
        M2C_FIELD(arg0, s32 *, 0x20) = temp_v0;
        if (temp_v0 == 0) {
            func_8012CAE4(arg0);
            return 0;
        }
        func_8001C810(temp_v0, M2C_FIELD(arg1, s32 *, 4));
        goto block_9;
    }
block_9:
    temp_a1 = M2C_FIELD(arg1, s32 *, 8);
    if (temp_a1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_a1 | 0x60000000);
    }
    return 1;
}
