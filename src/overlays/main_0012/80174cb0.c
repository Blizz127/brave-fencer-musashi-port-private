/* Overlay range [80174CB0,80174E9C) from MAIN.CD member 0012.
 * SHA256(span)=76331d6c5409515687e8190238dfcb57449a14a7b53dcc281160c5926bda9d1a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800123F0(void *, s16);                          /* extern */
void func_80012558(void *, s32);                          /* extern */
void func_800126C4(void *, s16);                          /* extern */
s16 func_80012ABC(s16, s16, s32);                     /* extern */
s16 func_80012C6C(s16, s16, s32);                     /* extern */
void func_80013F3C(void *);                               /* extern */
void func_8012F14C(void *, s16 *, s16 *);                 /* static */
extern s16 D_80126940;
extern s16 D_80126942;
extern s16 D_80126944;

void func_80174CB0(void *arg0, s16 arg1) {
    s16 sp38;
    s16 sp34;
    s16 sp32;
    s16 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp10;
    arg0->unk8 = (s32) func_80012C6C(arg0->unk8, arg0->unkC, 4);
    arg0->unk10 = (s32) func_80012C6C(arg0->unk10, arg0->unk14, 4);
    arg0->unk18 = func_80012ABC(arg0->unk18, arg0->unk20, 4);
    arg0->unk1A = func_80012ABC(arg0->unk1A, arg0->unk22, 4);
    arg0->unk1C = func_80012ABC(arg0->unk1C, arg0->unk24, 4);
    arg0->unk28 = func_80012C6C(arg0->unk28, arg0->unk2E, 0x10);
    arg0->unk2A = func_80012C6C(arg0->unk2A, arg0->unk30, 0x10);
    arg0->unk2C = func_80012C6C(arg0->unk2C, arg0->unk32, 0x10);
    arg0->unk48 = (s32) (arg0->unk28 + D_80126940);
    arg0->unk4C = (s32) (arg0->unk2A + D_80126942);
    arg0->unk50 = (s32) (arg0->unk2C + D_80126944);
    func_80013F3C(&sp10);
    func_800123F0(&sp10, arg0->unk1C);
    func_80012558(&sp10, (arg0->unk1A + arg1) & 0xFFF);
    func_800126C4(&sp10, arg0->unk18);
    sp24 = arg0->unk28 + D_80126940;
    sp28 = arg0->unk2A + D_80126942;
    sp30 = 0;
    sp32 = 0;
    sp2C = arg0->unk2C + D_80126944;
    sp34 = (s16) (s32) arg0->unk10;
    func_8012F14C(&sp10, &sp30, &sp38);
    arg0->unk3C = (s32) sp38;
    arg0->unk40 = (s32) sp3A;
    arg0->unk44 = (s32) sp3C;
}
