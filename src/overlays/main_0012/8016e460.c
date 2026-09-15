/* Overlay range [8016E460,8016E5B8) from MAIN.CD member 0012.
 * SHA256(span)=214bac07f34c477a288b86e62605fd0a384c4901295b20b75ca71594a4717f8a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(s16 *, void *);            /* extern */
void func_80017DC4(u16 *, void *);            /* extern */
void func_80048EAC(s32, void *);          /* extern */

void func_8016E460(void *arg0, s32 arg1) {
    u16 sp6A;
    u16 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp48;
    s32 sp40;
    s8 sp3E;
    s8 sp3D;
    s8 sp3C;
    u8 sp3A;
    s8 sp39;
    u8 sp38;
    u8 sp36;
    s8 sp35;
    u8 sp34;
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
    u16 temp_v0_2;
    u32 temp_a1;
    u32 temp_v0;
    u8 temp_v1;

    sp10 = 7;
    sp20 = 0;
    sp18 = 0;
    sp28 = -7;
    sp1A = 3;
    sp2A = 0;
    sp12 = 0;
    sp22 = -3;
    sp2C = 0;
    sp24 = 0;
    sp1C = 0;
    sp14 = 0;
    temp_v1 = M2C_FIELD(arg0, u8 *, 0x30);
    sp40 = 0x50000000;
    temp_a1 = temp_v1 >> 2;
    temp_v0 = temp_a1 >> 2;
    sp3A = temp_v1;
    sp36 = temp_v1;
    sp38 = temp_v1;
    sp34 = temp_v1;
    sp39 = (s8) temp_a1;
    sp35 = (s8) temp_a1;
    sp3C = (s8) temp_v0;
    sp30 = (s8) temp_v0;
    sp3E = (s8) temp_v0;
    sp32 = (s8) temp_v0;
    sp3D = (s8) temp_v0;
    sp31 = (s8) temp_v0;
    temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x2C);
    sp6A = temp_v0_2;
    sp68 = temp_v0_2;
    func_80017DC4(&sp68, &sp48);
    func_80048EAC(arg1, &sp48);
    sp5C = (s32) M2C_FIELD(arg0, s16 *, 6);
    sp60 = (s32) M2C_FIELD(arg0, s16 *, 0xA);
    sp64 = (s32) M2C_FIELD(arg0, s16 *, 0xE);
    func_80017758(&sp10, &sp48);
    sp10 = 3;
    sp20 = 0;
    sp18 = 0;
    sp28 = -3;
    sp1A = 7;
    sp2A = 0;
    sp12 = 0;
    sp22 = -7;
    func_80017758(&sp10, &sp48);
}
