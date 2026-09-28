/* Exact overlay word export for [800CEFD0,800CF104) from MAIN.CD
 * member0010 (extracted/overlays/main/0010.bin offset 0x200D8, base 800CEDF8).
 * 8001125C jals 800CEFDC mid this prologue; native enters 800CEFD0 so ra is saved.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CEFD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800CEFD0(void) {
    extern void func_8001B85C(void);
    extern s32 func_8001B86C(s32);
    extern void func_80011B7C(s32);
    extern void func_800596F4(s32);
    extern void func_8004239C(s32);
    extern void func_80059CF4(s32);
    extern void func_8001AF34(void);

    extern s32 D_80114E98;
    extern s32 D_80114E9C;
    extern u16 D_800B99F6;
    extern void (*D_800D3488[])(void);
    extern u8 D_800AF630[];
    extern s32 D_800A651C;

    u8 *base = &(*(u8 *)&D_800AF630);

    D_80114E98 = 0;
    D_80114E9C = 0;
    func_8001B85C();

loop:
    if (D_80114E98 == 0) {
        D_800D3488[D_800B99F6]();
    }
    if (D_80114E9C == 0) {
        D_80114E9C = func_8001B86C(0);
    }
    if (D_80114E98 != 0 && D_80114E9C != 0) {
        func_80011B7C(7);
        return;
    }
    func_800596F4(0);
    func_8004239C(*(s32 *)(base + 0xA3E8));
    func_80059CF4(*(s32 *)((u8 *)&D_800A651C + *(u16 *)(base + 0xA3D2) * 20) + 4);
    func_8001AF34();
    goto loop;
}
