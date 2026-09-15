/* Overlay range [8016A73C,8016A890) from MAIN.CD member 0012.
 * SHA256(span)=f6a185b71c04f06aa7fdcd2d90fe478fffa9da6db447f35906971f9e54e3db2f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048EAC(s32, void *);              /* extern */
void func_80048FBC(void *, u16 *, u16 *);     /* extern */
void func_80049A1C(u16 *, void *);            /* extern */
s32 func_8005C49C();                                /* extern */
extern s32 *D_800AE620;

void func_8016A73C(void *arg0) {
    u16 sp34;
    u16 sp32;
    u16 sp30;
    s32 sp10;
    s32 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_4;

    temp_v0 = func_8005C49C();
    sp32 = ((temp_v0 & 0x7F) * 0x10) + 0x400;
    sp30 = ((u32) (temp_v0 & 0x7F00) >> 5) - 0x300;
    sp34 = 0;
    func_80049A1C(&sp30, &sp10);
    func_80048EAC(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), void **, 0x34), s32 *, 0x20) + 0x34, &sp10);
    sp30 = 0;
    sp32 = 0;
    sp34 = -0x50U;
    func_80048FBC(&sp10, &sp30, &sp30);
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) M2C_FIELD(&D_800AE620, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) M2C_FIELD(&D_800AE620, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x4C) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x14);
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(&D_800AE620, s32 *, 0x1C);
    temp_v0_2 = M2C_FIELD(arg0, u16 *, 6) + sp30;
    M2C_FIELD(arg0, u16 *, 6) = temp_v0_2;
    M2C_FIELD(arg0, s32 *, 0x4C) = (s32) (s16) temp_v0_2;
    temp_v0_3 = M2C_FIELD(arg0, u16 *, 0xA) + sp32;
    M2C_FIELD(arg0, u16 *, 0xA) = temp_v0_3;
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) (s16) temp_v0_3;
    temp_v0_4 = M2C_FIELD(arg0, u16 *, 0xE) + sp34;
    M2C_FIELD(arg0, u16 *, 0xE) = temp_v0_4;
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (s16) temp_v0_4;
}
