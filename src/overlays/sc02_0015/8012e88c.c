/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012E88C - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8012E88C(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x20);
    p[1] = p[1] & 0x7FFFFFFF;
}
