/* Overlay range [80133298,8013339C) from MAIN.CD member 0012.
 * SHA256(span)=b3dd9a9428daa665e522619518c3cc0afb842c6f12c3f16e5e13f16261c3f117.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012B2CC(void *);                            /* static */
void func_8012F0BC(s32, s32 *, void *);                   /* static */
void func_8012F1A4(s32 *, void *, s32 *);                 /* static */
void func_8013339C(s32 *, void *, s32);                /* static */
extern s32 D_80126B5C;
extern s32 D_80126B60;
extern s32 D_80126B64;

void func_80133298(void *arg0) {
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp30;
    s32 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 temp_a2;
    void *temp_v0;

    sp10 = D_80126B5C;
    sp14 = D_80126B60;
    sp18 = D_80126B64;
    func_8012F0BC(arg0->unk20 + 0x34, &sp10, &sp30);
    func_8012B2CC(arg0);
    temp_v0 = arg0->unk20;
    sp40 = temp_v0->unk34;
    sp44 = temp_v0->unk38;
    sp48 = temp_v0->unk3C;
    sp4C = temp_v0->unk40;
    temp_a2 = temp_v0->unk50;
    sp50 = temp_v0->unk44;
    sp54 = temp_v0->unk48;
    sp58 = temp_v0->unk4C;
    sp5C = temp_a2;
    func_8013339C(&sp40, arg0->unk20 + 0x18, temp_a2);
    func_8012F1A4(&sp40, &sp30, &sp20);
    D_80126B5C = sp20;
    D_80126B60 = sp24;
    D_80126B64 = sp28;
}
