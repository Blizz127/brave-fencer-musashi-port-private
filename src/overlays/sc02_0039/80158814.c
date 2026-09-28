/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80158814 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147098(s32 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147084(s32 *a0);
extern void func_801470AC(s32 *a0);
extern s32 D_8019FB20;
extern s32 D_8019FB2C;
extern s32 D_8019FB30;
extern void func_80158880(s32 *param);

void func_80158814(void *arg0) {
    D_8019FB20 = 0;
    D_8019FB2C = 1;
    D_8019FB30 = 0;
    *(s8 *)((s32)arg0 + 0xA8) = 0;
    ((void (*)(void))func_80147084)();
    ((void (*)(void *))func_80147098)(arg0);
    ((void (*)(void *))func_801470AC)(arg0);
    ((void (*)(void *, s32))func_80147078)(arg0, 0x1A);
    ((void (*)(void *))func_80158880)(arg0);
}
