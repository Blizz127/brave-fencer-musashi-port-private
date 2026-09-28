/* SC02 resident image [8012A988,8012AAAC) at overlay base 0x80128158.
 * SHA256(span)=a6f2d6f81233bea8cdd901da4d85aa89796b04e49c89a63c7fd8077f3d948f25.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A988 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012ACE0(void *a0);
extern void func_8012AAAC();

void func_8012A988(u8 *a0) {
    s32 v0;
    s16 t;
    u16 flags;
    *(u16 *)(a0 + 0x72) = *(u16 *)(a0 + 0x72) & 0x9FFF;
    if (*(u16 *)(a0 + 0x0) == 0) return;
    if (*(u8 *)(a0 + 0xC1) == 0x11) return;
    t = *(s16 *)(a0 + 0x98);
    if (t == 0) return;
    t = t - 1;
    *(s16 *)(a0 + 0x98) = t;
    if (t > 0) return;
    if (*(s32 *)(a0 + 0x90) == 0) return;
    flags = *(u16 *)(a0 + 0x72);
    if (flags & 0x400) {
        v0 = *(s32 *)(a0 + 0x94) - 1;
        *(s32 *)(a0 + 0x94) = v0;
        if (v0 < 0) {
            *(s32 *)(a0 + 0x94) = 1;
            *(u16 *)(a0 + 0x72) = *(u16 *)(a0 + 0x72) & 0xFBFF;
        }
    } else if (flags & 0x200) {
        v0 = *(s32 *)(a0 + 0x94) - 1;
        *(s32 *)(a0 + 0x94) = v0;
        if (v0 < 0) {
            s32 idx = func_8012ACE0(a0);
            if (*(s16 *)((idx * 8) + *(s32 *)(a0 + 0x90) + 4) != -1) {
                *(s32 *)(a0 + 0x94) = 0;
                *(s16 *)(a0 + 0x98) = 0;
                return;
            }
            *(s32 *)(a0 + 0x94) = idx - 1;
        }
    } else {
        *(s32 *)(a0 + 0x94) = *(s32 *)(a0 + 0x94) + 1;
    }
    ((void (*)(u8 *))func_8012AAAC)(a0);
}
