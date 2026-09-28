/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A70D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8019FF8A;
extern s32 D_801B02B8[];
extern void func_801A5B5C(void *a0);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern int func_8005C49C(void);
extern s32 func_80128ED8(s32 a0, s32 *a1);

void func_801A70D0(void *arg0) {
    s32 s1;
    void *s2;

    s1 = *(s32 *)((u8 *)arg0 + 0xCC);
    func_801A5B5C(arg0);
    s2 = (u8 *)arg0 + 0xF0;

    if ((D_8019FF8A & 4) && *(s16 *)((u8 *)arg0 + 0xFE) == 0xB) {
        *(s32 *)(s1 + 4) |= 0x80000000;
    }

    if (func_80128ED8(s1, (s32 *)s2) != 0) {
        func_80128EA8(s1, (s32)s2, D_801B02B8[func_8005C49C() & 3]);
    }
}
