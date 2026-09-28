/* Exact retail word export for [8005AD34,8005ADB8); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8005AD34 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
u32 func_8005AD34(RECT *tw)
{
    s32 pat[4];

    if (tw) {
        pat[0] = (tw->x & 0xFF) >> 3;
        pat[2] = (-tw->w & 0xFF) >> 3;
        pat[1] = (tw->y & 0xFF) >> 3;
        pat[3] = (-tw->h & 0xFF) >> 3;
        return 0xE2000000 | (pat[1] << 15) | (pat[0] << 10) | (pat[3] << 5) | pat[2];
    }
    return 0;
}
