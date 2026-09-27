/* Overlay range [80132F40,80133060) from MAIN.CD member 0012.
 * SHA256(span)=0945b9e9d876453a8723459abe8afd91d35067daf1bdde9224e1e1e222dcaef1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012F038(s32, u16 *, void *);                   /* static */
void func_8012F14C(s32, void *, u16 *);                   /* static */
s32 func_80135888(s32, s32, void *, void *);              /* static */
extern s32 *D_80000008;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 *D_80126BE0;

void func_80132F40(void *arg0) {
    s32 sp1F;
    s32 sp1B;
    s8 sp1A;
    s32 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s32 temp_v0;

    sp10 = D_80126B5E;
    sp12 = D_80126B62;
    sp14 = D_80126B66;
    sp1B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp1F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    if (func_80135888(arg0->unk20, arg0->unk58, &D_80126BE0, &sp18) != 0) {
        temp_v0 = (arg0->unk58 & 0x0FFFFFFF) | (s32) &D_80000008;
        if (*temp_v0 < *temp_v0) {

        }
        func_8012F038(arg0->unk20 + 0x34, &sp10, &sp18);
        sp1A = *temp_v0;
        func_8012F14C(arg0->unk20 + 0x34, &sp18, &sp10);
        D_80126B5E = sp10;
        D_80126B62 = sp12;
        D_80126B66 = sp14;
    }
}
