/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB354 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(s32);
extern void func_80146CA0(s32 a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_800CB354(void *a0) {
    void *v1;
    s16 v0;

    v1 = *(void **)((s32)a0 + 0x20);
    v0 = *(u16 *)((s32)a0 + 0x62) - 0x40;
    *(u16 *)((s32)a0 + 0x62) = v0;
    if (v0 < 0) {
        func_80146CA0((s32)a0);
        return;
    }
    *(u16 *)((s32)v1 + 0x12) = (*(u16 *)((s32)v1 + 0x12) - 0x71) & 0xFFF;
    func_80146A6C(0x3E, a0, *(s16 *)((s32)a0 + 0x6), *(s16 *)((s32)a0 + 0xA),
                  *(s16 *)((s32)a0 + 0xE), 0, 0);
}
