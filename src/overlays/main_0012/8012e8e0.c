/* Overlay range [8012E8E0,8012E9C0) from MAIN.CD member 0012.
 * SHA256(span)=228c73ca8cef62b2a9abbc96c2544e2f1217907ec15bbfced72754d894047697.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80049CAC(void *, void *);              /* extern */

void func_8012E8E0(void *arg0, void *arg1) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    void *temp_a0;
    void *temp_a1;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg1, u16 *, 0);
    M2C_FIELD(arg0, u16 *, 0xA) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) M2C_FIELD(arg1, u16 *, 4);
    if (temp_v1 != 0) {
        M2C_FIELD(temp_v1, u16 *, 0x12) = (u16) M2C_FIELD(arg1, u16 *, 6);
        temp_a1 = M2C_FIELD(arg0, void **, 0x20);
        if (temp_a1 != 0) {
            func_80049CAC(temp_a1 + 0x10, temp_a1 + 0x34);
            temp_a0 = M2C_FIELD(arg0, void **, 0x20);
            temp_v0 = M2C_FIELD(arg0, u16 *, 6) + M2C_FIELD(arg0, u16 *, 0x50);
            M2C_FIELD(temp_a0, s16 *, 8) = temp_v0;
            M2C_FIELD(temp_a0, s32 *, 0x48) = (s32) temp_v0;
            temp_v0_2 = M2C_FIELD(arg0, u16 *, 0xA) + M2C_FIELD(arg0, u16 *, 0x52);
            M2C_FIELD(temp_a0, s16 *, 0xA) = temp_v0_2;
            M2C_FIELD(temp_a0, s32 *, 0x4C) = (s32) temp_v0_2;
            temp_v0_3 = M2C_FIELD(arg0, u16 *, 0xE) + M2C_FIELD(arg0, u16 *, 0x54);
            M2C_FIELD(temp_a0, s16 *, 0xC) = temp_v0_3;
            M2C_FIELD(temp_a0, u16 *, 0x2C) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x2C) | 1);
            M2C_FIELD(temp_a0, s32 *, 0x50) = (s32) temp_v0_3;
        }
    }
}
