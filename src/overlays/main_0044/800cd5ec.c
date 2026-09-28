/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD5EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CD758(s32 param_1);

void func_800CD5EC(void *a0) {
    func_800CD758((s32)a0);
    *(u16 *)((s32)a0 + 0x66) = (*(s32 *)((s32)a0 + 0x50) * 1365) & 0xFFF;
}
