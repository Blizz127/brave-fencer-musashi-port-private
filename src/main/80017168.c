/* Main-exec range [80017168,80017254) from the SLUS executable.
 * SHA256(span)=025a4f7595ab79e7ecbcd80c5dc488d786ab778cb29aa6410ef8774a625a6902.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
void func_80017E8C(s32);                         /* static */
void func_80018094(void *, s16, s32);            /* static */
s16 func_8004958C(void *, void *, void *, void *, void *, void *, void *, s32 *); /* static */
void func_80058D70(void *);                      /* static */

void func_80017168(void *arg0, s32 arg1) {
    s32 sp24;
    s32 sp20;
    s16 var_a1;
    void *temp_v0;

    temp_v0 = func_80010A08(0x14);
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    func_80058D70(temp_v0);
    if (arg1 != 0) {
        func_80017E8C(arg1);
        var_a1 = func_8004958C(arg0, arg0 + 8, arg0 + 0x10, temp_v0 + 8, temp_v0 + 0xC, temp_v0 + 0x10, &sp20, &sp24);
    } else {
        M2C_FIELD(temp_v0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        var_a1 = M2C_FIELD(arg0, s16 *, 4);
        sp24 = 0;
    }
    if (!(sp24 & ~0x1000)) {
        func_80018094(temp_v0, var_a1, M2C_FIELD(arg0, s32 *, 0x1C));
    }
}
