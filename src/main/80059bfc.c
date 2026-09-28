/* Exact retail word export for [80059BFC,80059CF4); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059BFC - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u8 pad0[0x2C];
    void (*f2C)(void *, void *);
} GpuFns;
extern GpuFns *D_80072780;
extern s32 (*D_80072784)(char *, ...);
extern u8 D_8007278A;
extern char D_800741C0[];
extern u8 D_80072844[];
void *func_80059BFC(void *a, void *b)
{
    if (D_8007278A >= 2) {
        D_80072784(D_800741C0, a, b);
    }
    D_80072780->f2C(a, b);
    *(u32 *)a = (u32)D_80072844 & 0xFFFFFF;
    return a;
}
