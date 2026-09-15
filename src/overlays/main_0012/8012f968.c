/* Overlay range [8012F968,8012FB54) from MAIN.CD member 0012.
 * SHA256(span)=473bb0edafd835c92beaa7908a73cf7e12d1993b177cabb9a5f78fd83485c508.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_8012B744(void *, s16 *);                   /* static */
void func_8012C588(s32, void *);                         /* static */
s32 func_80131A34(void *, s32, s32);                  /* static */
void func_80131CA8(void *, s32);                         /* static */
extern s32 *D_80000008;
extern void *D_801151D4;

void func_8012F968(void *arg0) {
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s32 temp_a0;
    s32 temp_v0_2;
    void *temp_s1;
    void *temp_v0;

    temp_s1 = D_801151D4;
    arg0->unkC1 = 0x12;
    if (arg0->unkB4 & 0x10000) {
        sp10 = (s16) temp_s1->unk5C;
        sp12 = (s16) temp_s1->unk60;
        sp14 = (s16) temp_s1->unk64;
        temp_v0 = arg0->unk20;
        arg0->unk5C = 0;
        arg0->unk54 = 0;
        arg0->unk52 = 0;
        arg0->unk50 = 0;
        temp_v0->unk14 = 0;
        temp_v0->unk10 = 0;
        arg0->unk20->unk12 = func_8012B744(arg0 + 4, &sp10);
        temp_a0 = arg0->unk58;
        arg0->unk1C = 0x2D;
        if (temp_a0 != 0) {
            arg0->unkAC = (s16) ((s32) (*((temp_a0 & 0x0FFFFFFF) | (s32) &D_80000008) * 2) >> 1);
        } else {
            arg0->unkAC = 0;
        }
        arg0->unk10 = (s32) (((temp_s1->unk5C - arg0->unk6) << 0x10) / 30);
        arg0->unk14 = (s32) ((((temp_s1->unk60 - arg0->unkA) - arg0->unkAC) << 0x10) / 30);
        temp_v0_2 = temp_s1->unk64 - arg0->unkE;
        arg0->unk98 = 0;
        arg0->unk18 = (s32) ((temp_v0_2 << 0x10) / 30);
        if (func_80131A34(arg0, 0x24, MULT_HI((temp_v0_2 << 0x10), 0x88888889)) == 0) {
            arg0->unkC4 = (s32) (arg0->unkC4 & ~4);
            if (func_80131A34(arg0, 0x20) != 0) {
                arg0->unkC4 = (s32) (arg0->unkC4 | 4);
            } else {
                arg0->unk98 = 0;
            }
        }
        func_8012C588(0x289, arg0);
    }
    func_80131CA8(arg0, 0x35);
}
