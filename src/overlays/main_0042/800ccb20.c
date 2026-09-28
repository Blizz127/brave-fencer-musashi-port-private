/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCB20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800D5360[];
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80156648(s32 *a0);
extern void func_80147324(s32 a0);
extern void func_80149020(s32 *a0);

void func_800CCB20(s32 a0)
{
    s32 s0;
    s32 v0;
    u16 v1;

    s0 = a0;
    func_80154274((s32 *)s0, (s32)&D_800D5360);
    v0 = *(s32 *)(s0 + 0x20);
    *(s32 *)(s0 + 0x234) = 0;
    *(s32 *)(s0 + 0x238) = 0;
    v1 = *(u16 *)(v0 + 0x12);
    *(s16 *)(s0 + 0x246) = 0;
    *(s16 *)(s0 + 0x248) = 0x100;
    *(s32 *)(s0 + 0x23C) = 0;
    *(s16 *)(s0 + 0x244) = v1;
    func_80146994(5, s0, 8, 0);
    func_80156648((s32 *)s0);
    func_80147324(0x450);
    func_80149020((s32 *)s0);
}
