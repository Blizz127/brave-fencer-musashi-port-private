/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCF58 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCF58(void *arg0) {
    void *s0;

    s0 = arg0;
    func_800CCF84();
    *(s16 *)((u8 *)s0 + 0x1C8) = 0;
}
