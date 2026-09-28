/* Native retail instruction export [80058B04,80058B40).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
/* func_80058B04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct {
    s16 x, y, w, h;
    s16 a, b, c, d;
    u8 e, f, g, i;
} S80058B04;

S80058B04 *func_80058B04(S80058B04 *p, s16 x, s16 y, s16 w, s32 h) {
    p->x = x;
    p->y = y;
    p->w = w;
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->f = 0;
    p->e = 0;
    p->i = 0;
    p->g = 0;
    p->h = h;
    return p;
}
