/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE138 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C810(s32 a0, s32 a1);
extern void func_8012AD50(void *a0);
extern u8 D_801F2538[];

void func_801AE138(void *param_1)
{
    register s32 d __asm__("$17") = (s32)param_1;
    register s32 obj __asm__("$16");
    register s32 w __asm__("$18");

    obj = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(d + 0x20) = obj;
    if (obj == 0) {
        func_8012CAE4((void *)d);
        return;
    }
    func_8001C810(obj, (s32)D_801F2538);
    w = 0x200;
    *(u32 *)(obj + 4) |= 0x50000000;
    *(u16 *)(obj + 0x2C) |= 0x10;
    *(s16 *)(obj + 0x1C) = w;
    *(s16 *)(obj + 0x1A) = w;
    *(s16 *)(obj + 0x18) = w;
    *(s16 *)(d + 0xA) -= 0x40;
    *(s16 *)(d + 0xE) += 0x20;
    obj = ((s32 (*)(void))func_8012C1B8)();
    if (obj != 0) {
        *(s32 *)(d + 0xCC) = obj;
        *(s16 *)(obj + 0x1A) = 0x300;
        *(u16 *)(obj + 0x2C) |= 0x10;
        *(u32 *)(obj + 4) |= 0x40;
        *(s16 *)(obj + 0x1C) = w;
        *(s16 *)(obj + 0x18) = w;
    }
    func_8012AD50((void *)d);
}
