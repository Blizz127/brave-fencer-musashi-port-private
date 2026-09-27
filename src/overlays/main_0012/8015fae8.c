/* Overlay range [8015FAE8,8015FBE0) from MAIN.CD member 0012.
 * SHA256(span)=eb3ab79c9c4799fcf9d6549c0fc8c521aeee2ee5c5ab505b76c6bb060c1ce943.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180A1C;
void func_80147078(void *, s32);                         /* static */
void func_8015BE94(void *);                            /* static */
void func_8015C0C4(void *);                            /* static */
void func_8015FBE0(void *);                            /* static */
void func_8016007C(void *);                            /* static */
s32 func_801612B8();                               /* static */

void func_8015FAE8(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_801612B8(0);
    if ((temp_v0 == 0) || (temp_v0 == 0x8000)) {
        func_8016007C(arg0);
        arg0->unk184 = (s32) (arg0->unk184 | 0x80000000);
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80147078(arg0, 3);
        func_8015BE94(arg0);
        return;
    }
    if (temp_v0 & 0x4000) {
        func_8016007C(arg0);
        arg0->unk184 = (s32) (arg0->unk184 | 0x80000000);
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80147078(arg0, 4);
        func_8015C0C4(arg0);
        return;
    }
    func_8015FBE0(arg0);
}
