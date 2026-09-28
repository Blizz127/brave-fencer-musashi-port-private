/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801821F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80182848(void *a0, u8 *a1, s32 a2, s32 a3, s32 a4);

void func_801821F4(void *a0)
{
    extern u8 D_80188E70[];
    extern u8 D_80188E78[];
    s32 pad[2];

    if (*(u16 *)((s32)a0 + 0x34) == 0) {
        if (func_8012BEE8() != 0) {
            *(s32 *)((s32)a0 + 0x1C) = 0x3C;
            *(u16 *)((s32)a0 + 0x34) = *(u16 *)((s32)a0 + 0x34) + 1;
        }
    } else {
        if (*(s32 *)((s32)a0 + 0x1C) == (*(s32 *)((s32)a0 + 0x1C) / 15) * 15) {
            func_80182674(a0, D_80188E70, 0xA, 0);
            func_8002D4C8(0x63C, 0);
        }
        if (*(s32 *)((s32)a0 + 0x1C) == (*(s32 *)((s32)a0 + 0x1C) / 3) * 3) {
            func_80182848(a0, D_80188E78, 5, 1, 1);
        }
        if (func_8012BEE8(a0) != 0) {
            *(u16 *)((s32)a0 + 0x2) = 3;
            *(s32 *)((s32)a0 + 0x1C) = 0;
            func_8012B21C(a0);
            func_8002D4C8(0x63D, 0);
            func_8002D4C8(4, 0xAC7);
        }
    }
    func_80182618(a0);
}
