/* Exact retail word export for [8005AE80,8005AF68); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8005AE80 - byte-exact against retail at -O2 (tools/register_match.py). */

extern volatile u32 *D_80072878;
extern volatile u32 *D_80072874;
extern volatile u32 *D_8007286C;
extern volatile u32 *D_80072870;
extern void func_8005C020(void);
extern s32 func_8005C054(void);
s32 func_8005AE80(u32 *ot, s32 n)
{
    *D_80072878 |= 0x08000000;
    *D_80072874 = 0;
    *D_8007286C = (u32)&ot[n - 1];
    *D_80072870 = n;
    *D_80072874 = 0x11000002;
    func_8005C020();
    while (*D_80072874 & 0x01000000) {
        if (func_8005C054()) {
            return -1;
        }
    }
    return n;
}
