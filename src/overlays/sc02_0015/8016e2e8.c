/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E2E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_8016E3CC(s32 a0);

void func_8016E2E8(void *a0) {
    s32 *s1 = *(s32 **)((s32)a0 + 0x20);
    func_8016E3CC((s32)a0);
    if (--*(s32 *)((s32)a0 + 0x1C) != 0) {
        *(u16 *)((s32)s1 + 0x18) -= 0x100;
        *(u16 *)((s32)s1 + 0x1A) -= 0x120;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)a0);
    }
}
