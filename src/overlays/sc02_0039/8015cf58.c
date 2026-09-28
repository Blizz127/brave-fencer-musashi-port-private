/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015CF58 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015D01C();

void func_8015CF58(s32 *param_1)
{
    func_80147078(param_1, 0xC);
    ((void (*)(s32 *))func_8015D01C)(param_1);
}
