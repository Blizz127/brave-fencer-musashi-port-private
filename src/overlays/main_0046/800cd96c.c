/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD96C - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixY func_8004A0DC


void func_800CD96C(s32 param_1) {
    extern void func_80013F3C(void *a0);
    extern void RotMatrixY(s32 a0, void *a1);
    extern void func_80048D9C(void *a0, void *a1);
    extern void func_80020F34(s32 a0, s32 a1);

    s32 work;
    s32 hdr;
    s32 model;

    work = *(s32 *)(param_1 + 0x4C);
    hdr = *(s32 *)(work + 0x20);
    model = *(s32 *)(param_1 + 0x20);
    *(s16 *)(param_1 + 6) = *(s32 *)(hdr + 0x48);
    *(s16 *)(param_1 + 0xA) = *(s32 *)(hdr + 0x4C) - 0x20;
    *(s16 *)(param_1 + 0xE) = *(s32 *)(hdr + 0x50);
    func_80013F3C((void *)(model + 0x34));
    RotMatrixY(*(s16 *)(model + 0x12), (void *)(model + 0x34));
    func_80048D9C((void *)(model + 0x34), (void *)(*(s32 *)(work + 0x20) + 0x34));
    func_80020F34(model + 0x34, model + 0x18);
    *(u16 *)(model + 0x2C) |= 1;
}
