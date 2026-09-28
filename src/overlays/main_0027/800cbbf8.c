/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBBF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800178EC(s32 a0);

void func_800CBBF8(s32 *a0, s32 *a1) {
    *(u16 *)((s8 *)a0 + 0x0) += *(u16 *)((s8 *)a1 + 0x0);
    *(u16 *)((s8 *)a0 + 0x2) += *(u16 *)((s8 *)a1 + 0x2);
    *(u16 *)((s8 *)a0 + 0x8) += *(u16 *)((s8 *)a1 + 0x0);
    *(u16 *)((s8 *)a0 + 0xA) += *(u16 *)((s8 *)a1 + 0x2);
    *(u16 *)((s8 *)a0 + 0x10) += *(u16 *)((s8 *)a1 + 0x0);
    *(u16 *)((s8 *)a0 + 0x12) += *(u16 *)((s8 *)a1 + 0x2);
    *(u16 *)((s8 *)a0 + 0x18) += *(u16 *)((s8 *)a1 + 0x0);
    *(u16 *)((s8 *)a0 + 0x1A) += *(u16 *)((s8 *)a1 + 0x2);
    func_800178EC((s32)a0);
}
