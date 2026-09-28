/* Main-exec range [80059E6C,80059F88) from the SLUS executable.
 * SHA256(span)=64cea11fda9b19ddcc5ec967dc0047cff5d9c279f5fe6c9a1c5c39a287f86636.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059E6C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s16 x, y, w, h; } RECT;
typedef struct { u32 tag; u32 code[15]; } DR_ENV;
typedef struct {
    RECT clip;
    s16 ofs[2];
    RECT tw;
    u16 tpage;
    u8 dtd;
    u8 dfe;
    u8 isbg;
    u8 r0, g0, b0;
    DR_ENV dr_env;
} DRAWENV;
typedef struct {
    u8 pad0[0x8];
    s32 (*addque2)(void *, void *, s32, s32);
    u8 padC[0x18 - 0xC];
    void *f18;
} GpuFns;
typedef struct { u8 f0, f1, level, f3; u8 pad4[0xC]; DRAWENV draw; } GpuState;
extern GpuState D_80072788;
extern GpuFns *D_80072780;
extern s32 (*D_80072784)(char *, ...);
extern char D_80074204[];
extern void func_8005A870(DR_ENV *, DRAWENV *);
typedef struct { unsigned addr : 24; unsigned len : 8; } P_TAG;
void func_80059E6C(u32 *ot, DRAWENV *env)
{
    if (D_80072788.level >= 2) {
        D_80072784(D_80074204, ot, env);
    }
    func_8005A870(&env->dr_env, env);
    ((P_TAG *)&env->dr_env)->addr = (u32)ot;
    D_80072780->addque2(D_80072780->f18, &env->dr_env, 0x40, 0);
    D_80072788.draw = *env;
}
