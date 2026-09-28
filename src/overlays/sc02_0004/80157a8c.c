/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157A8C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80161D20();

void func_80157A8C(s32 a0) {
    func_80161D20(a0, *(u16 *)(a0 + 0x16E));
    func_8014C010(a0, 1);
}
