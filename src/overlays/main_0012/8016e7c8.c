/* Overlay range [8016E7C8,8016E8F0) from MAIN.CD member 0012.
 * SHA256(span)=4714b0d45805f283cd893c829eefbec0143569028ad8b8837b3d0b3d55b5e4a1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80016ED4(void *, s32, s32, s32);    /* extern */
void func_80017DC4(s32, void *);          /* extern */
void func_8004914C(void *);                   /* extern */
void func_800491AC(void *);                   /* extern */
void func_8004945C(s32 (*)(), void *, void *); /* extern */
extern s32 D_801816CC;
extern s32 D_801816EC;
extern s32 D_801816F4;
extern s32 D_801816FC;
extern s32 D_80181704;

void func_8016E7C8(void *arg0, s32 arg1, s32 *arg2) {
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp50;
    s8 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp28;
    s32 sp20;
    s32 sp18;
    s16 sp14;
    s32 sp10;
    func_80017DC4(arg1, &sp50);
    sp64 = (s32) M2C_FIELD(arg0, s16 *, 6);
    sp68 = (s32) M2C_FIELD(arg0, s16 *, 0xA);
    sp6C = (s32) M2C_FIELD(arg0, s16 *, 0xE);
    func_8004914C(&sp50);
    func_800491AC(&sp50);
    func_8004945C(D_801816CC, &sp10, &sp70);
    func_8004945C(D_801816CC + 8, &sp18, &sp70);
    func_8004945C(D_801816CC + 0x10, &sp20, &sp70);
    func_8004945C(D_801816CC + 0x18, &sp28, &sp70);
    sp14 = 3;
    sp44 = 0x50000000;
    sp30 = D_801816EC;
    sp34 = D_801816F4;
    sp38 = D_801816FC;
    sp3C = D_80181704;
    sp48 = 0x27;
    sp40 = *arg2;
    func_80016ED4(&sp10, D_801816F4, D_801816FC, D_80181704);
}
