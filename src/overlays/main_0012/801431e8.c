/* Overlay range [801431E8,801432FC) from MAIN.CD member 0012.
 * SHA256(span)=0b04b6a0e6960a404ac80ad6895af10f570dd9e7edfc2ae89a5f6e705bf4154b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CA88(void *, void *);                       /* extern */
void func_800233CC(void *, s32);                            /* extern */
extern s32 D_801836A8;
extern s32 D_80184204;
void *func_8012C1B8(s32 (*)());                       /* static */
void func_8012CAE4(void *);                            /* static */
s32 func_8012E504(void *, s32);                       /* static */
void func_80142B2C(void *);                            /* static */
extern s32 *D_80184200;

void func_801431E8(void *arg0) {
    s32 sp13;
    s16 temp_v0_2;
    void *temp_v0;

    sp13 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    temp_v0 = func_8012C1B8(D_801836A8);
    arg0->unk20 = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001CA88(temp_v0, &D_80184200);
    temp_v0->unk76 = -0x10;
    temp_v0_2 = ((arg0->unk70 & 0xF) * 0x600) + 0xC00;
    temp_v0->unk1A = temp_v0_2;
    temp_v0->unk18 = temp_v0_2;
    temp_v0->unk4 = (s32) (temp_v0->unk4 | 0x50000000);
    if (func_8012E504(arg0, 0x33) == 0) {
        arg0->unkFC = 1;
        func_800233CC(&D_80184200, 0x10);
        D_80184204.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    } else {
        arg0->unkFC = 0;
    }
    func_80142B2C(arg0);
}
