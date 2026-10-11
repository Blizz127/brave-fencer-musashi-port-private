/* Overlay range [80164864,80164930) from MAIN.CD member 0012.
 * SHA256(span)=3ef68efbadeb6b5e1e9fff83b640b507e6682d128988e13f043c0cfd2a30278a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80164ACC();                            /* static */

void func_80164864(void *arg0) {
    s32 var_s2;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v1;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x20);
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x60) + M2C_FIELD(arg0, u16 *, 0x62);
    M2C_FIELD(arg0, u16 *, 0x60) = temp_v1;
    M2C_FIELD(temp_s0, u16 *, 0x1A) = (u16) (M2C_FIELD(temp_s0, u16 *, 0x1A) + temp_v1);
    var_s2 = 0x2000;
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        var_s2 = 0x4000;
        temp_v0 = M2C_FIELD(temp_s0, u16 *, 0x1C) + 0x100;
        M2C_FIELD(temp_s0, u16 *, 0x1C) = temp_v0;
        M2C_FIELD(temp_s0, u16 *, 0x18) = temp_v0;
        M2C_FIELD(temp_s0, u16 *, 0x12) = (u16) (M2C_FIELD(temp_s0, u16 *, 0x12) + 0x71);
        func_80164ACC();
    } else {
        temp_v0_2 = M2C_FIELD(temp_s0, u16 *, 0x1C) + 0x200;
        M2C_FIELD(temp_s0, u16 *, 0x1C) = temp_v0_2;
        M2C_FIELD(temp_s0, u16 *, 0x18) = temp_v0_2;
        M2C_FIELD(temp_s0, u16 *, 0x12) = (u16) (M2C_FIELD(temp_s0, u16 *, 0x12) - 0x71);
    }
    if (var_s2 < (s16) M2C_FIELD(temp_s0, u16 *, 0x1A)) {
        func_80146CA0(arg0);
    }
}
