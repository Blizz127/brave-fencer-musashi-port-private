/* Main-exec range [8002A1B4,8002A200) from the SLUS executable.
 * SHA256(span)=85447d38de075cb556948414a0a0b8175c0f800933e33c289858910506f02151.
 * Word export for the native seam. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8002A1B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8002A26C(void);
extern s32 func_8002AA00(s32);
extern s32 func_8002A27C(void);
extern s32 func_8002A28C(void);

s32 func_8002A1B4(void) {
    s32 a;

    a = func_8002A26C();
    if (func_8002AA00(a + 1) == 0) {
        return 0;
    }
    a = func_8002A27C();
    a ^= func_8002A28C();
    if (a == 0) {
        return 1;
    }
    return 0;
}
