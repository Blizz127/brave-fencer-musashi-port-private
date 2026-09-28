/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEF04 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800D3C10;
extern void func_800118AC(void);
extern void func_800CF290(void);

void func_800CEF04(void) {
    D_800D3C10 += 0x10;
    if (D_800D3C10 >= 0x80) {
        D_800D3C10 = 0x80;
        func_800118AC();
    }
    func_800CF290();
}
