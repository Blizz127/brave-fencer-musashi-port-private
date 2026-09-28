/* Native retail instruction export [8005D6A0,8005D6CC).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Source: written against Druthulu/BFM-decomp (vendor/bfm-decomp) as reference (libpad1; vendor keeps it as INCLUDE_ASM). */
/* func_8005D6A0 - byte-exact against retail at -O1 (tools/register_match.py). */
#include "psx_types.h"

extern void func_8005D6CC(void);
extern void func_8005D734(void);
extern void *D_8007898C[];

void func_8005D6A0(void) {
    D_8007898C[0] = (void *)func_8005D734;
    D_8007898C[1] = (void *)func_8005D6CC;
    D_8007898C[-1] = 0;
    D_8007898C[2] = 0;
}
