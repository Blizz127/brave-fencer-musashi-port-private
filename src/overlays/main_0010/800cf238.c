/* Exact retail overlay 0010 export [800CF238,800CF370), offset 0x20440. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF238 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80114E98;
extern u16 D_800B99F6;
extern u8 D_800AF630[];
extern s32 D_800A651C[];
extern void (*D_800D3488[])(void);
extern void func_8001B85C(void);
extern void func_80128158(void);
extern void func_8004239C(s32 arg0);
extern void func_8001AF34(void);
extern void func_80011B7C(s32 arg0);
extern void func_800596F4(s32 arg0);
extern s32 func_80059CF4(s32 arg0);

void func_800CF238(void) {
    register u8 *p = D_800AF630;
    D_80114E98 = 0;
    func_8001B85C();
L25C:
    if (D_80114E98 == 0) {
        (*(void (**)(void))((char *)D_800D3488 + (D_800B99F6 << 2)))();
        if (D_80114E98 == 0) {
            goto L300;
        }
    }
L2AC:
    func_80128158();
    if (*(u16 *)(p + 0xA3C2) == 0) {
        func_8004239C(*(s32 *)(p + 0xA3E8));
        func_8001AF34();
        goto L2AC;
    }
    func_80011B7C(8);
    goto L35C;
L300:
    func_800596F4(0);
    func_8004239C(*(s32 *)(p + 0xA3E8));
    func_80059CF4(*(s32 *)((char *)D_800A651C + ((*(u16 *)(p + 0xA3D2) * 5) << 2)) + 4);
    func_8001AF34();
    goto L25C;
L35C:
    return;
}
