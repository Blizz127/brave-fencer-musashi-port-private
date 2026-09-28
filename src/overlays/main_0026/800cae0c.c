/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800183E0(s32 a0);
extern s32 D_800CBBB8;
extern s32 D_800CBB78;

void func_800CAE0C(void)
{
    func_800183E0((s32)&D_800CBBB8);
    func_800183E0((s32)&D_800CBB78);
}
