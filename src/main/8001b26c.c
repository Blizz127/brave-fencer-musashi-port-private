/* Main-exec range [8001B26C,8001B324) from the SLUS executable.
 * SHA256(span)=93ede75dcc5c7b45418a5025c064a2f5081de273d076a8ba89427305e4d40b4b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8001ACF0(s32, s32, void *, s32, s32 *); /* static */
s32 func_8001AE90(s32, s32, void *);     /* static */
extern s32 *D_800A2E20;
extern s32 *D_800AEC78;
extern s32 D_800BA1B4;
extern s32 D_800C6D10;
extern s32 D_800C6D34;
extern s32 D_800C7C60;
extern void *D_800C7C64;

void func_8001B26C(void) {
    if (D_800C6D34 == 0) {
        D_800C7C60 = 8;
        D_800C7C64 = &D_800A2E20;
        if (D_800BA1B4 != 0) {
            if (D_800BA1B4 == 3) {
                if (func_8001AE90(0, 0, &D_800AEC78) == 0) {
                    goto block_4;
                }
                goto block_5;
            }
        } else {
block_4:
            if (func_8001ACF0(0, 0, &D_800AEC78, 0, &D_800C7C60) != 0) {
block_5:
                D_800BA1B4 = 0;
            }
        }
    }
    D_800C6D10 = M2C_ERROR(/* Read from unset register $v1 */);
}
