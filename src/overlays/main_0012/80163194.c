/* Overlay range [80163194,80163234) from MAIN.CD member 0012.
 * SHA256(span)=f9bb7d641582330dd9fbf0a802545daa78a4f3ddb537226233b93d358f55a99c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800484EC(s32, s32, s32 *);                   /* extern */
void func_80146D30(s32, s32);                          /* static */
void func_80162F60();                                  /* static */
void func_80162F80(s32, s32);                            /* static */
void func_80162FA0(s32, s32);                            /* static */
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80163194(s32 arg0, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp20;

    func_80162F60();
    func_80162F80(arg0, arg2);
    func_80162FA0(arg0, arg3);
    func_800484EC(arg4, arg0 + 0x24, &sp20);
    D_80127090 = sp20;
    D_80127094 = sp24;
    D_80127098 = sp28;
    func_80146D30(arg0, sp28);
}
