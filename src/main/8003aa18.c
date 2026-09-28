/* Main-exec range [8003AA18,8003AAD8) from the SLUS executable.
 * SHA256(span)=b71cc5cd15293ae294f80dca4d0e0161a1a2b2b798ffe22b9205b63d44d4ca53.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003AA18 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_8006B59C;
extern volatile u16 *D_8006B54C;
extern void (*volatile D_8006B584)(void);
extern void func_8003B0E4(void);
extern void func_8005CE68(u32, s32);
void func_8003AA18(void)
{
    u32 i;

    if (D_8006B59C == 0) {
        func_8003B0E4();
    }
    D_8006B54C[0xD5] &= 0xFFCF;
    i = 0;
    while (D_8006B54C[0xD5] & 0x30) {
        if (++i > 0xF00) {
            break;
        }
    }
    if (D_8006B584) {
        D_8006B584();
    } else {
        func_8005CE68(0xF0000009, 0x20);
    }
}
