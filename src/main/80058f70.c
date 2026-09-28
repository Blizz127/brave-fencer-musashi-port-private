/* Main-exec range [80058F70,80058FD0) from the SLUS executable.
 * SHA256(span)=3474a66b73ddc15d17f0710385bdf88f4cc816b55faf685d836ec49030dc1c22.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058F70 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
typedef struct { u32 tag; u32 code[5]; } DR_MOVE;
void func_80058F70(DR_MOVE *p, RECT *rect, s32 x, s32 y)
{
    s32 len;

    len = 5;
    if (rect->w == 0 || rect->h == 0) {
        len = 0;
    }
    p->code[0] = 0x01000000;
    p->code[1] = 0x80000000;
    ((u8 *)p)[3] = len;
    p->code[2] = *(u32 *)&rect->x;
    p->code[3] = (y << 16) | (x & 0xFFFF);
    p->code[4] = *(u32 *)&rect->w;
}
