/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC5E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);

void func_800CC5E4(void *a0) {
    void *a1;
    register s32 v0 __asm__("$2");
    s32 v1;
    s32 t;

    a1 = *(void **)((u8 *)a0 + 0x20);
    *(u16 *)((u8 *)a1 + 0x1E) += 0x200;
    v0 = *(u16 *)((u8 *)a0 + 0x60) + 0xC0;
    *(u16 *)((u8 *)a0 + 0x60) = v0;
    v1 = *(u16 *)((u8 *)a1 + 0x1A) + v0;
    *(u16 *)((u8 *)a1 + 0x1A) = v1;
    __asm__ __volatile__("" ::: "memory");
    t = *(s16 *)((u8 *)a1 + 0x1A);
    *(u16 *)((u8 *)a1 + 0x18) = v1;
    if (t >= 0xC01) {
        *(u16 *)((u8 *)a1 + 0x1A) = 0xC00;
        *(u16 *)((u8 *)a1 + 0x18) = 0xC00;
        func_80146CA0(a0);
    }
}
