/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE408 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801AD55C(void *a0);
extern void func_801292C8(u8 *a0);
extern u8 D_801F8D98[];
extern s32 D_801B07FC[];
extern s32 D_801B0800[];
typedef struct {
    u16 a, b;
} U16x2;

void func_801AE408(void *a0) {
    u8 *s1 = D_801F8D98 + ((*(u16 *)((s32)a0 + 0x2E) & 3) << 6);

    if (*(s32 *)((s32)a0 + 0x1C) != 0) {
        /* §193-I: an aggregate local gets an 8-byte frame stride (ceil(size,8)),
         * not its raw size — declaring the reinterpret temp AS the struct type
         * (rather than s32+&cast) is what supplies the target's extra 8 bytes. */
        U16x2 tmp;
        s32 idx2;
        /* unused, but required to reach the target's 0x30 frame (§193-I
         * padding math accounts for 0x28; this local supplies the last 8
         * bytes — see notes: not independently verified against source). */
        u16 pad[4];

        *(s32 *)((s32)a0 + 0x1C) -= 1;
        func_801AD55C(a0);

        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) -= 0x4F0;
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18);
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x14) += 0x60;

        idx2 = (*(u16 *)((s32)a0 + 0x2E) & 3) * 2;

        *(s32 *)&tmp = *(s32 *)(s1 + 0);
        *(s32 *)&tmp += D_801B07FC[idx2];
        *(U16x2 *)(s1 + 0) = tmp;

        *(s32 *)&tmp = *(s32 *)(s1 + 4);
        *(s32 *)&tmp += D_801B0800[idx2];
        *(U16x2 *)(s1 + 4) = tmp;

    } else {
        func_801292C8((u8 *)a0);
    }
}
