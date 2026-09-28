/* Main-exec range [80059A1C,80059A80) from the SLUS executable.
 * SHA256(span)=66a605a37c67e8821cf6b7a9cdad2f62d9556dea2e68e6a8cda3c610e79560d4.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059A1C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u8 pad0[0x8];
    s32 (*addque2)(void *, void *, s32, void *);
    u8 padC[0x18 - 0xC];
    void *f18;
    void *f1C;
} GpuFns;
extern GpuFns *D_80072780;
extern void func_80059760(char *, void *);
extern char D_80074190[];
s32 func_80059A1C(void *rect, void *p)
{
    func_80059760(D_80074190, rect);
    return D_80072780->addque2(D_80072780->f1C, rect, 8, p);
}
