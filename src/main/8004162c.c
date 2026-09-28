/* Exact retail word export for [8004162C,800416A8); EXE and assembly verified. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8004162C - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u32 addr; u32 size; } SpuBlk;
extern SpuBlk *D_8006B5B0;
extern s32 D_8006B5A8;
extern void func_800416A8(void);
void func_8004162C(u32 addr)
{
    s32 i;

    for (i = 0; i < D_8006B5A8; i++) {
        if (D_8006B5B0[i].addr & 0x40000000) {
            break;
        }
        if (D_8006B5B0[i].addr == addr) {
            D_8006B5B0[i].addr = addr | 0x80000000;
            break;
        }
    }
    func_800416A8();
}
