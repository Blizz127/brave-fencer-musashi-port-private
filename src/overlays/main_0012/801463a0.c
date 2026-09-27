/* Overlay range [801463A0,80146534) from MAIN.CD member 0012.
 * SHA256(span)=7838b43b1082f45f253e7804e5eef5e8d353fee38ccf5ee5abb1d30bf0e8b8e7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801470C0(void *);                               /* static */
void func_80147118(void *);                               /* static */
void func_80147478(void *);                               /* static */
void func_8014B5B0(void *);                               /* static */
void func_8014BDE8(void *);                               /* static */
void func_8014C6F4(void *);                               /* static */
void func_801508F8(void *, u16, u16, s32);                  /* static */
void func_80155150(void *);                               /* static */
void func_80161D88(void *);                               /* static */
extern s32 *D_80126B58;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern void *D_80126B78;
extern s32 D_80126B9C;
extern s32 D_80126BA0;
extern s32 D_80126BE0;
extern u16 D_80126BE2;
extern u16 D_80126BE4;
extern s32 D_80126BE8;
extern u16 D_80126C90;
extern u16 D_80126C92;
extern u16 D_80126C94;
extern s16 D_80126C9E;

void func_801463A0(void) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    void *temp_s0;

    temp_s0 = D_80126B78;
    func_8014C6F4(&D_80126B58);
    func_80155150(&D_80126B58);
    func_801470C0(&D_80126B58);
    func_80147478(&D_80126B58);
    func_80147118(&D_80126B58);
    if (temp_s0 != 0) {
        temp_v0 = D_80126B5E + D_80126C90;
        temp_s0->unk8 = temp_v0;
        temp_s0->unk48 = (s32) temp_v0;
        temp_v0_2 = D_80126B62 + D_80126C92;
        temp_s0->unkA = temp_v0_2;
        temp_s0->unk4C = (s32) temp_v0_2;
        temp_v0_3 = D_80126B66 + D_80126C94;
        temp_s0->unkC = temp_v0_3;
        temp_s0->unk2C = (u16) (temp_s0->unk2C | 0x11);
        temp_s0->unk50 = (s32) temp_v0_3;
    }
    func_8014BDE8(&D_80126B58);
    D_80126BE8.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126BE8.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126BA0 = D_80126B9C;
    D_80126BE0.unk0 = (u16) D_80126B5E;
    D_80126BE2 = D_80126B62;
    D_80126BE4 = D_80126B66;
    D_80126B9C &= 0x3FFFFFFF;
    func_801508F8(&D_80126B58, D_80126B62, D_80126B66, 0x3FFFFFFF);
    D_80126C9E = 0;
    func_8014B5B0(&D_80126B58);
    func_80161D88(&D_80126B58);
}
