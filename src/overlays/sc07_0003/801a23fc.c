/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A23FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012CBCC(s32 a0);
extern void func_8013C9C4(void *a0);
extern void func_801A2658(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_80186F44[];
extern u8  D_801A68BC[];

s32 func_801A23FC(s32 arg0) {
    s32 s1;
    s32 v;
    s32 p;

    s1 = 0;
    v = *(s32 *)(arg0 + 0xD0);
    if (v != 0) {
        s1 = v;
        *(u16 *)(*(s32 *)(s1 + 0x20) + 0x18) += 0x266;
        *(u16 *)(*(s32 *)(s1 + 0x20) + 0x1A) += 0x266;
    }

    if (((s32 (*)(s32))func_8012CBCC)(arg0) & 0x2000) {
        func_8013C9C4(D_80186F44);
        func_801A2658(arg0, (s32)D_801A68BC);
        func_801A2658(arg0, (s32)(D_801A68BC + 8));
        if (s1 != 0) {
            p = *(s32 *)(s1 + 0x20);
            *(u16 *)(p + 0x1A) = 0x3000;
            *(u16 *)(p + 0x18) = 0x3000;
        }
        *(s32 *)(arg0 + 0xE0) |= 4;
        func_8002D4C8(0xB52, 0);
        return 1;
    }
    return 0;
}
