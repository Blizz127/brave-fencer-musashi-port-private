/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014BC44 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014BC80(s32 a0, s32 a1);
extern u16 D_80078EB2;

void func_8014BC44(s32 a0, s32 a1) {
    if (*(s32 *)((s32)a0 + 0x44) & 0x2000000) {
        a1 = D_80078EB2;
    }
    func_8014BC80(a0, a1);
}
