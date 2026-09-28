/* Exact retail word export for [8003AF4C,8003AFF0); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003AF4C - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_8006B570;
extern u32 D_8006B578;
extern u32 D_8006B57C;
extern s32 D_8006B574;
extern volatile u16 *D_8006B54C;
u32 func_8003AF4C(s32 idx, u32 addr)
{
    u16 v;

    if (D_8006B570 && (addr % D_8006B578)) {
        addr += D_8006B578;
        addr &= ~D_8006B57C;
    }
    v = addr >> D_8006B574;
    switch (idx) {
    case -1:
        return v;
    case -2:
        return addr;
    }
    D_8006B54C[idx] = v;
    return addr;
}
