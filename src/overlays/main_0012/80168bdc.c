/* Overlay range [80168BDC,80168D58) from MAIN.CD member 0012.
 * SHA256(span)=16465872d600a0f874cdc85c1f695309cef91aa754f6d4c4613a46695e9883c1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048FBC(void *, u16 *, u16 *);     /* extern */
void func_80049A1C(u16 *, void *);            /* extern */
void func_800D2318();                            /* extern */
void *func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */

void func_80168BDC(void *arg0, s32 arg1, s16 arg2, s16 arg3) {
    u16 sp44;
    u16 sp42;
    u16 sp40;
    s32 sp20;
    s16 var_s1;
    s16 var_v0_2;
    s32 var_a0;
    u16 var_v0;
    void *temp_v0;

    func_800D2318();
    sp40 = M2C_FIELD(arg0, u16 *, 0x12);
    sp44 = 0;
    sp42 = M2C_FIELD(arg0, u16 *, 0x16);
    func_80049A1C(&sp40, &sp20);
    sp40 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x2C) < 0) {
        sp44 = -8U;
        var_v0 = -4U;
    } else {
        sp44 = 2;
        var_v0 = -2U;
    }
    sp42 = var_v0;
    func_80048FBC(&sp20, &sp40, &sp40);
    M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) + sp40);
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) + sp42);
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) (M2C_FIELD(arg0, u16 *, 0xE) + sp44);
    var_s1 = 0;
    if (arg3 > 0) {
        var_a0 = arg1 & 0xFFFF;
        do {
            temp_v0 = func_80146A6C(var_a0, arg0, (s16) M2C_FIELD(arg0, u16 *, 6), (s16) M2C_FIELD(arg0, u16 *, 0xA), (s32) (s16) M2C_FIELD(arg0, u16 *, 0xE), (s32) arg2, 0);
            var_v0_2 = var_s1 + 1;
            if (temp_v0 != 0) {
                M2C_FIELD(temp_v0, u16 *, 0x12) = (u16) M2C_FIELD(arg0, u16 *, 0x12);
                M2C_FIELD(temp_v0, u16 *, 0x16) = (u16) M2C_FIELD(arg0, u16 *, 0x16);
                M2C_FIELD(temp_v0, u16 *, 0x1A) = (u16) M2C_FIELD(arg0, u16 *, 0x1A);
                var_v0_2 = var_s1 + 1;
            }
            var_s1 = var_v0_2;
            var_a0 = arg1 & 0xFFFF;
        } while (var_v0_2 < arg3);
    }
}
