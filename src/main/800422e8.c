/* Main-exec range [800422E8,80042374) from the SLUS executable.
 * SHA256(span)=efec1a52509d6c00b9f4e1a8a12c428816b4ed4a70521dc1aa115618f3f4d859.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_800422E8 - byte-exact against retail at -O2 (tools/register_match.py). */

extern u16 D_8006B564;
extern s32 D_8006B574;
extern s32 D_8006B584;
extern s32 D_8006B580;
extern void func_8003AE14(s32, u32);
extern u16 func_8003AF4C(s32, u32);
u32 func_800422E8(s32 a0, u32 size)
{
    u32 addr;

    if (size > 0x7EFF0) {
        size = 0x7EFF0;
    }
    addr = D_8006B564 << D_8006B574;
    func_8003AE14(a0, size);
    D_8006B564 = func_8003AF4C(-1, addr + size);
    if (D_8006B584 == 0) {
        D_8006B580 = 0;
    }
    return size;
}
