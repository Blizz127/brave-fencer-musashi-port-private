/* Overlay range [8015D1B8,8015D380) from MAIN.CD member 0012.
 * SHA256(span)=81db4d4bfb325b0f3c05091d15903c66be41d0374cfc347a7acd016774ec565f.
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
extern s32 D_80180BFC;
extern s32 D_80180C00;
extern s32 D_80180C44;
void func_80146DB8(void *, void *);                    /* static */
void func_80146E90(void *, s32);                         /* static */
void func_80147078(void *, s32);                         /* static */
void func_80147324(s32, s16);                            /* static */
void func_801477E8(void *, s32);                       /* static */
s32 func_80148800(void *);                          /* static */
void func_80149724(void *);                            /* static */
void func_80149FB0();                                  /* static */
s32 func_8014E6A0(void *);                          /* static */
void func_8014FA04(void *);                            /* static */
void func_80154274(void *, void *);                       /* static */
void func_80159B70(void *);                            /* static */
void func_8015D380(void *);                            /* static */
void func_801725F4(void *);                            /* static */
extern s32 *D_800D4C14;

void func_8015D1B8(void *arg0) {
    s16 temp_v0;
    s16 temp_v1_2;
    s16 var_v0;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_v1;
    void *temp_a0;

    func_80149FB0();
    temp_a0 = arg0->unk20;
    temp_v1 = temp_a0->unk10 + arg0->unk236;
    temp_a0->unk10 = (u16) (temp_v1 & 0xFFF);
    temp_v1_2 = arg0->unk244;
    temp_v0 = (s16) arg0->unk20->unk10;
    if ((temp_v0 - temp_v1_2) >= 0) {
        var_v0 = temp_v0 - temp_v1_2;
    } else {
        var_v0 = temp_v1_2 - temp_v0;
    }
    if (var_v0 >= 0x801) {
        func_80147324(0x5E9, temp_v0);
    }
    arg0->unk244 = (s16) arg0->unk20->unk10;
    if (func_80148800(arg0) & 0x40) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80149724(arg0);
        func_80154274(arg0, &D_800D4C14);
        func_80146E90(arg0, 0x10);
        var_v1 = temp_v1 & 0xFFF;
        if (var_v1 < 0) {
            var_v1 += 0x1FF;
        }
        temp_s0 = ((u32) var_v1 >> 9) * 8;
        D_80180C44 = (s32) *(D_80180BFC + temp_s0);
        func_80146DB8(arg0, D_80180C44 - 8);
        func_801477E8(arg0, *(D_80180C00 + temp_s0));
        func_80147324(0x5EA);
        return;
    }
    func_8014FA04(arg0);
    if (func_8014E6A0(arg0) == 0) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80147078(arg0, 0);
        func_80159B70(arg0);
        return;
    }
    func_8015D380(arg0);
    func_801725F4(arg0);
}
