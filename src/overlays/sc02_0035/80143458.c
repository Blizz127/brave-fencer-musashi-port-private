/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80143458 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern u8 D_800D387C[];
extern u32 D_80185CCC[];

void func_80143458(s32 param_1)
{
    s32 p;
    u16 v;

    *(u32 *)(*(s32 *)(param_1 + 0x20) + 0x20) = (u32)&D_800D387C;

    p = *(s32 *)(param_1 + 0x20);
    if (*(s32 *)(p + 4) == 0) {
        *(s32 *)(p + 4) = 0x50000000;
    }

    *(u8 *)(*(s32 *)(param_1 + 0x20) + 0x27) = 0x9c;

    v = *(u16 *)(param_1 + 0x34) & 0x7fff;
    if (v != 0) {
        p = *(s32 *)(param_1 + 0x20);
        *(u16 *)(p + 0x1a) = v;
        *(u16 *)(p + 0x18) = v;
    }

    func_80128EA8(*(u32 *)(param_1 + 0x20), param_1 + 0x24,
                  D_80185CCC[*(u16 *)(param_1 + 0x34) & 3]);

    *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
}
