/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D64C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_80146C3C(void);
extern short func_8016CBC0(void);
short func_8016CBC0(void);

void func_8016D64C(int param_1)
{
    if (func_8016CBC0() == 0) {
        ((void (*)(int))func_80146C3C)(param_1);
    }
    return;
}
