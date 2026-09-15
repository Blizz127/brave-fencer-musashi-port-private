/* Overlay range [801372B0,801375EC) from MAIN.CD member 0012.
 * SHA256(span)=f24091a1361be5a350a7fe568410c6fa0f07e4172c9a76b861723ca3c1128db7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80048FBC(void *, u16 *, u16 *);              /* extern */
void func_80051DC8(s32 *, void *, s32, s16);             /* extern */
void func_80137030(s16, s16);                          /* static */
void func_80137178(s16, s16);                          /* static */
extern s32 *D_800A6518;
extern s32 *D_800AF630;
extern u16 D_800B9A02;
extern u8 D_800B9A11;

void func_801372B0(void) {
    s8 sp2E;
    s8 sp2D;
    s8 sp2C;
    s16 sp2A;
    s16 sp28;
    s16 sp26;
    s16 sp24;
    s32 sp20;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_a3;
    s16 temp_a3_2;
    s16 temp_a3_3;
    s16 temp_s0;
    s16 temp_s1;
    s16 temp_s2;
    s16 temp_s4;
    void *temp_s7;

    sp14 = 0;
    sp12 = 0;
    sp10 = 0;
    if (D_800B9A11 != 1) {
        temp_s7 = &D_800AF630 + 0x18;
        sp10 = 0x10;
        func_80048FBC(temp_s7, &sp10, &sp18);
        sp24 = 0x78;
        sp20 = 0;
        sp2C = 0xFF;
        sp2D = 0xFF;
        sp2E = 0xFF;
        sp26 = -0x5A;
        temp_a3 = sp18 + 0x78;
        sp28 = temp_a3;
        sp2A = sp1A - 0x5A;
        func_80051DC8(&sp20, (D_800B9A02 * 0x14) + &D_800A6518, 0, temp_a3);
        sp10 += 6;
        func_80048FBC(temp_s7, &sp10, &sp18);
        sp20 = 0;
        sp2C = 0xFF;
        sp2D = 0;
        sp2E = 0;
        temp_s4 = sp1A - 0x5D;
        temp_s0 = sp18 + 0x7B;
        temp_s2 = sp1A - 0x57;
        temp_s1 = sp18 + 0x75;
        sp24 = temp_s1;
        sp26 = temp_s4;
        sp28 = temp_s0;
        sp2A = temp_s2;
        func_80051DC8(&sp20, (D_800B9A02 * 0x14) + &D_800A6518, 0);
        sp20 = 0;
        sp2C = 0xFF;
        sp2D = 0;
        sp2E = 0;
        sp24 = temp_s0;
        sp26 = temp_s4;
        sp28 = temp_s1;
        sp2A = temp_s2;
        func_80051DC8(&sp20, (D_800B9A02 * 0x14) + &D_800A6518, 0);
        sp10 = 0;
        sp12 = 0x10;
        func_80048FBC(temp_s7, &sp10, &sp18);
        sp24 = 0x78;
        sp20 = 0;
        sp2C = 0xFF;
        sp2D = 0xFF;
        sp2E = 0xFF;
        sp26 = -0x5A;
        temp_a3_2 = sp18 + 0x78;
        sp28 = temp_a3_2;
        sp2A = sp1A - 0x5A;
        func_80051DC8(&sp20, (D_800B9A02 * 0x14) + &D_800A6518, 0, temp_a3_2);
        sp12 += 6;
        func_80048FBC(temp_s7, &sp10, &sp18);
        func_80137030((s16) (sp18 + 0x78), (s16) (sp1A - 0x5A));
        sp12 = 0;
        sp14 = 0x10;
        func_80048FBC(temp_s7, &sp10, &sp18);
        sp24 = 0x78;
        sp20 = 0;
        sp2C = 0xFF;
        sp2D = 0xFF;
        sp2E = 0xFF;
        sp26 = -0x5A;
        temp_a3_3 = sp18 + 0x78;
        sp28 = temp_a3_3;
        sp2A = sp1A - 0x5A;
        func_80051DC8(&sp20, (D_800B9A02 * 0x14) + &D_800A6518, 0, temp_a3_3);
        sp14 += 6;
        func_80048FBC(temp_s7, &sp10, &sp18);
        func_80137178((s16) (sp18 + 0x78), (s16) (sp1A - 0x5A));
    }
}
