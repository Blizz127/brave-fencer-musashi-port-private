/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB6E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C(void);

void func_800CB6E4(void *arg0) {
    extern s32 func_80146A6C(s32, void *, s32, s32, s32, s32, s32);
    extern void func_80146C3C();
    u8 *a0 = *(u8 **)((s32)arg0 + 0x34);
    if (*(s32 *)((s32)arg0 + 0x30) == *(s16 *)(a0 + 0x36)) {
        s16 var;
        if (*(s32 *)(a0 + 0x58) < 0) {
            u8 *p = (u8 *)(*(s32 *)(a0 + 0x58) & (s32)0x8FFFFFFF);
            var = ((*(s16 *)(p + 8) + *(s16 *)(p + 0xA)) >> 1) - 0x10;
        } else {
            var = -0x30;
        }
        *(s32 *)((s32)arg0 + 0x4C) = *(s16 *)(a0 + 6);
        *(s32 *)((s32)arg0 + 0x50) = *(s16 *)(a0 + 0xA) + (s16)var;
        *(s32 *)((s32)arg0 + 0x54) = *(s16 *)(a0 + 0xE);
    }
    if (*(s32 *)((s32)arg0 + 0x1C) < 0x18 && *(u16 *)a0 != 0) {
        if (*(s32 *)((s32)arg0 + 0x1C) < 0xE) {
            func_80146A6C(0x15, arg0, 0, 0, 0, 0x8000, *(s32 *)((s32)arg0 + 0x1C));
        }
        *(s32 *)((s32)arg0 + 0x1C) = *(s32 *)((s32)arg0 + 0x1C) + 1;
    } else {
        ((void (*)(void *))func_80146C3C)(arg0);
    }
}
