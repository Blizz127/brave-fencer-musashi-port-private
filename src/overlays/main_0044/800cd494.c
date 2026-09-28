/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD494 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80162CCC(void);
extern s16 D_800CE210[];
extern u16 D_800CE212[];

void func_800CD494(void *arg0) {
    s16 idx;
    s32 a1;
    s16 tv;
    u16 tv2;
    u16 acc;

    idx = *(s16 *)((s32)arg0 + 0x5E);
    a1 = *(s32 *)((s32)arg0 + 0x20);
    tv = D_800CE210[idx * 2];
    if (tv != 0) {
        *(s16 *)((s32)arg0 + 0x5E) = idx + 1;
        tv2 = D_800CE212[idx * 2];
        acc = *(u16 *)(a1 + 0x1A) + 0x555;
        *(u16 *)(a1 + 0x28) = tv;
        *(u16 *)(a1 + 0x1A) = acc;
        *(u16 *)(a1 + 0x18) = acc;
        *(u16 *)(a1 + 0x2A) = tv2;
    } else {
        func_80162CCC();
    }
}
