/* Exact retail word export for [8005F6CC,8005F704); EXE and assembly verified. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference (vendor keeps this PsyQ routine as INCLUDE_ASM). */
/* func_8005F6CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 D_80078A48[];

s32 func_8005F6CC(u8 *arg0) {
    s32 i;
    s32 r;
    u8 *p;

    i = 0;
    r = 0x10;
    p = D_80078A48;
    while (i < 2) {
        if (arg0 == p) {
            return r;
        }
        r += 0x10;
        i++;
        p += 0xF0;
    }
    return 0xFF;
}
