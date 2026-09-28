/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5F6C - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_8005C49C(void);

void func_801A5F6C(s32 a0) {
    s32 v0;
    s32 v1;
    s32 p64;
    u16 tmp;

    v0 = func_8012C1B8();
    *(s32 *)(a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4((void *)a0);
        return;
    }
    func_8001C214(v0, 0);

    *(s32 *)(a0 + 0xE0) = func_8005C49C() % 64 + 0x20;

    *(s32 *)(a0 + 0xE8) = func_8005C49C() % 5 + 4;
    *(s32 *)(a0 + 0x48) = 0xC000;

    p64 = *(s32 *)(a0 + 0x64);
    tmp = *(u16 *)(p64 + 0x36);
    *(u16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
    *(u16 *)(a0 + 0x10A) = tmp;
}
