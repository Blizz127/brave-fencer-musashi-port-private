/* Retail word export [8005B684,8005B6AC); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
/* func_8005B684 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u32 *D_8007285C;
extern u8 D_80078874[];

void func_8005B684(u32 arg0) {
    *D_8007285C = arg0;
    D_80078874[arg0 >> 24] = arg0;
}
