/* Overlay range [8016B4F8,8016B5C0) from MAIN.CD member 0012.
 * SHA256(span)=c362c565bf2f3abffb63cb3407962442f66772f3bcf805eb1a1a6107bec55a61.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015978(s32, s32 (*)());          /* extern */
extern s32 D_801846B8;
s32 func_8016B834(void *, s32);                 /* static */
void func_8016B91C(void *);                      /* static */
void func_8016B984(void *);                      /* static */
s32 func_8016B9F8(void *);                          /* static */

void func_8016B4F8(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_v0;

    func_80015978(arg0 + 4, D_801846B8);
    if ((func_8016B9F8(arg0) != 0) || (M2C_FIELD(arg0, s32 *, 0x18) = 0, M2C_FIELD(arg0, s32 *, 0x14) = 0, M2C_FIELD(arg0, s32 *, 0x10) = 0, temp_v0 = func_8016B834(arg0, 0), M2C_FIELD(arg0, s32 *, 0x10) = temp_v0, (temp_v0 == 0)) || (temp_v0_2 = func_8016B834(arg0, 1), M2C_FIELD(arg0, s32 *, 0x14) = temp_v0_2, (temp_v0_2 == 0)) || (temp_v0_3 = func_8016B834(arg0, 2), M2C_FIELD(arg0, s32 *, 0x18) = temp_v0_3, (temp_v0_3 == 0))) {
        func_8016B984(arg0);
        return;
    }
    func_8016B91C(arg0);
    var_v0 = 0x2D0;
    if (M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
        var_v0 = 0xF0;
    }
    M2C_FIELD(arg0, s32 *, 0x1C) = var_v0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
}
