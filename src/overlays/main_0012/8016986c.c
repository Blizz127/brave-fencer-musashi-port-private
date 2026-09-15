/* Overlay range [8016986C,801699D0) from MAIN.CD member 0012.
 * SHA256(span)=f6d78042c7ab9f109afbe7b2b5430279522a3167211548e56dbccbb58cb82c0e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048EAC(void *, void *);        /* extern */
void func_80048FBC(void *, u16 *, u16 *);     /* extern */
void func_80049A1C(u16 *, void *);            /* extern */
s32 func_8005C49C();                                /* extern */
void func_800D20C0(u16 *, u16 *, s32);       /* extern */
void func_800D23D0(u16 *);                       /* extern */

void func_8016986C(void *arg0) {
    s32 sp40;
    s32 sp20;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_v0;
    s32 var_v0_2;
    u16 var_v0;
    u32 temp_v0_2;

    sp10 = M2C_FIELD(arg0, u16 *, 6);
    sp12 = M2C_FIELD(arg0, u16 *, 0xA);
    sp14 = M2C_FIELD(arg0, u16 *, 0xE);
    func_800D20C0(&sp10, &sp18, 1);
    func_800D23D0(&sp18);
    func_80049A1C(&sp18, arg0 + 0x38);
    sp10 = M2C_FIELD(arg0, u16 *, 0x12);
    sp12 = M2C_FIELD(arg0, u16 *, 0x16);
    sp14 = M2C_FIELD(arg0, u16 *, 0x1A);
    func_80049A1C(&sp10, &sp40);
    temp_v0 = func_8005C49C();
    sp10 = (temp_v0 & 0x1FC) + 0x180;
    temp_v0_2 = temp_v0 & 0x7F00;
    if (M2C_FIELD(arg0, s32 *, 0x2C) & 2) {
        var_v0 = (temp_v0_2 >> 6) + 0x200;
    } else {
        var_v0 = (temp_v0_2 >> 6) + 0xC00;
    }
    sp12 = var_v0;
    sp14 = 0;
    func_80049A1C(&sp10, &sp20);
    func_80048EAC(&sp40, &sp20);
    var_v0_2 = 0xA00;
    if (!(M2C_FIELD(arg0, s32 *, 0x2C) & 1)) {
        var_v0_2 = 0xE00;
    }
    M2C_FIELD(arg0, s32 *, 0x2C) = var_v0_2;
    sp10 = 0;
    sp12 = 0;
    sp14 = 0xA;
    func_80048FBC(&sp20, &sp10, &sp10);
    M2C_FIELD(arg0, u16 *, 0x12) = sp10;
    M2C_FIELD(arg0, u16 *, 0x16) = sp12;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
    M2C_FIELD(arg0, u16 *, 0x1A) = sp14;
}
