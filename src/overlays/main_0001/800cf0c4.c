/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CF0C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800B9A18;
extern void func_800146B0(s32 a0);

void func_800CF0C4(void) {
    extern void func_800CF180(void);
    extern s32 func_800167F0(s32 arg);
    extern void func_800146B0(s32 arg);
    extern u16 D_800B99E6;
    extern s32 D_800B9A18;

    func_800CF180();
    if (func_800167F0(4) & 0xFFFF) {
        D_800B99E6 = 1;
        func_800146B0(1);
        D_800B9A18 = 2;
    }
}
