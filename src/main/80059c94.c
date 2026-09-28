/* Main-exec range [80059C94,80059CF4) from the SLUS executable.
 * SHA256(span)=ae32eb8ba06f0cb3569a32707afcda05bb6ab97ed01863939f3d3bc00980c787.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059C94 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u8 pad0[0x14];
    void (*cwc)(u32 *, s32);
    u8 pad18[0x3C - 0x18];
    s32 (*sync)(s32);
} GpuFns;
extern GpuFns *D_80072780;
void func_80059C94(void *p)
{
    s32 len = ((u8 *)p)[3];
    D_80072780->sync(0);
    D_80072780->cwc((u32 *)p + 1, len);
}
