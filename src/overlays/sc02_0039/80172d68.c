/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172D68 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern s32 func_8014C168(s32 * param_1, s32 param_2);
extern s32 func_8014C168(s32 *a0, s32 a1);
extern void func_80174684(void *);
extern s32 D_80127508;
extern s32 func_80172DAC();

void func_80172D68(s32 a0)
{
    D_80127508 = func_8014C168(&D_80126B58, a0);
    func_80174684(func_80172DAC);
}
