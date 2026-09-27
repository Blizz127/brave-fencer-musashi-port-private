/* Overlay range [80164418,80164530) from MAIN.CD member 0012.
 * SHA256(span)=ec6c50fde455d84eaa73b94778f332494cc2c662267276923f8abb7ddba0bcc9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012ABC(s16, s16, s32);               /* extern */
s16 func_8004CFEC(s16, s16);                        /* extern */
void func_80162D88(void *);                      /* static */
void func_80162FC0(void *);                      /* static */
void func_801630C4(void *, s32, s32, s32); /* static */

void func_80164418(void *arg0) {
    s16 sp1A;
    s16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 temp_a0;
    s16 temp_v0;
    void *temp_a1;
    void *temp_s1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x4C);
    temp_s1 = M2C_FIELD(arg0, void **, 0x20);
    temp_a0 = M2C_FIELD(temp_a1, u16 *, 6) - M2C_FIELD(arg0, u16 *, 6);
    sp10 = temp_a0;
    sp12 = M2C_FIELD(temp_a1, u16 *, 0xA) - (M2C_FIELD(arg0, u16 *, 0xA) + 0x1E);
    temp_v0 = M2C_FIELD(temp_a1, u16 *, 0xE) - M2C_FIELD(arg0, u16 *, 0xE);
    sp14 = temp_v0;
    sp1A = func_8004CFEC(temp_a0, temp_v0);
    if (sp14 < 0) {
        sp14 = -sp14;
    }
    if (sp14 == 0) {
        sp18 = 0;
    } else {
        sp18 = func_8004CFEC(-sp12, sp14);
    }
    M2C_FIELD(temp_s1, u16 *, 0x14) = (u16) ((M2C_FIELD(temp_s1, u16 *, 0x14) + 0x71) & 0xFFF);
    M2C_FIELD(temp_s1, s16 *, 0x10) = func_80012ABC(M2C_FIELD(temp_s1, s16 *, 0x10), sp18, 2);
    M2C_FIELD(temp_s1, s16 *, 0x12) = func_80012ABC(M2C_FIELD(temp_s1, s16 *, 0x12), sp1A, 2);
    func_801630C4(arg0, 0, 0, 0x8000);
    func_80162FC0(arg0);
    func_80162D88(arg0);
}
