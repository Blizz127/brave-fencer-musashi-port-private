/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80162F80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801479BC(s32 a0, s32 a1, s32 a2);
extern void func_801479BC(int a0, int a1, int a2);

void func_80162F80(s32 arg0, s32 arg1) {
    func_801479BC(arg0, arg1, 0x7F0000);
}
