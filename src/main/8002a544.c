/* Main-exec range [8002A544,8002A5C4) from the SLUS executable.
 * SHA256(span)=b51002e0f5933d6770a2d2cd79086913e4f775f509f4425331d545db2562df89.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8002A544 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8002A5C4(s32 arg0);
extern s32 func_8002A728(void);
extern void func_8016E918(s16 a0, s16 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002AAAC(void);
extern u16 D_80063902[][8];

s32 func_8002A544(s32 arg0) {
    s32 idx;

    if (func_8002A5C4(arg0) != 0) {
        idx = func_8002A728();
        func_8016E918(3, (s16)(D_80063902[idx][0] - D_80063902[idx - 1][0]));
        func_8002D4C8(0xB2C, 0);
        func_8002AAAC();
        return 1;
    }
    return 0;
}
