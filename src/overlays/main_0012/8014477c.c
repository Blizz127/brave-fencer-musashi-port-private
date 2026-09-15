/* Overlay range [8014477C,80144880) from MAIN.CD member 0012.
 * SHA256(span)=50ff2cd50a551ae0020bcc5ad4093c9ce46ee781ac432b19594415253ba6ee1a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CA1C(void *, s32 (*)());                   /* extern */
extern s32 D_8017FCC0;
extern s32 D_8017FCCC;
void func_8012A828(void *, s32 (*)());                   /* static */
void *func_8012C1B8();                              /* static */
void func_8012CAE4(void *);                            /* static */
extern s32 *D_80000008;

void func_8014477C(void *arg0) {
    s32 temp_v0_2;
    void *temp_v0;
    void *temp_v1;

    temp_v0 = func_8012C1B8();
    arg0->unk20 = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001CA1C(temp_v0, D_8017FCC0);
    temp_v1 = arg0->unk64;
    if (temp_v1->unk0 != 0) {
        arg0->unkFC = (u16) temp_v1->unk36;
        temp_v0_2 = arg0->unk64->unk58;
        if (temp_v0_2 != 0) {
            arg0->unkA = (u16) (*((temp_v0_2 & 0x0FFFFFFF) | (s32) &D_80000008) + (arg0->unkA - 0x30));
        } else {
            arg0->unkA = (u16) (arg0->unkA - 0x60);
        }
    }
    func_8012A828(arg0, D_8017FCCC);
    arg0->unk2 = 1;
    arg0->unk20->unk12 = (s16) ((arg0->unk70 << 0xC) / 3);
    arg0->unk1C = 0x78;
}
