/* Overlay range [80153D7C,80153E00) from MAIN.CD member 0012.
 * SHA256(span)=d49b0bb3fec8430c141ae5115de7359a36774e284e36b283c14e517b20aa588b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80153D7C - byte-exact against retail at -O2 (tools/register_match.py). */
#define currentLocationId D_800B9A08
extern s16 currentLocationId;
extern short currentLocationId;
void func_80146CA0(void *a0);
void func_80147324(s32 arg0);
void func_80149020(s32 *a0);
s32 a1;
extern void func_80147324(s32 a0);
extern void func_80147324(s32 arg0);
extern void func_80146CA0(void *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80149020(s32 *a0);

void func_80153D7C(s32 param_1)
{

    extern u8 D_80180180;
    func_80147324(0x451);
    func_80154274((s32 *)param_1, (s32)&D_80180180);
    func_80149020((s32 *)param_1);
    *(u16 *)(param_1 + 0x244) = *(u16 *)(param_1 + 6);
    *(u16 *)(param_1 + 0x246) = *(u16 *)(param_1 + 10);
    *(u16 *)(param_1 + 0x248) = *(u16 *)(param_1 + 0xe);
    if (currentLocationId == 0x3075) *(u8 *)(param_1 + 0xde) = 0x14;
    else *(u8 *)(param_1 + 0xde) = 10;
    *(u8 *)(param_1 + 0xdf) = 0;
    __asm__ __volatile__("" ::: "memory");
    func_80146CA0((void *)param_1);
}
