/* Main-exec range [80030634,80030730) from the SLUS executable.
 * SHA256(span)=98c4b54bee0d0e860e85eb3d1bbf8773f25c1e4dcb920d00c5a7135ecf95fa21.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80042154(s32, s32, s16);                     /* static */
s32 func_80042374();                               /* static */
extern s32 *D_800A4642;
extern s32 *D_800A4650;
extern s32 D_800A46C0;
extern s32 D_800A46C4;
extern u16 D_800A46CC;
extern s16 D_800A46CE;

s32 func_80030634(void) {
    s16 temp_v0;
    s32 temp_s0;

    if ((func_80042374(0) << 0x10) != 0) {
        temp_s0 = D_800A46CE * 0x18;
        temp_v0 = func_80042154(D_800A46C0 + D_800A46C4, 0x8000, *(&D_800A4642 + temp_s0));
        switch (temp_v0) {                          /* irregular */
        case -2:
            D_800A46C4 += 0x8000;
            return 0;
        case -1:
            *(&D_800A4650 + temp_s0) = 1;
            D_800A46CC += 1;
            return 0;
        default:
            D_800A46CC += 1;
            /* Duplicate return node #7. Try simplifying control flow for better match */
            return 0;
        }
    } else {
        return 0;
    }
}
