/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CEE44 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8001C044(void);
extern void func_80015310(void);
extern u8 D_800B9A11;
extern s32 D_800CF13C;
extern void func_800167B8(s32);
extern void func_800118AC(void);

void func_800CEE44(void) {
    func_8001C044();
    func_80015310();
    D_800B9A11 = 0;
    D_800CF13C = 0;
    func_800167B8(0);
    func_800118AC();
}
