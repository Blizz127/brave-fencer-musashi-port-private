/* Main-exec range [80059074,80059188) from the SLUS executable.
 * SHA256(span)=5b0d8f67053d59321e94b81f53d174f65378d58d9fe836f243baa3ce30c5ab84.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059074 - byte-exact against retail at -O2 (tools/register_match.py). */

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
extern s32 (*D_80072784)(char *, ...);
extern char D_80073FA8[], D_80073FC0[], D_80073FD0[], D_80073FE8[], D_80073FF4[], D_80073F80[];
void func_80059074(DRAWENV *env)
{
    D_80072784(D_80073FA8, env->clip.x, env->clip.y, env->clip.w, env->clip.h);
    D_80072784(D_80073FC0, env->ofs[0], env->ofs[1]);
    D_80072784(D_80073FD0, env->tw.x, env->tw.y, env->tw.w, env->tw.h);
    D_80072784(D_80073FE8, env->dtd);
    D_80072784(D_80073FF4, env->dfe);
    D_80072784(D_80073F80, (env->tpage >> 7) & 3, (env->tpage >> 5) & 3, (env->tpage << 6) & 0x7C0,
               ((env->tpage << 4) & 0x100) + ((env->tpage >> 2) & 0x200));
}
