/* Overlay range [80147C30,80147CC8) from MAIN.CD member 0012.
 * SHA256(span)=7b0bd2810d787769e7707f6b55c3b29403a2b52c398e3474a91dbcb9d83933fd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80147CC8(s32 *);                             /* static */
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147C30(void *arg0) {
    s32 sp18;

    func_80147CC8(&sp18);
    D_80127090 = sp18;
    D_80127098 = sp20;
    D_80127094 = sp1C;
    arg0->unk10 = (s32) D_80127090;
    arg0->unk14 = (s32) D_80127094;
    arg0->unk18 = (s32) D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
