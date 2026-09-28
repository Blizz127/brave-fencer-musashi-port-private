/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB470 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CAF90(void *a0);

void func_800CB470(void *a0) {
    extern u8 D_80078EC1;
    extern void func_800CAF90(void *);
    extern void func_80146C3C(void *);
    u16 uVar1;

    if (D_80078EC1 == 5) {
        uVar1 = *(u16 *)((s32)a0 + 0x28) - 0x100;
        *(u16 *)((s32)a0 + 0x28) = uVar1;
        if ((s16)uVar1 > 0) {
            *(s32 *)((s32)a0 + 0x50) -= 3;
            func_800CAF90(a0);
        } else {
            func_80146C3C(a0);
        }
    } else {
        func_80146C3C(a0);
    }
}
