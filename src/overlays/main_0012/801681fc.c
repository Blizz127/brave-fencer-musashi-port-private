/* Overlay range [801681FC,8016829C) from MAIN.CD member 0012.
 * SHA256(span)=59b5e8b8915e485b57e426322f2c04a78ce6ac63727f3f8fe9d0b2516672a3f8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
extern s32 D_801812E5[];
extern s32 D_80181314[];
void func_80166F58(void *, s32, s32, s32); /* static */
extern s32 *D_801812E4;

void func_801681FC(void *arg0) {
    s16 temp_v0;
    s32 temp_a3;

    M2C_FIELD(arg0, s16 *, 0x28) = (s16) (func_80029178(0x81) & 0xFF);
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x2C) * 2;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) *(D_80181314 + M2C_FIELD(arg0, s32 *, 0x2C));
    M2C_FIELD(arg0, s16 *, 0x2A) = (s16) *(&D_801812E4 + temp_v0);
    temp_a3 = M2C_FIELD(arg0, s32 *, 0x2C) & 1;
    M2C_FIELD(arg0, s32 *, 0x2C) = temp_a3;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) *(D_801812E5 + temp_v0);
    func_80166F58(arg0, 4, 4, temp_a3);
    M2C_FIELD(arg0, u16 *, 2) = (u16) (M2C_FIELD(arg0, u16 *, 2) + 1);
}
