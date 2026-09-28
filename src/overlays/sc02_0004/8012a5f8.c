/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A5F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012A62C(s32);

void func_8012A5F8(void (*a0)(void), s32 a1) {
    func_8012A62C(a1 & 0xFF);
    a0();
}
