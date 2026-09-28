/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015E22C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern u8 D_800D4FF4[];

void func_8015E22C(s32 a0) {
    func_80154274((s32 *)a0, (s32)D_800D4FF4);
    *(s32 *)(a0 + 0x234) = 0;
    func_80146994(5, a0, 0xA, 0);
    *(s32 *)(a0 + 0x44) |= 2;
    func_80146CA0((void *)a0);
}
