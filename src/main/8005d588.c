/* Main-exec range [8005D588,8005D6A0) from the SLUS executable.
 * SHA256(span)=d35a7276f71d07fc34b347422598c57041fa02614c34289ca5859890a30885ee.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072960();                               /* static */
extern s32 D_80072990;
extern s32 D_80072994;
extern s32 D_800729AC;
extern s32 D_800729B0;
extern s32 D_80078998;
extern s32 D_8007899C;

s32 func_8005D588(s32 arg0) {
    s32 temp_s1;

    temp_s1 = (D_800729B0 * 2) | (D_800729AC == 0);
    if (temp_s1 != arg0) {
        D_80072994 = 0;
        if (arg0 & 1) {
            D_800729AC = 0;
            if (D_80078998 >= 0x96) {
                D_80072960(D_80072990);
            }
            D_80078998 = 0;
        } else {
            D_800729AC = 1;
        }
        if (arg0 & 2) {
            D_800729B0 = 1;
            if (D_8007899C >= 0x96) {
                D_80072960(D_80072990 + 0xF0);
            }
            D_8007899C = 0;
        } else {
            D_800729B0 = 0;
        }
        D_80072994 = 1;
    }
    return temp_s1;
}
