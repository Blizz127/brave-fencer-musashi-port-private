/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB304 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB304(void *a0) {
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern s32 func_80146E98(s32 a0);
    extern void func_80146CA0(void *a0);
    extern void func_800CB3DC(void *a0);
    s32 pad[2];
    s32 var_s2;
    s32 i;

    if (pad == ((void *)0) ) {}
    var_s2 = *(s32 *)((s32)a0 + 0x20);
    for (i = 0; i < 6; i++) {
        func_80146A6C(0x4D, a0, *(s16 *)((s32)a0 + 0x6), *(s16 *)((s32)a0 + 0xA),
                      *(s16 *)((s32)a0 + 0xE), i, 1);
    }
    if (func_80146E98((s32)a0) != 0) {
        func_80146CA0(a0);
    } else {
        u16 var_v0;
        var_v0 = *(u16 *)(var_s2 + 0x1C);
        var_v0 = var_v0 - 0x80;
        *(u16 *)(var_s2 + 0x1C) = var_v0;
        *(u16 *)(var_s2 + 0x1A) = var_v0;
        *(u16 *)(var_s2 + 0x18) = var_v0;
        func_800CB3DC(a0);
    }
}
