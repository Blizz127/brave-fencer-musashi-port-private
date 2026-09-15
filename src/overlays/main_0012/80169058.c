/* Overlay range [80169058,801691B8) from MAIN.CD member 0012.
 * SHA256(span)=c7230aea3a6e0a5f96d8d9bec02297485e0954e7b7202fe8c0cb62bc2044ef34.
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

void func_80169058(void *arg0) {
    s32 sp40;
    s32 sp20;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    u16 var_v0;
    u16 var_v1;

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
    if (!(M2C_FIELD(arg0, s32 *, 0x2C) & 2)) {
        temp_v0 = func_8005C49C();
        var_v1 = (temp_v0 & 0x7F) * 8;
        var_v0 = ((u32) (temp_v0 & 0x7F00) >> 5) + 0xC00;
    } else {
        temp_v0_2 = func_8005C49C();
        var_v1 = ((temp_v0_2 & 0x7F) * 8) + 0xE40;
        var_v0 = ((u32) (temp_v0_2 & 0x7F00) >> 5) + 0xE00;
    }
    sp10 = var_v1;
    sp12 = var_v0;
    sp14 = 0;
    func_80049A1C(&sp10, &sp20);
    func_80048EAC(&sp40, &sp20);
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
