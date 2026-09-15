/* Overlay range [8016BBE0,8016BCC0) from MAIN.CD member 0012.
 * SHA256(span)=774d37ed856bd6fa2b3f61c932fdf0fbe01463dca82e656c47d2c0869796f9c2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CF00(void *);                      /* extern */
extern s32 D_801847F5;
extern s32 D_801847F6;
extern s32 D_801847F9;
extern s32 D_801847FA;
void *func_801465C0();                              /* static */
void func_80146C3C(void *);                      /* static */
void func_8016BF34(void *);                      /* static */
void func_8016BF50(void *);                      /* static */
extern s8 D_801847F4;
extern s8 D_801847F8;

void func_8016BBE0(void *arg0) {
    void *temp_v0;

    temp_v0 = func_801465C0();
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    if (temp_v0 != 0) {
        func_8016BF34(arg0);
        func_8016BF50(arg0);
        func_8001CF00(temp_v0);
        M2C_FIELD(temp_v0, s16 *, 0x10) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x14) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x1A) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x18) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x12) = (s16) (M2C_FIELD(arg0, s32 *, 0x2C) * 0x555);
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s16 *, 0x14) = 0;
        D_801847F4 = 0x20;
        D_801847F5 = 0x20;
        D_801847F6 = 0;
        D_801847F8 = 0xC0;
        D_801847F9 = 0xC0;
        D_801847FA = 0;
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        return;
    }
    func_80146C3C(arg0);
}
