/* Overlay range [8012E138,8012E27C) from MAIN.CD member 0012.
 * SHA256(span)=93ca1d3e6705a7113cb661d490ae5e0b4c4db03109087b529924ce9f02d420c7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80049CAC(s32, s32);                    /* extern */
void func_8012F038(s32, u16 *, void *);       /* static */
void func_8012F14C(void *, void *, void *); /* static */
s32 func_80135888(void *, s32, void *, u16 *);   /* static */
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;

void func_8012E138(void *arg0) {
    s32 sp20;
    s32 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    void *temp_a0;
    void *temp_a1;

    sp10 = D_80126B5E;
    sp12 = D_80126B62;
    sp14 = D_80126B66;
    func_8012F038(M2C_FIELD(arg0, void **, 0x20) + 0x34, &sp10, &sp20);
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
    func_8012F14C(M2C_FIELD(arg0, void **, 0x20) + 0x34, &sp20, &sp18);
    if (func_80135888(M2C_FIELD(arg0, void **, 0x20), M2C_FIELD(arg0, s32 *, 0x58), &sp18, &sp10) != 0) {
        D_80126B5E = sp10;
        D_80126B62 = sp12;
        D_80126B66 = sp14;
    }
}
