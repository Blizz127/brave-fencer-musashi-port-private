/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD1F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801553C0(s32 a0);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_800CD1F4(s32 *a0) {
    func_801553C0((s32)a0);
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    *(s32 *)((u8 *)a0 + 0x44) &= ~0x1000;
}
