/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA3CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80132EF4(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8004864C(void *a0, void *a1);
extern void func_80048B6C(void *a0, void *a1);

void func_801AA3CC(s32 arg0)
{
    s16 rot[3]; /* sp+0x10 */
    s32 vec[3]; /* sp+0x18 */
    s32 s1;

    s1 = func_80132EF4(arg0, 0x2C);
    if (s1 != 0) {
        rot[0] = (func_8005C49C() & 0x3F) - 0x20;
        rot[1] = -(func_8005C49C() & 0x3F);
        rot[2] = func_8005C49C() & 0x3F;
        func_8004864C(&rot, &vec);
        *(u16 *)(s1 + 0x6) += vec[0];
        *(u16 *)(s1 + 0xA) += vec[1];
        *(u16 *)(s1 + 0xE) += vec[2];
        vec[2] = 0x40000;
        vec[0] = rot[0] << 14;
        vec[1] = rot[1] << 13;
        func_80048B6C(&vec, (void *)(s1 + 0x10));
    }
}
