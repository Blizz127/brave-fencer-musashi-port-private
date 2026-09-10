/* SC02.CD FILE_031 / ov_SC02_031 retail span [80128CFC,80128D60).
 * Offset 0xBA4 at overlay base 80128158. SHA256(span)=d7c7d67f1a82bd578e47600617d560eec08dee195379b25bc7c4d59d2376ec75.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8017E640->D_8017EEC8; D_80182D1C->D_801A3234.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80128CFC (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): func_80128C98
 * sibling keyed on s16 table D_8017EEC8: negative returns 1,
 * else returns func_8001ABBC(0, 0, &D_800AE830 + (v << 3),
 * D_801A3234, 0). */

extern s16 D_8017EEC8[];
extern u8 D_800AE830;
extern s32 func_8001ABBC(s32 arg0, s32 arg1, void *arg2, s32 arg3, void *arg4);
extern s32 D_801A3234;

s32 func_80128CFC(s32 arg0) {
    s16 v;

    v = D_8017EEC8[arg0];
    if (v < 0) {
        return 1;
    }
    return func_8001ABBC(0, 0, &D_800AE830 + (v << 3), D_801A3234, 0);
}
