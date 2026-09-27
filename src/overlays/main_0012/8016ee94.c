/* Overlay range [8016EE94,8016EF78) from MAIN.CD member 0012.
 * SHA256(span)=8446ec1e5215499e66f4a76259f6d66f61d358a73dc03963fdc8e495733140eb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801726D0(void *);                               /* static */
extern s8 D_800B9A17;
extern s32 *D_80126B58;
extern s8 D_80126D1A;
extern s16 D_80126D20;
extern s32 D_80126D50;
extern s32 D_80126D54;
extern s32 D_80126D5C;
extern s32 D_80126D60;
extern s16 D_80126D64;
extern s16 D_80126D66;
extern s16 D_80126D68;
extern s16 D_80126D6A;
extern s8 D_80126D6C;
extern s8 D_80126D6D;
extern s8 D_80126D6E;
extern s32 D_80127058;
extern s32 D_8012705C;
extern s32 D_80127060;
extern s32 D_80127064;
extern s32 D_80127068;
extern s32 D_8012706C;
extern s32 D_80127070;
extern s32 D_80127074;

void func_8016EE94(s32 arg0, s32 arg1) {
    s32 t = arg0 | 0x04000000;
    D_80126D50 = t | arg1;
    D_80126D54 = 0;
    D_80126D6C = 0;
    D_80126D6D = 0;
    D_80126D6E = 0;
    D_80126D5C = 0;
    D_80126D60 = 0;
    D_80126D64 = 0;
    D_80126D66 = 0;
    D_80126D68 = 0;
    D_80126D6A = 0;
    D_80126D1A = 0;
    D_80127058 = 0;
    D_8012705C = 0;
    D_80127060 = 0;
    D_80127064 = 0;
    D_80127068 = 0;
    D_8012706C = 0;
    D_80127070 = 0;
    D_80127074 = 0;
    func_801726D0(&D_80126B58);
    D_800B9A17 = 0;
    D_80126D20 = 0;
}
