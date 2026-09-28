/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015EE7C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_801474EC(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_8014CBF8(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146DB8(s32*, s32*);
extern int D_800D4C48;
extern int D_8018177C;

void func_8015EE7C(s32 param_1)
{
    ((int (*)(void))func_8014CBF8)();
    ((int (*)(int))func_801474EC)(param_1);
    ((int (*)(int, void *))func_80154274)(param_1, &D_800D4C48);
    ((int (*)(int, void *))func_80146DB8)(param_1, &D_8018177C);
    ((int (*)(int, int))func_801477E8)(param_1, 0xFFF40000);
    ((int (*)(int))func_80146CA0)(param_1);
}
