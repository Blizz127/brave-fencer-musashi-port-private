/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017303C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80174684(void *);
extern s16 D_80126B30;
extern s32 D_80127508;
extern s32 func_80173078();

void func_8017303C(void * a0)
{
    D_80127508 = a0;
    D_80126B30 = 1;
    func_80174684((void *)func_80173078);
}
