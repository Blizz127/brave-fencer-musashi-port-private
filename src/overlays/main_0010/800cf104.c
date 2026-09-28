/* Exact retail overlay 0010 export [800CF104,800CF238), offset 0x2030C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF104 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void (*D_800D3488[])(void);
extern u8  D_800AF630[];
extern s32 D_800A651C[];
extern void func_8001B85C(void);
extern s32  func_8001B86C(s32);
extern void func_80011B7C(s32);
extern void func_800596F4(s32);
extern void func_8004239C(s32);
extern s32  func_80059CF4(s32);
extern void func_8001AF34(void);

void func_800CF104(void) {
    register u8 *p = D_800AF630;
    D_80114E98 = 0;
    D_80114E9C = 0;
    func_8001B85C();
loop:
    if (D_80114E98 == 0) {
        D_800D3488[D_800B99F6]();
    }
    if (D_80114E9C == 0) {
        D_80114E9C = func_8001B86C(1);
    }
    if (D_80114E98 != 0 && D_80114E9C != 0) {
        func_80011B7C(7);
        return;
    }
    func_800596F4(0);
    func_8004239C(*(s32 *)(p + 0xA3E8));
    func_80059CF4(D_800A651C[*(u16 *)(p + 0xA3D2) * 5] + 4);
    func_8001AF34();
    goto loop;
}
