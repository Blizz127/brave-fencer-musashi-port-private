/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146FC4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_80015954(s32 a0, s32 a1);
extern u8 D_80126DB0[];
extern u16 D_80126DB6;

void func_80146FC4(s32 a0) {
    s32 s1 = a0;
    s32 s0;
    if (*(s16 *)(s1 + 0xA) >= 0x401) {
        s0 = (s32)D_80126DB0;
        func_80015954(s0, s1 + 0x4);
        memcpy((void *)(s1 + 0x88), (void *)s0, 8);
        *(s16 *)(*(s32 *)(s1 + 0x20) + 0x12) = D_80126DB6;
    }
}
