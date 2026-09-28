/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD7D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s16 D_800CE8D4;
extern void func_800CD94C(void);
extern s32 func_8014659C(void);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_800CD96C(s32 a0);
extern s32 D_800CE8CC;

void func_800CD7D8(s32 a0) {
    s32 s0;
    s32 s2;
    s2 = *(s32 *)(a0 + 0x4C);
    s0 = func_8014659C();
    *(s32 *)(a0 + 0x20) = s0;
    if (s0 != 0) {
        func_8001C214(s0, (s32)&D_800CE8CC);
        *(s32 *)(s0 + 4) |= 0x50000000;
        *(s16 *)(s0 + 0x1C) = 0;
        *(s16 *)(s0 + 0x1A) = 0;
        *(s16 *)(s0 + 0x18) = 0;
        func_800CD96C(a0);
        D_800CE8D4 = *(u16 *)(*(s32 *)(s2 + 0x20) + 0x12);
        func_80146CA0((void *)a0);
    } else {
        ((void (*)(s32))func_800CD94C)(a0);
    }
}
