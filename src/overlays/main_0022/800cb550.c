/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB550 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800233CC(void *, unsigned short);
extern void func_80146C3C();
extern void *func_800D2294(s32 a0, s32 a1);
extern void func_80146E90(s32 *a0, s32 a1);

void func_800CB550(void *a0) {
    extern u8 D_800CBCCC;
    void *base;
    void *ptr;

    base = &D_800CBCCC;
    ptr = func_800D2294((s32)a0, (s32)base);
    *(void **)((s32)a0 + 0x20) = ptr;
    if (ptr != ((void *)0) ) {
        func_800233CC(base, 0x20);
        *(s32 *)((s32)ptr + 4) |= 0x50000000;
        func_80146E90((s32 *)a0, 8);
        *(u16 *)((s32)a0 + 2) = *(u16 *)((s32)a0 + 2) + 1;
    } else {
        ((void (*)(void *))func_80146C3C)(a0);
    }
}
