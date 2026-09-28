/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC794 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);
extern void func_801AA540(void *arg0);

void func_801AC794(void *arg0) {
    switch (*(u16 *)((u8 *)arg0 + 0x34)) {
    case 0:
        *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18) += 0x800;
        *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x1C) = *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18);
        *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x1A) = *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18)
            + ((s16)*(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18) >> 1);
        if (*(s16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18) >= 0x2400) {
            *(u16 *)((u8 *)arg0 + 0x34) += 1;
        }
        break;
    case 1:
        *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18) -= 0x400;
        {
            s16 tmp = *(s16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18);
            if (tmp > 0) {
                *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x1C) = tmp;
                *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x1A) = *(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18)
                    + ((s16)*(u16 *)(*(u32 *)((u8 *)arg0 + 0x20) + 0x18) >> 1);
            } else {
                func_8012C218(arg0);
                return;
            }
        }
        break;
    }
    func_801AA540(arg0);
}
