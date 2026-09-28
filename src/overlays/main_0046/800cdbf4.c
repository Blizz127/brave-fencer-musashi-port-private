/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDBF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
extern void func_80049CAC(s32 a0, s32 a1);
extern void ApplyMatrixSV(void *m0, void *m1, void *m2);
extern void func_80015954(s32 a0, s32 a1);
extern s16 D_800CE0B8[4];

void func_800CDBF4(s32 s0) {
    u16 sp10[3];
    u16 sp18[16];
    s32 *outer;
    s32 *inner;
    s32 t;

    outer = *(s32 **)(s0 + 0x4C);
    *(u16 *)(s0 + 0x62) = (*(u16 *)(s0 + 0x62) + *(u16 *)(s0 + 0x66)) & 0xFFF;
    func_80049CAC(s0 + 0x60, sp18);
    ApplyMatrixSV(sp18, D_800CE0B8, sp10);
    inner = *(s32 **)((s32)outer + 0x20);
    sp10[0] = sp10[0] + inner[18];
    t = sp10[1] - 0x20;
    sp10[1] = t + inner[19];
    sp10[2] = sp10[2] + inner[20];
    func_80015954(sp10, s0 + 4);
}
