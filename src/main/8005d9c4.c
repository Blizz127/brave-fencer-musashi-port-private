/* Exact retail word export for [8005D9C4,8005DBD8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8007297C();                                     /* static */
void D_80072980();                                     /* static */
extern s32 D_8007299C;
extern s32 D_800729B4;
extern s32 *D_800729BC;
extern s32 D_800729C0;
void func_8005E13C();                                  /* static */
void func_8005FBA8();                                 /* static */

s32 func_8005D9C4(void *arg0) {
    s32 var_a0;
    s32 *temp_a1;
    s32 *temp_v1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    u16 var_v1;

    D_800729C0->unkA = 0x40U;
    D_800729C0->unkA = 0U;
    D_800729C0->unk8 = 0xD;
    D_800729C0->unkE = 0x88;
    var_a0 = 0x91;
    if (arg0->unkE8 == 8) {
        var_a0 = 0x50;
    }
    func_8005FBA8(var_a0);
    var_v1 = 0x1003;
    if (D_8007299C != 0) {
        var_v1 = 0x3003;
    }
    D_800729C0->unkA = var_v1;
    temp_v0 = *(D_800729B4 + (D_8007299C * 4));
    if (temp_v0 >= 0) {
        if (temp_v0 > 0) {
            do {
                temp_v1 = (D_8007299C * 4) + D_800729B4;
                temp_v0_2 = *temp_v1 - 1;
                *temp_v1 = temp_v0_2;
                D_8007297C(arg0->unkC + (temp_v0_2 * 0xF0));
            } while (*((D_8007299C * 4) + D_800729B4) > 0);
        }
        temp_a1 = (D_8007299C * 4) + D_800729B4;
        if (*temp_a1 == 0) {
            *temp_a1 = -1;
            D_8007297C(arg0, temp_a1);
            D_80072980(arg0);
        }
    }
    if (D_800729C0->unk4 & 0x200) {
        D_800729C0->unkA = (u16) (D_800729C0->unkA | 0x10);
        if (D_800729C0->unk4 & 0x200) {
            D_800729C0->unk0 = 1U;
            func_8005E13C();
            return 0;
        }
        *D_800729BC = -0x81;
        goto block_14;
    }
block_14:
    if ((arg0->unk50 == 0) || (var_v0 = 0, (arg0->unk36 == 0))) {
        var_v0 = 1;
        *arg0->unk3C = 0;
    }
    return var_v0;
}
