/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172D14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern s16 func_80171AB0(s32 param_1, void * _arg1);
extern s32 func_80174650(s32);
extern s16 D_80126B30;

void func_80172D14(u8 * a0)
{
    if (func_80171AB0(a0, &D_80126B30) == 0) {
        func_80171A1C((u8 *)a0);
        func_80174650(a0);
    }
}
