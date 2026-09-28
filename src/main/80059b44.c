/* Main-exec range [80059B44,80059BFC) from the SLUS executable.
 * SHA256(span)=b6e71f25aa74a05afdd5116ccdd978bd511071f3583139f8330a6be3ee704b4c.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80059B44 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { unsigned addr : 24; unsigned len : 8; } P_TAG;
extern s32 (*D_80072784)(char *, ...);
extern u8 D_8007278A;
extern char D_800741A8[];
extern u8 D_80072844[];
u32 *func_80059B44(u32 *ot, s32 n)
{
    if (D_8007278A >= 2) {
        D_80072784(D_800741A8, ot, n);
    }
    while (--n) {
        ((P_TAG *)ot)->len = 0;
        ((P_TAG *)ot)->addr = (u32)(ot + 1);
        ot++;
    }
    *ot = (u32)D_80072844 & 0xFFFFFF;
    return ot;
}
