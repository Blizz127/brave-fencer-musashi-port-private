/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A28AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012E544(s32 a0);
extern void func_8012C218(void *a0);
extern s32 D_801F1FD8;
extern u16 D_801F43C0;
extern s32 D_801AE21C[];

void func_801A28AC(s32 arg0)
{
    s32 handle;
    s32 obj;

    if (*(s32 *)(arg0 + 0x90) == (s32)&D_801F1FD8) {
        handle = func_8012E544(0x3D0);
        if (handle != 0) {
            func_8012C218((void *)handle);
        }
        obj = *(s32 *)(arg0 + 0x20);
        {
            register s32 state __asm__("$2");

            state = 3;
            D_801F43C0 = (u16)state;
        }
        *(s32 *)(obj + 0x24) = (s32)D_801AE21C;
    }
}
