/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012D624 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_8012D664();

void func_8012D624(s32 a0) {
    u16 sp[3];
    sp[0] = *(u16 *)(a0 + 0x6);
    sp[1] = *(u16 *)(a0 + 0xA);
    sp[2] = *(u16 *)(a0 + 0xE);
    func_8012D664((void *)sp);
}
