/* Overlay range [8016BD78,8016BEA0) from MAIN.CD member 0012.
 * SHA256(span)=f2c05d6504e2619bc940c55136cd2afb70296a36a3e33ce730fdce432d524fd3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801847F5;
extern s32 D_801847F6;
extern s32 D_801847F9;
extern s32 D_801847FA;
void func_8016BF50();                            /* static */
void func_8016BFA8(void *, u8 *, u8 *, void *);  /* static */
extern u8 D_801847F4;
extern u8 D_801847F8;

void func_8016BD78(void *arg0) {
    u16 temp_v0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x20);
    func_8016BF50();
    if (D_801847F4 != 0) {
        D_801847F4 -= 4;
    }
    if (D_801847F5 != 0) {
        D_801847F5 = (u8) (D_801847F5 - 4);
    }
    if (D_801847F6 != 0) {
        D_801847F6 = (u8) (D_801847F6 - 4);
    }
    if (D_801847F8 != 0) {
        D_801847F8 -= 4;
    }
    if (D_801847F9 != 0) {
        D_801847F9 = (u8) (D_801847F9 - 4);
    }
    if (D_801847FA != 0) {
        D_801847FA = (u8) (D_801847FA - 4);
    }
    temp_v0 = M2C_FIELD(temp_s0, u16 *, 0x18) - 0x80;
    M2C_FIELD(temp_s0, u16 *, 0x18) = temp_v0;
    if (temp_v0 & 0x8000) {
        M2C_FIELD(temp_s0, u16 *, 0x18) = 0U;
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
    }
    M2C_FIELD(temp_s0, u16 *, 0x12) = (u16) ((M2C_FIELD(temp_s0, u16 *, 0x12) + 0x22) & 0xFFF);
    func_8016BFA8(arg0, &D_801847F4, &D_801847F8, temp_s0 + 0x18);
}
