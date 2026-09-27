/* Overlay range [80156044,8015616C) from MAIN.CD member 0012.
 * SHA256(span)=9af3bee5544e8de9658bfd91c05037b477ff6aca8257c32119bd61a05fd956a9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180240;
extern s32 D_801803A8;
extern s32 D_801803BC;
s32 func_8015616C(void *, u16);                     /* static */
s32 func_801565C0(void *);                          /* static */
void func_80156670(void *, s32, s32, s32, s32, s32); /* static */
void func_801567BC(void *);                      /* static */
void func_80156848(void *, void *, s32);         /* static */
void func_80156A88(void *, void *);              /* static */

void func_80156044(void *arg0, s32 arg1) {
    s32 (*var_v0)();
    s32 temp_s2;
    s32 temp_v0;
    s32 var_v1;
    void *temp_s0;

    if (arg1 & 0x10000) {
        var_v0 = D_801803A8;
        var_v1 = (arg1 & 0xFFFF) * 0x14;
    } else {
        temp_v0 = arg1 & 0xFFFF;
        if (arg1 & 0x20000) {
            var_v0 = D_801803BC;
            var_v1 = temp_v0 * 0x14;
        } else {
            var_v1 = temp_v0 * 0x14;
            var_v0 = D_80180240;
        }
    }
    temp_s0 = var_v1 + var_v0;
    temp_s2 = func_8015616C(arg0, M2C_FIELD(temp_s0, u16 *, 0)) & 0xFFFF;
    if (M2C_FIELD(arg0, u8 *, 0x1A8) != 0) {
        func_80156670(arg0, (s32) M2C_FIELD(temp_s0, u16 *, 0), temp_s2, M2C_FIELD(temp_s0, s32 *, 4), (s32) M2C_FIELD(temp_s0, u8 *, 0xA), (s32) M2C_FIELD(temp_s0, u16 *, 0x12));
        if (M2C_FIELD(temp_s0, u8 *, 0x10) != 0) {
            func_801567BC(arg0);
        }
        func_80156848(arg0, temp_s0, temp_s2);
        func_80156A88(arg0, temp_s0);
        if (func_801565C0(arg0) != 0) {
            M2C_FIELD(arg0, s8 *, 0x1C0) = 1;
        }
    }
}
