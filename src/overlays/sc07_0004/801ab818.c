/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB818 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A8440(s32 a0);
extern void func_801292C8(u8 *a0);
typedef struct {
    u16 a, b;
} U16x2N;

void func_801AB818(void *a0) {
    u8 *s1 = *(u8 **)((s32)a0 + 0x24);

    if (*(s32 *)((s32)a0 + 0x1C) != 0) {
        U16x2N tmp;
        s32 cur;
        s32 addend;

        *(s32 *)((s32)a0 + 0x1C) -= 1;
        func_801A8440((s32)a0);

        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) -= 0x370;
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18);

        cur = *(s32 *)(s1 + 0);
        addend = *(s32 *)((s32)a0 + 0x30);
        *(s32 *)&tmp = cur;
        /* §22-ADDENDUM: a plain memory clobber, not `volatile`. It defeats
         * flow.c's last_mem_set dead-store rule so the FIRST store to the
         * temp survives, without pinning either store's schedule. Without
         * it the target's `sw $v0,0x10($sp)` at idx 24 is deleted. */
        __asm__("" ::: "memory");
        *(s32 *)&tmp = cur + addend;
        *(U16x2N *)(s1 + 0) = tmp;
    } else {
        func_801292C8((u8 *)a0);
    }
}
