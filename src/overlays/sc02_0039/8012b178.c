/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B178 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012B178(s32 a0, s32 a1) {
    s32 sp10[3];
    sp10[2] = a1;
    sp10[1] = 0;
    sp10[0] = 0;
    func_800484EC(*(s32 *)(a0 + 0x20) + 0x34, (s32)sp10, a0 + 0x10);
}
