/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012B1B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_8012B1B4(s32 a0, s32 a1) {
    s32 sp10[4];
    func_800484EC(*(s32 *)(a0 + 0x20) + 0x34, a1, (s32)sp10);
    *(s32 *)(a0 + 0x10) = sp10[0];
    *(s32 *)(a0 + 0x18) = sp10[2];
}
