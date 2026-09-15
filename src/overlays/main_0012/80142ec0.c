/* Overlay range [80142EC0,80142F68) from MAIN.CD member 0012.
 * SHA256(span)=6b98e49ca953f27ee4f3633f778477b2f514c8f0f8828209cb6d706a5e761ce9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CA1C(void *, s32);                         /* extern */
extern s32 D_8017F9A4;
void func_8012A828(void *, s32);                       /* static */
void *func_8012C1B8();                              /* static */
void func_8012CAE4(void *);                            /* static */
void func_80142B2C(void *);                            /* static */

void func_80142EC0(void *arg0) {
    s16 temp_v1;
    void *temp_v0;

    temp_v0 = func_8012C1B8();
    arg0->unk20 = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001CA1C(temp_v0, 0);
    temp_v1 = ((arg0->unk70 & 0xF) * 0x600) + 0xC00;
    temp_v0->unk1A = temp_v1;
    temp_v0->unk18 = temp_v1;
    arg0->unkFC = 0;
    func_8012A828(arg0, *(D_8017F9A4 + ((arg0->unk70 & 0xF) * 4)));
    func_80142B2C(arg0);
}
