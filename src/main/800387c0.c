/* Exact retail word export for [800387C0,80038838); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800387C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

s32 func_800387C0(void *arg0) {
    u8 *p;
    s32 v;

    p = *(u8 **)arg0;
    (*(s32 *)arg0)++;
    v = p[0];
    (*(s32 *)arg0) = p + 2;
    v |= p[1] << 8;
    (*(s32 *)arg0) = p + 3;
    v |= p[2] << 16;
    (*(s32 *)arg0) = p + 4;
    v |= p[3] << 24;
    if (v != 0x6B72544D) {
        return -1;
    }
    (*(s32 *)arg0) = p + 8;
    return 0;
}
