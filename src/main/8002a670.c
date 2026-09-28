/* Main-exec range [8002A670,8002A6BC) from the SLUS executable.
 * SHA256(span)=885337f0cc86a65c954b0ff2d27a96c74b458931a17fb7c55491b0698ecc6bd9.
 * Word export for the native seam. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference. */
/* func_8002A670 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern s32 func_8002A728(void);
extern s32 func_8002AA00(s32);
extern s32 func_8002A738(void);
extern s32 func_8002A748(void);

s32 func_8002A670(void) {
    s32 a;

    if (func_8002AA00(func_8002A728() + 1) != 0) {
        a = func_8002A738();
        return a == func_8002A748();
    }
    return 0;
}
