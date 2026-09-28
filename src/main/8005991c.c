/* Main-exec range [8005991C,800599B8) from the SLUS executable.
 * SHA256(span)=a0cabb509982a5f3870d30c030decd9b90f4c6ed99cbdb911eb22e29bccf685f.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8005991C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u8 pad0[0x8];
    s32 (*addque2)(void *, void *, s32, u32);
    void *f0C;
} GpuFns;
extern GpuFns *D_80072780;
extern void func_80059760(char *, void *);
extern char D_80074178[];
s32 func_8005991C(void *rect, u8 r, u8 g, u8 b)
{
    func_80059760(D_80074178, rect);
    return D_80072780->addque2(D_80072780->f0C, rect, 8, 0x80000000 | (b << 16) | (g << 8) | r);
}
