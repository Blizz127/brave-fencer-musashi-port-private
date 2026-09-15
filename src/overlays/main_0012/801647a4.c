/* Overlay range [801647A4,80164864) from MAIN.CD member 0012.
 * SHA256(span)=31cec8b116222ded3a5ea84960e6f4e3a885f71c3635bc24944a3d6f98b9c134.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001C810(void *, void *);                       /* extern */
extern s32 D_80180F4C;
extern s32 D_80180F7E;
extern s32 D_80180F80;
void *func_8014659C();                              /* static */
void func_80146CA0(void *);                            /* static */
void func_80164930(void *);                            /* static */
void func_80164A74(void *, s32);                         /* static */
extern s32 *D_800DF2E0;
extern s16 D_80180F7C;

void func_801647A4(void *arg0) {
    void *temp_v0;

    temp_v0 = func_8014659C();
    arg0->unk20 = temp_v0;
    if (temp_v0 != 0) {
        func_8001C810(temp_v0, &D_800DF2E0);
        temp_v0->unk80 = D_80180F4C;
        temp_v0->unk4 = (s32) (temp_v0->unk4 | 0x50000000);
        temp_v0->unk2C = (u16) (temp_v0->unk2C | 0xB0);
        D_80180F80 = 0x80;
        D_80180F7E = 0x80;
        D_80180F7C = 0x80;
        temp_v0->unk1A = 0;
        arg0->unk60 = 0;
        arg0->unk62 = 0x200;
        func_80164A74(arg0, 0x50000000);
        func_80146CA0(arg0);
        return;
    }
    func_80164930(arg0);
}
