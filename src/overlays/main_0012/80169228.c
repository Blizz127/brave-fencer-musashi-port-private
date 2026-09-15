/* Overlay range [80169228,801693CC) from MAIN.CD member 0012.
 * SHA256(span)=108664f4213025ebf530e04d2c9ac0fbd10b102d013c9b36589d76298fba950a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(s16 *, void *);            /* extern */
void func_80017DC4(s16 *, void *);            /* extern */
void func_80048EAC(void *, void *);           /* extern */

void func_80169228(void *arg0) {
    s16 sp6C;
    s16 sp6A;
    s16 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp48;
    s32 sp40;
    s8 sp3E;
    s8 sp3D;
    s8 sp3C;
    s8 sp3A;
    s8 sp39;
    s8 sp38;
    s8 sp36;
    s8 sp35;
    s8 sp34;
    s8 sp32;
    s8 sp31;
    s8 sp30;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp24;
    s16 sp22;
    s16 sp20;
    s16 sp1C;
    s16 sp1A;
    s16 sp18;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s16 temp_v0_3;
    s32 var_v1;
    s8 temp_v0;
    s8 temp_v0_2;

    sp18 = -5;
    sp10 = -5;
    sp28 = 5;
    sp20 = 5;
    sp22 = -5;
    sp12 = -5;
    sp2A = 5;
    sp1A = 5;
    sp2C = 0;
    sp24 = 0;
    sp1C = 0;
    sp14 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0x2C) & 2)) {
        temp_v0 = -0x40 - (M2C_FIELD(arg0, s32 *, 0x1C) * 0x10);
        sp3E = temp_v0;
        sp3D = temp_v0;
        sp3A = temp_v0;
        sp39 = temp_v0;
        sp36 = temp_v0;
        sp35 = temp_v0;
        sp32 = temp_v0;
        sp31 = temp_v0;
        sp3C = temp_v0;
        sp38 = temp_v0;
        sp34 = temp_v0;
        sp30 = temp_v0;
    } else {
        sp3E = 0x20;
        sp3A = 0x20;
        sp34 = 0x20;
        sp30 = 0x20;
        temp_v0_2 = -0x40 - (M2C_FIELD(arg0, s32 *, 0x1C) * 0x10);
        sp3D = temp_v0_2;
        sp39 = temp_v0_2;
        sp35 = temp_v0_2;
        sp31 = temp_v0_2;
        sp3D = 0x20;
        sp39 = 0x20;
    }
    sp40 = 0x50000000;
    var_v1 = 0x800;
    if (M2C_FIELD(arg0, s32 *, 0x2C) & 1) {
        var_v1 = 0x4CC;
    }
    temp_v0_3 = var_v1 + (M2C_FIELD(arg0, s32 *, 0x1C) << 7);
    sp6C = temp_v0_3;
    sp6A = temp_v0_3;
    sp68 = temp_v0_3;
    func_80017DC4(&sp68, &sp48);
    func_80048EAC(arg0 + 0x38, &sp48);
    sp5C = (s32) M2C_FIELD(arg0, s16 *, 6);
    sp60 = (s32) M2C_FIELD(arg0, s16 *, 0xA);
    sp64 = (s32) M2C_FIELD(arg0, s16 *, 0xE);
    func_80017758(&sp10, &sp48);
    sp10 = -7;
    sp20 = 0;
    sp18 = 0;
    sp28 = 7;
    sp2A = 0;
    sp12 = 0;
    sp1A = 7;
    sp22 = -7;
    func_80017758(&sp10, &sp48);
}
