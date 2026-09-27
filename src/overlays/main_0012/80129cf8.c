/* Overlay range [80129CF8,80129FF4) from MAIN.CD member 0012.
 * SHA256(span)=e5434bd4b699497011d41603ea6ea784ddb5da58c68dab3966a08b08d1eb6543.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012F74(s16, s16, s32, s32);                  /* extern */
void func_80053308(s32);                               /* extern */
void func_80054DCC(void *, s32);                       /* extern */
void func_8012A328();                                  /* static */
extern s32 D_800AE688;
extern s32 D_800AF630;
extern u8 D_801150D6;
extern void *D_801151D4;
extern s32 *D_80126948;
extern s32 D_80126DB8;
extern s32 *D_80126E60;
extern s32 *D_80126F04;
extern s32 *D_80126FA8;
extern u8 D_80127504;

void func_80129CF8(void) {
    s32 (*temp_v0)();
    void *var_s0;
    s32 temp_a1;

    func_8012A328();
    if (D_801150D6 == 1) {
        var_s0 = &D_80126E60;
    } else if (D_801150D6 == 2) {
        var_s0 = &D_80126F04;
    } else {
        var_s0 = &D_80126948;
        if (D_801150D6 == 3) {
            var_s0 = &D_80126FA8;
        }
    }
    temp_v0 = var_s0->unk0;
    if (temp_v0 != 0) {
        temp_v0(var_s0);
    }
    func_80053308(var_s0->unk8);
    if (D_80127504 != 0) {
        D_80126DB8.unk3C = (s32) func_80012F74(D_80126DB8.unk3C, var_s0->unk3C, 2, 1);
        D_80126DB8.unk40 = (s32) func_80012F74(D_80126DB8.unk40, var_s0->unk40, 2, 1);
        D_80126DB8.unk44 = (s32) func_80012F74(D_80126DB8.unk44, var_s0->unk44, 2, 1);
        D_80126DB8.unk48 = (s32) func_80012F74(D_80126DB8.unk48, var_s0->unk48, 2, 1);
        D_80126DB8.unk4C = (s32) func_80012F74(D_80126DB8.unk4C, var_s0->unk4C, 2, 1);
        D_80126DB8.unk50 = (s32) func_80012F74(D_80126DB8.unk50, var_s0->unk50, 2, 1);
        D_80126DB8.unk54 = (s32) func_80012F74(D_80126DB8.unk54, var_s0->unk54, 2, 1);
        D_80127504 -= 1;
    } else {
        D_80126DB8.unk3C = (s32) var_s0->unk3C;
        D_80126DB8.unk40 = (s32) var_s0->unk40;
        D_80126DB8.unk44 = (s32) var_s0->unk44;
        D_80126DB8.unk48 = (s32) var_s0->unk48;
        D_80126DB8.unk4C = (s32) var_s0->unk4C;
        D_80126DB8.unk50 = (s32) var_s0->unk50;
        D_80126DB8.unk54 = (s32) var_s0->unk54;
    }
    var_s0->unk5C = (s32) ((s32) D_80126DB8.unk3C + var_s0->unk7C);
    var_s0->unk60 = (s32) ((s32) D_80126DB8.unk40 + var_s0->unk80);
    var_s0->unk64 = (s32) ((s32) D_80126DB8.unk44 + var_s0->unk84);
    var_s0->unk68 = (s32) ((s32) D_80126DB8.unk48 + var_s0->unk88);
    var_s0->unk6C = (s32) ((s32) D_80126DB8.unk4C + var_s0->unk8C);
    temp_a1 = var_s0->unk94;
    var_s0->unk70 = (s32) ((s32) D_80126DB8.unk50 + var_s0->unk90);
    var_s0->unk78 = (s32) var_s0->unk58;
    var_s0->unk74 = (s32) ((s32) D_80126DB8.unk54 + temp_a1);
    func_80054DCC(var_s0 + 0x5C, temp_a1);
    D_800AF630.unk18 = (s32) D_800AE688.unk0;
    D_800AF630.unk1C = (s32) D_800AE688.unk4;
    D_800AF630.unk20 = (s32) D_800AE688.unk8;
    D_800AF630.unk24 = (s32) D_800AE688.unkC;
    D_800AF630.unk28 = (s32) D_800AE688.unk10;
    D_800AF630.unk2C = (s32) D_800AE688.unk14;
    D_800AF630.unk30 = (s32) D_800AE688.unk18;
    D_800AF630.unk34 = (s32) D_800AE688.unk1C;
    D_801151D4 = var_s0;
}
