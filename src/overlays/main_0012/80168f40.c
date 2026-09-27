/* Overlay range [80168F40,8016901C) from MAIN.CD member 0012.
 * SHA256(span)=3e1a122a103c2614c26c8512c84e405298203495a660bbe2fd0e87f8c9732c3f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016A5C(u16 *, s32 *);                /* extern */
extern s32 *D_800AE620;

void func_80168F40(void *arg0) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp28;
    s8 sp26;
    s8 sp25;
    s8 sp24;
    s8 sp22;
    s8 sp21;
    s8 sp20;
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;

    sp10 = M2C_FIELD(arg0, u16 *, 0x10);
    sp12 = M2C_FIELD(arg0, u16 *, 0x14);
    sp14 = M2C_FIELD(arg0, u16 *, 0x18);
    sp18 = M2C_FIELD(arg0, u16 *, 6);
    sp1A = M2C_FIELD(arg0, u16 *, 0xA);
    sp20 = 8;
    sp24 = 0xC0;
    sp22 = 0;
    sp21 = 0;
    sp26 = 0x80;
    sp25 = 0x80;
    sp1C = M2C_FIELD(arg0, u16 *, 0xE);
    sp30 = M2C_FIELD(&D_800AE620, s32 *, 0);
    sp34 = M2C_FIELD(&D_800AE620, s32 *, 4);
    sp38 = M2C_FIELD(&D_800AE620, s32 *, 8);
    sp3C = M2C_FIELD(&D_800AE620, s32 *, 0xC);
    sp40 = M2C_FIELD(&D_800AE620, s32 *, 0x10);
    sp44 = M2C_FIELD(&D_800AE620, s32 *, 0x14);
    sp48 = M2C_FIELD(&D_800AE620, s32 *, 0x18);
    sp4C = M2C_FIELD(&D_800AE620, s32 *, 0x1C);
    sp28 = 0x50000000;
    func_80016A5C(&sp10, &sp30);
}
