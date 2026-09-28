/* Main-exec range [80058FD0,8005903C) from the SLUS executable.
 * SHA256(span)=f29ac63652f9feece48ea9559c009b69b1f9b52c2046db3c839a2d381ec4e5b9.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058FD0 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
void func_80058FD0(u32 *p, RECT *rect)
{
    s32 n = (rect->w * rect->h + 1) / 2;
    s32 len = n + 4;
    if ((u32)n >= 13) {
        len = 0;
    }
    ((u8 *)p)[3] = len;
    p[1] = 0xA0000000;
    p[2] = *(u32 *)&rect->x;
    p[3] = *(u32 *)&rect->w;
    *(u32 *)((len << 2) + (u8 *)p) = 0x01000000;
}
