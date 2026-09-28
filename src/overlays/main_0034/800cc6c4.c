/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC6C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CC7FC(s32 a0, void *a1, void *a2, void *a3, void *a4);

void func_800CC6C4(void *a0, void *a1, void *a2, void *a3) {
    extern s32 D_800CCA9C;
    void *v4;

    v4 = *(void **)((s32)a0 + 0x20);
    *(u16 *)((s32)a3 + 0x6) = *(u16 *)((s32)v4 + 0x12);
    func_800CC7FC((s32)a0, a1, a2, a3, &D_800CCA9C);

    *(u16 *)((s32)a3 + 0x6) = (*(u16 *)((s32)a3 + 0x6) + 0x555) & 0xFFF;
    func_800CC7FC((s32)a0, a1, a2, a3, &D_800CCA9C);

    *(u16 *)((s32)a3 + 0x6) = (*(u16 *)((s32)a3 + 0x6) + 0x555) & 0xFFF;
    func_800CC7FC((s32)a0, a1, a2, a3, &D_800CCA9C);

    *(u16 *)((s32)a3 + 0x6) = *(u16 *)((s32)v4 + 0x10);
    func_800CC7FC((s32)a0, a1, a2, a3, &D_800CCA9C);

    *(u16 *)((s32)a3 + 0x6) = (*(u16 *)((s32)a3 + 0x6) - 0x555) & 0xFFF;
    func_800CC7FC((s32)a0, a1, a2, a3, &D_800CCA9C);

    *(u16 *)((s32)a3 + 0x6) = (*(u16 *)((s32)a3 + 0x6) - 0x555) & 0xFFF;
    func_800CC7FC((s32)a0, a1, a2, a3, &D_800CCA9C);
}
