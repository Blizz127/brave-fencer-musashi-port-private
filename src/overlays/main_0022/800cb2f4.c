/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB2F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(s32);
extern void func_80146CA0(s32 a0);

void func_800CB2F4(void *a0) {
    void *a1;
    s16 v0;

    a1 = *(void **)((s32)a0 + 0x20);
    *(u16 *)((s32)a0 + 0x60) += 0x60;
    v0 = *(u16 *)((s32)a1 + 0x1A) + 0x200;
    *(u16 *)((s32)a1 + 0x1A) = v0;
    *(u16 *)((s32)a1 + 0x18) = v0;
    if (v0 >= 0x1001) {
        *(u16 *)((s32)a1 + 0x1A) = 0x1000;
        *(u16 *)((s32)a1 + 0x18) = 0x1000;
        func_80146CA0((s32)a0);
    }
}
