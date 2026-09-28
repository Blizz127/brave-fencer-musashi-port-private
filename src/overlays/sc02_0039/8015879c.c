/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015879C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147098(s32 *a0);
extern void func_80146C98(s32 *a0, s16 a1);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147084(s32 *a0);
extern void func_801470AC(s32 *a0);
extern s32 D_8019FB20;
extern s32 D_8019FB2C;
extern s32 D_8019FB30;
extern void func_80158880(s32 *param);

void func_8015879C(s32 param_1) {
    D_8019FB20 = 0;
    D_8019FB2C = 1;
    D_8019FB30 = 0;
    *(u8 *)(param_1 + 0xa8) = 0;
    ((void (*)(void))func_80147084)();
    ((void (*)(s32))func_80147098)(param_1);
    ((void (*)(s32))func_801470AC)(param_1);
    ((void (*)(s32, s32))func_80147078)(param_1, 0x1a);
    ((void (*)(s32, s32))func_80146C98)(param_1, 1);
    ((void (*)(s32))func_80158880)(param_1);
}
