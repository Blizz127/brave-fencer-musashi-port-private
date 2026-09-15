/* Overlay range [8015C0C4,8015C128) from MAIN.CD member 0012.
 * SHA256(span)=a3bb2981808fae7b59ef0cb8f1eb824a9008982fd141aa3e2306d6bd26b976a7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146CA0(void *);                      /* static */
void func_80154150();                     /* static */
void func_801553A8(void *);                      /* static */
extern s16 D_801152B0;
extern s16 D_801152B4;

void func_8015C0C4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x238) = 0x80000;
    M2C_FIELD(arg0, s32 *, 0x234) = (s32) (D_801152B0 << 6);
    M2C_FIELD(arg0, s32 *, 0x23C) = (s32) (D_801152B4 << 6);
    func_80154150(0x11);
    func_801553A8(arg0);
    func_80146CA0(arg0);
}
