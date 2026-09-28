/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015FBE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146CA0(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80147324(s32 arg0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553C0(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
extern u16 D_801270C0;
extern void func_80159B70(void *a0);
extern void (*D_80180378[])(void *);
extern void func_80159B70(void*);
extern void (*D_80180378[])(void*);
extern void func_80154150(int, int);
extern void func_80154A74(s32, s32);
extern void func_80154150(s32, s32);
extern void func_80147078(s32*, s16);
extern void func_80159B70(void *);
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);
extern void func_80147078(s32 *, s16);

void func_8015FBE0(s32 *param_1)
{

    extern u8 D_800B9A17;
    if (param_1[0x61] < 0) {
        ((void (**)())D_80180378)[*(u16 *)param_1]();
        ((void (*)(s32 *, s16))func_80147078)(param_1, 0);
        ((void (*)(s32 *))func_80159B70)(param_1);
    } else {
        __asm__ __volatile__("");
        D_80078EC1 = 0;
        ((void (*)(s32 *, s32))func_80154150)(param_1, 0x20);
        ((void (*)(s32 *, s32))func_80154A74)(param_1, 0x18);
        ((void (*)(s32, s32 *, s32, s32, s32, s32, s32))func_80146A6C)(0x16, param_1, 0, 0, 0, 0, 0);
        func_80147324(0x44F);
        ((void (*)(s32 *))func_801553A8)(param_1);
        ((void (*)(s32 *))func_801553C0)(param_1);
        D_801270C0 = 2;
        D_800B9A17 = 0;
        ((void (*)(s32 *))func_80146CA0)(param_1);
    }
}
