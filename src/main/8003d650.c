/* Exact retail word export [8003D650,8003D6E4); verified against pinned EXE and asm. */
/* Sony PsyQ library routine (vendor/bfm-decomp keeps it as INCLUDE_ASM); C written from the retail disassembly. */
#include "psx_types.h"

/* func_8003D650 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef struct { s32 mask; s32 f04[4]; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; } RvAttr;
extern void func_8003C598(RvAttr *);
void func_8003D650(u8 a, u8 b, u8 c)
{
    RvAttr at;

    if (a == 0) {
        if (b == 0) {
            at.mask = 0x200;
            at.f18 = c;
        }
        if (b == 1) {
            at.mask = 0x100;
            at.f14 = c;
        }
    }
    if (a == 1) {
        if (b == 0) {
            at.mask = 0x2000;
            at.f24 = c;
        }
        if (b == 1) {
            at.mask = 0x1000;
            at.f20 = c;
        }
    }
    func_8003C598(&at);
}
