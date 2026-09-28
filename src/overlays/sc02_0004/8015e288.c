/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015E288 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80146C98(s32 *a0, s16 a1);
extern void func_80146CA0(void *a0);
extern s32 func_8014A850(s32 param_1);
extern void func_80154274(s32 *a0, s32 a1);
extern int func_80161208();
extern s32 func_80161208();
extern u8 D_800D5098[];
extern u8 D_800D5060[];
extern s32 func_8014A850(s32 a0);
extern void func_8015E40C(s32 a0);
extern void func_8015E588(void);
extern void func_8015E4B0(s32 a0);

void func_8015E288(s32 a0) {
    if (func_80161208() != 0) {
        return;
    }
    if (func_8014A850(a0) != 0) {
        func_80154274((s32 *)a0, (s32)D_800D5098);
        func_8015E40C(a0);
        ((void (*)(s32))func_8015E588)(a0);
        func_8015E4B0(a0);
        func_80146994(5, a0, 0xB, 0);
        func_80146CA0((void *)a0);
        return;
    }
    if (*(u16 *)(a0 + 0xB8) & 0x8000) {
        func_80154274((s32 *)a0, (s32)D_800D5060);
        func_80146C98((s32 *)a0, 3);
    }
}
