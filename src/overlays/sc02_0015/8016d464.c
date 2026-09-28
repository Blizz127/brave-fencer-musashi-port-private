/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D464 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
short func_8016CF04(s32 param_1, s32 param_2);

void func_8016D464(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x34);
    s32 v0;
    func_800D22E4((s32)a0);
    func_8016CF04((s32)a0, 1);
    v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == -1 || *(u16 *)s1 != 1) {
        *(u16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
    }
}
