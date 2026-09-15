/* Overlay range [8016D4DC,8016D5EC) from MAIN.CD member 0012.
 * SHA256(span)=9c1b9073419294b530947087e7feb38affb24ebdee850bce537b05903959634b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80047E98(s16 *, s16 *);                    /* extern */
void func_800D22E4(void *);                      /* extern */
void func_8016C74C(void *, s16 *, s32, s32, s32); /* static */
void func_8016C83C(void *);                   /* static */
void func_8016CF04(void *, s32);             /* static */
extern s32 *D_80126B58;

void func_8016D4DC(void *arg0) {
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    void *temp_a1;
    s32 var_a2;
    s32 temp_v0;

    temp_a1 = M2C_FIELD(arg0, void **, 0x34);
    if (M2C_FIELD(temp_a1, u16 *, 0) != 1) {
        M2C_FIELD(arg0, s16 *, 2) = 3;
        M2C_FIELD(arg0, void **, 0x34) = &D_80126B58;
        M2C_FIELD(arg0, s32 *, 0x1C) = 0x40;
        func_8016C83C(temp_a1);
        return;
    }
    sp18 = M2C_FIELD(temp_a1, u16 *, 6) - M2C_FIELD(arg0, u16 *, 6);
    sp1A = M2C_FIELD(temp_a1, u16 *, 0xA) - M2C_FIELD(arg0, u16 *, 0xA);
    sp1C = M2C_FIELD(temp_a1, u16 *, 0xE) - M2C_FIELD(arg0, u16 *, 0xE);
    temp_v0 = func_80047E98(&sp18, &sp18);
    if (temp_v0 < 0x510) {
        func_8016CF04(arg0, 2);
        M2C_FIELD(arg0, s16 *, 2) = 4;
        return;
    }
    if (temp_v0 < 0x1900) {
        var_a2 = 6;
    } else {
        var_a2 = 4;
        if (temp_v0 < 0x6400) {
            var_a2 = 5;
        }
    }
    func_8016C74C(arg0, &sp18, var_a2, 9, 0x400);
    func_800D22E4(arg0);
    func_8016CF04(arg0, 1);
}
