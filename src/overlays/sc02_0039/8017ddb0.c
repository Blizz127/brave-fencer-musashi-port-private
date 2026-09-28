/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DDB0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*code_fn)(void);
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32);

void func_8017DDB0(int param_1)
{

    extern code_fn D_8019B574[];
    D_8019B574[*(unsigned short *)(param_1 + 2)]();
    ((void (*)(int))func_8012B2CC)(param_1);
    return;
}
