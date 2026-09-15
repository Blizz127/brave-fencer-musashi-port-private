/* Overlay range [8012A1BC,8012A2F4) from MAIN.CD member 0012.
 * SHA256(span)=e21b72491ca1c024b5e26bb630846f88b6183cfc6916c84abbfd847676b52b7c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80120200;
extern s32 D_80120204;
extern s32 D_80120208;
extern s32 D_8012020C;
extern u16 D_80120220;
extern u16 D_80120222;
extern u16 D_80120224;
extern u16 D_80120226;
extern u16 D_80120228;
extern u16 D_8012022A;
extern s32 D_80120294;
extern u16 D_80120298;
extern u16 D_8012029A;
extern s32 D_80126950;
extern s32 D_80126954;
extern s32 D_80126958;
extern s32 D_8012695C;
extern s32 D_80126960;
extern s32 D_80126968;
extern u16 D_80126970;
extern u16 D_80126972;
extern u16 D_80126974;
extern u16 D_80126976;
extern u16 D_80126978;
extern u16 D_8012697A;
extern s32 D_801269E4;
extern u16 D_801269E8;
extern u16 D_801269EA;

void func_8012A1BC(void) {
    D_80126950 = D_80120200;
    D_80126954 = D_80120204;
    D_80126958 = D_80120208;
    D_8012695C = D_8012020C;
    D_80126960.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126960.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126968.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126968.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80126978 = D_80120228;
    D_8012697A = D_8012022A;
    D_801269E4 = D_80120294;
    D_801269E8 = D_80120298;
    D_801269EA = D_8012029A;
    D_80126970 = D_80120220;
    D_80126972 = D_80120222;
    D_80126974 = D_80120224;
    D_80126976 = D_80120226;
}
