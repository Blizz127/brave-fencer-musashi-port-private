/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E2F4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);
typedef struct {
    u16 x;  
    u16 y;  
    u16 z;  
    u16 w;  
} Vec4h_8017E2F4;

s32 func_8017E2F4(s32 a0, s32 a1) {
    Vec4h_8017E2F4 p1;
    Vec4h_8017E2F4 p2;
    register s32 p2addr __asm__("$17");
    u32 avg;

    p2addr = (s32)&p2;
    p1.x = p2.x = *(u16 *)(a1 + 0x4);
    p1.y = p2.y = *(u16 *)(a1 + 0x8) - 0x10;
    p1.z = *(u16 *)(a1 + 0xC);
    p2.z = *(u16 *)(a1 + 0xE);
    if (func_8012DEB8(a0, (s32)&p1, p2addr)) {
        return 1;
    }

    avg = (*(s16 *)(a1 + 0x4) + *(s16 *)(a1 + 0x6)) >> 1;
    p1.x = p2.x = avg;
    if (func_8012DEB8(a0, (s32)&p1, p2addr)) {
        return 1;
    }

    p1.x = p2.x = (*(s16 *)(a1 + 0x4) + avg) >> 1;
    if (func_8012DEB8(a0, (s32)&p1, p2addr)) {
        return 1;
    }

    p1.x = p2.x = (*(s16 *)(a1 + 0x6) + avg) >> 1;
    if (func_8012DEB8(a0, (s32)&p1, p2addr)) {
        return 1;
    }

    p1.x = p2.x = *(u16 *)(a1 + 0x6);
    if (func_8012DEB8(a0, (s32)&p1, p2addr)) {
        return 1;
    }
    return 0;
}
