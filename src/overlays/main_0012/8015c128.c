/* Overlay range [8015C128,8015C32C) from MAIN.CD member 0012.
 * SHA256(span)=54303083700161a367183f4cd02acc4df130eddb8d184f5e3d82008382a5303f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001382C(s16, s32 *, s32 *);                 /* extern */
extern s32 D_80180A1C;
void func_80146CA0(void *);                            /* static */
void func_80146DB8(void *, s32 *);                     /* static */
void func_80146E90(void *, s32);                         /* static */
s32 func_80146E98(void *);                          /* static */
void func_80147078(void *, s32);                         /* static */
void func_80147324();                                 /* static */
void func_801473EC(void *);                            /* static */
void func_80147A84(void *);                            /* static */
s32 func_80148AFC(void *);                          /* static */
void func_80149FB0();                                  /* static */
void func_8014C010(void *, s32);                         /* static */
s32 func_8014CC28(void *);                          /* static */
s32 func_8014D738(void *);                          /* static */
s32 func_8014F3E8(void *);                          /* static */
void func_8015BE94(void *);                            /* static */
void func_8015C0C4(void *);                            /* static */
void func_8015C6E0(void *);                            /* static */
extern u16 D_800B99DA;

void func_8015C128(void *arg0) {
    s32 sp20;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 temp_s0;
    s32 temp_v0;

    func_80149FB0();
    if (func_80148AFC(arg0) & 0xFF) {
        sp10 = 0;
        sp14 = 0;
        sp18 = -0x4000;
        func_8001382C(arg0->unk20->unk12, &sp10, &sp20);
        arg0->unk234 = (s32) (arg0->unk234 + sp20);
        arg0->unk238 = (s32) (arg0->unk238 + sp24);
        arg0->unk23C = (s32) (arg0->unk23C + sp28);
    }
    func_8001382C((s16) ((s32) (u16) arg0->unk20->unk12 * -1), arg0 + 0x234, &sp20);
    func_80146DB8(arg0, &sp20);
    func_80147A84(arg0);
    func_801473EC(arg0);
    if (!(D_800B99DA & 3)) {
        func_8014C010(arg0, 1);
        func_80147324(0x65F);
    }
    if (func_8014D738(arg0) != 0) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_8015C6E0(arg0);
        return;
    }
    temp_s0 = func_8014CC28(arg0);
    temp_v0 = func_8014F3E8(arg0);
    if (temp_v0 != 0) {
        if ((temp_v0 & 0xFF00) != 0x4000) {
            func_80146E90(arg0, 6);
            func_80146CA0(arg0);
            return;
        }
        if ((temp_v0 & 0x4000) && (func_80146E98(arg0) != 0)) {
            func_80147078(arg0, 4);
            func_8015C0C4(arg0);
        }
    } else if (temp_s0 == 0) {
        *(D_80180A1C + (arg0->unk0 * 4))(arg0);
        func_80147078(arg0, 3);
        func_8015BE94(arg0);
    }
}
