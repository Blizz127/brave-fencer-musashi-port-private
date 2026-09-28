/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012AF0C - byte-exact against retail at -O2 (tools/register_match.py). */
struct M8012AF0C;
struct M8012AF0C { short a, b, c, d; };
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8012AF0C(s32 a0, s32 a1) {
    s32 s1 = a0;
    s32 s2 = a1;
    s16 spA[4];                 
    struct M8012AF0C spB;       
    struct M8012AF0C spC;       
    s16 spD[4];                 
    spA[0] = *(u16 *)(s1 + 0x3A);
    spA[1] = *(u16 *)(s1 + 0x3E);
    spA[2] = *(u16 *)(s1 + 0x42);
    spB.a = *(u16 *)(s1 + 0x6);
    spB.b = *(u16 *)(s1 + 0xA);
    spB.c = *(u16 *)(s1 + 0xE);
    spC = spB;
    if (func_80135888(*(s32 *)(s2 + 0x20), *(s32 *)(s2 + 0x58), (s32)spA, (s32)&spC) != 0) {
        s32 r0, r1;
        spD[0] = *(u16 *)(s2 + 0x6);
        spD[1] = *(u16 *)(s2 + 0xA);
        spD[2] = *(u16 *)(s2 + 0xE);
        r0 = func_800132BC((s32)spD, (s32)spA);
        r1 = func_800132BC((s32)spD, (s32)&spB);
        if (r0 < r1) return 0;
        *(s32 *)(s1 + 0x4) = *(s32 *)(s1 + 0x38);
        *(s32 *)(s1 + 0x8) = *(s32 *)(s1 + 0x3C);
        *(s32 *)(s1 + 0xC) = *(s32 *)(s1 + 0x40);
        return 1;
    }
    return 0;
}
