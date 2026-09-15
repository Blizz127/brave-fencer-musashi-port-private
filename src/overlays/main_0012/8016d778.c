/* Overlay range [8016D778,8016D848) from MAIN.CD member 0012.
 * SHA256(span)=c289cf7ca1079d8a17d90f42f621edd95b483cda0353924f874d8f3e99e9dadf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800D20C0(u16 *, void *, s32);   /* extern */
void func_80146C3C(void *, void *);           /* static */
extern s32 D_80126B9C;

void func_8016D778(void *arg0, void *arg1) {
    s32 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    void *var_a1;
    void *temp_a0;

    var_a1 = arg1;
    if ((M2C_FIELD(arg0, s16 *, 0x28) != M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s16 *, 0x36)) || (var_a1 = &sp18, ((D_80126B9C & 0x20) == 0))) {
        func_80146C3C(arg0, var_a1);
        return;
    }
    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(temp_a0, u16 *, 0x18) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x18) ^ 0x400);
    M2C_FIELD(temp_a0, u16 *, 0x1A) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x1A) ^ 0x200);
    sp10 = M2C_FIELD(arg0, u16 *, 0x12);
    sp12 = M2C_FIELD(arg0, u16 *, 0x16);
    sp14 = M2C_FIELD(arg0, u16 *, 0x1A);
    func_800D20C0(&sp10, var_a1, 6);
    M2C_FIELD(arg0, u16 *, 6) = sp10;
    M2C_FIELD(arg0, u16 *, 0xA) = sp12;
    M2C_FIELD(arg0, u16 *, 0xE) = sp14;
}
