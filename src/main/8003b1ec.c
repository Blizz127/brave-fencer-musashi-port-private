/* Exact retail word export for [8003B1EC,8003B250); EXE-verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003B1EC - byte-exact against retail at -O2 (tools/register_match.py). */

extern u32 D_8006B544;
void func_8003B1EC(s32 *attr)
{
    if (attr[0] == 0 || (attr[0] & 1)) {
        if (attr[1]) {
            u32 *p = &D_8006B544;
            *p |= 1;
        } else {
            u32 *p = &D_8006B544;
            *p &= ~1;
        }
    }
}
