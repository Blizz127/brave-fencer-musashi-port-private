/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157788 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern int D_8018F1C0;
extern void func_801578C0(s32 a0);

void func_80157788(int param_1)
{
    D_8018F1C0 = 300;
    ((void (*)(int, int))func_80147078)(param_1, 7);
    func_801578C0(param_1);
}
