/* Overlay range [8012E014,8012E138) from MAIN.CD member 0012.
 * SHA256(span)=c77eac8744fb2c478938e6bc3cc5ecc62e7aaeaee64feeb7c8eb149a57a160d3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80049CAC(s32, s32);                          /* extern */
void func_8012F0BC(s32, s32 *, void *);                   /* static */
void func_8012F1A4(void *, void *, s32 *);                /* static */
extern s32 D_80126B5C;
extern s32 D_80126B60;
extern s32 D_80126B64;

void func_8012E014(void *arg0) {
    s32 sp30;
    s32 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    void *temp_a0;
    void *temp_a1;

    sp10 = D_80126B5C;
    sp14 = D_80126B60;
    sp18 = D_80126B64;
    func_8012F0BC(arg0->unk20 + 0x34, &sp10, &sp30);
    temp_a1 = arg0->unk20;
    if (temp_a1 != 0) {
        func_80049CAC(temp_a1 + 0x10, temp_a1 + 0x34);
        temp_a0 = arg0->unk20;
        temp_v0 = arg0->unk6 + arg0->unk50;
        temp_a0->unk8 = temp_v0;
        temp_a0->unk48 = (s32) temp_v0;
        temp_v0_2 = arg0->unkA + arg0->unk52;
        temp_a0->unkA = temp_v0_2;
        temp_a0->unk4C = (s32) temp_v0_2;
        temp_v0_3 = arg0->unkE + arg0->unk54;
        temp_a0->unkC = temp_v0_3;
        temp_a0->unk2C = (u16) (temp_a0->unk2C | 1);
        temp_a0->unk50 = (s32) temp_v0_3;
    }
    func_8012F1A4(arg0->unk20 + 0x34, &sp30, &sp20);
    D_80126B5C = sp20;
    D_80126B60 = sp24;
    D_80126B64 = sp28;
}
