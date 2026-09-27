/* Overlay range [8016C188,8016C2C4) from MAIN.CD member 0012.
 * SHA256(span)=3585f64f04d6722c86bd4e0e0de321c91f9edefdfc33223fbf030b678f5989df.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(u16 *, void *);               /* extern */
void func_8001CD9C(void *, s32 (*)());       /* extern */
void func_800233CC(s32 (*)(), s32);      /* extern */
extern s32 D_801847B4;
extern s32 D_801847FE;
extern s32 D_80184800;
extern s32 D_80184806;
extern s32 D_80184808;
void *func_801465C0();                              /* static */
void func_80146C3C(void *);                      /* static */
void func_80149350(s32, u16 *, u16 *);           /* static */
void func_8016C374(void *, s16 *, s16 *, s32 (*)()); /* static */
extern s16 D_801847FC;
extern s16 D_80184804;

void func_8016C188(void *arg0) {
    u16 sp14;
    u16 sp12;
    u16 sp10;
    void *temp_v0;

    temp_v0 = func_801465C0();
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(arg0, u16 *, 6);
        M2C_FIELD(arg0, u16 *, 0x16) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
        M2C_FIELD(arg0, u16 *, 0x1A) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
        sp10 = M2C_FIELD(arg0, u16 *, 0x12);
        sp12 = M2C_FIELD(arg0, u16 *, 0x16);
        sp14 = M2C_FIELD(arg0, u16 *, 0x1A);
        func_80149350(M2C_FIELD(arg0, s32 *, 0x34), &sp10, &sp10);
        func_80015954(&sp10, arg0 + 4);
        func_8001CD9C(temp_v0, D_801847B4);
        M2C_FIELD(temp_v0, s16 *, 0x1E) = 0xCCC;
        M2C_FIELD(temp_v0, s32 *, 4) = (s32) (M2C_FIELD(temp_v0, s32 *, 4) | 0x50000000);
        func_800233CC(D_801847B4, 0x80);
        M2C_FIELD(temp_v0, s16 *, 0x1A) = 0;
        M2C_FIELD(temp_v0, s16 *, 0x18) = 0;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        D_801847FC = 0x20;
        D_801847FE = 0x20;
        D_80184800 = 0;
        D_80184804 = 0xC0;
        D_80184806 = 0xC0;
        D_80184808 = 0;
        func_8016C374(arg0, &D_801847FC, &D_80184804, D_801847B4);
        M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
        return;
    }
    func_80146C3C(arg0);
}
