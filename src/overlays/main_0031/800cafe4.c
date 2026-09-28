/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFE4 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CAE74(s32 arg0, s32 arg1, s32 *arg2);
extern u16 D_801270C0;
extern void func_80154150(s32 a0, s32 a1);
extern void func_801655E4(s32 a0);
extern void func_800183E0(s32 a0);
extern void func_800CAE74();
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern u8 D_800CC09C[];
extern u8 D_800CBF3C[];
extern u8 D_800CBF7C[];
extern u8 D_800CC0DC[];
extern u8 D_800CBF5C[];
extern u8 D_800CBFA8[];
extern u8 D_800CC05C[];

void func_800CAFE4(u8 *a0) {
    D_801270C0 = 2;
    func_80154150((s32)a0, 3);
    func_801655E4((s32)a0);
    func_800CAE74((void *)&D_800CC09C, (void *)&D_800CBF3C, (void *)&D_800CBF7C);
    func_800CAE74((void *)&D_800CC0DC, (void *)&D_800CBF5C, (void *)&D_800CBFA8);
    func_800183E0((s32)&D_800CC05C);
    *(u16 *)(a0 + 0x234) = 0;
    *(u16 *)(a0 + 0x236) = 0x10;
    *(u32 *)(a0 + 0x238) = 0;
    *(u8 *)(a0 + 0xBE) = 0;
    *(u8 *)(a0 + 0xBF) = 0;
    func_80146E90((s32 *)a0, 0x10);
    func_80147324(0x8EA);
    *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
}
