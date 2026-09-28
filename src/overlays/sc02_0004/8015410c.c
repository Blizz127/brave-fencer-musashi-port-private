/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015410C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80151664(void);
void func_80151664(void);
extern s32 D_80127518;

void func_8015410C(void) {
    D_80127518 = 0;
    func_80151664();
}
