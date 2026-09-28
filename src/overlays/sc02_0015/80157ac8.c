/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80157AC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_801473EC(s32 *a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80154274(s32 *a0, s32 a1);
extern int func_80161208();
extern int func_80155FF8(int arg, int a1);
extern s32 func_80161208();
int func_80155FF8(int arg, int a1);
extern s32 func_801725A4(u8 *a0);
extern void func_8016706C(s32 a0);
extern u8 D_800D51AC[];

void func_80157AC8(s32 param_1)
{
    *(u32 *)(param_1 + 0x44) = *(u32 *)(param_1 + 0x44) | 2;
    ((s32 (*)(s32, s32, s32, s32))func_80147AD4)(param_1, 0, 0, 0x10000);
    ((void (*)(s32))func_801473EC)(param_1);
    if (((s32 (*)(s32))func_80161208)(param_1) == 0) {
        if (*(s32 *)(param_1 + 0x2c) > 0) {
            func_8016706C(4);
            func_8016706C(5);
            ((void (*)(s32, s32))func_80154274)(param_1, (s32)D_800D51AC);
            ((void (*)(s32))func_80146CA0)(param_1);
        } else {
            ((void (*)(s32, s32))func_80155FF8)(param_1, *(u8 *)(param_1 + 0x1aa));
            ((void (*)(s32))func_801725A4)(param_1);
        }
    }
}
