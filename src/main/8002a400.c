/* Main-exec range [8002A400,8002A44C) from the SLUS executable.
 * SHA256(span)=78c807474851e67454d28c8407b51ac781f3597292dee959df26a07d2a6a586f.
 * Word export for the native seam. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8002A400 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8002A4B8(void);
extern s32 func_8002AA00(s32);
extern s32 func_8002A4C8(void);
extern s32 func_8002A4D8(void);

s32 func_8002A400(void) {
    s32 a;

    a = func_8002A4B8();
    if (func_8002AA00(a + 1) == 0) {
        return 0;
    }
    a = func_8002A4C8();
    a ^= func_8002A4D8();
    if (a == 0) {
        return 1;
    }
    return 0;
}
