/* Overlay range [8016B834,8016B91C) from MAIN.CD member 0012.
 * SHA256(span)=b34f12ba76ae57dba20f6ffdce610051fdbc741d2e03a269025d148563c739e5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CD9C(void *, void *);              /* extern */
void func_800233CC(void *, u16);                 /* extern */
extern s32 D_801815A0[];
extern s32 D_801815A8[];
extern s32 D_801815B0[];
extern s32 D_801846C0;
void *func_801465C0(s32);                           /* static */

void *func_8016B834(void *arg0, s32 arg1) {
    s32 temp_a1;
    s32 temp_s0;
    s32 temp_s4;
    void *temp_s2;
    void *temp_v0;
    void *temp_v0_2;

    temp_a1 = arg1 << 6;
    temp_s4 = *(D_801815A0 + (M2C_FIELD(arg0, s32 *, 0x2C) * 4));
    temp_s2 = temp_a1 + D_801846C0;
    temp_v0 = func_801465C0(temp_a1);
    if (temp_v0 != 0) {
        func_8001CD9C(temp_v0, temp_s2);
        temp_s0 = arg1 * 2;
        func_800233CC(temp_s2, *(D_801815A8 + temp_s0));
        temp_v0_2 = (arg1 * 8) + temp_s4;
        M2C_FIELD(temp_s2, s32 *, 0) = (s32) M2C_FIELD(temp_v0_2, s32 *, 0);
        M2C_FIELD(temp_s2, s32 *, 4) = (s32) M2C_FIELD(temp_v0_2, s32 *, 4);
        M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) | 0x50040000);
        M2C_FIELD(temp_v0, u16 *, 0x1E) = (u16) *(D_801815B0 + temp_s0);
    }
    return temp_v0;
}
