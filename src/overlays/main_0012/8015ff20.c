/* Overlay range [8015FF20,8016004C) from MAIN.CD member 0012.
 * SHA256(span)=d6518d628d45aa22d856117a269d231b149aeb2c1f21fd6c544360f5ab7e6c0f.
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
void func_8014BFF4(void *, s32, s32);                    /* static */
void func_80150820(void *, s32);                       /* static */
void func_80154A74(void *, s32);                         /* static */
void func_80159B70(void *);                            /* static */
void func_8016004C(void *);                            /* static */
void func_8016007C();                                  /* static */
void func_80165670(void *, u8);                        /* static */
s32 func_801656E8(void *, s32, s32);                /* static */
void func_80165840(void *);                            /* static */
void func_801658DC(void *);                            /* static */
extern u8 D_80078EC1;
extern u8 D_80078EC2;
extern s32 D_800AE6B0;
extern s16 D_801270C0;

void func_8015FF20(void *arg0) {
    s32 temp_a2;
    u8 temp_v0;

    if (D_800AE6B0 & 0x80FFFFFF) {
        func_8016007C();
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80147078(arg0, 0);
        func_80159B70(arg0);
        return;
    }
    temp_a2 = arg0->unk184;
    if (temp_a2 < 0) {
        func_80150820(arg0, func_801656E8(arg0, temp_a2 & 0xFF, temp_a2) & 0xFF);
    } else {
        if (arg0->unk1A0 != arg0->unk196) {
            arg0->unk1A0 = (u8) temp_a2;
            arg0->unk197 = 0;
            arg0->unkBE = 0;
            arg0->unkBF = 0;
            func_8014BFF4(arg0, 1, temp_a2);
        }
        temp_v0 = arg0->unk1A0;
        D_80078EC1 = temp_v0;
        D_80078EC2 = temp_v0;
        func_80165670(arg0, temp_v0);
        func_80165840(arg0);
        func_801658DC(arg0);
        func_80154A74(arg0, 0x11);
        D_801270C0 = 1;
    }
    func_8016004C(arg0);
}
