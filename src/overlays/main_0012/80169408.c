/* Overlay range [80169408,8016951C) from MAIN.CD member 0012.
 * SHA256(span)=a8db10cf56e68012ba5adb801d6f5e352182013f49cf6946e1ca416c639b5bbb.
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
void func_80169584(void *);                      /* static */

void func_80169408(void *arg0) {
    s32 sp20;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    void *temp_s1;
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
        temp_s1 = arg0 + 0x38;
        temp_v0 = func_8005C49C();
        sp10 = (temp_v0 & 0x7F) << 5;
        sp12 = (u16) ((u32) (temp_v0 & 0x7F00) >> 3);
        sp14 = 0;
        func_80049A1C(&sp10, &sp20);
        func_80048EAC(temp_s1, &sp20);
        sp10 = 0;
        sp12 = 0;
        sp14 = 2;
        func_80048FBC(&sp20, &sp10, &sp10);
        M2C_FIELD(arg0, u16 *, 0x12) = sp10;
        M2C_FIELD(arg0, u16 *, 0x16) = sp12;
        M2C_FIELD(arg0, u16 *, 0x1A) = sp14;
        sp10 = M2C_FIELD(arg0, u16 *, 6);
        sp12 = M2C_FIELD(arg0, u16 *, 0xA);
        sp14 = M2C_FIELD(arg0, u16 *, 0xE);
        func_800D20C0(&sp10, &sp18, 1);
        func_800D23D0(&sp18);
        func_80049A1C(&sp18, temp_s1);
    }
    func_80169584(arg0);
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
}
