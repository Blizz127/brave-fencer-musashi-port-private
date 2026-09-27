/* Overlay range [80168430,801684B4) from MAIN.CD member 0012.
 * SHA256(span)=ea83104c2618feca29c99ae3fc2c45dcc8021f77f83c76ba108c422146db715f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_801812F9[];
extern s32 D_80181320[];
void func_80166F58(s32, s32, s32);   /* static */
extern s32 *D_801812F8;

void func_80168430(void *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x2C) * 2;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) *(D_80181320 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16) *(&D_801812F8 + temp_v0);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) *(D_801812F9 + temp_v0);
    func_80166F58(5, 0x3B, 2);
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
}
