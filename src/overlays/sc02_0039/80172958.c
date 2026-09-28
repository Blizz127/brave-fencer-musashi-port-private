/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80172958 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80171D1C(void *a0, void *a1, s32 a2);
extern void func_80171A1C(u8 *a0);
s32 func_80171D1C(void * a0, void * a1, s32 a2);
extern s32 func_80174650(s32);
extern s16 D_80126B30;
extern s16 D_80126B36;

void func_80172958(u8 * a0)
{
    if (func_80171D1C(a0, &D_80126B30, *(u8 *)&D_80126B36)) {
        func_80171A1C(a0);
        func_80174650((s32)a0);
    }
}
