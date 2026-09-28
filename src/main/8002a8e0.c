/* Main-exec range [8002A8E0,8002A92C) from the SLUS executable.
 * SHA256(span)=a77e0c7ab6571ca18f7736c988f866af351a915b68654226040dcf59cbb120d4.
 * Word export for the native seam. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8002A8E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8002A998(void);
extern s32 func_8002AA00(s32);
extern s32 func_8002A9A8(void);
extern s32 func_8002A9B8(void);

s32 func_8002A8E0(void) {
    s32 a;

    if (func_8002AA00(func_8002A998() + 1) == 0) {
        return 0;
    }
    a = func_8002A9A8();
    a ^= func_8002A9B8();
    if (a == 0) {
        return 1;
    }
    return 0;
}
