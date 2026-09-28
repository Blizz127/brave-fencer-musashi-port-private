/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD5DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80013F3C(void *a0);
extern void func_800126C4(s32 a0, s32 a1);
extern void func_80012558(s32 a0, s32 a1);
extern void func_800123F0(s32 a0, s32 a1);

void func_800CD5DC(s32 a0, s32 a1) {
    s32 q = *(s32 *)(a0 + 0x20);
    func_80013F3C((void *)a1);
    func_800126C4((s32)a1, *(s16 *)(a0 + 0x60));
    func_800123F0((s32)a1, *(s16 *)(a0 + 0x64));
    func_80012558((s32)a1, *(s16 *)(a0 + 0x62));
    func_80012558((s32)a1, *(s16 *)(q + 0x12));
    func_800126C4((s32)a1, *(s16 *)(q + 0x10));
    func_800123F0((s32)a1, *(s16 *)(q + 0x14));
}
