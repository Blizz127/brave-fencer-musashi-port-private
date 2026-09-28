/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F28B0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern s32 D_801F9F54;
extern s32 D_801F9DD4;

void func_801F28B0(void) {
    func_80016714(&D_801F9DD4, 0x180);
    D_801F9F54 = 0;
}
