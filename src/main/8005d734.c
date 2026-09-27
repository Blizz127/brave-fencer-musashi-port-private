/* Native retail instruction export [8005D734,8005D8A0).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_8007295C();                               /* static */
extern s32 D_80072990;
extern s32 D_80072994;
extern s32 D_8007299C;
extern s32 D_800729A0;
extern s32 D_800729A4;
extern s32 D_800729AC;
extern s32 D_800729B0;
extern s32 D_800729C0;
extern s32 D_800729C4;
s32 func_8005D9C4(s32);                             /* static */
void func_8005DBD8(s32);                         /* static */
extern s32 D_80078998;
extern s32 D_8007899C;

s32 func_8005D734(void) {
    s32 temp_v1;

    D_800729C4 = 1;
    if ((D_800729AC != 0) && (D_80078998 < 0x96)) {
        D_80078998 += 1;
    }
    if ((D_800729B0 == 0) && (D_8007899C < 0x96)) {
        D_8007899C += 1;
    }
    if ((D_80072994 != 0) && (D_800729B0 >= D_800729AC)) {
        D_800729A0 = 0;
        D_8007299C = (s32) D_800729AC;
        if (func_8005D9C4(D_80072990 + (D_800729AC * 0xF0)) == 0) {
            D_8007295C(0xFFFF);
        }
        temp_v1 = D_8007299C;
        D_800729A4 = 0;
        if (D_800729B0 >= temp_v1) {
            do {
                func_8005DBD8(D_80072990 + (temp_v1 * 0xF0));
            } while (D_800729B0 >= D_8007299C);
        }
        M2C_FIELD(D_800729C0, s16 *, 0xE) = 0x88;
    }
    return 0;
}
