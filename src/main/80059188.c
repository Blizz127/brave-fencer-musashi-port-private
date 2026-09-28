/* Main-exec range [80059188,80059234) from the SLUS executable.
 * SHA256(span)=3f24c7480bc1481775ada837956957221943282897fcdc7839c7a1dcda82add6.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059188 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
typedef struct { RECT disp; RECT screen; u8 isinter; u8 isrgb24; u8 pad0; u8 pad1; } DISPENV;
extern s32 (*D_80072784)(char *, ...);
extern char D_80074000[];
extern char D_8007401C[];
extern char D_80074038[];
extern char D_80074044[];
void func_80059188(DISPENV *env)
{
    D_80072784(D_80074000, env->disp.x, env->disp.y, env->disp.w, env->disp.h);
    D_80072784(D_8007401C, env->screen.x, env->screen.y, env->screen.w, env->screen.h);
    D_80072784(D_80074038, env->isinter);
    D_80072784(D_80074044, env->isrgb24);
}
