/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D4D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800167B8(s32 a0);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2);
extern void func_8017D670(void *arg0);

s32 func_8017D4D8(s32 param_1)
{
    ((void (*)(void *, s32))func_8016EDEC)(func_8017D670, 0x1000000);
    func_800167B8(0);
    *(u8 *)(param_1 + 0x15) = *(u8 *)(param_1 + 0x15) + 1;
    return 0;
}
