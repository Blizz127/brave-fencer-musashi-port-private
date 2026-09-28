/* Exact retail word export for [8005386C,800538BC); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8005386C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s32 w[8]; } Blk32;
extern Blk32 D_800A6558;
void func_8005386C(Blk32 *p)
{
    *p = D_800A6558;
}
