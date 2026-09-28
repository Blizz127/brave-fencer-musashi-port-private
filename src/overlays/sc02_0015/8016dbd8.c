/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016DBD8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149374(s32 a0, s32 a1);
extern void func_80149374(s32 arg0, s32 arg1);
extern void func_80149374(int, int);
extern void func_800D1FC8(s32 a0, s32 a1);

void func_8016DBD8(u8 *a0) {
    *(s32 *)(a0 + 0x4) = 0;
    *(s32 *)(a0 + 0x8) = 0;
    *(s32 *)(a0 + 0xC) = 0;
    func_80149374(*(s32 *)(a0 + 0x34), (s32)(a0 + 0x4));
    func_800D1FC8((s32)a0, 5);
}
