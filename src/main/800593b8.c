/* Main-exec range [800593B8,800594CC) from the SLUS executable.
 * SHA256(span)=b0c54910e209fed58c607c42ae94dcf22dd499872d5f01ede4793205daf6f161.
 * Word export for the native seam (m2c produced no draft). */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_800593B8 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct {
    u8 pad0[0x8];
    u8 pad8[0x8];
    void (*f10)(u32);
    u8 pad14[0x28 - 0x14];
    u32 (*f28)(s32);
} GpuFns;
typedef struct { u8 f0, f1, level, reverse; } GpuState;
extern GpuState D_80072788;
extern GpuFns *D_80072780;
extern s32 (*D_80072784)(char *, ...);
extern char D_800740B8[];
s32 func_800593B8(s32 mode)
{
    u8 old = D_80072788.reverse;
    u32 v;

    if (D_80072788.level >= 2) {
        D_80072784(D_800740B8, mode);
    }
    D_80072788.reverse = mode;
    v = D_80072780->f28(8);
    if (D_80072788.reverse) {
        v |= 0x08000080;
    } else {
        v |= 0x08000000;
    }
    D_80072780->f10(v);
    if (D_80072788.f0 == 2) {
        D_80072780->f10(D_80072788.reverse ? 0x20000501 : 0x20000504);
    }
    return old;
}
