/* Overlay range [8016BFD0,8016C14C) from MAIN.CD member 0012.
 * SHA256(span)=7713f489577ebddec36f90a5f4b11764ede1bedcd3a1ea38658f416bdb20fa19.
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
void func_80013F3C(void *);                               /* extern */
void func_80017714(void *);                            /* extern */
void func_80020F34(void *, u16 *);                        /* extern */
extern s32 D_801815C8;
extern s32 D_801815D0;
extern s32 D_801815D8;
extern s32 D_801815E0;
void func_8012EFB8(u16 *, u16 *);                      /* static */
void func_8012F14C(void *, s32 (*)(), void *, s16);         /* static */

void func_8016BFD0(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    u16 sp5C;
    u16 sp5A;
    u16 sp58;
    u16 sp54;
    u16 sp52;
    u16 sp50;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp10;
    void *temp_s2;

    temp_s2 = arg0->unk20;
    arg4->unk30 = 0x50000000;
    arg4->unk23 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    arg4->unk27 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    arg4->unk2B = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    arg4->unk2F = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    sp50 = arg0->unk6;
    sp52 = arg0->unkA;
    sp54 = arg0->unkE;
    func_8012EFB8(&sp50, &sp50);
    func_80013F3C(&sp10);
    func_800123F0(&sp10, temp_s2->unk12);
    sp58 = arg3->unk0;
    sp5A = arg3->unk2;
    sp5C = arg3->unk4;
    func_80020F34(&sp10, &sp58);
    sp24 = (s32) (s16) sp50;
    sp28 = (s32) (s16) sp52;
    sp2C = (s32) (s16) sp54;
    func_8012F14C(&sp10, D_801815C8, arg4, (s16) sp54);
    func_8012F14C(&sp10, D_801815D0, arg4 + 8);
    func_8012F14C(&sp10, D_801815D8, arg4 + 0x10);
    func_8012F14C(&sp10, D_801815E0, arg4 + 0x18);
    arg4->unk4 = 0;
    arg4->unkC = 0;
    arg4->unk14 = 0;
    arg4->unk1C = 0;
    func_80017714(arg4);
}
