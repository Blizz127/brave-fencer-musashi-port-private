/* Overlay range [8016325C,801632E0) from MAIN.CD member 0012.
 * SHA256(span)=d9c554d491e1f1aeea8baaa362e133aecf973a99d5041b7a923e1c4e14a7c790.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146D30(void *);                      /* static */
void func_80162F60();                            /* static */
void func_80162F80(void *, s32);             /* static */
void func_80162FA0(void *, s32);             /* static */
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_8016325C(void *arg0, s32 unused, s32 arg2, s32 arg3) {
    func_80162F60();
    func_80162F80(arg0, arg2);
    func_80162FA0(arg0, arg3);
    D_80127090 = M2C_FIELD(arg0, s32 *, 0x24);
    D_80127094 = M2C_FIELD(arg0, s32 *, 0x28);
    D_80127098 = M2C_FIELD(arg0, s32 *, 0x2C);
    func_80146D30(arg0);
}
