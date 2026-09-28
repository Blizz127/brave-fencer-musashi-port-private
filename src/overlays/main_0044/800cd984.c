/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD984 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146E90(s32*, s32);
extern void func_80146E90(s32 *a0, s32 a1);
extern s32 func_800D21C4(s32 a0, void *a1, s32 a2);
extern s32 func_80146C3C(void *a0);
extern s32 D_800CE240;

void func_800CD984(s32 a0) {
    s32 a2;

    a2 = func_800D21C4(a0, (s32)&D_800CE240, 0x21);
    if (a2 != 0) {
        *(s32 *)(a2 + 4) |= 0x40000000;
        *(s32 *)(a0 + 0x20) = a2;
        *(s16 *)(a2 + 0x28) = 0x230;
        *(s16 *)(a2 + 0x2A) = 0x1C0;
        func_80146E90((s32 *)a0, 2);
        *(u16 *)(a0 + 2) += 1;
    } else {
        func_80146C3C((void *)a0);
    }
}
