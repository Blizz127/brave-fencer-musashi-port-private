/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178B70 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80178CBC(s32 a0, s32 a1);

s32 func_80178B70(s32 param_1, s32 param_2)
{
    extern void func_80178BF8();
    extern void func_80178CBC();
    extern int D_80181618;

    int *p = &D_80181618;
    *p = ((int)param_2);
    func_80178BF8();
    func_80178CBC(((int)param_1), p - 3);
}
