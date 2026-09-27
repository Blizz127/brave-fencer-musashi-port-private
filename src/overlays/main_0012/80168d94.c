/* Overlay range [80168D94,80168EC4) from MAIN.CD member 0012.
 * SHA256(span)=62b90d213b2fe8c76b001b550cf8728cd7a338f1a2c3ad0b0757cecd85d39bd2.
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

void func_80168D94(void *arg0) {
    s32 sp38;
    s32 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    u16 var_v0;
    u16 var_v1;

    sp10 = M2C_FIELD(arg0, u16 *, 0x12);
    sp12 = M2C_FIELD(arg0, u16 *, 0x16);
    sp14 = M2C_FIELD(arg0, u16 *, 0x1A);
    func_80049A1C(&sp10, &sp38);
    if (M2C_FIELD(arg0, s32 *, 0x2C) == 0) {
        temp_v0 = func_8005C49C();
        var_v1 = (temp_v0 & 0x7F) * 8;
        var_v0 = ((u32) (temp_v0 & 0x7F00) >> 5) + 0xC00;
    } else {
        temp_v0_2 = func_8005C49C();
        var_v1 = ((temp_v0_2 & 0x7F) * 8) + 0xE00;
        var_v0 = ((u32) (temp_v0_2 & 0x7F00) >> 5) + 0xE00;
    }
    sp10 = var_v1;
    sp12 = var_v0;
    sp14 = 0;
    func_80049A1C(&sp10, &sp18);
    func_80048EAC(&sp38, &sp18);
    sp10 = 0;
    sp12 = 0;
    sp14 = 0x24;
    func_80048FBC(&sp18, &sp10, &sp10);
    M2C_FIELD(arg0, u16 *, 0x12) = sp10;
    M2C_FIELD(arg0, u16 *, 0x16) = sp12;
    M2C_FIELD(arg0, u16 *, 0x10) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg0, u16 *, 0x14) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    M2C_FIELD(arg0, u16 *, 0x18) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
    M2C_FIELD(arg0, u16 *, 0x1A) = sp14;
}
