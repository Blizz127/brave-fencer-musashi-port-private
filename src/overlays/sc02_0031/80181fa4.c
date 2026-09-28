/* Complete SC02 record initialization; independently matched ordinary C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181FA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_80029504(void);
extern void func_8012CAE4(void *a0);
extern s32 func_80181F5C(void *a0, s32 *p);
extern s32 D_80188E10[];
extern s32 D_80188E20[];
extern s32 D_80188E30[];
extern s32 D_80188E40[];
extern void func_8012C1B8(void);

void func_80181FA4(void *a0) {
    register s32 t __asm__("$2");
    s32 s1;
    s32 v0;

    s1 = func_80029504();
    v0 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C214(v0, 0);
    *(s32 *)((s32)a0 + 0x58) = (s32)D_80188E40;
    __asm__ volatile("");
    t = *(u16 *)((s32)a0 + 0x2);
    *(s16 *)((s32)a0 + 0x5C) = 0x80;
    *(u16 *)((s32)a0 + 0x2) = t + 1;
    if (s1 >= 0x384) {
        *(s32 *)((s32)a0 + 0xDC) = func_80181F5C(a0, D_80188E30);
    } else if (s1 >= 0x258) {
        *(s32 *)((s32)a0 + 0xDC) = func_80181F5C(a0, D_80188E20);
    } else if (s1 >= 0xC8) {
        *(s32 *)((s32)a0 + 0xDC) = func_80181F5C(a0, D_80188E10);
    }
}
