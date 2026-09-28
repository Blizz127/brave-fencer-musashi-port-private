/* Native retail instruction export [80059760,80059888).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059760 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
extern u8 D_8007278A;
extern s16 D_8007278C;
extern s16 D_8007278E;
extern s32 (*D_80072784)(char *, ...);
extern char D_80074154[], D_80074160[], D_80074174[];
void func_80059760(char *name, RECT *r)
{
    switch (D_8007278A) {
    case 1:
        if (r->w > D_8007278C || r->w + r->x > D_8007278C || r->y > D_8007278E ||
            r->y + r->h > D_8007278E || r->w <= 0 || r->x < 0 || r->y < 0 || r->h <= 0) {
            D_80072784(D_80074154, name);
            D_80072784(D_80074160, r->x, r->y, r->w, r->h);
        }
        break;
    case 2:
        D_80072784(D_80074174, name);
        D_80072784(D_80074160, r->x, r->y, r->w, r->h);
        break;
    }
}
