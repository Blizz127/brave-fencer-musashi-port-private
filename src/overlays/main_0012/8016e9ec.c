/* Overlay range [8016E9EC,8016EAC0) from MAIN.CD member 0012.
 * SHA256(span)=c15e271062dd33d194dd2cf49eebbdd458ec9d22ed12b615abeebee590dde792.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80024054(s32, void *);                       /* extern */
s32 func_800D2CA8(u8, s32);                           /* extern */
void func_800D2D10(s32, s32, s32, s32);                    /* extern */
extern s32 D_8018171C;
extern s32 D_80181734;
extern s32 D_80181738;
void func_8016EC0C(void *, s32);                         /* static */

void func_8016E9EC(void *arg0) {
    s32 temp_s2;
    u8 temp_s0;
    u8 temp_s3;
    u8 temp_s4;

    temp_s0 = arg0->unk0 - 1;
    temp_s3 = *(D_80181734 + temp_s0);
    temp_s2 = *(D_8018171C + (temp_s0 * 4));
    temp_s4 = temp_s0;
    func_800D2D10(func_800D2CA8(arg0->unk3, 0x1C), 1, temp_s3 + temp_s2, 0);
    func_80024054(temp_s2, arg0 + 8);
    arg0->unk3 = temp_s4;
    arg0->unk4 = -0xD7;
    arg0->unk2 = 0;
    arg0->unk6 = (u16) *(D_80181738 + (temp_s0 * 2));
    arg0->unk1 = (u8) (arg0->unk1 + 1);
    func_8016EC0C(arg0, 0x80);
}
