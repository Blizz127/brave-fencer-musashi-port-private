/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801687CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80168828(void);

void func_801687CC(s32 param_1)
{
    if (*(int *)(param_1 + 0x1c) < 3) {
        func_80168828();
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
}
