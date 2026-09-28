/* Exact retail word export for [80053804,8005386C); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_80053804 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s32 w[8]; } Blk32;
extern Blk32 D_800A6558;
extern void func_800538BC(void);
void func_80053804(Blk32 *p)
{
    D_800A6558 = *p;
    func_800538BC();
}
