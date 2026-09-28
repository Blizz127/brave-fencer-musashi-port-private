/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800D3C10;
extern void func_800118AC(void);
extern void func_800CF290(void);

void func_800CEFA8(void) {
    D_800D3C10 -= 4;
    if (D_800D3C10 <= 0) {
        D_800D3C10 = 0;
        func_800118AC();
    }
    func_800CF290();
}
