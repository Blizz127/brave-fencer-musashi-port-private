/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801726D0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80172760(s32 a0);
extern s32 func_80174650(s32);
extern void (*D_80127088)(void);
extern s32 D_801270BC;
extern s16 D_80126B0C;

void func_801726D0(void * _arg0)
{
    D_80127088 = func_80172760;
    D_801270BC = 0;
    D_80126B0C = 0;
    ((void (*)(void))func_80174650)();
}
