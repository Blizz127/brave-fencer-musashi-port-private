/* Native retail instruction export [80058A4C,80058B04).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80058A4C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
typedef struct {
    RECT clip;
    s16 ofs[2];
    RECT tw;
    u16 tpage;
    u8 dtd;
    u8 dfe;
    u8 isbg;
    u8 r0, g0, b0;
} DRAWENV;
extern s32 func_80043078(void);
DRAWENV *func_80058A4C(DRAWENV *env, s32 x, s32 y, s32 w, s32 h)
{
    s32 mode = func_80043078();

    env->clip.x = x;
    env->clip.y = y;
    env->clip.w = w;
    env->tw.x = 0;
    env->tw.y = 0;
    env->tw.w = 0;
    env->tw.h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip.h = h;
    if (mode) {
        env->dfe = h < 289;
    } else {
        env->dfe = h < 257;
    }
    env->ofs[0] = x;
    env->ofs[1] = y;
    env->tpage = 10;
    env->isbg = 0;
    return env;
}
