/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEFF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800118AC(void);

void func_800CEFF4(void) {
    extern void func_800CF180(void);
    extern void func_800CF114(void);
    extern s32 func_800167F0(s32 arg0);
    extern void func_800118AC(void);

    func_800CF180();
    func_800CF114();
    if (func_800167F0(0) & 0xFFFF) {
        func_800118AC();
    }
}
