/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80170E70 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_80170EAC(u8 *a0);

void func_80170E70(u8 *a0) {
    func_801719A4((int)a0, 3);
    func_80171990(a0);
    func_80170EAC(a0);
}
