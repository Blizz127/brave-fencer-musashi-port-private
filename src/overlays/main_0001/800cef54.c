/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEF54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800118AC(void);
extern void func_800CF290(void);

void func_800CEF54(void) {
    extern u16 D_800B99EE;
    extern void func_800CF290(void);
    extern void func_800118AC(void);

    func_800CF290();
    D_800B99EE = D_800B99EE + 1;
    if ((s16)D_800B99EE >= 0x105) {
        func_800118AC();
    }
}
