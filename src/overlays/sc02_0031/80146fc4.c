/* Complete SC02 retail span [80146FC4,8014704C).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"


extern u8 D_80126DB0[];
extern u16 D_80126DB6;
extern void func_80015954(s32 a0, s32 a1);
extern void *memcpy(void *dst, const void *src, u32 n);

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
