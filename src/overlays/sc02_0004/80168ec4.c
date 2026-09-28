/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80168EC4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C(void);
extern void func_80168F40();

void func_80168EC4(s32 a0) {
    if (*(s32 *)(a0 + 0x1C) < 5) {
        func_80168F40();
        *(u16 *)(a0 + 0x10) = *(u16 *)(a0 + 0x6);
        *(u16 *)(a0 + 0x14) = *(u16 *)(a0 + 0xA);
        *(u16 *)(a0 + 0x18) = *(u16 *)(a0 + 0xE);
        func_800D22E4(a0);
        *(s32 *)(a0 + 0x1C) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
