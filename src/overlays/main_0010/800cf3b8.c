/* Exact retail overlay 0010 export [800CF3B8,800CF47C), offset 0x205C0. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF3B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80114E98;
extern s32 D_80114E9C;
extern u16 D_800B99F6;
extern u8 D_800AF630[];
extern void (*D_800D3488[])(void);
extern void func_8001B85C(void);
extern void func_8001AF34(void);
extern void func_80015310(void);
extern void func_80011B7C(s32 arg0);
extern void func_8004239C(s32 arg0);

void func_800CF3B8(void) {
    register u8 *p = D_800AF630;
    D_80114E98 = 0;
    D_80114E9C = 0;
    func_8001B85C();
L3E4:
    if (D_80114E98 != 0) goto L458;
    (*(void (**)(void))((char *)D_800D3488 + (D_800B99F6 << 2)))();
    if (D_80114E98 != 0) goto L458;
    func_8004239C(*(s32 *)(p + 0xA3E8));
    func_8001AF34();
    goto L3E4;
L458:
    func_80015310();
    func_80011B7C(7);
}
