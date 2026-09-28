/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014799C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801479BC(s32 a0, s32 a1, s32 a2);
extern void func_801479BC(int a0, int a1, int a2);

void func_8014799C(int a0, int a1) {
    func_801479BC(a0, a1, 0x1F0000);
}
