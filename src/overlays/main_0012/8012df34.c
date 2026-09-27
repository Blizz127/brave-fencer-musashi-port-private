/* Overlay range [8012DF34,8012DFBC) from MAIN.CD member 0012.
 * SHA256(span)=7bb11003d41a70e8208f0196013630a220ef4836fdea1662806429ff64e02f0b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Verified byte-exact against retail by tools/match_function.py
 * (34/34 words at 0x8012DF34). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"
#include "m2c_macros.h"

void func_8012F568(s32, s32, s32, s32, s32, void *); /* static */
s32 func_80135888(s32, s32, s32, s32);          /* static */
extern s32 D_80126B58[];
extern s32 D_801152A8[];

s32 func_8012DF34(void *arg0, s32 arg1, s32 arg2) {
    s32 *p = D_80126B58;

    if ((arg0 != 0) && (M2C_FIELD(arg0, s16 *, 0xAA) != 0)) {
        return 0;
    }
    if (func_80135888(p[8], p[14], arg1, arg2) != 0) {
        func_8012F568(1, 1, 0, 0xA, arg2, D_801152A8);
        return 1;
    }
    return 0;
}
