/* Main-exec range [80017778,800178C8) from the SLUS executable.
 * SHA256(span)=86449607c3a465df6de3b15c857e41fa4385aa7c23c715daf72292c085cca77d.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
void func_80017E8C(s32);                         /* static */
void func_80017F14(void *, s16, s32);            /* static */
void func_80018094(void *, s16, s32);            /* static */
s16 func_8004961C(void *, void *, void *, void *, void *, void *, void *, void *, void *, s32 *); /* static */
void func_80058DE8(void *);                      /* static */

void func_80017778(void *arg0, s32 arg1, s32 arg2) {
    s32 sp2C;
    s32 sp28;
    s16 var_a1;
    void *temp_v0;

    temp_v0 = func_80010A08(0x24);
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x24);
    M2C_FIELD(temp_v0, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(temp_v0, s32 *, 0x1C) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
    func_80058DE8(temp_v0);
    if (arg1 != 0) {
        func_80017E8C(arg1);
        var_a1 = func_8004961C(arg0, arg0 + 8, arg0 + 0x10, arg0 + 0x18, temp_v0 + 8, temp_v0 + 0x10, temp_v0 + 0x18, temp_v0 + 0x20, &sp28, &sp2C);
    } else {
        M2C_FIELD(temp_v0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(temp_v0, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(temp_v0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
        var_a1 = M2C_FIELD(arg0, s16 *, 4);
        sp2C = 0;
    }
    if (!(sp2C & ~0x1000)) {
        if (arg2 != 0) {
            func_80017F14(temp_v0, var_a1, M2C_FIELD(arg0, s32 *, 0x30));
            return;
        }
        func_80018094(temp_v0, var_a1, M2C_FIELD(arg0, s32 *, 0x30));
    }
}
