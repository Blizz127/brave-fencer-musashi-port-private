/* Native retail instruction export [8003B3D0,8003B45C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003B3D0 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { u32 addr; u32 size; } SpuBlk;
extern SpuBlk *D_8006B5B0;
extern s32 D_8006B574;
s32 func_8003B3D0(u32 addr)
{
    s32 i;
    u32 a;

    addr <<= D_8006B574;
    if (D_8006B5B0 == 0) {
        return 0;
    }
    i = 0;
    while (1) {
        a = D_8006B5B0[i].addr;
        if (!(a & 0x80000000)) {
            if (a & 0x40000000) {
                break;
            }
            a &= 0x0FFFFFFF;
            if (a >= addr) {
                return 1;
            }
            if (addr < a + D_8006B5B0[i].size) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
