/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB968 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 a0);
extern void func_8001CBDC(s32 a0, void *a1, s32 a2, s32 a3);
extern void func_800CBB50(void *a0);
extern void func_80146CA0(void *a0);

void func_800CB968(void *a0) {
    extern u8 D_800CBF20[];
    void *s0;
    void *s2;
    s32 v0;

    s2 = *(void **)((s32)a0 + 0x20);
    s0 = *(void **)((s32)a0 + 0x10);
    v0 = func_80146E98((s32)a0);
    if (v0 != 0) {
        if (s0 != 0) {
            func_8001CBDC((s32)s0, D_800CBF20, 0x1A0, 0x170);
            func_800CBB50(s0);
            *(s32 *)((s32)s2 + 4) &= 0x7FFFFFFF;
        }
        func_80146CA0(a0);
    } else {
        if (s0 != 0) {
            *(u16 *)((s32)s0 + 0x18) += 0x2AA;
        }
    }
}
