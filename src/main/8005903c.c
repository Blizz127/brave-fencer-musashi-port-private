/* Main-exec range [8005903C,80059074) from the SLUS executable.
 * SHA256(span)=99da0c1e4c21acae4c348682d809ea425eeac362d3c98e3723f6fdc81a553e0d.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"

/* func_8005903C - byte-exact against retail (tools/register_match.py). */

s32 func_8005903C(void *p0, void *p1)
{
    s32 l = ((u8 *)p0)[3] + ((u8 *)p1)[3] + 1;
    if (l > 16) {
        return -1;
    }
    ((u8 *)p0)[3] = l;
    *(u32 *)p1 = 0;
    return 0;
}
