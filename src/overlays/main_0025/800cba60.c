/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBA60 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 a0);
extern void func_800CBB50(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146E90(s32 *a0, s16 a1);

void func_800CBA60(void *a0) {
    extern s32 func_80146E98(s32 a0);
    extern void func_8001CB00(s32 a0, void *a1, s32 a2, s32 a3);
    extern void func_800CBB50(void *a0);
    extern void func_80146E90(s32 *a0, s16 a1);
    extern void func_80146CA0(void *a0);
    extern u8 D_800CBF20[];
    void *s2;
    void *s0;

    s2 = *(void **)((s32)a0 + 0x20);
    s0 = *(void **)((s32)a0 + 0x10);
    if (func_80146E98((s32)a0) != 0) {
        if (s0 != 0) {
            func_8001CB00((s32)s0, D_800CBF20, 0x1A0, 0x170);
            func_800CBB50(s0);
        }
        *(s32 *)((s32)s2 + 4) |= 0x80000000;
        func_80146E90((s32 *)a0, 4);
        func_80146CA0(a0);
    }
}
