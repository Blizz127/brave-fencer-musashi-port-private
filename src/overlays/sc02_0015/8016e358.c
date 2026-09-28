/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016E358 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C(void);
extern void func_8016E460(void *a0, void *a1);

void func_8016E358(void *a0) {
    s32 v0;
    v0 = *(s32*)((s32)a0 + 0x1C) - 1;
    *(s32*)((s32)a0 + 0x1C) = v0;
    if (v0 != 0) {
        func_800D22E4((s32)a0);
        *(s16*)((s32)a0 + 0x16) = *(u16*)((s32)a0 + 0x16) - 3;
        *(s32*)((s32)a0 + 0x30) = *(s32*)((s32)a0 + 0x30) - 0xE;
        func_8016E460(a0, (void*)((s32)a0 + 0x38));
    } else {
        ((void (*)(void *))func_80146C3C)(a0);
    }
}
