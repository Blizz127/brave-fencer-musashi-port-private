/* Exact retail word export for [80059CF4,80059D68); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059CF4 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u8 pad0[0x8];
    s32 (*addque2)(void *, void *, s32, void *);
    u8 padC[0x18 - 0xC];
    void *f18;
    void *f1C;
} GpuFns;
extern GpuFns *D_80072780;
extern s32 (*D_80072784)(char *, ...);
extern u8 D_8007278A;
extern char D_800741D8[];
s32 func_80059CF4(void *x)
{
    if (D_8007278A >= 2) {
        D_80072784(D_800741D8, x);
    }
    return D_80072780->addque2(D_80072780->f18, x, 0, 0);
}
