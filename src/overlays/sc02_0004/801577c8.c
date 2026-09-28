/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801577C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern int D_801950E8;

void func_801577C8(s32 arg0) {
    D_801950E8 = 0x12C;
    func_80147078(arg0, 7);
    func_80157808(arg0);
}
