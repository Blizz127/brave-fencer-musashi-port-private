/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016F4C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80165770(void);
extern void func_8016F0E4(void);

s32 func_8016F4C4(s32 param_1)
{
    func_8016F0E4();
    ((void (*)(s32))func_80165770)(param_1);
}
